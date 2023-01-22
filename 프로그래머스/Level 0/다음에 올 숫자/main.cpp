#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> common);

int main(int argc, char* argv[])
{
	cout << solution({1, 2, 3, 4, 5}) << endl;
	cout << solution({2, 4, 8}) << endl;
}

int solution(vector<int> common)
{
	int diff = common[1] - common[0];

	return (diff == common[2] - common[1]) ? common.back() + diff : common.back() * (common[1] / common[0]);
}
