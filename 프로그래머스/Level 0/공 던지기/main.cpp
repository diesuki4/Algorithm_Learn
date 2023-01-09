#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k);

int main(int argc, char* argv[])
{
    cout << solution({1, 2, 3, 4}, 2) << endl;
    cout << solution({1, 2, 3, 4, 5, 6}, 5) << endl;
    cout << solution({1, 2, 3}, 3) << endl;
}

int solution(vector<int> numbers, int k)
{
    return numbers[--k * 2 % numbers.size()];
}
