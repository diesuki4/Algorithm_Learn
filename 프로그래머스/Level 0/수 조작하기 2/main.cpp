#include <iostream>
#include <vector>

using namespace std;

string solution(vector<int> numLog);

int main(int argc, char* argv[])
{
    cout << solution({0, 1, 0, 10, 0, 1, 0, 10, 0, -1, -2, -1}) << endl;

    return 0;
}

string solution(vector<int> numLog)
{
    size_t n = numLog.size() - 1;
    string answer(n, '\0');
    const char* wasd = "d        w s        a";

    for (int i = 0; i < n; ++i)
        answer[i] = wasd[numLog[i] - numLog[i + 1] + 10];

    return answer;
}
