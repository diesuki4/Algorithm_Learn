#include <iostream>

using namespace std;

int solution(int slice, int n);

int main()
{
	cout << solution(7, 10) << endl;
	cout << solution(4, 12) << endl;

	return 0;
}

int solution(int slice, int n)
{
    return (n + slice - 1) / slice;
}
