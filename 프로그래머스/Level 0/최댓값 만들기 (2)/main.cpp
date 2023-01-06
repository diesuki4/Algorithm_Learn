#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> numbers);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, -3, 4, -5}) << endl;
	cout << solution({0, -31, 24, 10, 1, 9}) << endl;
	cout << solution({10, 20, 30, 5, 5, 20, 5}) << endl;

	return 0;
}

int solution(vector<int> numbers)
{
    int answer = INT_MIN;

	for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); ++it)
		for (vector<int>::iterator jt = it + 1; jt < numbers.end(); ++jt)
			answer = max(answer, *it * *jt);

    return answer;
}
