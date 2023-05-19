#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);
int solution(vector<int> arr);

int main(int argc, char* argv[])
{
    cout << solution({2, 6, 8, 14}) << endl;
    cout << solution({1, 2, 3}) << endl;
    cout << solution({2, 3, 4}) << endl;

    return 0;
}

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

int solution(vector<int> arr)
{
    int lcm = arr[0];

    for (int i = 1; i < arr.size(); ++i)
        lcm = LCM(lcm, arr[i]);

    return lcm;
}
