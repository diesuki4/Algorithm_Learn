#include <iostream>
#include <sstream>
#include <map>

using namespace std;

string solution(string letter);

int main(int argc, char* argv[])
{
	cout << solution(".... . .-.. .-.. ---") << endl;
	cout << solution(".--. -.-- - .... --- -.") << endl;

	return 0;
}

string solution(string letter)
{
	map<string, char> morse = {	{".-", 'a'},
								{"-...", 'b'},
								{"-.-.", 'c'},
								{"-..", 'd'},
								{".", 'e'},
								{"..-.", 'f'},
								{"--.", 'g'},
								{"....", 'h'},
								{"..", 'i'},
								{".---", 'j'},
								{"-.-", 'k'},
								{".-..", 'l'},
								{"--", 'm'},
								{"-.", 'n'},
								{"---", 'o'},
								{".--.", 'p'},
								{"--.-", 'q'},
								{".-.", 'r'},
								{"...", 's'},
								{"-", 't'},
								{"..-", 'u'},
								{"...-", 'v'},
								{".--", 'w'},
								{"-..-", 'x'},
								{"-.--", 'y'},
								{"--..", 'z'}};
    string str, answer = "";
	istringstream iss(letter);

	while (iss >> str)
		answer += morse[str];

    return answer;
}
