#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(vector<int> num_list, int n);

int main(int argc, char* argv[])
{
	print(solution({1, 2, 3, 4, 5, 6, 7, 8}, 2));
	print(solution({100, 95, 2, 4, 5, 6, 18, 33, 948}, 3));

	return 0;
}

void print(vector<vector<int>> result)
{
	for (vector<int> v : result)
	{
		for (int num : v)
			cout << num << ' ';

		cout << endl;
	}

	cout << endl;
}

vector<vector<int>> solution(vector<int> num_list, int n)
{
    vector<vector<int>> answer;

	for (vector<int>::iterator it = num_list.begin(); it < num_list.end(); it += n)
		answer.push_back(vector<int>(it, it + n));

    return answer;
}
