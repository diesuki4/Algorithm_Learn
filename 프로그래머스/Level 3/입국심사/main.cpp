#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times);

int main(int argc, char* argv[])
{
    cout << solution(6, {7, 10}) << endl;

    return 0;
}

long long solution(int n, vector<int> times)
{
    long long s = times.front();
    long long e = (long long) * max_element(times.begin(), times.end()) * n;

    while (s <= e)
    {
        long long nPeople = 0;
        long long m = (s + e) / 2;

        for (int tm : times)
            nPeople += (m / tm);

        if (nPeople < n)
            s = m + 1;
        else
            e = m - 1;
    }

    return ++e;
}
