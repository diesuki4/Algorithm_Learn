#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number);

int main(int argc, char* argv[])
{
    cout << solution({-2, 3, 0, 2, -5}) << endl;
    cout << solution({-3, -2, -1, 0, 1, 2, 3}) << endl;
    cout << solution({-1, 1, -1, 1}) << endl;

    return 0;
}

int solution(vector<int> number)
{
    int answer = 0;

    vector<int> comb(number.size() - 3, 0);
    comb.insert(comb.end(), {1, 1, 1});

    do
    {
        int sum = 0;
        auto it = comb.begin();

        while ((it = find(it, comb.end(), 1)) != comb.end())
            sum += number[it++ - comb.begin()];

        answer += !sum;
    }
    while (next_permutation(comb.begin(), comb.end()));

    return answer;
}
