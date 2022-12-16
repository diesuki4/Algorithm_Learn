#include <iostream>

using namespace std;

int solution(int age);

int main(int argc, char* argv[])
{
	cout << solution(40) << endl;
	cout << solution(23) << endl;

	return 0;
}

int solution(int age)
{
    return 2023 - age;
}
