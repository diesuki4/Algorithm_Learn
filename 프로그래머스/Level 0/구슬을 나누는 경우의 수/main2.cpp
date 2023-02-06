#include <iostream>

using namespace std;
using ullong = unsigned long long;

ullong solution(int balls, int share);

int main(int argc, char* argv[])
{
    cout << solution(3, 2) << endl;
    cout << solution(5, 3) << endl;

    return 0;
}

ullong solution(int balls, int share)
{
    double answer = 1;

    for (int i = balls - share + 1; i <= balls; ++i)
        answer *= i;

    for (int i = 1; i <= share; ++i)
        answer /= i;

    return answer;
}
