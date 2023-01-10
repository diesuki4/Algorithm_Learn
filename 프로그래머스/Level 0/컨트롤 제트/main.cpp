#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int solution(string s);

int main()
{
    cout << solution("1 2 Z 3") << endl;
    cout << solution("10 20 30 40") << endl;
    cout << solution("10 Z 20 Z 1") << endl;
    cout << solution("10 Z 20 Z") << endl;
    cout << solution("-1 -2 -3 Z") << endl;
}

int solution(string s)
{
    int answer = 0, prev = 0;
    string str;
    istringstream iss(s);

    while (iss >> str)
        if (str == "Z")
            answer -= prev;
        else
            answer += (prev = stoi(str));

    return answer;
}
