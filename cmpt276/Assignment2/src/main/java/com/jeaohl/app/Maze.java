package com.jeaohl.app;

import java.util.HashSet;
import java.util.Set;

/**
 * maze structure in the game, which contains the collection of rooms that are connected with the
 * door components. it manages the layout of the maze. 
 */
public class Maze {
    //printing when creating the maze
    /**
     * construct new maze instance with empty set of room.
     */
    Maze() {
        System.out.println("creating a Maze");
    }
    //creating a empty list of rooms using hashset
    private Set<Room> rooms = new HashSet<>();

    /**
     * Adding a room to maze if there is no room that shares the same unique number.
     * @param room Room that is getting added to the maze
     */
    public void addingRoom(Room room) {
        //checking whether the room already exist if not add room
        if(!rooms.contains(room)) {
            rooms.add(room);
            //printing to show which room is being added
            System.out.println("Add room: " + room.toString());
        }
    }
    /**
     * getting the total room count within the maze.
     * 
     * @return number of unique rooms in the maze.
     */
    public int getRoomCount() {
        return rooms.size();
    }
}