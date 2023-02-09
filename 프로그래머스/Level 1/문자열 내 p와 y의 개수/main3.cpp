#include <iostream>
#include <cctype>

using namespace std;

bool solution(string s);

int main(int argc, char* argv[])
{
    cout << boolalpha << solution("pPoooyY") << endl;
    cout << boolalpha << solution("Pyy") << endl;

    return 0;
}

bool solution(string s)
{
    int isDifferent = 0;

    for (const char c : s)
    {
        char lowerC = tolower(c);

        isDifferent += (lowerC == 'p');
        isDifferent -= (lowerC == 'y');
    }

    return !isDifferent;
}
