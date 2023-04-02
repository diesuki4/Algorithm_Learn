#include <iostream>
#include <bitset>

using namespace std;

int solution(int n);

int main()
{
    cout << solution(78) << endl;
    cout << solution(15) << endl;

    return 0;
}

int solution(int n)
{
    int cnt = bitset<20>(n).count();

    while (bitset<20>(++n).count() != cnt);

    return n;
}
