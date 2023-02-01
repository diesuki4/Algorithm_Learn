#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(10) << endl;
    cout << solution(15) << endl;

    return 0;
}

int solution(int n)
{
    int last = n / 2;
    vector<bool> v(n + 1, true);

    for (int i = 2; i <= last; ++i)
        if (v[i])
            for (int j = 2 * i; j <= n; j += i)
                v[j] = false;

    return count(v.begin() + 1, v.begin() + n + 1, false);
}
