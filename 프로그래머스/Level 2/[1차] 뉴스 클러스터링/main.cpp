#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string str1, string str2);

int main(int argc, char* argv[])
{
    cout << solution("FRANCE", "french") << endl;
    cout << solution("handshake", "shake hands") << endl;
    cout << solution("aa1+aa2", "AAAA12") << endl;
    cout << solution("E=M*C^2", "e=m*c^2") << endl;

    return 0;
}

int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> setA, setB;
    vector<string> setUnion, setInter;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (int i = 0; i < str1.length() - 1; ++i)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            setA.emplace_back(str1.substr(i, 2));

    for (int i = 0; i < str2.length() - 1; ++i)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            setB.emplace_back(str2.substr(i, 2));

    sort(setA.begin(), setA.end());
    sort(setB.begin(), setB.end());

    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(setUnion));
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(setInter));

    return setUnion.size() ? (1.f * setInter.size() / setUnion.size() * 65536) : 65536;
}
