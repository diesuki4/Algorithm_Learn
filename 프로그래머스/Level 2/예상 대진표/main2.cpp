#include <iostream>

using namespace std;

int solution(int n, int a, int b);

int main(int argc, char* argv[])
{
    cout << solution(8, 4, 7) << endl;

    return 0;
}

int solution(int n, int a, int b)
{
    int answer = 0;

    --a, --b;

    while (a != b)
    {
        a >>= 1, b >>= 1;

        ++answer;
    }

    return answer;
}
