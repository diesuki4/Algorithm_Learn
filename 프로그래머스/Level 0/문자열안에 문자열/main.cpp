#include <iostream>

using namespace std;

int solution(string str1, string str2);

int main(int argc, char* argv[])
{
	cout << solution("ab6CDE443fgh22iJKlmn1o", "6CD") << endl;
	cout << solution("ppprrrogrammers", "pppp") << endl;

	return 0;
}

int solution(string str1, string str2)
{
    return (str1.find(str2) == string::npos) ? 2 : 1;
}
