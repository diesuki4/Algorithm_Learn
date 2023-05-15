#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 2, 4, 3}, {{0, 4, 2}, {0, 3, 2}, {0, 2, 2}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    size_t size = queries.size();
    vector<int> answer(size);

    for (int i = 0; i < size; ++i)
    {
        int t_min = 1'000'001;

        for (int j = queries[i][0]; j <= queries[i][1]; ++j)
            if (queries[i][2] < arr[j])
                t_min = min(t_min, arr[j]);

        answer[i] = (t_min != 1'000'001) ? t_min : -1;
    }

    return answer;
}
