#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(10) << endl;
    cout << solution(4) << endl;

    return 0;
}

int solution(int n)
{
    n /= 2;

    return n * (n + 1);
}
