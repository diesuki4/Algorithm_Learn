#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sides);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, 3}) << endl;
	cout << solution({3, 6, 2}) << endl;
	cout << solution({199, 72, 222}) << endl;

	return 0;
}

int solution(vector<int> sides)
{
	int max = 0;
	int sum = 0;

	for (int num : sides)
	{
		sum += num;

		if (max < num)
			max = num;
	}

    return (max * 2 < sum) ? 1 : 2;
}
