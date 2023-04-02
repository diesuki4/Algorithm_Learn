#include <iostream>
#include <deque>
#include <algorithm>

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
    int answer = 0;
    deque<int> binary;

    do binary.emplace_front(n & 1);
    while (n >>= 1);

    binary.emplace_front(0);
    next_permutation(binary.begin(), binary.end());

    for (int bit : binary)
        (answer <<= 1) += bit;

    return answer;
}
