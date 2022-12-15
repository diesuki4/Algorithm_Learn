#include <iostream>

using namespace std;

int solution(int num1, int num2);

int main(int argc, char* argv[])
{
	cout << solution(10, 5) << endl;
	cout << solution(7, 2) << endl;

	return 0;
}

int solution(int num1, int num2)
{
    return num1 / num2;
}
