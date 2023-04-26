#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 1, 4, 5, 2, 9}));
    print(solution({1, 2, 1}));
    print(solution({1, 1, 1}));

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
    vector<int> two {2};

    auto l = find(arr.begin(), arr.end(), 2);

    if (l == arr.end())
        return vector<int> {-1};

    auto r = find_end(arr.begin(), arr.end(), two.begin(), two.end());

    return vector<int>(l, ++r);
}
