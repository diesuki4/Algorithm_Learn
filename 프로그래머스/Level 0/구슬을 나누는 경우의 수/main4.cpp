#include <iostream>
#include <vector>

using namespace std;

int solution(int balls, int share);

int main(int argc, char* argv[])
{
    cout << solution(3, 2) << endl;
    cout << solution(5, 3) << endl;

    return 0;
}

int solution(int balls, int share)
{
    // nC0을 1로 초기화하기 위함이다.
    vector<vector<int>> comb(31, vector<int>(31, 1));

    // i가 5일 때
    for (int i = 1; i <= balls; ++i)
    {
        // 5C1부터 5C4까지 계산한 후
        for (int j = 1; j < i; ++j)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

        // 5C5에는 1을 적는다.
        comb[i][i] = 1;
    }

    return comb[balls][share];
}
