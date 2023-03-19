#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
string ToBinaryString(int num);
vector<int> solution(string s);

int main(int argc, char* argv[])
{
    print(solution("110010101001"));
    print(solution("01110"));
    print(solution("1111111"));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

string ToBinaryString(int num)
{
    string s = "";

    if (num == 0)
        return "0";

    do
        s = (num & 1 ? "1" : "0") + s;
    while (num >>= 1);

    return s;
}

vector<int> solution(string s)
{
    vector<int> answer(2, 0);
    size_t o_length = s.length();

    while (s != "1")
    {
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        answer[1] += (o_length - s.length());

        s = ToBinaryString(s.length());
        o_length = s.length();

        ++answer[0];
    }

    return answer;
}
