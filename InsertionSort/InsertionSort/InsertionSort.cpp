// SortDemo.cpp

//#include "pch.h"
#include <iostream>
#include <time.h>

#define LISTSIZE 20

using namespace std;

int current;
int temp;
int top;

struct listToSort {
	int items[LISTSIZE];
	int steps;
};

void initList(struct listToSort* aList)
{
	aList->steps = 0;
	srand(time(NULL));
	for (int i = 0; i < LISTSIZE; i++) aList->items[i] = rand() % 100;
}

void showList(struct listToSort* aList)
{
	for (int i = 0; i < LISTSIZE; i++) cout << aList->items[i] << " ";
}

void sortList(struct listToSort* aList)
{
	cout << "\n\n\n...doing Bubble Sort...\n";

	///////////////////////////////////
	// INSERT SORTING ALGORITHM HERE //
	///////////////////////////////////

	for (top = 0; top < LISTSIZE-1; top++)
	{
		current = top;
		temp = aList->items[current + 1];
		do
		{
			if (aList->items[current] > temp)
			{
				aList->items[current + 1] = aList->items[current];
			}
			else
			{
				break;
			}
			current--;
		} while (current >= 0);
		aList->items[current + 1] = temp;
	}



	// Use showList(aList) to display list at current stage of sorting.
}

int main()
{
	struct listToSort myList;
	initList(&myList);

	cout << "Source array:\n";
	showList(&myList);

	sortList(&myList);

	cout << "\n\n\nSorted array:\n";
	showList(&myList);

	cout << "\n\n\nSteps taken: " << myList.steps;
	cout << "\n\n\n";
}