#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int num, int total);

int main(int argc, char* argv[])
{
	print(solution(3, 12));
	print(solution(5, 15));
	print(solution(4, 14));
	print(solution(5, 5));
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << ' ';
	cout << endl;
}

vector<int> solution(int num, int total)
{
	vector<int> answer(num, total / num - (num - 1) / 2);

	for (int i = 0; i < num; ++i)
		answer[i] += i;

	return answer;
}
