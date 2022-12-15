#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
	print(solution(10));
	print(solution(15));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(int n)
{
	vector<int> answer;

	for (int i = 1; i <= n; i += 2)
		answer.push_back(i);

	return answer;
}
