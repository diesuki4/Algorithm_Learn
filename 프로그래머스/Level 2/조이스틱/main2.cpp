#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int horizontal(int pos, bool bLeft, string& current, string& name);
int vertical(char c);
int rDFS(int cost, int pos, string current, string& name);
int solution(string name);

int main(int argc, char* argv[])
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
    cout << solution("ABABAAAAABA") << endl;

    return 0;
}

int horizontal(int pos, bool bLeft, string& current, string& name)
{
    int dist = 0;
    int d = (bLeft) ? -1 : +1;
    size_t len = name.length();

    while (current[(pos + dist + len) % len] == name[(pos + dist + len) % len])
        if (len <= abs(dist += d))
            return len;

    return dist;
}

int vertical(char c)
{
    return (c <= 'N') ? ('A' - c) : ('Z' + 1 - c);
}

int rDFS(int cost, int pos, string current, string& name)
{
    size_t len = name.length();
    int lDist = horizontal(pos, true, current, name);

    if (len <= abs(lDist))
        return cost;

    int rDist = horizontal(pos, false, current, name);

    string lCurrent(current);
    string rCurrent(current);

    int lPos = (pos + lDist + len) % len;
    int rPos = (pos + rDist) % len;

    int lCost = cost + abs(lDist);
    int rCost = cost + abs(rDist);

    lCurrent[lPos] = name[lPos];
    rCurrent[rPos] = name[rPos];

    lCost += abs(vertical(name[lPos]));
    rCost += abs(vertical(name[rPos]));

    return min(rDFS(lCost, lPos, lCurrent, name), rDFS(rCost, rPos, rCurrent, name));
}

int solution(string name)
{
    return rDFS(0, 0, string(name.length(), 'A'), name);
}
