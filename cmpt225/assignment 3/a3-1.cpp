// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jea Oh Lee    
// St.# : 301351043
// Email: jeaohl@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////
//
// Do not #include any other files!
//
#include <iostream>
#include <fstream>
#include <string>
#include "Announcement.h"
#include "JingleNet_announcer.h"
#include "Queue_base.h"

using namespace std;

// Queue from Queue_base.h hold announcement object
class Queue : public Queue_base<Announcement> {
private:
    //node holding each announcement and pointer to next Node
    struct Node {
        Announcement data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int queueSize;
public:
    //constructor initilaize empty list
    Queue() : head(nullptr), tail(nullptr), queueSize(0) {}

    //destructor deleting all nodes in the list
    ~Queue() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // enqueue :
    // -add new announcement to the back
    // -increase the queueSize
    void enqueue(const Announcement& a) override {
        //check if its empty
        if(isEmpty()) {
            head = new Node {a , nullptr};
            tail = head;
        } else {
            tail->next = new Node {a, nullptr};
            tail = tail->next;
        }
        //size of the queue increase if element has been added
        queueSize++;
    }

    // enqueueFront :
    // -add new announcement to the front of the queue
    // -increasing the queueSize
    void enqueueFront(const Announcement& a) {
        Node* newNode = new Node{a, head};
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        queueSize++;
    }

    // deuqueue :
    // -removing announcement at the front 
    // -decrease queueSize
    void dequeue() override {
        //check if the queue is empty
        assert(!isEmpty());
        if(head == tail) {
            tail = nullptr;
        }
        //update head to point to next
        Node* temp = head;
        head = head->next;
        if(head == nullptr) {
            tail = nullptr;
        }
        //delete temp
        delete temp;
        //decrement size of the list after dequeuing
        queueSize--;
    }

    //front :
    //returns the announcement at the front of the list
    const Announcement& front() const override {
        assert(!isEmpty());
        return head->data;
    }
    // isEmpty :
    //returns true if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
    // size : 
    //returns the size of the list size
    int size() const override{
        return queueSize;
    }  
};

//handle the enqueueing, dequeuing, promoting, and announcing of announcements 
//in the JingleNet class using the underlying Queue class.


class JingleNet {
private:
    //5 queue object representing different ranks
    Queue santa;
    Queue reindeer;
    Queue elf2;
    Queue elf1;
    Queue snowman;

public:
    //constructor initialize the 5 queue objects
    JingleNet() {
        santa = Queue();
        reindeer = Queue();
        elf2 = Queue();
        elf1 = Queue();
        snowman = Queue();
    }

    ~JingleNet() {
        //destructor, no dynamic allocations to deal
        //so nothing inside
    }
    // promoteRank :
    // -promoting rank to the next higher rank
    Rank promoteRank(Rank rank) {
    switch (rank) {
        case Rank::SNOWMAN:
            return Rank::ELF1;
        case Rank::ELF1:
            return Rank::ELF2;
        case Rank::ELF2:
            return Rank::REINDEER;
        case Rank::REINDEER:
            return Rank::SANTA;
        case Rank::SANTA:
            return Rank::SANTA; //higher rank does not exist after Santa
        default: 
            throw invalid_argument("Invalid rank detected");
        }
    }
    // sendAnnouncement :
    // -sending announcement to correct queue based on rank
    void sendAnnouncement(const Announcement& announcement) {
        Rank rank = announcement.get_rank();
        switch(rank) {
        case Rank::SANTA:
            santa.enqueue(announcement);
            break;
        case Rank::REINDEER:
            reindeer.enqueue(announcement);
            break;
        case Rank::ELF2:
            elf2.enqueue(announcement);
            break;
        case Rank::ELF1:
            elf1.enqueue(announcement);
            break;
        case Rank::SNOWMAN:
            snowman.enqueue(announcement);
            break;
        default:
            throw invalid_argument("invalid rank detected");
        }
    }//send announcement into queue

    // removeAllannouncement :
    // -remove announcements sent by the user from all queues
    void removeAllAnnouncement(const string& username) {
        for(Queue* queue : {&santa, &reindeer, &elf1, &elf2, &snowman}) {
            Queue temp;
            while(!queue->isEmpty()) {
                const Announcement a = queue->front();
                if(a.get_sender_name() != username) {
                    temp.enqueue(a);
                }
                queue->dequeue();
            }
            while (!temp.isEmpty()) {
                queue->enqueue(temp.front());
                temp.dequeue();
            }
        }
    }// remove announcement

    // promoteAnnouncement : 
    // -promotes all announcements sent by user
    void promoteAnnouncement(const string& username) {
        for (Queue* queue : {&reindeer, &elf2, &elf1, &snowman}) {
            Queue temp;
            while (!queue->isEmpty()) {
                Announcement a = queue->front();
                if (a.get_sender_name() == username) {
                    Rank newRank = promoteRank(a.get_rank());
                    Announcement newAnnouncement(username, newRank, a.get_text());
                    queue->dequeue();

                    switch(newRank) {
                    case Rank::SANTA:
                        santa.enqueue(newAnnouncement); 
                        break;
                    case Rank::REINDEER:
                        reindeer.enqueue(newAnnouncement);
                        break;
                    case Rank::ELF2:
                        elf2.enqueue(newAnnouncement);
                        break;
                    case Rank::ELF1:
                        elf1.enqueue(newAnnouncement);
                        break;
                    case Rank::SNOWMAN:
                        snowman.enqueue(newAnnouncement);
                        break;
                    default:
                        throw invalid_argument("Invalid rank detected");
                    }
                } else {
                    temp.enqueue(a);
                    queue->dequeue();
                }
            }
            while (!temp.isEmpty()) {
                queue->enqueue(temp.front());
                temp.dequeue();
            }
        }
    }

    // announce :
    // -announces a number of announcements, from high rank to low
    void announce(int n) {
        int announcementAnnounced = 0;
        for (Queue* queue : {&santa, &reindeer, &elf2, &elf1, &snowman}) {
            while (!queue->isEmpty() && announcementAnnounced < n) {
                const Announcement& a = queue->front();
                jnet.announce(a);  // Use announcer.announce to print the announcement
                    
                queue->dequeue();
                announcementAnnounced++;
            }
        }
    }

    // writeAnnouncementsToFile :
    // -write announcements in all queues into file
    void writeAnnouncementsToFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cerr << "Failed to open output file." << endl;
            return;
        }

        //iterate through all the queues and write their announcements to the file
        Queue* queues[] = {&santa, &reindeer, &elf2, &elf1, &snowman};
        for (Queue* queue : queues) {
            Queue temp;
            while (!queue->isEmpty()) {
                const Announcement& a = queue->front();
                outputFile << "SEND " << a.get_sender_name() << 
                    " " << to_string(a.get_rank()) << " " << a.get_text() << endl;
                temp.enqueue(a);
                queue->dequeue();
            }
            while (!temp.isEmpty()) {
                queue->enqueue(temp.front());
                temp.dequeue();
            }
        }

        outputFile.close();
    }
};

int main(int argc, char* argv[]) {
    //checking if the correct num of command arguments are provided
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    //opening input file for reading
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file: " << argv[1] << endl;
        return 1;
    }

    //create instance of junglenet to handle announcement
    JingleNet jnet;
    //variable to hold each line of input and parameters of command
    string line;
    while (getline(inputFile, line)) {
        string command, sender, rankStr, message;
        //size_t - used to represent sizes and guarantees to be big enough
        //to contain the biggest object that the system can handle
        //used as index for string operations
        size_t pos = 0;

        //finding command
        //finding the position of the first space which separates the command from rest of the line
        pos = line.find(' '); 
        //get command from beginning of the line to the first space
        command = line.substr(0, pos);
        //removing command and space from line. only arguments will be there
        line.erase(0, pos + 1);

        //annouce command handler that doesnt have a sender or rank
        if (command == "ANNOUNCE") {
            //converting string line into an int n using stoi
            //stoi coverts a string to an integer.
            int n = stoi(line);
            jnet.announce(n);
        } else {
            //finding the sender
            pos = line.find(' ');
            sender = line.substr(0, pos);
            line.erase(0, pos + 1);

            //finding the rank
            pos = line.find(' ');
            rankStr = line.substr(0, pos);
            line.erase(0, pos + 1);

            //the rest of the line is the message so set line to message
            message = line;

            if (command == "SEND") {
                Rank rank = to_rank(rankStr.c_str());
                Announcement announcement(sender.c_str(), rank, message.c_str());
                jnet.sendAnnouncement(announcement);
            } else if (command == "REMOVE_ALL") {
                jnet.removeAllAnnouncement(sender.c_str());
            } else if (command == "PROMOTE_ANNOUNCEMENTS") {
                jnet.promoteAnnouncement(sender.c_str());
            }
        }
    }

    inputFile.close();
    return 0;
}
