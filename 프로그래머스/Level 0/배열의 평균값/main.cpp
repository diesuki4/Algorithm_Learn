#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
	cout << solution({89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}) << endl;

	return 0;
}

double solution(vector<int> numbers)
{
    return accumulate(numbers.begin(), numbers.end(), 0) / (double)numbers.size();
}
