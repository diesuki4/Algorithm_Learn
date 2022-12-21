#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, 3, 4, 5}) << endl;
	cout << solution({0, 31, 24, 10, 1, 9}) << endl;

	return 0;
}

int solution(vector<int> numbers)
{
	sort(numbers.rbegin(), numbers.rend());

    return numbers[0] * numbers[1];
}
