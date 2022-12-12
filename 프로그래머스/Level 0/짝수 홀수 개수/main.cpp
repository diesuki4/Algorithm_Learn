#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> num_list);

int main(int argc, char* argv[])
{
	print(solution({1, 2, 3, 4, 5}));
	print(solution({1, 3, 5, 7}));
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<int> num_list)
{
	int evenCount = 0, oddCount = 0;

	for (int num : num_list)
	{
		bool lsb = num & 1;

		evenCount += !lsb,
		oddCount += lsb;
	}

	return vector({evenCount, oddCount});
}
