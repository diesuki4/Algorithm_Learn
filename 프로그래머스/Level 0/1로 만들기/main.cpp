#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list);

int main(int argc, char* argv[])
{
    cout << solution({12, 4, 15, 1, 14}) << endl;

    return 0;
}

int solution(vector<int> num_list)
{
    auto func = [](int sum, int num)
    {
        int n = 0;

        while (num >>= 1)
            ++n;

        return sum + n;
    };

    return accumulate(num_list.begin(), num_list.end(), 0, func);
}
