class Instructor extends Person {
	private int employeeID;

	//constructor for the instructor
	Instructor(String name, String email,int ei) {
		super(name,email);
		this.employeeID = ei;
	}

	int getEID() {
		return employeeID;
	}

	void setEID(int ei) {
		this.employeeID = ei;
	}
	//information being returned to be written into file in main
	public String print(){
		return "Name : " + this.name + "\nEmail : " + this.email + 
		"\nemployeeID :" + getEID() + "\n\n";
	} 
}