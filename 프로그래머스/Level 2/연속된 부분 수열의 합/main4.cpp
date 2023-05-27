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
    vector<int> answer;

    int srt = 0, end = 0, sum = 0;

    for (int i = 0; i < sequence.size(); i++)
    {
        end = i;
        sum += sequence[end];

        while (sum > k)
            sum -= sequence[srt++];

        if (sum == k)
            if (answer.empty() || end - srt < answer[1] - answer[0])
                answer = {srt, end};
    }

    return answer;
}
