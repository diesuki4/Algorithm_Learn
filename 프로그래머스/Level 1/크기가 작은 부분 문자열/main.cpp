#include <iostream>
#include <string>

using namespace std;

int solution(string t, string p);

int main(int argc, char* argv[])
{
    cout << solution("3141592", "271") << endl;
    cout << solution("500220839878", "7") << endl;
    cout << solution("10203", "15") << endl;

    return 0;
}

int solution(string t, string p)
{
    int answer = 0;
    double numP = stod(p);
    size_t lenT = t.length(), lenP = p.length();
    size_t last = lenT - lenP;
    
    for (int i = 0; i <= last; ++i)
        answer += (stod(t.substr(i, lenP)) <= numP);

    return answer;
}
