#include <iostream>
#include <sstream>

using namespace std;

int solution(string binomial);

int main(int argc, char* argv[])
{
    cout << solution("43 + 12") << endl;
    cout << solution("0 - 7777") << endl;
    cout << solution("40000 * 40000") << endl;

    return 0;
}

int solution(string binomial)
{
    istringstream iss(binomial);

    int a, b;
    char op;

    iss >> a >> op >> b;

    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    default:  return 0;
    }
}
