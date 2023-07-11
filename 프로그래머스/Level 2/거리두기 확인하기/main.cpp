#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
bool check_distancing(vector<string>& place, int i, int j);
bool check_place(vector<string>& place);
vector<int> solution(vector<vector<string>> places);

int main(int argc, char* argv[])
{
    print(solution({{"POOOP",
                     "OXXOX",
                     "OPXPX",
                     "OOXOX",
                     "POXXP"},

                    {"POOPX",
                     "OXPXP",
                     "PXXXO",
                     "OXXXO",
                     "OOOPP"},

                    {"PXOPX",
                     "OXOXP",
                     "OXPOX",
                     "OXXOP",
                     "PXPOX"},

                    {"OOOXX",
                     "XOOOX",
                     "OOOXX",
                     "OXOOX",
                     "OOOOO"},

                    {"PXPXP",
                     "XPXPX",
                     "PXPXP",
                     "XPXPX",
                     "PXPXP"}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

bool check_distancing(vector<string>& place, int i, int j)
{
    int row = place.size();
    int col = place.front().length();

    auto check_bound = [row, col](int i, int j) { return (0 <= i) && (i < row) && (0 <= j) && (j < col); };

    if (check_bound(i - 1, j))
    {
        if (place[i - 1][j] == 'P') return false;

        if (place[i - 1][j] == 'O')
        {
            if (check_bound(i - 1, j - 1) && place[i - 1][j - 1] == 'P') return false;
            if (check_bound(i - 1, j + 1) && place[i - 1][j + 1] == 'P') return false;
            if (check_bound(i - 2, j)     && place[i - 2][j] == 'P')     return false;
        }
    }

    if (check_bound(i + 1, j))
    {
        if (place[i + 1][j] == 'P') return false;

        if (place[i + 1][j] == 'O')
        {
            if (check_bound(i + 1, j - 1) && place[i + 1][j - 1] == 'P') return false;
            if (check_bound(i + 1, j + 1) && place[i + 1][j + 1] == 'P') return false;
            if (check_bound(i + 2, j)     && place[i + 2][j] == 'P')     return false;
        }
    }

    if (check_bound(i, j - 1))
    {
        if (place[i][j - 1] == 'P') return false;

        if (place[i][j - 1] == 'O')
        {
            if (check_bound(i - 1, j - 1) && place[i - 1][j - 1] == 'P') return false;
            if (check_bound(i + 1, j - 1) && place[i + 1][j - 1] == 'P') return false;
            if (check_bound(i, j - 2)     && place[i][j - 2] == 'P')     return false;
        }
    }

    if (check_bound(i, j + 1))
    {
        if (place[i][j + 1] == 'P') return false;

        if (place[i][j + 1] == 'O')
        {
            if (check_bound(i - 1, j + 1) && place[i - 1][j + 1] == 'P') return false;
            if (check_bound(i + 1, j + 1) && place[i + 1][j + 1] == 'P') return false;
            if (check_bound(i, j + 2)     && place[i][j + 2] == 'P')     return false;
        }
    }

    return true;
}

bool check_place(vector<string>& place)
{
    for (int i = 0; i < place.size(); ++i)
        for (int j = 0; j < place[i].length(); ++j)
            if (place[i][j] == 'P' && check_distancing(place, i, j) == false)
                return false;

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (vector<string>& place : places)
        answer.emplace_back(check_place(place));

    return answer;
}
