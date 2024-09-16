    package com.jeaohl.app;
    /**
    * walls that are surrounding the room.
    */

    public class Wall extends MapSite {
        private int wallNumber; //unique number of the wall
        private static int wallCount = 1; //to assign unique number of the wall

        /**
         * consturct wall and assign number based on the ordering of when its created
         */
        public Wall() {
            wallNumber = wallCount++;
            System.out.println("Creating the " + this.toString());
        }

        /**
         * Action of entering the wall. Overridden by subclasses to impletement special action.
         */
        @Override
        public void enter() {}

        /**
         * Giving string representation of the wall, including wall number
         * @return String that represents the wall, including wall number
         */
        @Override
        public String toString() {
            return "wall #" + wallNumber;
        }
    }