#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

void solve(string input);
int numBlackKeys(int start, int end);

int main(int argc, char* argv[])
{
	solve("5 1 6 4 2 11");
	solve("4 1 4 9 12");

	return 0;
}

void solve(string input)
{
	int N, answer = 0;
	int start;
	istringstream cin(input);

	cin >> N >> start;

	while (--N)
	{
		int end;

		cin >> end;

		answer += abs(end - start) - numBlackKeys(start, end);

		start = end;
	}

	cout << answer << endl;
}

int numBlackKeys(int start, int end)
{
	if (end < start)
		swap(start, end);

	return	(start < 2 && 2 < end) +
			(start < 4 && 4 < end) +
			(start < 6 && 6 < end) +
			(start < 9 && 9 < end) +
			(start < 11 && 11 < end);
}
