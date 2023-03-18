#include <iostream>
#include <sstream>
#include <climits>
#include <algorithm>

using namespace std;

string solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("1 2 3 4") << endl;
    cout << solution("-1 -2 -3 -4") << endl;
    cout << solution("-1 -1") << endl;

    return 0;
}

string solution(string s)
{
    int num;
    int Min = INT_MAX, Max = INT_MIN;
    istringstream iss(s);
    ostringstream oss;

    while (iss >> num)
    {
        Min = min(Min, num);
        Max = max(Max, num);
    }

    oss << Min << " " << Max;

    return oss.str();
}
