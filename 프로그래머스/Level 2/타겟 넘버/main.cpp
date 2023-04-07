#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target);

int main(int argc, char* argv[])
{
    cout << solution({1, 1, 1, 1, 1}, 3) << endl;
    cout << solution({4, 1, 2, 1}, 4) << endl;

    return 0;
}

int solution(vector<int> numbers, int target)
{
    size_t size = numbers.size();
    vector<int> sign(size, -1);
    int answer = 0, i = size - 1;

    while (true)
    {
        vector<int> t_sign = sign;

        do
        {
            int sum = 0;

            for (int j = 0; j < size; ++j)
                sum += numbers[j] * t_sign[j];

            if (sum == target)
                ++answer;
        }
        while (next_permutation(t_sign.begin(), t_sign.end()));

        if (0 <= i)
            sign[i--] = 1;
        else
            break;
    }

    return answer;
}
