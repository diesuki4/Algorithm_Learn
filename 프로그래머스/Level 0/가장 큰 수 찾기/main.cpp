#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> array);

int main(int argc, char* argv[])
{
	print(solution({1, 8, 3}));
	print(solution({9, 10, 11, 8}));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<int> array)
{
	vector<int>::iterator max_it = max_element(array.begin(), array.end());

    return vector<int>({*max_it, static_cast<int>(max_it - array.begin())});
}
