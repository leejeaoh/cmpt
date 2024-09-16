package com.jeaohl.app;

/**
 * MazeGame class is important to create and set up the maze game environment.
 * It uses the factory method design pattern to abstract the creation of the maze
 * components like rooms, doors and walls.
 * 
 * Factories can be used by creating different room by utilizing different factories 
 * which can be extended like enchanted factory.
 */

public class MazeGame {
    /**
     * Creating maze using provided mazefactory. 
     * @param factory MazeFactory instance used to create the maze components.
     * @return assembled maze
     */
    public Maze createMaze(MazeFactory factory) {
        Maze maze = factory.makeMaze();
        Room r1 = factory.makeRoom();
        Room r2 = factory.makeRoom();
        Door door = factory.makeDoor(r1,r2);

        maze.addingRoom(r1);
        maze.addingRoom(r2);
        //first room
        r1.setSide(Direction.North, factory.makeWall());
        r1.setSide(Direction.East, door);
        r1.setSide(Direction.South, factory.makeWall());
        r1.setSide(Direction.West, factory.makeWall());
        //second room
        r2.setSide(Direction.North, factory.makeWall());
        r2.setSide(Direction.East, factory.makeWall());
        r2.setSide(Direction.South, factory.makeWall());
        r2.setSide(Direction.West, door);        
        return maze;
    }
}