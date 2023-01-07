#include <iostream>

using namespace std;

int solution(int n);

int main()
{
    cout << solution(6) << endl;
    cout << solution(10) << endl;
    cout << solution(4) << endl;
}

int solution(int n)
{
    int LCM;

    for (LCM = 6; LCM % n; LCM += 6);

    return LCM / 6;
}
