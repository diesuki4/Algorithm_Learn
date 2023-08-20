#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b);
int max_divisor(vector<int> array1, vector<int> array2);
int solution(vector<int> arrayA, vector<int> arrayB);

int main(int argc, char* argv[])
{
    cout << solution({10, 17}, {5, 20}) << endl;
    cout << solution({10, 20}, {5, 15}) << endl;
    cout << solution({10, 20}, {5, 17}) << endl;
    cout << solution({14, 35, 119}, {18, 30, 102}) << endl;

    return 0;
}

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int max_divisor(vector<int> array1, vector<int> array2)
{
    int gcd = array1[0];

    for (int e : array1)
        gcd = GCD(gcd, e);

    for (int e : array2)
        if (e % gcd == 0)
            return 0;

    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int divA = max_divisor(arrayA, arrayB);
    int divB = max_divisor(arrayB, arrayA);

    return max(divA, divB);
}
