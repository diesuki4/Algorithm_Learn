#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> numlist, int n);

int main(int argc, char* argv[])
{
	print(solution({1, 2, 3, 4, 5, 6}, 4));
	print(solution({10000, 20, 36, 47, 40, 6, 10, 7000}, 30));
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << ' ';
	cout << endl;
}

vector<int> solution(vector<int> numlist, int n)
{
	sort(numlist.begin(), numlist.end(), [n](int a, int b) { int distA = abs(n - a), distB = abs(n - b); return (distA != distB) ? distA < distB : a > b; });

	return numlist;
}
