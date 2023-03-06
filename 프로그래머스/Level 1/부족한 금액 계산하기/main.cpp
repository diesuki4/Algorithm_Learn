#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int price, int money, int count);

int main(int argc, char* argv[])
{
    cout << solution(3, 20, 4) << endl;

    return 0;
}

long long solution(int price, int money, int count)
{
    return max(0, price * count * (count + 1) / 2 - money);
}
