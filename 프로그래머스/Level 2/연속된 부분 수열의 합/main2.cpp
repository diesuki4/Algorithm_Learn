// 이 풀이는 틀린 풀이다.
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> sequence, int k);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 4, 5}, 7));
    print(solution({1, 1, 1, 2, 3, 4, 5}, 5));
    print(solution({2, 2, 2, 2, 2}, 6));
    print(solution({3, 3, 3, 3}, 3));
    print(solution({7, 5, 5, 1, 1, 50, 50}, 100));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> sequence, int k)
{
    int l = sequence.size() - 1;
    int r = l, sum = sequence[r];

    while (sum != k)
        if (sum < k)
            sum += sequence[--l];
        else
            sum -= sequence[r--];

    while ( (0 < l) && (sequence[l] + sequence[r] == sequence[l - 1] + sequence[r - 1]) )
        --l, --r;

    return {l, r};
}
