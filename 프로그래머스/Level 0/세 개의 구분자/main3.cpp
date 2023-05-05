#include <iostream>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

void print(vector<string> result);
vector<string> solution(string myStr);

int main(int argc, char* argv[])
{
    print(solution("baconlettucetomato"));
    print(solution("abcd"));
    print(solution("cabab"));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> solution(string myStr)
{
    vector<string> answer;
    string s = regex_replace(myStr, regex("[a, b, c]"), " ");
    istringstream iss(s);

    while (iss >> s)
        answer.emplace_back(s);

    return answer.empty() ? vector<string>{"EMPTY"} : answer;
}
