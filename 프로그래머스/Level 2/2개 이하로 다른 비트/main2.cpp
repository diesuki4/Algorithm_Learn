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
    auto func = [](unsigned long long num)
    {
        if (~num & 1)
            return ++num;

        string s = bitset<64>(num).to_string();
        vector<char> v(s.begin(), s.end());

        next_permutation(v.begin(), v.end());

        return bitset<64>(string(v.begin(), v.end())).to_ullong();
    };

    transform(numbers.begin(), numbers.end(), numbers.begin(), func);

    return numbers;
}
