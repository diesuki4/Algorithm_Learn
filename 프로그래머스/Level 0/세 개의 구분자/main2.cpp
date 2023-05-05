#include <iostream>
#include <vector>

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
    size_t last = 0;
    
    do
    {
        size_t first = myStr.find_first_not_of("abc", last);
        last = myStr.find_first_of("abc", first);

        if (first != string::npos)
            answer.emplace_back(myStr.substr(first, last - first));
    }
    while (last != string::npos);

    return answer.empty() ? vector<string>{"EMPTY"} : answer;
}
