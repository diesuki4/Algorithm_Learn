#include <iostream>

void bubble_sort(int arr[], size_t size);
void swap(int &a, int &b);

int main(int argc, char* argv[])
{
	int arr[] = {5, 7, 2, 8, 3, 4, 1, 6};
	size_t size = sizeof(arr) / sizeof(*arr);

	bubble_sort(arr, size);

	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << std::endl;

	return 0;
}

void bubble_sort(int arr[], size_t size)
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - 1 - i; ++j)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
