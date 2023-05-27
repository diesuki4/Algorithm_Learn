#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(string my_string);

int main(int argc, char* argv[])
{
    print(solution("Programmers"));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(string my_string)
{
    vector<int> answer(52, 0);

    for (char c : my_string)
        ++answer[c - (isupper(c) ? 'A' : 'G')];

    return answer;
}
