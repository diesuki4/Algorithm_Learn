#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(3) << endl;
    cout << solution(5) << endl;

    return 0;
}

int solution(int n)
{
    int pp = 0, p = 1, c = 1;

    while (0 < --n)
    {
        c = (pp + p) % 1234567;
        pp = p;
        p = c;
    }

    return c;
}
