// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void rSolution(int cur_col, int depth, int sum, vector<vector<int>>& land, set<int>& st);
int solution(vector<vector<int>> land);

int main(int argc, char* argv[])
{
    cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << endl;

    return 0;
}

void rSolution(int cur_col, int depth, int sum, vector<vector<int>>& land, set<int>& st)
{
    const static int row = land.size(), col = land.front().size();

    if (row <= depth)
    {
        st.emplace(sum);
        return;
    }

    for (int c = 0; c < col; ++c)
        if (c != cur_col)
            rSolution(c, depth + 1, sum + land[depth][c], land, st);
}

int solution(vector<vector<int>> land)
{
    set<int> st;

    rSolution(-1, 0, 0, land, st);

    return *st.rbegin();
}
