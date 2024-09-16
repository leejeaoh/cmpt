package com.jeaohlee.assignment3;

import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

public class ShellSortTest {
    //checking the implements of the interface
    @Test
    private <T extends Comparable<T>> ShellSort<T> createSorter() {
        return new ShellSort<>();
    }

    private final ShellSort<Integer> integerSorter = new ShellSort<>();
    private final ShellSort<String> stringSorter = new ShellSort<>();
    private final ShellSort<Character> characterSorter = new ShellSort<>();

    @Test
    void sortIntegers() {
        Integer[] array = {34, 2, -1, 5, 6, 8, 0, -3, 14, 76};
        Integer[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);
        
        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "The array should be sorted in ascending order");
    }

    @Test
    void sortCharacters() {
        Character[] array = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
        Character[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        characterSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "The array of characters should be sorted in ascending order");
    }

    @Test
    void sortStrings() {
        String[] array = {"banana", "apple", "fig", "orange", "elderberry", "cherry"};
        String[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        stringSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "The array of strings should be sorted in ascending order");
    }

    @Test
    void sortEmptyArray() {
        Integer[] array = {};
        integerSorter.sort(array);
        assertTrue(Arrays.equals(array, new Integer[]{}), "Sorting an empty array should not change it");
    }

    @Test
    void sortSingleElementArray() {
        Integer[] array = {42};
        Integer[] expected = Arrays.copyOf(array, array.length);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting a single-element array should not change it");
    }

    @Test
    void sortAlreadySortedArray() {
        Integer[] array = {1, 2, 3, 4, 5};
        Integer[] expected = Arrays.copyOf(array, array.length);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting an already sorted array should not change it");
    }

    @Test
    void sortReverseOrderArray() {
        Integer[] array = {5, 4, 3, 2, 1};
        Integer[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting a reverse order array should reorder it to ascending");
    }

    @Test
    void sortArrayWithDuplicates() {
        Integer[] array = {5, 1, 3, 5, 3, 1};
        Integer[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting an array with duplicates should correctly order it");
    }

    @Test
    void sortArrayWithNegativeNumbers() {
        Integer[] array = {-3, -1, -4, 5, 0, 2};
        Integer[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting an array with negative numbers should correctly order it");
    }

    @Test
    void sortLargeRangeNumbers() {
        Integer[] array = {Integer.MAX_VALUE, 0, Integer.MIN_VALUE, 100, -100};
        Integer[] expected = Arrays.copyOf(array, array.length);
        Arrays.sort(expected);

        integerSorter.sort(array);
        assertTrue(Arrays.equals(expected, array), "Sorting an array with a large range of numbers should correctly order it");
    }
}