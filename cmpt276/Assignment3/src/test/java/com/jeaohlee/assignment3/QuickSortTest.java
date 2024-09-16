package com.jeaohlee.assignment3;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class QuickSortTest {
    //checking the implements of the interface
    @Test
    private <T extends Comparable<T>> QuickSort<T> createSorter() {
        return new QuickSort<>();
    }

    @Test
    void shellSortImplementsSorterInterface() {
        Sorter<Integer> sorter = new ShellSort<>();
        assertNotNull(sorter, "ShellSort should implement the Sorter interface.");
    }

    @Test
    void quicksortImplmentsSorterInterface() {
        Sorter<Integer> sorter = new QuickSort<>();
        assertNotNull(sorter, "QuickSort should implement the Sorter Interface.");
    }

    //testing for the quicksort algorithm
    @Test
    void quickSortTestInt() {
        Integer[] array = {5, 2, 6, 1, 6, 7, 2, 4, 10, 0};
        Integer[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Integer array should be sorted correctly.");
    }

    @Test
    void quickSortTestChar() {
        Character[] array = {'A', 'C', 'D', 'O', 'B', 'A', 'B', 'F', 'Z', 'E'};
        Character[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Character> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Character array should be sorted correctly.");
    }

    @Test
    void quickSortTestString() {
        String[] array = {"Apple", "Banana", "Orange", "Fig", "Grape", "Date", "Cherry", "Elderberry"};
        String[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<String> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "String array should be sorted correctly.");
    }

    @Test
    void quickSortTestAlreadySorted() {
        Integer[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Integer[] sortedArray = array.clone();

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Already sorted array should remain sorted.");
    }

    @Test
    void quickSortTestReverseOrder() {
        Integer[] array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        Integer[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Array sorted in reverse order should be correctly sorted.");
    }

    @Test
    void quickSortTestWithDuplicates() {
        Integer[] array = {5, 2, 5, 1, 6, 2, 1, 4, 6, 0};
        Integer[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Array with duplicates should be sorted correctly.");
    }

    @Test
    void quickSortTestSingleElement() {
        Integer[] array = {42};
        Integer[] sortedArray = array.clone();

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Single-element array should be considered sorted.");
    }

    @Test
    void quickSortTestEmpty() {
        Integer[] array = {};
        Integer[] sortedArray = array.clone();

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Empty array should be considered sorted.");
    }

    @Test
    void quickSortTestWithNegativeNumbers() {
        Integer[] array = {-3, -1, -4, -2, 0, 2, 1, 3, 5, 4};
        Integer[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Array with negative numbers should be sorted correctly.");
    }

    @Test
    void quickSortTestLargeRange() {
        Integer[] array = {Integer.MAX_VALUE, 0, -1, Integer.MIN_VALUE, 100, -100, 2000000, -2000000};
        Integer[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        QuickSort<Integer> sorter = new QuickSort<>();
        sorter.sort(array);

        assertTrue(Arrays.equals(array, sortedArray), "Array with a large range of numbers should be sorted correctly.");
    }
}