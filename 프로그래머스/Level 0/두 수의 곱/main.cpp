#include <iostream>

using namespace std;

int solution(int num1, int num2);

int main(int argc, char* argv[])
{
	cout << solution(3, 4) << endl;
	cout << solution(27, 19) << endl;

	return 0;
}

int solution(int num1, int num2)
{
    return num1 * num2;
}
