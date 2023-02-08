#include <iostream>

using namespace std;

int solution(int a, int b);

int main(int argc, char* argv[])
{
    cout << solution(7, 20) << endl;
    cout << solution(11, 22) << endl;
    cout << solution(12, 21) << endl;

    return 0;
}

int solution(int a, int b)
{
    while ((b & 1) == 0)
        b >>= 1;

    while (b % 5 == 0)
        b /= 5;

    return (a % b) ? 2 : 1;
}
