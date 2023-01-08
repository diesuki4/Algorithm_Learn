#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(string my_string);

int main(int argc, char* argv[])
{
    cout << solution("aAb1B2cC34oOp") << endl;
    cout << solution("1a2b3c4d123Z") << endl;
}

int solution(string my_string)
{
    int answer = 0, num;
    istringstream iss;

    transform(my_string.begin(), my_string.end(), my_string.begin(), [](char c) { return isdigit(c) ? c : ' '; });

    iss = istringstream(my_string);

    while (iss >> num)
        answer += num;

    return answer;
}
