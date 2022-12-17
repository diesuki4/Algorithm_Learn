#include <iostream>

using namespace std;

string solution(int age);

int main(int argc, char* argv[])
{
	cout << solution(23) << endl;
	cout << solution(51) << endl;
	cout << solution(100) << endl;

	return 0;
}

string solution(int age)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string answer = "";

	do answer = alphabet[age % 10] + answer;
	while (age /= 10);

    return answer;
}
