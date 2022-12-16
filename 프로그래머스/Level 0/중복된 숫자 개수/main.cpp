#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array, int n);

int main(int argc, char* argv[])
{
	cout << solution({1, 1, 2, 3, 4, 5}, 1) << endl;
	cout << solution({0, 2, 3, 4}, 1) << endl;

	return 0;
}

int solution(vector<int> array, int n)
{
    return count(array.begin(), array.end(), n);
}
