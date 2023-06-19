#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<vector<int>> intervals);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 4, 5}, {{1, 3}, {0, 4}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<vector<int>> intervals)
{
    vector<int> answer;

    for (vector<int>& interval : intervals)
        answer.insert(answer.end(), &arr[interval[0]], &arr[++interval[1]]);

    return answer;
}
