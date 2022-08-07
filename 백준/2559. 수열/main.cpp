#include <iostream>
#include <climits>

using namespace std;

#define MAX(x, y) ((x) < (y) ? (y) : (x))

int main(int argc, char* argv[])
{
	int n, k;
	int *temp, maxTemp = INT_MIN;

	cin >> n >> k;
	temp = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> temp[i];

	n -= k - 1;

	for (int i = 0; i < n; ++i)
	{
		int sumTemp = 0;

		for (int j = i; j < i + k; ++j)
			sumTemp += temp[j];

		maxTemp = MAX(maxTemp, sumTemp);
	}

	cout << maxTemp;

	delete temp;

	return 0;
}
