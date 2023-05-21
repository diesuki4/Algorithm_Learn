#include <iostream>

using namespace std;

string solution(string my_string, int m, int c);

int main(int argc, char* argv[])
{
    cout << solution("ihrhbakrfpndopljhygc", 4, 2) << endl;
    cout << solution("programmers", 1, 1) << endl;

    return 0;
}

string solution(string my_string, int m, int c)
{
    string answer = "";

    for (int i = c - 1; i < my_string.length(); i += m)
        answer += my_string[i];

    return answer;
}
