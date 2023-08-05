#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> weights);

int main(int argc, char* argv[])
{
    cout << solution({100, 180, 360, 100, 270}) << endl;

    return 0;
}

long long solution(vector<int> weights)
{
    long long answer = 0;
    vector<int> W(1001), N(4001);

    for (int w : weights)
    {
        int w2 = w * 2, w3 = w * 3, w4 = w * 4;

        answer += N[w2] + N[w3] + N[w4] - W[w] * 2;

        ++N[w2], ++N[w3], ++N[w4], ++W[w];
    }

    return answer;
}
