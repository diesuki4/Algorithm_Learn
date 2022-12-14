#include <iostream>
#include <vector>

using namespace std;

int solution(int num1, int num2);

int main(int argc, char* argv[])
{
	cout << solution(2, 3) << endl;
	cout << solution(11, 11) << endl;
	cout << solution(7, 99) << endl;

	return 0;
}

int solution(int num1, int num2)
{
    return (num1 == num2) ? 1 : -1;
}
