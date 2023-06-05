#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> prices);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 2, 3}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> prices)
{
    size_t n = prices.size();
    vector<int> answer(n, 0);

    for (int i = 0; i < n; ++i)
        for (int j = i; (j < n - 1) && (prices[i] <=prices[j]); ++j)
            ++answer[i];

    return answer;
}
