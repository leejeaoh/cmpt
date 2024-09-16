package com.jeaohlee.assignment3;

/**
 * Implementation of the Shell sort aglorithm to sort an array of elements that
 * implements the comparable interface. 
 * 
 * Class provides a public sort method to sort an array in ascending order.
 * Class utilizes the default no-argument constructor for instantiation.
 * 
 * @param <T> Type of elements to be sorted 
 */

public class ShellSort<T extends Comparable<T>> implements Sorter<T> {
	/**
	 * Sorts the array of objects using shell sorting algroithm
	 * @param arr Array that needs to be sorted
	 */
	public void shellSort(T arr[]) {
		int n = arr.length;

		for (int gap = n / 2; gap > 0; gap /=2) {
			for(int i = gap; i < n; i += 1) {
				T temp = arr[i];
				int j;
				for(j = i; j >= gap && arr[j - gap].compareTo(temp) > 0; j -= gap) {
					arr[j] = arr[j - gap];
				}
				arr[j] = temp;
			}
		}
	}
	/**
	 * Sorts the array of objects in ascending order
	 * If the array is either null or empty, no action is taken
	 * 
	 * @param list Array to be sorted
	 */

	@Override
	public void sort(T[] list) {
		if (list != null && list.length > 0) {
            shellSort(list);
        }
	}
}