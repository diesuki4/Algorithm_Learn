// 이 풀이는 틀린 풀이다.
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int GCD(int a, int b);
int solution(vector<int> arr);

int main(int argc, char* argv[])
{
    cout << solution({2, 6, 8, 14}) << endl;
    cout << solution({1, 2, 3}) << endl;
    cout << solution({2, 3, 4}) << endl;

    return 0;
}

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

int solution(vector<int> arr)
{
    int gcd = arr[0];

    for (int i = 1; i < arr.size(); ++i)
        gcd = GCD(gcd, arr[i]);

    return accumulate(arr.begin(), arr.end(), 1, ::multiplies<int>()) / pow(gcd, arr.size() - 1);
}
