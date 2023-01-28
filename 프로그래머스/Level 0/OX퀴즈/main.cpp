#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> quiz);

int main(int argc, char* argv[])
{
    print(solution({"3 - 4 = -3", "5 + 6 = 11"}));
    print(solution({"19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"}));

    return 0;
}

void print(vector<string> result)
{
    for (string s : result)
        cout << s << ' ';
    cout << endl;
}

vector<string> solution(vector<string> quiz)
{
    size_t size = quiz.size();
    vector<string> answer(size);

    for (int i = 0; i < size; ++i)
    {
        istringstream iss(quiz[i]);
        int n1, n2, nResult;
        char op, eq;

        iss >> n1 >> op >> n2 >> eq >> nResult;

        answer[i] = ((op == '+' ? n1 + n2 : n1 - n2) == nResult) ? "O" : "X";
    }

    return answer;
}
