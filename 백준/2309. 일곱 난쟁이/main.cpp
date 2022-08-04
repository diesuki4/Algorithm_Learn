#include <iostream>

#define NUM_OF_DWARFS 9
#define NUM_OF_REAL_DWARFS 7
#define SUM_OF_HEIGHTS 100
#define INVALID_ELEMENT -1

void fnInput(int arr[], size_t size);
void swap(int &nA, int &nB);
int fnMinIndexFrom(int arr[], int nFrom, size_t size);
void fnSelectionSort(int arr[], size_t size);

int main(int argc, char *argv[])
{
	int nSumHeights = 0, nDiffHeights = 0;
	int *arrDwarfHeights = new int[NUM_OF_DWARFS];
	bool isEnd = false;

	fnInput(arrDwarfHeights, NUM_OF_DWARFS);
	fnSelectionSort(arrDwarfHeights, NUM_OF_DWARFS);

	for (int i = 0; i < NUM_OF_DWARFS; ++i)
		nSumHeights += arrDwarfHeights[i];

	nDiffHeights = nSumHeights - SUM_OF_HEIGHTS;

	for (int i = 0; i < NUM_OF_DWARFS - 1; ++i)
	{
		for (int j = i + 1; j < NUM_OF_DWARFS; ++j)
		{
			if (arrDwarfHeights[i] + arrDwarfHeights[j] == nDiffHeights)
			{
				arrDwarfHeights[i] = arrDwarfHeights[j] = INVALID_ELEMENT;
				isEnd = true;
				break;
			}
		}

		if (isEnd) break;
	}

	for (int i = 0; i < NUM_OF_DWARFS; ++i)
		if (arrDwarfHeights[i] != INVALID_ELEMENT)
			std::cout << arrDwarfHeights[i] << std::endl;

	delete arrDwarfHeights;

	return 0;
}

void fnInput(int arr[], size_t size)
{
	for (int i = 0; i < size; ++i)
		std::cin >> arr[i];
}

void fnSelectionSort(int arr[], size_t size)
{
	for (int i = 0; i < size - 1; ++i)
		swap(arr[i], arr[fnMinIndexFrom(arr, i, size)]);
}

int fnMinIndexFrom(int arr[], int nFrom, size_t size)
{
	int nMinIndex = nFrom;

	for (int i = nFrom + 1; i < size; ++i)
		if (arr[i] < arr[nMinIndex])
			nMinIndex = i;

	return nMinIndex;
}

void swap(int &nA, int &nB)
{
	int t = nA;
	nA = nB;
	nB = t;
}
