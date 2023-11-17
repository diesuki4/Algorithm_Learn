#include <iostream>
#include <vector>
#include <map>

using namespace std;

pair<int, int> SlidingWindow(vector<int>& v, int w)
{
    int window = 0;
    map<int, int> mp;

    for (int i = 0; i < w; ++i)
        window += v[i];

    ++mp[window];

    for (int i = w; i < v.size(); ++i)
    {
        window += v[i] - v[i - w];
        ++mp[window];
    }

    return *mp.rbegin();
}

int main(int argc, char* argv[])
{
    int N, X;
    cin >> N >> X;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    auto pr = SlidingWindow(v, X);

    if (pr.first == 0)
        cout << "SAD";
    else
        cout << pr.first << "\n" << pr.second;

    return 0;
}
