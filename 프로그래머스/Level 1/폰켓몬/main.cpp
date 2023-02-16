#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums);

int main(int argc, char* argv[])
{
    cout << solution({3, 1, 2, 3}) << endl;
    cout << solution({3, 3, 3, 2, 2, 4}) << endl;
    cout << solution({3, 3, 3, 2, 2, 2}) << endl;

    return 0;
}

int solution(vector<int> nums)
{
    return min(unordered_set <int>(nums.begin(), nums.end()).size(), nums.size() / 2);
}
