#include <iostream>

using namespace std;

string solution(string myString, string pat);

int main(int argc, char* argv[])
{
    cout << solution("AbCdEFG", "dE") << endl;
    cout << solution("AAAAaaaa", "a") << endl;

    return 0;
}

string solution(string myString, string pat)
{
    return myString.substr(0, myString.rfind(pat) + pat.length());
}
