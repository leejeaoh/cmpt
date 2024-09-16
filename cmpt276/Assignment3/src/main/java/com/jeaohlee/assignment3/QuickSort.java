package com.jeaohlee.assignment3;

/**
 * 
 * Implementation of the quick sorting algorithm for sorting an array of the elements with comparable interface.
 *
 * Class provides a public sort method to sort an array in ascending order.
 * Class does not define an explicit constructor and relies on the default no-argument constructor.
 * 
 * @param <T> type of element that is being sorted and it must extend the comparable interface to ensure that elements can be compared.
 */

public class QuickSort<T extends Comparable<T>> implements Sorter<T> {
    /**
     * partition the array into two different parts based on the pivot element. 
     * Element(s) that is less or equal to pivot should be moved to left.
     * Element(s) that is greater than pivot should be moved to right.
     * 
     * @param arr Array of elements to be partitioned.
     * @param begin starting index of the array that is going to be partitioned.
     * @param end end index of the array that is going to be partitioned.
     * @return the partition index where the pivot element is going to be placed.
     * 
	 */

    private int partition(T arr[], int begin, int end) {
        T pivot = arr[end];
        int i = (begin - 1);

        for (int j = begin; j < end; j++) {
            if (arr[j].compareTo(pivot) <= 0) {
                i++;

                T swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
            }
        }

        T swapTemp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = swapTemp;

        return i + 1;
    }

    /**
     * Recursive method that implements the quicksort algorithm to sort 
     * 
     * @param arr Array of elements to be sorted using quick sort algoritm
     * @param begin The starting index of the array
     * @param end The ending index of the array
     */

    private void quickSort(T arr[], int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, end);
        }
    }

    /**
     * sorts the array that is passed using the quick sort algorithm. It is public interface of the quicksort class
     * and is intended to be called by users that wants to sort the array.
     * 
     * @param list Array of elements that needs to be sorted. The elements must be instance of class that implements 
     * the comparabl interface.
     */

    @Override
    public void sort(T[] list) {
        if (list != null && list.length > 0) {
            quickSort(list, 0, list.length - 1);
        }
    }
}