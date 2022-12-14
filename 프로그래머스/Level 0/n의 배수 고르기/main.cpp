#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, vector<int> numlist);

int main(int argc, char* argv[])
{
	print(solution(3, {4, 5, 6, 7, 8, 9, 10, 11, 12}));
	print(solution(5, {1, 9, 3, 10, 13, 5}));
	print(solution(12, {2, 100, 120, 600, 12, 12}));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(int n, vector<int> numlist)
{
    vector<int> answer;

	for (int num : numlist)
		if (num % n == 0)
			answer.push_back(num);

    return answer;
}
