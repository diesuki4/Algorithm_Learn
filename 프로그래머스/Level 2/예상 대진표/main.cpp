#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b);

int main(int argc, char* argv[])
{
    cout << solution(8, 4, 7) << endl;

    return 0;
}

int solution(int n, int a, int b)
{
    int answer = 1;

    if (a > b)
        swap(a, b);
    
    while (~a & 1 || a + 1 != b)
    {
        ++a /= 2;
        ++b /= 2;

        ++answer;
    }

    return answer;
}
