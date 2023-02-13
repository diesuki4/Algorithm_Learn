#include <iostream>

using namespace std;

int solution(int a, int b, int n);

int main(int argc, char* argv[])
{
    cout << solution(2, 1, 20) << endl;
    cout << solution(3, 1, 20) << endl;

    return 0;
}

int solution(int a, int b, int n)
{
    return (n > b ? n - b : 0) / (a - b) * b;
}
