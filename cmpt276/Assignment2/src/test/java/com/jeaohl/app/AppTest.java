package com.jeaohl.app;

import org.junit.Test;
import static org.junit.Assert.*;

public class AppTest {
    @Test
    public void testRoomCreation() {
        int roomNumber = 1;
        Room room = new Room();
        //Room room = NULL;
        assertNotNull("room cannot be null if added", room);
    }

    @Test
    public void testSetSide() {
        Room room = new Room(); 
        Wall wall = new Wall();
        room.setSide(Direction.North, wall);
        MapSite northSide = room.getSide(Direction.North);
        
        assertNotNull("north side should contain a wall", northSide);
    }

    @Test
    public void testMazeCreation() {
        Maze maze = new Maze();
        Room room1 = new Room();
        Room room2 = new Room();
        maze.addingRoom(room1);
        maze.addingRoom(room2);
        assertEquals("Maze should contain 2 rooms", 2, maze.getRoomCount());
    }

}
