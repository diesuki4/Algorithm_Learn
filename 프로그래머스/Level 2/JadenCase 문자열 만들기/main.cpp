#include <iostream>

using namespace std;

string solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("3people unFollowed me") << endl;
    cout << solution("for the last week") << endl;

    return 0;
}

string solution(string s)
{
    char prev = ' ';
    
    for (char& cur : s)
        prev = cur = (prev == ' ' && isalpha(cur) ? ::toupper : ::tolower)(cur);

    return s;
}
