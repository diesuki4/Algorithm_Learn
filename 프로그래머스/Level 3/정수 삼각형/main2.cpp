#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle);

int main(int argc, char* argv[])
{
    cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;

    return 0;
}

int solution(vector<vector<int>> tr)
{
    for (int i = tr.size() - 2; 0 <= i; --i)
        for (int j = 0; j < tr[i].size(); ++j)
            tr[i][j] += (tr[i + 1][j] < tr[i + 1][j + 1]) ? tr[i + 1][j + 1] : tr[i + 1][j];
                
    return tr[0][0];
}
