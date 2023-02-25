#include <iostream>
#include <cmath>

using namespace std;

int getNumberOfDivisor(int num);
int solution(int number, int limit, int power);

int main(int argc, char* argv[])
{
    cout << solution(5, 3, 2) << endl;
    cout << solution(10, 3, 2) << endl;

    return 0;
}

int getNumberOfDivisor(int num)
{
    int last = sqrt(num);
    int count = (pow(last, 2) == num) ? -1 : 0;

    for (int i = 1; i <= last; ++i)
        if (num % i == 0)
            count += 2;

    return count;
}

int solution(int number, int limit, int power)
{
    int answer = 0;

    do
    {
        int count = getNumberOfDivisor(number);

        answer += (limit < count) ? power : count;
    }
    while (--number);

    return answer;
}
