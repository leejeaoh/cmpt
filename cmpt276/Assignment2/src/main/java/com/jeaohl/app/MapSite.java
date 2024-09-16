package com.jeaohl.app;

/**
 * abstract class MapSite is used for all components in the maze 
 * defining the interaction with maze objects like walls, doors and rooms.
 */

public abstract class MapSite {
    /**
     * the action of entering certain site from the maze. its an abstract and will
     * be implemented by subclasses to define speical action when entering those site.
     */
    public abstract void enter();
}