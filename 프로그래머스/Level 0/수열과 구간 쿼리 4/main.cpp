#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 2, 4, 3}, {{0, 4, 1}, {0, 3, 2}, {0, 3, 3}}));

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
    for (vector<int>& query : queries)
        for (int i = (query[0] + query[2] - 1) / query[2] * query[2]; i <= query[1]; i += query[2])
            ++arr[i];

    return arr;
}
