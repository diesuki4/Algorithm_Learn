#include <iostream>
#include <algorithm>

using namespace std;

string solution(string a, string b);

int main(int argc, char* argv[])
{
    cout << solution("582", "734") << endl;
    cout << solution("18446744073709551615", "287346502836570928366") << endl;
    cout << solution("0", "0") << endl;

    return 0;
}

string solution(string a, string b)
{
    string answer = "";
    size_t lenA = a.length(), lenB = b.length();
    int last = max(lenA, lenB), carry = 0;

    for (int i = 1; i <= last; ++i)
    {
        int A = (i <= lenA) ? (a[lenA - i] - '0') : 0;
        int B = (i <= lenB) ? (b[lenB - i] - '0') : 0;
        int sum = A + B + carry;

        answer += ('0' + sum % 10);
        carry = sum / 10;
    }

    answer += (carry ? "1" : "");

    reverse(answer.begin(), answer.end());

    return answer;
}
