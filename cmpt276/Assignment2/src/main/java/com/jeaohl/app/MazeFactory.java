package com.jeaohl.app;
/**
 * Factory class creating enchanted maze components.
 */

public class MazeFactory {
    /**
     * Creating new maze instance. Method can be overridden by subclasses to create
     * different type of maze.
     * 
     * @return new Maze object
     */
    public Maze makeMaze() {
        return new Maze();
    }

    /**
     * Creating new room instance. Method can be overridden by subclasses to create
     * different type of room.
     * 
     * @return new room object
     */
    public Room makeRoom() {
        return new Room();
    }

    /**
     * Creating new wall instance. Method can be overridden by subclasses to create
     * different type of wall.
     * 
     * @return new wall object
     */
    public Wall makeWall() {
        return new Wall();
    }

    /**
     * Creating new door instance. Method can be overridden by subclasses to create
     * different type of door.
     * 
     * @param r1 The first room that is connected by the door
     * @param r2 the second room that is connected by the door
     * @return new door object connecting two specified rooms.
     */
    public Door makeDoor(Room r1, Room r2) {
        return new Door(r1, r2);
    }
}
