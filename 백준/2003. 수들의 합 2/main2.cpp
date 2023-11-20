#include <iostream>
#include <vector>

using namespace std;

int TwoPointers(vector<int>& v, int M)
{
    int answer = 0;
    size_t n = v.size();
    int l = 0, r = 0, sum = 0;

    while (l <= r)
    {
        if (M <= sum)
            sum -= v[l++];
        else if (n <= r)
            break;
        else
            sum += v[r++];

        answer += (sum == M);
    }

    return answer;
}

int main(int argc, char* argv[])
{
    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    cout << TwoPointers(v, M);

    return 0;
}
