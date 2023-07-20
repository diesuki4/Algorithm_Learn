#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

long long calculate(long long A, long long B, char op);
long long solution(string expression);

int main(int argc, char* argv[])
{
    cout << solution("100-200*300-500+20") << endl;
    cout << solution("50*6-3*2") << endl;

    return 0;
}

long long calculate(long long A, long long B, char op)
{
    switch (op)
    {
    case '+': return A + B;
    case '-': return A - B;
    case '*': return A * B;
    default:  return 0;
    }
}

long long solution(string expression)
{
    long long answer = 0;

    vector<long long> nums;
    vector<char> ops;
    bool isNumberTurn = true;

    for (char c : expression)
    {
        if (isNumberTurn)
            nums.emplace_back(0),
            isNumberTurn = false;

        if (isdigit(c))
            nums.back() *= 10,
            nums.back() += c - '0';
        else
            ops.emplace_back(c),
            isNumberTurn = true;
    }

    vector<string> cases {"-+*", "-*+", "+-*", "+*-", "*+-", "*-+"};

    for (string& cs : cases)
    {
        vector<long long> t_nums = nums;
        vector<char> t_ops = ops;

        for (char op : cs)
        {
            for (int i = 0; i < t_ops.size(); ++i)
            {
                if (t_ops[i] == op)
                {
                    t_nums[i] = calculate(t_nums[i], t_nums[i + 1], op);

                    t_nums.erase(t_nums.begin() + i + 1);
                    t_ops.erase(t_ops.begin() + i--);
                }
            }
        }

        answer = max(answer, abs(t_nums[0]));
    }

    return answer;
}
