#include <iostream>

using namespace std;

int solution(int n);

int main()
{
	cout << solution(7) << endl;
	cout << solution(1) << endl;
	cout << solution(15) << endl;

	return 0;
}

int solution(int n)
{
    return (n + 6) / 7;
}
