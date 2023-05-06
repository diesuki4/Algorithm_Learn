#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d);

int main(int argc, char* argv[])
{
    cout << solution(2, 2, 2, 2) << endl;
    cout << solution(4, 1, 4, 4) << endl;
    cout << solution(6, 3, 3, 6) << endl;
    cout << solution(2, 5, 2, 6) << endl;
    cout << solution(6, 4, 2, 5) << endl;

    return 0;
}

int solution(int a, int b, int c, int d)
{
    int answer = 1;
    map<int, int> mp;

    ++mp[a], ++mp[b], ++mp[c], ++mp[d];

    switch (mp.size())
    {
    case 1:
        answer = 1111 * a;
        break;
    case 2:
        if (mp.begin()->second == 2) answer = (mp.begin()->first + mp.rbegin()->first) * abs(mp.begin()->first - mp.rbegin()->first);
        else if (mp.begin()->second == 3) answer = pow(10 * mp.begin()->first + mp.rbegin()->first, 2);
        else answer = pow(10 * mp.rbegin()->first + mp.begin()->first, 2);
        break;
    case 3:
        for (auto pr : mp) answer *= (pr.second == 1) ? pr.first : 1;
        break;
    case 4:
        answer = mp.begin()->first;
        break;
    default:
        break;
    }

    return answer;
}
