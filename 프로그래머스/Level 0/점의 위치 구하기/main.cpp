#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> dot);

int main(int argc, char* argv[])
{
	cout << solution({2, 4}) << endl;
	cout << solution({-7, 9}) << endl;

	return 0;
}

int solution(vector<int> dot)
{
	int x = dot[0];
	int y = dot[1];

	return	(0 < x) ?
			(0 < y) ? 1 : 4 :
			(0 < y) ? 2 : 3;
}
