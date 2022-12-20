#include <iostream>

using namespace std;

int solution(string message);

int main(int argc, char* argv[])
{
	cout << solution("happy birthday!") << endl;
	cout << solution("I love you~") << endl;

	return 0;
}

int solution(string message)
{
    return message.length() * 2;
}
