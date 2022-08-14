#include <iostream>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	int maxTemp = INT_MIN;
	list<int> lst;

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int temp;

		cin >> temp;

		for (int &e : lst)
			e += temp;

		lst.push_back(temp);

		if (lst.size() == k)
		{
			int sum = lst.front();

			maxTemp = max(maxTemp, sum);

			lst.pop_front();
		}
	}

	cout << maxTemp;

	lst.clear();

	return 0;
}
