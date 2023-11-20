#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int TwoPointers(vector<int>& v, int M)
{
    int answer = 0;
    size_t n = v.size();
    int l = 0, r = 0, sum = v[0];

    while (l < n || r < n)
    {
        if (sum <= M)
        {
            answer += (sum == M);
            
            if (++r < n)
                sum += v[r];
            else
                sum -= v[l++];
        }
        else
        {
            sum -= v[l++];
        }
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
