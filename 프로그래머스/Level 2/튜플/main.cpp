#include <iostream>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(string s);

int main(int argc, char* argv[])
{
    print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"));
    print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"));
    print(solution("{{20,111},{111}}"));
    print(solution("{{123}}"));
    print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(string s)
{
    vector<int> answer;
    vector<vector<int>> elements;
    string input;

    s = string(s.begin() + 2, s.end() - 2);
    s = regex_replace(s, regex("\\},\\{"), " ");

    istringstream iss(s);

    while (iss >> input)
    {
        replace(input.begin(), input.end(), ',', ' ');

        int num;
        istringstream iss2(input);

        elements.emplace_back(vector<int>());

        while (iss2 >> num)
            elements.back().emplace_back(num);
    }

    while (!elements.empty())
    {
        int num;
        vector<vector<int>>::iterator it;

        for (it = elements.begin(); it->size() != 1; ++it);
        num = it->front();

        answer.emplace_back(num);
        
        for (vector<int>& v : elements)
            v.erase(find(v.begin(), v.end(), num));
        elements.erase(it);
    }

    return answer;
}
