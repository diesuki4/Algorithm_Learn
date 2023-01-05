#include <iostream>
#include <cmath>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
	cout << solution(144) << endl;
	cout << solution(976) << endl;

	return 0;
}

int solution(int n)
{
    float f = sqrt(n);

    return (pow(f, 2) == n) ? 1 : 2;
}
