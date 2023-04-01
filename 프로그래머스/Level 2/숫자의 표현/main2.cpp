#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(15) << endl;

    return 0;
}

int solution(int n)
{
    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;

        for (int j = i; sum < n; ++j)
            if ((sum += j) == n)
                ++answer;
    }

    return answer;
}
