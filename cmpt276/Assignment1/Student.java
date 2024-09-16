class Student extends Person {
	//private attributes
	private int id;
	private double gpa;

	//constructor for the student class
	Student(String name, String email, int id, double gpa) {
		super(name,email);
		this.id = id;
		this.gpa = gpa;
	}

	//encapsulation 
	//getter and setter for student class
	int getID() {
		return id;
	}

	double getGPA() {
		return gpa;
	}

	void setID(int i) {
		this.id = i;
	}

	void setGPA(double g) {
		this.gpa = g;
	}

	//return information about this class (object)
	public String print(){
		return "Name : " + this.name + "\nEmail : " + this.email + 
		"\nStudent ID :" + getID() + "\nGPA : " + getGPA() + "\n\n";
	} 
}