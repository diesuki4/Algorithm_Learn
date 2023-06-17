#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;

    return 0;
}

string solution(int n)
{
    string answer;

    while (n)
    {
        int mod = n % 3;
        (n /= 3) -= (mod == 0);

        answer += "412"[mod];
    }

    reverse(answer.begin(), answer.end());

    return answer;
}
