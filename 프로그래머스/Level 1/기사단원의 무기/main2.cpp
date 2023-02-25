#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> countDivisors(int num);
int solution(int number, int limit, int power);

int main(int argc, char* argv[])
{
    cout << solution(5, 3, 2) << endl;
    cout << solution(10, 3, 2) << endl;

    return 0;
}

vector<int> countDivisors(int num)
{
    vector<int> divisorCounts(num + 1, 0);

    for (int i = 1; i <= num; ++i)
        for (int j = i; j <= num; j += i)
            ++divisorCounts[j];

    return divisorCounts;
}

int solution(int number, int limit, int power)
{
    int answer = 0;
    vector<int> divisorCounts = countDivisors(number);

    do
        answer += (limit < divisorCounts[number]) ? power : divisorCounts[number];
    while (--number);

    return answer;
}
