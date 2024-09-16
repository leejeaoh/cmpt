// a4_sort_implementations.h

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jea Oh Lee
// St.# : 301351043
// Email: jeaohl@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "a4_base.h"
//
// Do NOT add any other #includes to this file!
//

using namespace std;

//
// Put the implementations of all the functions listed in a4_base.h here, as
// well as is_sorted and rand_vec. You can use other helper functions if needed.
//

template <typename T>
bool is_sorted(vector<T> &v) {
	for(size_t i = 1; i < v.size(); i++) {
		if(v[i-1] > v[i]) {
			return false;
		}
	}
	return true;
}

vector<int> rand_vec(int n, int min, int max) {
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		v[i] = min + rand() % (max - min + 1);
	}
	return v;
}

// from : https://tjd1234.github.io/cmpt225fall2023/assignments/a4/
//		  Assignment 4 : Example of implementation using bullble sort

/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : element in the vector are sorted in non-decreasing order. 
					 Sort_stats object with sorting information will be returning.
*/
template <typename T>
Sort_stats bubble_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Bubble Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;

	clock_t start = clock();

	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v.size() - 1; j++) {
			stats.num_comparisons++;
			if(v[j] > v[j + 1]) {
				T temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;

	return stats;
}

// From : https://www.geeksforgeeks.org/insertion-sort/
// Example of implementation of insertion sort using c++

/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : vector is sorted in non-decreasing order. The Sort_stats object will contain
					 the sort name, size of the vector, number of comparison, and CPU time
*/
template <typename T>
Sort_stats insertion_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Insertion Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;

	clock_t start = clock();
	for(int i = 1; i < v.size(); i++) {
		T temp = v[i];
		int j = i;
		while (j > 0 && v[j-1] > temp) {
			stats.num_comparisons++;
			v[j] = v[j - 1];
			j--;
		}
		v[j] = temp;
	}

	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;

	return stats;
}

// From : https://www.geeksforgeeks.org/selection-sort/
// Example implementation of the selection sort using c++

/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : vector is sorted in non-decreasing order. Sort_stats will be returned
*/
template <typename T>
Sort_stats selection_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Selection Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;
	if(v.empty()) {
		return stats;
	}

	clock_t start = clock();
	for(int  i = 0; i < v.size() - 1; i++) {
		int min = i;
		for(int j = i + 1; j < v.size(); j++) {
			stats.num_comparisons++;
			if(v[j] < v[min]) {
				min = j;
			}
		}
		if(min != i) {
			T temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}

	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
	return stats;
}

// From : https://en.wikipedia.org/wiki/Shellsort
//        Basic layout of the shell sorting and Pseudocode

/*
	Pre-Condition : input is a non-const reference to vector of type T
	Post-Condition : vector is sorted in non-decreasing order, using sequence of gaps
					 reducing by half each time.

					 Sort_stats will be returned
*/
template <typename T>
Sort_stats shell_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Shell Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;

	clock_t start = clock();
	for(int gap = v.size() / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < v.size(); i++) {
			T temp = v[i];
			int j;
			for(j = i; j >= gap; j -= gap) {
				stats.num_comparisons++;
				if(v[j - gap] > temp) {
					v[j] = v[j - gap];
				} else {
					break;
				}
			}
			v[j] = temp;
		}
	}
	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
	return stats;

}

//From : https://github.com/tjd1234/cmpt225fall2023/blob/main/lecture_notes/week9/sorting.cpp
//       Sorting.cpp - Example of Merge implementation from the lecture note

/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : vector is sorted in non-decreasing order. Sort_stats will be returned
*/
//helper function for the merge sort
template <typename T>
void mergeSortHelper(vector<T> &v, int left, int right, Sort_stats &stats) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        //sort the first half and second half
        mergeSortHelper(v, left, mid, stats);
        mergeSortHelper(v, mid + 1, right, stats);
        //merge the sorted half
        merge(v, left, mid, right, stats);
    }
}

template <typename T>
void merge(vector<T> &v, int left, int mid, int right, Sort_stats &stats) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //creating temporary vectors
    vector<T> L(n1), R(n2);
    //copying data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }
    //merge the temp vectors back into v
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        stats.num_comparisons++;
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    //copying the remaining elements of L[] if there are any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    //copying the remaining elements of R[] if there are any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
Sort_stats merge_sort(vector<T> &v) {
    Sort_stats stats;
    stats.sort_name = "Merge Sort";
    stats.vector_size = v.size();
    stats.num_comparisons = 0;

    clock_t start = clock();
    //helper function to sort the whole vector
    mergeSortHelper(v, 0, v.size() - 1, stats);

    clock_t end = clock();
    stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
    return stats;
}

//From : https://github.com/tjd1234/cmpt225fall2023/blob/main/lecture_notes/week9/sorting.cpp
//       Sorting.cpp - Example of quickSort implementation from the lecture note
/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : vector is sorted in non-decreasing order. Sort_stats will be returned
*/
template <typename T>
int partition(vector<T> &v, int start, int end, Sort_stats &stats) {
	T pivot = v[end];
	int i = start;
	for(int j = start; j < end; j++) {
		stats.num_comparisons++;
		if(v[j] < pivot) {
			swap(v[i],v[j]);
			i++;
		}
	}
	swap(v[i],v[end]);
	return i;
}

//helper function for quick sort
template <typename T>
void quickSort(vector<T> &v, int start, int end, Sort_stats &stats) {
	if(start >= end){
		return;
	}
	int pivot = partition(v,start,end,stats);
	quickSort(v, start, pivot - 1, stats);
	quickSort(v, pivot + 1, end, stats);
}

template <typename T>
Sort_stats quick_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Quick Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;

	clock_t start = clock();
	quickSort(v,0,v.size()-1,stats);
	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
	return stats;
}

/*  iquick sorting algorithm

	Pre-Condition : input is non-const reference to a vector of type T and 
					a threshold for switching to insertion sort on small sub arrays
	Post-Condition : vector is sorted in non-decreasing order. The algorithm uses quicksort
					 until the sub-arrays are smaller than threshold which switches to 
					 insertion sort. Sort_stats will be returned
*/
//helper function for the iQuick sorting

template <typename T>
void insertionSubvector(vector<T> &v, int start, int end, Sort_stats &stats) {
    for (int i = start + 1; i <= end; ++i) {
        T temp = v[i];
        int j = i - 1;
        while(j >= start) {
        	stats.num_comparisons++;
        	if(v[j] > temp) {
        		v[j+1] = v[j];
        		j--;
        	} else {
        		break;
        	}
        }
        v[j + 1] = temp;
    }
}

//helper function for the iquick sorting
template <typename T>
void quickSort(vector<T> &v, int start, int end, int threshold, Sort_stats &stats) {
    if (start < end) {
        if (end - start < threshold) {
            insertionSubvector(v, start, end, stats);
        } else {
            int pivot = partition(v, start, end, stats);
            quickSort(v, start, pivot - 1, threshold, stats);
            quickSort(v, pivot + 1, end, threshold, stats);
        }
    }
}

template <typename T>
Sort_stats iquick_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Iquick Sort";
	stats.vector_size = v.size();
	stats.num_comparisons = 0;
	int threshold = 10;

	clock_t start = clock();
	quickSort(v, 0, v.size() - 1, threshold, stats); 
	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
	return stats;
}

// From : https://github.com/tjd1234/cmpt225fall2023/blob/main/lecture_notes/week7/priority_queues.cpp
//        Priority_queues.cpp - Lecture note example
/*
	Pre-Condition : input is non-const reference to a vector of type T
	Post-Condition : vector is sorted in non-decreasing order using priority queue (heap)
					 Sort_stats will be retruned 
*/

template <typename T>
class PqHeap {
	vector<T> v;
	ulong num_comparisons = 0;

public:
	int size() const {
		return v.size();
	}

	bool empty() const {
		return size() == 0;
	}
	void insert(const T &x) {
		v.push_back(x);
		int i = size() - 1;
		while(i > 0) {
            num_comparisons++;
            if (v[i] < v[(i - 1) / 2]) {
                swap(v[i], v[(i - 1) / 2]);
                i = (i - 1) / 2;
            } else {
            	//no swap needed
                break;
            }
        }
	}

	const T &min() const {
		return v[0];
	}

	void remove_min() {
        v[0] = v.back();
        v.pop_back();

        int i = 0;
        while (2 * i + 1 < size()) {
            int j = 2 * i + 1;
            num_comparisons++;
            if (j + 1 < size() && v[j + 1] < v[j]) {
            	num_comparisons++;
                j++;
            }
            if (v[i] <= v[j]) {
                break;
            }
            swap(v[i], v[j]);
            i = j;
        }
    }

    //get ulong type function
    ulong getNum() const {
    	return num_comparisons;
    }

};

template <typename T>
Sort_stats priority_queue_sort(vector<T> &v) {
	Sort_stats stats;
	stats.sort_name = "Priority Queue Sort";
	stats.vector_size = v.size();
	clock_t start = clock();
	PqHeap<T> pq;
	for(const T& x: v) {
		pq.insert(x);
	}

	for(size_t i = 0; i < v.size(); i++) {
		v[i] = pq.min();
		pq.remove_min();
	}

	clock_t end = clock();
	stats.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;
	stats.num_comparisons = pq.getNum(); //getNum used here to get num_comparison
	return stats;
}

