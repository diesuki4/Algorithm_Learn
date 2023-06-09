#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int*> GetBorder(vector<vector<int>>& nxn, vector<int>& query);
vector<int> solution(int rows, int columns, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    print(solution(6, 6, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}));
    print(solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}));
    print(solution(100, 97, {{1, 1, 100, 97}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int*> GetBorder(vector<vector<int>>& nxn, vector<int>& query)
{
    int x1 = query[0], y1 = query[1];
    int x2 = query[2], y2 = query[3];
    int r = x1, c = y1;

    int n = 0;
    vector<int*> v((x2 - x1 + y2 - y1) * 2);

    while (c < y2)
        v[n++] = &nxn[r][c++];

    while (r < x2)
        v[n++] = &nxn[r++][c];

    while (y1 < c)
        v[n++] = &nxn[r][c--];

    while (x1 < r)
        v[n++] = &nxn[r--][c];

    return v;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    size_t n = queries.size();
    vector<int> answer(n);
    vector<vector<int>> nxn(rows + 1, vector<int>(columns + 1));
    int num = 1;

    for (int r = 1; r <= rows; ++r)
        for (int c = 1; c <= columns; ++c)
            nxn[r][c] = num++;

    for (int i = 0; i < n; ++i)
    {
        vector<int*> v = GetBorder(nxn, queries[i]);
        vector<int> t(v.size());
        int Min = 10001;

        transform(v.begin(), v.end(), t.begin(), [](int* p) { return *p; });
        rotate(t.begin(), t.end() - 1, t.end());

        transform(v.begin(), v.end(), t.begin(), v.begin(), [&Min](int* pv, int nt)
        {
            Min = min(*pv = nt, Min);

            return pv;
        });

        answer[i] = Min;
    }

    return answer;
}
