#include <iostream>

using namespace std;

int combination(int n, int r);
int solution(int balls, int share);

int main(int argc, char* argv[])
{
    cout << solution(3, 2) << endl;
    cout << solution(5, 3) << endl;

    return 0;
}

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(int balls, int share)
{
    return combination(balls, share);
}
