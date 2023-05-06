#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<int> query);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 2, 3, 4, 5}, {4, 1, 2}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<int> query)
{
    size_t size = query.size();

    for (int i = 0; i < size; ++i)
        if (i & 1)
            arr.erase(arr.begin(), arr.begin() + query[i]);
        else
            arr.erase(arr.begin() + ++query[i], arr.end());

    return arr;
}
