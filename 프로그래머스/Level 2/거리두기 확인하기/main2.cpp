#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
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

bool check_place(vector<string>& place)
{
    int row = place.size();
    int col = place.front().length();
    vector<vector<int>> isInUse(row, vector<int>(col, false));

    int dx[] = {1, -1,  0,  0};
    int dy[] = {0,  0,  1, -1};

    for (int x = 0; x < row; ++x)
    {
        for (int y = 0; y < col; ++y)
        {
            if (place[x][y] == 'P')
            {
                for (int z = 0; z < 4; ++z)
                {
                    unsigned moved_x = x + dx[z];
                    unsigned moved_y = y + dy[z];

                    if (row <= moved_x || col <= moved_y)
                        continue;

                    switch (place[moved_x][moved_y])
                    {
                    case 'P':
                        return false;
                    case 'O':
                        if (isInUse[moved_x][moved_y])
                            return false;
                        else
                            isInUse[moved_x][moved_y] = true;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (vector<string>& place : places)
        answer.emplace_back(check_place(place));

    return answer;
}
