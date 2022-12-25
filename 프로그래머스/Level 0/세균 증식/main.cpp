#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int t);

int main(int argc, char* argv[])
{
	cout << solution(2, 10) << endl;
	cout << solution(7, 15) << endl;

	return 0;
}

int solution(int n, int t)
{
    return n * pow(2, t);
}
