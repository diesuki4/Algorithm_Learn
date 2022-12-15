#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, 7, 10, 11}) << endl;
	cout << solution({9, -1, 0}) << endl;

	return 0;
}

int solution(vector<int> array)
{
	sort(array.begin(), array.end());

    return array[array.size() / 2];
}
