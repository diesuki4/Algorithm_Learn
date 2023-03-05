#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

void step1(string& s);
void step2(string& s);
void step3(string& s);
void step4(string& s);
void step5(string& s);
void step6(string& s);
void step7(string& s);
string solution(string new_id);

int main(int argc, char* argv[])
{
    cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("=.=") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;

    return 0;
}

void step1(string& s)
{
    transform(s.begin(), s.end(), s.begin(), [](char c) { return isalpha(c) ? tolower(c) : c; });
}

void step2(string& s)
{
    auto it = remove_if(s.begin(), s.end(), [](char c) { return !(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.'); });
    s.erase(it, s.end());
}

void step3(string& s)
{
    auto it = unique(s.begin(), s.end(), [](char a, char b) { return (a == '.') && (b == '.'); });
    s.erase(it, s.end());
}

void step4(string& s)
{
    if (!s.empty() && s[0] == '.')     s.erase(s.begin());
    if (!s.empty() && s.back() == '.') s.erase(s.end() - 1);
}

void step5(string& s)
{
    if (s == "") s = "a";
}

void step6(string& s)
{
    if (16 <= s.length())
    {
        s = s.substr(0, 15);
        step4(s);
    }
}

void step7(string& s)
{
    while (s.length() < 3)
        s += s.back();
}

string solution(string new_id)
{
    step1(new_id);
    step2(new_id);
    step3(new_id);
    step4(new_id);
    step5(new_id);
    step6(new_id);
    step7(new_id);

    return new_id;
}
