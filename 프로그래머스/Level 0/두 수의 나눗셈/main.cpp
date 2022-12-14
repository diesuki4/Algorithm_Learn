#include <iostream>
#include <vector>

using namespace std;

int solution(int num1, int num2);

int main(int argc, char* argv[])
{
	cout << solution(3, 2) << endl;
	cout << solution(7, 3) << endl;
	cout << solution(1, 16) << endl;

	return 0;
}

int solution(int num1, int num2)
{
    return (float)num1 / num2 * 1000;
}
