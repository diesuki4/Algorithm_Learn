#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(12));
    print(solution(17));
    print(solution(420));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << ' ';
    cout << endl;
}

vector<int> solution(int n)
{
    vector<int> answer;

    for (int i = 2; 1 < n; ++i)
    {
        if (n % i == 0)
        {
            answer.emplace_back(i);

            do
                n /= i;
            while (n % i == 0);
        }
    }

    return answer;
}
