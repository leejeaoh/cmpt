abstract class Person {
	String name;
	String email;

	//constructor for the person class
	Person(String name,String email) {
		this.name = name;
		this.email = email;
	}

	//encapsulation 
	//getter and setter for person class
	String getName() {
		return name;
	}

	String getemail() {
		return email;
	}

	void setName(String n) {
		this.name = n;
	}

	void setEmail(String e) {
		this.email = e;
	}

	//information for person object
	public String print(){
		return "Name : " + this.name + "\nEmail : " + this.email + "\n\n";
	} 
};