#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, int s);

int main(int argc, char* argv[])
{
    print(solution(2, 9));
    print(solution(2, 1));
    print(solution(2, 8));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, int s)
{
    if (n > s)
        return {-1};

    vector<int> answer;

    while (0 < n)
    {
        int num = s / n--;

        s -= num;

        answer.emplace_back(num);
    }

    return answer;
}
