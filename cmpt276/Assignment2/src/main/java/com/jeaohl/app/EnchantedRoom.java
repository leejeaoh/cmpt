package com.jeaohl.app;

/**
 * Enchanted room within the maze. it has unqiue property compare to the basic room.
 */

public class EnchantedRoom extends Room {
	/**
	 * constructs EnchantedRoom with spell. 
	 * @param s Spell that is associated with the enchanted room.
	 */
	EnchantedRoom(Spell s) {
		super(); //calling constructor of the superclass -> room
	} 

	/**
     * Giving string representation of the enchanted room, including property
     * @return String that represents the enchanted room, including property
     */
	public String toString() {
		return "Enchanted " + super.toString();
	}
}
