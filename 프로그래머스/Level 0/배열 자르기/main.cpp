#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> numbers, int num1, int num2);

int main(int argc, char* argv[])
{
	print(solution({1, 2, 3, 4, 5}, 1, 3));
	print(solution({1, 3, 5}, 1, 2));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<int> numbers, int num1, int num2)
{
    return vector<int>(numbers.begin() + num1, numbers.begin() + ++num2);
}
