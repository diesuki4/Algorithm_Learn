#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;

    return 0;
}

int solution(int n)
{
    int DIV = 1'000'000'007;
    long pa = 1, a = 0, b = 0, c = 2;

    for (int i = 1; i < n; ++i)
    {
        long A = a, B = b;

        a = (c + pa) % DIV;
        b = c;
        c = (B + 2 * A) % DIV;
        pa = A;
    }

    return a;
}
