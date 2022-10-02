#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool compare(int i, int j);

map<int, int> counts, firsts;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, C;
	int msg[1000];
	set<int> numbers;

	cin >> N >> C;

	for (int i = 0; i < N; ++i)
	{
		cin >> msg[i];
		numbers.insert(msg[i]);
	}

	for (int num : numbers)
	{
		counts[num] = count(msg, msg + N, num);
		firsts[num] = find(msg, msg + N, num) - msg;
	}

	sort(msg, msg + N, compare);

	for (int i = 0; i < N; ++i)
		cout << msg[i] << " ";

	return 0;
}

bool compare(int i, int j)
{
	if (counts[i] > counts[j])
		return true;
	else if (counts[i] < counts[j])
		return false;

	if (firsts[i] < firsts[j])
		return true;
	else
		return false;
}
