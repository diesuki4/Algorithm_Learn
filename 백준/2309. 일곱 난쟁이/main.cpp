#include <iostream>

#define NUM_OF_DWARFS 9
#define SUM_OF_HEIGHTS 100
#define INVALID_ELEMENT -1

void Input(int arr[], size_t size);
void SelectionSort(int arr[], size_t size);
int MinIndex(int arr[], size_t size, int iFrom = 0);
void Swap(int &nA, int &nB);

int main(int argc, char *argv[])
{
	int sumHeights = 0, diffHeights = 0;
	int dwarfHeights[NUM_OF_DWARFS] = {0};

	Input(dwarfHeights, NUM_OF_DWARFS);
	SelectionSort(dwarfHeights, NUM_OF_DWARFS);

	for (int height : dwarfHeights)
		sumHeights += height;

	diffHeights = sumHeights - SUM_OF_HEIGHTS;

	for (int i = 0; i < NUM_OF_DWARFS - 1; ++i)
	{
		for (int j = i + 1; j < NUM_OF_DWARFS; ++j)
		{
			if (dwarfHeights[i] + dwarfHeights[j] == diffHeights)
			{
				dwarfHeights[i] = dwarfHeights[j] = INVALID_ELEMENT;
				i = j = NUM_OF_DWARFS;
			}
		}
	}

	for (int height : dwarfHeights)
		if (height != INVALID_ELEMENT)
			std::cout << height << std::endl;

	return 0;
}

void Input(int arr[], size_t size)
{
	for (int i = 0; i < size; ++i)
		std::cin >> arr[i];
}

void SelectionSort(int arr[], size_t size)
{
	for (int i = 0; i < size - 1; ++i)
		Swap(arr[i], arr[MinIndex(arr, size, i)]);
}

int MinIndex(int arr[], size_t size, int iFrom)
{
	int iMin = iFrom;

	for (int i = iFrom + 1; i < size; ++i)
		if (arr[i] < arr[iMin])
			iMin = i;

	return iMin;
}

void Swap(int &nA, int &nB)
{
	int t = nA;
	nA = nB;
	nB = t;
}
