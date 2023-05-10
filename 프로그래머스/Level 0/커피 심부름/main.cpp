#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> order);

int main(int argc, char* argv[])
{
    cout << solution({"cafelatte", "americanoice", "hotcafelatte", "anything"}) << endl;
    cout << solution({"americanoice", "americano", "iceamericano"}) << endl;

    return 0;
}

int solution(vector<string> order)
{
    int answer = 0;

    for (string& s : order)
        if (s.find("cafelatte") != string::npos)
            answer += 5000;
        else
            answer += 4500;

    return answer;
}
