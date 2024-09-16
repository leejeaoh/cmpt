package com.jeaohl.app;

/**
 * Door needing spell to be open. This extends the basic funtionality of the 
 * door by adding property like spell.
 */
public class DoorNeedingSpell extends Door {
	/**
	 * construct DoorNeedingSpell connecting two different rooms.
	 * 
	 * @param r1 first room that is connected by the door
	 * @param r2 second room that is connected by the door
	 */
	DoorNeedingSpell(Room r1, Room r2) {
		super(r1,r2);
	}

	/**
	 * string representation of door and the status of the object.
	 * 
	 * @return the door, and the requirement (status)
	 */
	public String toString() {
		return super.toString() + "(Needing Spell)";
	}
}
