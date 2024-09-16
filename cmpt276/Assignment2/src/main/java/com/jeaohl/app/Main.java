package com.jeaohl.app;

public class Main {
    /**
     * The main initializes the game by creating maze with its characteristic using the
     * mazeFactory or EnchantedMazeFactory.
     * It sets the environment of the maze.
     * @param args command line arugments passed to main method but in this case its not being used.
     */
    public static void main(String[] args) {
        MazeFactory factory = new EnchantedMazeFactory();
        MazeGame game = new MazeGame();
        Maze maze = game.createMaze(factory);
    }
}