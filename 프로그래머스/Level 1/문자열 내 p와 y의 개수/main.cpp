#include <iostream>
#include <cctype>
#include <algorithm>

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
    return count_if(s.begin(), s.end(), [](const char c) { return tolower(c) == 'p'; })
            == count_if(s.begin(), s.end(), [](const char c) { return tolower(c) == 'y'; });
}
