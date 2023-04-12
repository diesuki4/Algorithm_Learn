#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<long long> result);
vector<long long> solution(vector<long long> numbers);

int main(int argc, char* argv[])
{
    print(solution({2, 7}));

    return 0;
}

void print(vector<long long> result)
{
    for (long long e : result)
        cout << e << " ";

    cout << endl;
}

vector<long long> solution(vector<long long> numbers)
{
    auto func = [](long long num)
    {
        long long LS0 = 1;

        while (num & LS0)
            LS0 <<= 1;

        return num + LS0 - (LS0 >> 1);
    };

    transform(numbers.begin(), numbers.end(), numbers.begin(), func);

    return numbers;
}
