package com.jeaohl.app;

/**
 * Room within the maze. Each room will have four sides where each of which can be a door
 * or a wall. Rooms are fundamental components in the maze since it provides spaces for players 
 * to access and nevigate through
 */

public class Room extends MapSite {
    private int roomNumber; //unique room number
    private static int roomCount = 1;//to assign unique number of the room
    private MapSite northDir, southDir, eastDir, westDir; //the sides of the room
    
    /**
     * consturct room and assign number based on the ordering of when its created
     */

    public Room() {
        this.roomNumber = roomCount++;
        System.out.println("Generating " + this.toString());
    }

    /**
     * setting one of the room's sides to specified MapSite.
     * 
     * @param d the direction where the wall or door is facing towards (North, West, East, South)
     * @param site MapSite to place door or wall to the speicified side of the room
     */
    public void setSide(Direction d, MapSite site) {
        switch (d) {
            case North:
                northDir = site;
                break;
            case South:
                southDir = site;
                break;
            case East:
                eastDir = site;
                break;
            case West:
                westDir = site; 
                break;
            default:
                System.out.println("Invalid direction detected");
                break;
        }
        System.out.println("Set " + d + " side of " + this.toString() + " to " + site.toString());
    }
    /**
     * getSide method allows to get return value where the which side the wall or door is located in the room.
     * 
     * @param d set of variable determing the direction where its facing towards of wall or door
     * @return MapSite located on the specified side of the room
     */
    public MapSite getSide(Direction d) {
        switch(d) {
            case North:
                return northDir;
            case South:
                return southDir;
            case East:
                return eastDir;
            case West:
                return westDir;
            default:
                return null;
        }
    }
    /**
     * Action of entering the room. Overridden by subclasses to impletement special action.
     */
    @Override
    public void enter() {}
    
    /**
     * Giving string representation of the room, including room number
     * @return String that represents the room, including room number
     */
    @Override
    public String toString() {
        return "Room #" + roomNumber;
    }
}
