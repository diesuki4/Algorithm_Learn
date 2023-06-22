#include <iostream>
#include <vector>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;

    return 0;
}

int solution(int n)
{
    vector<int> v(n + 1, 1);
    const int P = 1'000'000'007;

    for (int i = 2; i <= n; ++i)
        v[i] = (v[i - 1] + v[i - 2]) % P;

    return v[n];
}
