#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

string solution(vector<int> numbers);

int main(int argc, char* argv[])
{
    cout << solution({6, 10, 2}) << endl;
    cout << solution({3, 30, 34, 5, 9}) << endl;

    return 0;
}

string solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(), [](int a, int b)
    {
        string A = to_string(a), B = to_string(b);

        return A + B > B + A;
    });

    return accumulate(numbers.begin(), numbers.end(), string(), [](string s, int num)
    {
        return (s == "0" ? "" : s) + to_string(num);
    });
}
