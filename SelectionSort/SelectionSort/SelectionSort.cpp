// SortDemo.cpp

#include <iostream>
#include <time.h>

#define LISTSIZE 20

using namespace std;

int lowestIndex, temp;

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
	cout << "\n\n\n...doing Selection Sort...\n";

	for (int current = 0; current < LISTSIZE; current++)
	{
		lowestIndex = current;
		for (int check = current + 1; check < LISTSIZE; check++)
		{
			if (aList->items[check] < aList->items[lowestIndex])
			{
				lowestIndex = check;
			}
			aList->steps++;
		}
		temp = aList->items[lowestIndex];
		aList->items[lowestIndex] = aList->items[current];
		aList->items[current] = temp;
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

