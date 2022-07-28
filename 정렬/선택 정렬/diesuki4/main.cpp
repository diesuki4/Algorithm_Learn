#include <iostream>

void selection_sort(int arr[], size_t size);
void swap(int &a, int &b);
int min_index(int arr[], size_t size, int startIdx);

int main(int argc, char* argv[])
{
	int arr[] = {5, 7, 2, 8, 3, 4, 1, 6};
	size_t size = sizeof(arr) / sizeof(*arr);

	selection_sort(arr, size);

	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << std::endl;

	return 0;
}

void selection_sort(int arr[], size_t size)
{
	for (int i = 0; i < size; ++i)
		swap(arr[i], arr[min_index(arr, size, i)]);
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int min_index(int arr[], size_t size, int startIdx)
{
	int min_idx = startIdx;

	for (int i = startIdx + 1; i < size; ++i)
		if (arr[i] <= arr[min_idx])
			min_idx = i;

	return min_idx;
}
