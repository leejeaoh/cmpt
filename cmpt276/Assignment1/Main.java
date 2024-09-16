import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedWriter;

public class Main {
	public static void main(String argv[]) {
		//creating Arraylist to store people object
		ArrayList<Person> people = new ArrayList<>();
		//for instructor - creating object 
		Instructor prof1 = new Instructor("Saba Alimadadi Jani", "saba@sfu.ca", 111111);
		Instructor prof2 = new Instructor("Steve Ko", "steveko@sfu.ca", 1313131);
		//for instructor - creating object
		Student student1 = new Student("Jake","jake@sfu.ca",12345,4.0);
		Student student2 = new Student("Jay","jeaohl@sfu.ca",301351043,4.33);
		//adding object that was created into arrayList - Person people
		people.add(prof1);
		people.add(prof2);
		people.add(student1);
		people.add(student2);

		//try-catch exception
		//if the file is unable to be written, throw exception error
		//if it works, write to a file "people.txt"
		try {
			BufferedWriter writer = new BufferedWriter(new FileWriter("people.txt"));
			for(Person person : people) {
				writer.write(person.print());
			}
			writer.close();
		}
		catch(IOException e) { 
			System.err.println("Error while writting file");
		}
 	}
}