#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int price[4] = {0};
	int trucksInMinute[101] = {0};
	int totalPrice = 0;

	cin >> price[1] >> price[2] >> price[3];

	for (int i = 0; i < 3; ++i)
	{
		int from, to;

		cin >> from >> to;

		for (int j = ++from; j <= to; ++j)
			++trucksInMinute[j];
	}

	for (int truck : trucksInMinute)
		totalPrice += truck * price[truck];

	cout << totalPrice;

	return 0;
}
