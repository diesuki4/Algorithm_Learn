#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> result);
template <typename T> T twice(int n);
vector<int> solution(vector<int> numbers);

int main()
{
	print(solution({1, 2, 3, 4, 5}));
	print(solution({1, 2, 100, -99, 1, 2, 3}));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

template <typename T> T twice(int n)
{
	return n * 2;
}

vector<int> solution(vector<int> numbers)
{
	transform(numbers.begin(), numbers.end(), numbers.begin(), twice<int>);

    return numbers;
}
