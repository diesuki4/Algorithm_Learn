#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (int z = 0, i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                swap(nums[z++], nums[i]);
    }

    void print(vector<int>& result)
    {
        for (int e : result)
            cout << e << " ";

        cout << endl;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;

    vector<int> input = {0, 1, 0, 3, 12};
    solution.moveZeroes(input);
    solution.print(input);

    input = {0, 0, 0, 4, 9, 3, 5, 0, 8};
    solution.moveZeroes(input);
    solution.print(input);

    input = {0};
    solution.moveZeroes(input);
    solution.print(input);

    return 0;
}
