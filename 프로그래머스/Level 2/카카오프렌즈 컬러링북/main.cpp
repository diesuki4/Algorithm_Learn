#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
int rDFS(unsigned i, unsigned j, int color, vector<vector<int>>& picture);
vector<int> solution(int m, int n, vector<vector<int>> picture);

int main(int argc, char* argv[])
{
    print(solution(6, 4, {{1, 1, 1, 0},
                          {1, 2, 2, 0},
                          {1, 0, 0, 1},
                          {0, 0, 0, 1},
                          {0, 0, 0, 3},
                          {0, 0, 0, 3}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

int rDFS(unsigned i, unsigned j, int color, vector<vector<int>>& picture)
{
    if (picture.size() <= i || picture.front().size() <= j || picture[i][j] != color)
        return 0;

    picture[i][j] = 0;

    return rDFS(i - 1, j, color, picture) +
           rDFS(i + 1, j, color, picture) +
           rDFS(i, j - 1, color, picture) +
           rDFS(i, j + 1, color, picture) + 1;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (unsigned i = 0; i < m; ++i)
        for (unsigned j = 0; j < n; ++j)
            if (picture[i][j])
                max_size_of_one_area = max(max_size_of_one_area, rDFS(i, j, picture[i][j], picture)),
                ++number_of_area;

    return {number_of_area, max_size_of_one_area};
}
