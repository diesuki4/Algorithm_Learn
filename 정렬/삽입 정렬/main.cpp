#include <iostream>

void insertion_sort(int arr[], size_t size);
void insertion_sort_advanced(int arr[], size_t size);
void swap(int &a, int &b);

int main(int argc, char* argv[])
{
	int arr1[] = {5, 7, 2, 8, 3, 4, 1, 6};
	size_t size = sizeof(arr1) / sizeof(*arr1);

	int *arr2 = new int[size];
	std::copy(arr1, arr1 + size, arr2);

	insertion_sort(arr1, size);
	insertion_sort_advanced(arr2, size);

	for (int i = 0; i < size; ++i)
		std::cout << arr1[i] << " " << arr2[i] << std::endl;

	return 0;
}

void insertion_sort(int arr[], size_t size)
{
	for (int i = 1; i < size; ++i)
	{
		int num = arr[i], j;

		for (j = i - 1; 0 <= j && arr[j] > arr[i]; --j);

		std::copy(arr + j + 1, arr + i, arr + j + 2);
		/*
		for (int k = i - 1; j < k; --k)
			arr[k + 1] = arr[k];
		*/

		arr[j + 1] = num;
	}
}

void insertion_sort_advanced(int arr[], size_t size)
{
	for (int i = 1; i < size; ++i)
		for (int j = i; 0 < j && arr[j - 1] > arr[j]; --j)
			swap(arr[j - 1], arr[j]);
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
