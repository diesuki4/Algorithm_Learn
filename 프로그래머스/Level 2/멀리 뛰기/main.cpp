// 이 풀이는 시간 초과가 발생한다.
#include <iostream>

using namespace std;

long long rSolution(int n);
long long solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;
    cout << solution(3) << endl;
    
    return 0;
}

long long rSolution(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;

    return rSolution(n - 1) + rSolution(n - 2);
}

long long solution(int n)
{
    return rSolution(n) % 1234567;
}
