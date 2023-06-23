#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int idx);

int main(int argc, char* argv[])
{
    cout << solution({0, 0, 0, 1}, 1) << endl;
    cout << solution({1, 0, 0, 1, 0, 0}, 4) << endl;
    cout << solution({1, 1, 1, 1, 0}, 3) << endl;

    return 0;
}

int solution(vector<int> arr, int idx)
{
    auto result = find(next(arr.begin(), idx), arr.end(), 1);

    return (result == arr.end()) ? -1 : result - arr.begin();
}
