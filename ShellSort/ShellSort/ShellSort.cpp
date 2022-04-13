// SortDemo.cpp
//#include "pch.h"
#include <iostream>
#include <time.h>
#define LISTSIZE 20
using namespace std;

struct listToSort
{
	int items[LISTSIZE];
	int steps;
};

void initList(struct listToSort* aList, bool randomFill = false)
{
	// This version of the init function has an optional boolean parameter.
	// If randomFill is specified as true, the list will be filled with random ints.
	// If it is false or not specified, the list will be filled with -1.

	aList->steps = 0;
	srand(time(NULL));
	for (int i = 0; i < LISTSIZE; i++)
	{
		if (randomFill) aList->items[i] = rand() % 100;
		else aList->items[i] = -1;
	}
}

void showList(struct listToSort* aList)
{
	for (int i = 0; i < LISTSIZE; i++) cout << aList->items[i] << " ";
	cout << "\n\n";
}

void gappedInsertionSort(struct listToSort* aList, int gap = 1)
{
	cout << "...doing Gapped Insertion Sort, gap = " << gap << "...\n";
	// This version of insertion sort takes an optional gap parameter.
	// The loop skips the number of iterations specified by gap.
	// So if gap is 1, every iteration is included.
	// Or if gap is 5, only every 5th iteration is included.

	// TODO:
	// Edit the loop declaration and body to implement the gap.
	// Increment the step counter for every comparison and assignment.

	int i, j, temp;
	for (i = gap; i < LISTSIZE; i++)
	{
		j = i;
		while (j > 0 && aList->items[j - gap] > aList->items[j])
		{
			temp = aList->items[j];
			aList->items[j] = aList->items[j - gap];
			aList->items[j - gap] = temp;
			j--;
			aList->steps++;
		}
	}

	//int i, j, temp;
	//for (i = 1; i < LISTSIZE; i++)
	//{
	//	j = i;
	//	while (j > 0 && aList->items[j - 1] > aList->items[j])
	//	{
	//		temp = aList->items[j];
	//		aList->items[j] = aList->items[j - 1];
	//		aList->items[j - 1] = temp;
	//		j--;
	//		aList->steps++;
	//	}
	//}
	
}

void shellSort(struct listToSort* aList)
{
	cout << "\n...doing Shell Sort...\n";
	// TODO:
	// This first version of shell sort will automatically select slice sizes.
	// The first slice size will be 2 halves; the second slice size will be 4 quarters; and so on.
	// Therefore, we can use a for loop that starts at 2, and doubles every loop so long as it is less than or equal to LISTSIZE.
	// We can then use these slice amounts as input parameters for the gapped insertion sort.
	// After each pass, show the running total of the step counter.

	int gap;

	for (gap = LISTSIZE / 2; gap > 0; gap /= 2)
	{
		gappedInsertionSort(aList, gap);
		aList->steps++;
	}
}

void shellSort2(struct listToSort* aList)
{
	cout << "\n...doing Shell Sort v2...\n";
	// TODO:
	// This second version of shell sort will contain an array of integers.
	// The integers will specify the pattern of slice sizes.
	// After each pass, show the running total of the step counter.
	// Compare the steps taken with the previous 2-4-8 pattern.
	// Experiment will different patterns to find an efficient combination.

	int pattern[4] = { 1, 3, 5, 10 };
	int gap, i;
	i = 3;

	for (gap = pattern[i]; i >= 0; gap = pattern[i])
	{
		gappedInsertionSort(aList, gap);
		aList->steps++;
		i--;
	}
}

int main()
{
	// Create a new source list and fill it with random integers.
	struct listToSort myList;
	initList(&myList, true);

	// Display the source list.
	cout << "Source list:\n";
	showList(&myList);

	// Sort the list.
	//gappedInsertionSort(&myList);
	//shellSort(&myList);
	shellSort2(&myList);

	// Display the sorted list.
	cout << "\n\nSorted list:\n";
	showList(&myList);

	// Display the total steps taken.
	cout << "\n\nSteps taken: " << myList.steps;
	cout << "\n\n\n";
}