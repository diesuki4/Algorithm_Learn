#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons);

int main(int argc, char* argv[])
{
    cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl;

    return 0;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    size_t size = dungeons.size();
    vector<int> pmt(size);

    for (int i = 0; i < size; ++i)
        pmt[i] = i;

    do
    {
        int cnt;
        int stamina = k;

        for (cnt = 0; cnt < size && 0 < stamina; ++cnt)
            if (dungeons[pmt[cnt]][0] <= stamina)
                stamina -= dungeons[pmt[cnt]][1];
            else
                break;

        answer = max(answer, cnt);
    }
    while (next_permutation(pmt.begin(), pmt.end()));

    return answer;
}
