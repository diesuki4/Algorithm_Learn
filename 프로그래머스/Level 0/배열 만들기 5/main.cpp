#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> intStrs, int k, int s, int l);

int main(int argc, char* argv[])
{
    print(solution({"0123456789","9876543210","9999999999999"}, 50000, 5, 5));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> intStrs, int k, int s, int l)
{
    vector<int> answer;

    for (string& str : intStrs)
    {
        int num = stoi(str.substr(s, l));

        if (k < num)
            answer.emplace_back(num);
    }

    return answer;
}
