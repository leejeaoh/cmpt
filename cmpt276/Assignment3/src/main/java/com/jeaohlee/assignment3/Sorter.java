package com.jeaohlee.assignment3;
/**
 * Generic interface for sorting an array of elements in-place
 * @param <T> the type of the elements to be sorted
 */

public interface Sorter<T extends Comparable<T>> {
    /**
     * Sorts the provided array in-place in ascending orders
     * @param list Array of elements to be sorted
     */
    void sort(T[] list);
}