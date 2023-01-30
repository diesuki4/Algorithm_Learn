#include <iostream>
#include <cmath>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(20) << endl;
    cout << solution(100) << endl;

    return 0;
}

int solution(int n)
{
    float square_root = sqrt(n);
    int answer = (pow(square_root, 2) == n);

    for (int i = 1; i < square_root; ++i)
        answer += !(n % i) * 2;

    return answer;
}
