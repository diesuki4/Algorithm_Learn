#include <iostream>

using namespace std;

int solution(string ineq, string eq, int n, int m);

int main(int argc, char* argv[])
{
    cout << solution("<", "=", 20, 50) << endl;
    cout << solution(">", "!", 41, 78) << endl;

    return 0;
}

int solution(string ineq, string eq, int n, int m)
{
    if (ineq == "<" && eq == "=")
        return n <= m;
    else if (ineq == "<" && eq == "!")
        return n < m;
    else if (ineq == ">" && eq == "=")
        return n >= m;
    else if (ineq == ">" && eq == "!")
        return n > m;
}
