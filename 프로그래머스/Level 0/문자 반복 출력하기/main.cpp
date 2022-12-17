#include <iostream>

using namespace std;

string solution(string my_string, int n);

int main(int argc, char* argv[])
{
	cout << solution("hello", 3) << endl;

	return 0;
}

string solution(string my_string, int n)
{
	string answer = "";

	for (char ch : my_string)
		answer += string(n, ch);
    
    return answer;
}
