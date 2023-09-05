#include <iostream>
#include <vector>
#include <algorithm>

#define I(i) (((i) + n) % n)

using namespace std;

int solution(vector<int> sticker);

int main(int argc, char* argv[])
{
    cout << solution({14, 6, 5, 11, 3, 9, 2, 10}) << endl;
    cout << solution({1, 3, 2, 5, 4}) << endl;

    return 0;
}

int solution(vector<int> sticker)
{
    if (sticker.size() <= 1)
        return sticker[0];

    size_t n = sticker.size();
    vector<int> d1(n, 0), d2(d1);

    d1[1] = d1[0] = sticker[0];
    
    for (int i = 2; i < n - 1; ++i)
        d1[i] = max(d1[i - 2] + sticker[i], d1[i - 1]);

    for (int i = 1; i < n; ++i)
        d2[i] = max(d2[I(i - 2)] + sticker[i], d2[i - 1]);

    return max(d1[I(-2)], d2[I(-1)]);
}
