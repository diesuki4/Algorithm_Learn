#include <iostream>

using namespace std;

long long solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;
    cout << solution(3) << endl;
    
    return 0;
}

long long solution(int n)
{
    long long arr[2001] = {1, 1, };

    for (int i = 2; i <= n; ++i)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;

    return arr[n];
}
