// Algorhitms_w3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* C implementation QuickSort */
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

long long Comparisons = 0;
const int sz = 10000;

//Builds an array from a txt file
void buildArray(int anArray[]) {
	ifstream dataFile;
	dataFile.open("QuickSort.txt", ios::in);

	for (int i = 0; i < sz; i++)
		dataFile >> anArray[i];
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];    // pivot
	int i = low;  // Index of smaller element

	for (int j = low; j <= high; j++)
	{
		// If current element is smaller than or
		// equal to pivot
         		if (arr[j] < pivot )
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i ], &arr[low]);
	return (i);
}

int RandomPivotPartitioning(int arr[], int low, int high, int type)
{
	int pvt, pnt1, pnt2, pnt3, n, temp;

  
	if (type == 3)
	{
		if (high - low + 1 >= 3)
		{
			// choose the pivot
			pnt1 = arr[low];
			pnt2 = arr[high];
			pnt3 = arr[(low + high) / 2];

			if ((pnt1 < pnt2 && pnt2 < pnt3) || (pnt3 < pnt2 && pnt2 < pnt1))
			{
				pvt = (low + high) / 2;
			}

			if ((pnt2 < pnt1 && pnt1 < pnt3) || (pnt3 < pnt1 && pnt1 < pnt2))
			{
				pvt = low;
			}

			if ((pnt2 < pnt3 && pnt3 < pnt1) || (pnt1 < pnt3 && pnt3 < pnt2))
			{
				pvt = high;
			}
		}
		else
			pvt = high;
	}
	else if (type == 2)
	{
		pvt = high;
	}
	else if (type ==1)
	{
		pvt = low;
	}
	swap(&arr[low], &arr[pvt]);

	return partition(arr, low, high);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high, int type)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = RandomPivotPartitioning(arr, low, high, type);
		Comparisons = Comparisons + high - low;
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1, type);
		quickSort(arr, pi + 1, high, type);
	}
     }

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}

// Driver program to test above functions
int main()
{
	int arr[sz];

	int k;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (k = 1; k <= 3; k++)
	{
		Comparisons = 0;
		buildArray(arr);
		quickSort(arr, 0, n - 1, k);
		printf("\n Sorted array: \n");
		//printArray(arr, n);
		printf("%llu\n", Comparisons);
	}
	return 0;
}

