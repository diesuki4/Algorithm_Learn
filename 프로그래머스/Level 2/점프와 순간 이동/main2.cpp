#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    cout << solution(5000) << endl;
    
    return 0;
}

int solution(int n)
{
    int bat = 0;

    do if (n & 1)
        --n,
        ++bat;
    while (n /= 2);

    return bat;
}
