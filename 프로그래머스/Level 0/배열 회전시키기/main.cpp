#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> numbers, string direction);

int main(int argc, char* argv[])
{
	print(solution({1, 2, 3}, "right"));
	print(solution({4, 455, 6, 4, -1, 45, 6}, "left"));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<int> numbers, string direction)
{
	vector<int>::iterator itbegin = numbers.begin();
	vector<int>::iterator itend = numbers.end();

	rotate(itbegin, (direction == "right") ? itend - 1 : itbegin + 1, itend);

    return numbers;
}
