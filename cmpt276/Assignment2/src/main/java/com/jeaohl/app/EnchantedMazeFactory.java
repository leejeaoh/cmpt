package com.jeaohl.app;

/**
 * Factory class creating enchanted maze components, including rooms that requires
 * spells casting and the door needing spell to unlock. 
 */


public class EnchantedMazeFactory extends MazeFactory {
	protected static Spell castSpell() {
		return new Spell();
	}

	@Override
	/**
	 * @param r1 first room that is connected by the door
     * @param r2 second room that is connected by the door
     * @return Generating the door that needs spell to unlock
	 */
	public Door makeDoor(Room r1, Room r2) {
		return new DoorNeedingSpell(r1,r2);
	}

	@Override
	/**
	 * @return Generating room that is enchanted by spell
	 */
	public Room makeRoom()  {
		return new EnchantedRoom(castSpell());
	}
}