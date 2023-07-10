#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int solution(vector<int> n);

int main(int argc, char* argv[])
{
    cout << solution({3, 4, 5, 2, 1}) << endl;
    cout << solution({5, 7, 8, 3}) << endl;

    return 0;
}

int solution(vector<int> n)
{
    int product = accumulate(n.begin(), n.end(), 1, ::multiplies<int>());
    int sum_pow = pow(accumulate(n.begin(), n.end(), 0), 2);

    return product < sum_pow;
}
