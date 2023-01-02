#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> box, int n);

int main(int argc, char* argv[])
{
	cout << solution({1, 1, 1}, 1) << endl;
	cout << solution({10, 8, 6}, 3) << endl;

	return 0;
}

int solution(vector<int> box, int n)
{
    return (box[0] / n) * (box[1] / n) * (box[2] / n);
}
