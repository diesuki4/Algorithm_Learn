#include <iostream>

using namespace std;

int solution(int n, int k);

int main(int argc, char* argv[])
{
	cout << solution(10, 3) << endl;
	cout << solution(64, 6) << endl;

	return 0;
}

int solution(int n, int k)
{
    return n * 12000 + (k - n / 10) * 2000;
}
