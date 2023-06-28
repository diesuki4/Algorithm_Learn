#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(10));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n)
{
    vector<int> answer {n};

    while (n != 1)
        answer.emplace_back(n += (n & 1) ? (2*n + 1) : -(n / 2));

    return answer;
}
