#include <iostream>
#include <regex>

using namespace std;

long long solution(string numbers);

int main(int argc, char* argv[])
{
	cout << solution("onetwothreefourfivesixseveneightnine") << endl;
	cout << solution("onefourzerosixseven") << endl;

	return 0;
}

long long solution(string numbers)
{
	string strZeroToNine[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string nZeroToNine[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	for (int i = 0; i < 10; ++i)
		numbers = regex_replace(numbers, regex(strZeroToNine[i]), nZeroToNine[i]);

    return stoll(numbers);
}
