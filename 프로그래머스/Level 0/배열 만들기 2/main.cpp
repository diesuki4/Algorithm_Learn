#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
void rSolution(int l, int r, vector<int>& vec, int val);
vector<int> solution(int l, int r);

int main(int argc, char* argv[])
{
    print(solution(5, 555));
    print(solution(10, 20));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

void rSolution(int l, int r, vector<int>& vec, int val)
{
    if (l <= val && val <= r)
        vec.emplace_back(val);
    else if (r < val)
        return;

    int next_val = val * 10;

    rSolution(l, r, vec, next_val);
    rSolution(l, r, vec, next_val + 5);
}

vector<int> solution(int l, int r)
{
    vector<int> answer;

    rSolution(l, r, answer, 5);
    sort(answer.begin(), answer.end());

    return answer.empty() ? vector<int>{-1} : answer;
}
