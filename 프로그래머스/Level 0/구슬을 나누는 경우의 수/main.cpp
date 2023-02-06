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
    ullong denominator = 1;
    ullong numerator = 1;

    for (ullong i = 1; i <= share; ++i)
    {
        denominator *= (balls - share + i);
        numerator *= i;

        if (denominator % numerator == 0)
        {
            denominator /= numerator;
            numerator = 1;
        }
    }

    return denominator;
}
