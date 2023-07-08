#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<double> result);
vector<int> get_collatz(int n);
vector<double> solution(int k, vector<vector<int>> ranges);

int main(int argc, char* argv[])
{
    print(solution(5, {{0, 0}, {0, -1}, {2, -3}, {3, -3}}));

    return 0;
}

void print(vector<double> result)
{
    for (double d : result)
        cout << d << " ";

    cout << endl;
}

vector<int> get_collatz(int n)
{
    vector<int> v;

    while (n != 1)
    {
        v.emplace_back(n);

        if (n & 1) n += n + n + 1;
        else       n >>= 1;
    }

    v.emplace_back(1);

    return v;
}

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<int> collatz = get_collatz(k);

    for (vector<int>& range : ranges)
    {
        int s = range[0];
        int e = collatz.size() + range[1] - 1;

        if (e < s)
        {
            answer.emplace_back(-1);
            continue;
        }

        double integral = 0;

        for (int i = s; i < e; ++i)
            integral += (collatz[i] + collatz[i + 1]) * 0.5;

        answer.emplace_back(integral);
    }

    return answer;
}
