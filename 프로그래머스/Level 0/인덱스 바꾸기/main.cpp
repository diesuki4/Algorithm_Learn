#include <iostream>

using namespace std;

string solution(string my_string, int num1, int num2);

int main(int argc, char* argv[])
{
	cout << solution("hello", 1, 2) << endl;
	cout << solution("I love you", 3, 6) << endl;

	return 0;
}

string solution(string my_string, int num1, int num2)
{
	swap(my_string.at(num1), my_string.at(num2));

    return my_string;
}
