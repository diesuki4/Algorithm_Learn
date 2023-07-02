#include <iostream>
#include <numeric>

using namespace std;

int solution(string number);

int main(int argc, char* argv[])
{
    cout << solution("123") << endl;
    cout << solution("78720646226947352489") << endl;

    return 0;
}

int solution(string number)
{
    return accumulate(number.begin(), number.end(), 0, [](int sum, int num) { return sum + num - '0'; }) % 9;
}
