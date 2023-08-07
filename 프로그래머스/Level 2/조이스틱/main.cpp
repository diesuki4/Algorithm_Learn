// 이 풀이는 틀린 풀이다.
#include <iostream>
#include <cmath>

using namespace std;

int horizontal(int pos, string& current, string& name);
int vertical(char c);
int solution(string name);

int main(int argc, char* argv[])
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
    cout << solution("ABABAAAAABA") << endl;

    return 0;
}

int horizontal(int pos, string& current, string& name)
{
    int l = 0, r = 0;
    size_t len = name.length();

    while (current[(pos + l + len) % len] == name[(pos + l + len) % len])
        if (len <= -(--l))
            return len;

    while (current[(pos + r) % len] == name[(pos + r) % len])
        ++r;

    return (-l <= r) ? l : r;
}

int vertical(char c)
{
    return (c <= 'N') ? ('A' - c) : ('Z' + 1 - c);
}

int solution(string name)
{
    int answer = 0;
    int pos = 0, dist;
    int len = name.length();
    string current(len, 'A');

    while ((dist = horizontal(pos, current, name)) < len)
    {
        answer += abs(dist);
        pos = (pos + dist + len) % len;

        answer += abs(vertical(name[pos]));
        current[pos] = name[pos];
    }

    return answer;
}
