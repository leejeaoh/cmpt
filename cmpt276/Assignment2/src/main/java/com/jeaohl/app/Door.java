package com.jeaohl.app;
/**
 * Door that connects two different rooms within the maze.
 * Door is a connecting path way between two room
 */

public class Door extends MapSite {
    //attributes
    private Room room1; //first room connected by the door
    private Room room2; //second room connected by the door
    private int doorNumber; //unique number for the door
    private int doorCount = 1; //to assign unique number to the door
    
    //methods
    /**
     * Constructs a door that is connected between two specified rooms.
     * 
     * @param r1 first room that is connected by the door
     * @param r2 second room that is connected by the door
     */
    public Door(Room r1, Room r2) {
        //if there is two rooms, increment one door count to show that the two room is
        //connected to each other
        doorNumber = doorCount++;
        System.out.println("Create " + this.toString() + " with " + 
            r1.toString() + " and " + r2.toString()); //print to display information
        this.room1 = r1;
        this.room2 = r2;
    }
    /**
     * Action of entering the door. Overridden by subclasses to impletement special action.
     */
    @Override
    public void enter() {}

    /**
     * Giving string representation of the door, including door number
     * @return String that represents the door, including door number
     */
    @Override
    //override the toString to use it on System.out.println when needed to print door #
    public String toString(){
        return "Door #" + doorNumber;
    }

}