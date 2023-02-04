#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
void print(vector<int> result);
vector<int> solution(int numer1, int denom1, int numer2, int denom2);

int main(int argc, char* argv[])
{
    print(solution(1, 2, 3, 4));
    print(solution(9, 2, 1, 3));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";
    cout << endl;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2)
{
    int denom = lcm(denom1, denom2);
    int numer = (numer1 * denom / denom1) + (numer2 * denom / denom2);

    int GCD = gcd(denom, numer);

    return vector<int>({numer / GCD, denom / GCD});
}
