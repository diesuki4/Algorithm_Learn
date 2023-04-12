// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

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
        int diff = 0;
        bitset<64> bset(num);

        while (diff != 1 && diff != 2)
            diff = (bset ^ bitset<64>(++num)).count();

        return num;
    };

    transform(numbers.begin(), numbers.end(), numbers.begin(), func);

    return numbers;
}
