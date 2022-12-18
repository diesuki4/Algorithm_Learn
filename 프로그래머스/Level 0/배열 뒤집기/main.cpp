#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> num_list);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 4, 5}));
    print(solution({1, 1, 1, 1, 1, 2}));
    print(solution({1, 0, 1, 1, 1, 3, 5}));

    return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<int> num_list)
{
	reverse(num_list.begin(), num_list.end());

    return num_list;
}
