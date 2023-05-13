#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr);

int main(int argc, char* argv[])
{
    print(solution({1, 4, 2, 5, 3}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr)
{
    vector<int> stk;

    for (int i = 0; i < arr.size(); ++i)
        if (stk.empty() || stk.back() < arr[i])
            stk.emplace_back(arr[i]);
        else
            stk.pop_back(),
            --i;

    return stk;
}
