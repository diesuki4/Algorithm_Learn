#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array, int height);

int main()
{
	cout << solution({149, 180, 192, 170}, 167) << endl;
	cout << solution({180, 120, 140}, 190) << endl;

	return 0;
}

int solution(vector<int> array, int height)
{
    return count_if(array.begin(), array.end(), [height](int elem) { return height < elem; });
}
