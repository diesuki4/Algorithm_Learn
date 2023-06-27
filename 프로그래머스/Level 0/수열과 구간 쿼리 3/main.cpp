#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v);
vector<int> solution(vector<int> arr, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 2, 3, 4}, {{0, 3}, {1, 2}, {1, 4}}));

    return 0;
}

void print(vector<int> v)
{
    for (int e : v)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    for (vector<int>& query : queries)
        swap(arr[query[0]], arr[query[1]]);

    return arr;
}
