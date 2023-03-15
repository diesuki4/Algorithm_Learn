#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section);

int main(int argc, char* argv[])
{
    cout << solution(8, 4, {2, 3, 6}) << endl;
    cout << solution(5, 4, {1, 3}) << endl;
    cout << solution(4, 1, {1, 2, 3, 4}) << endl;

    return 0;
}

int solution(int n, int m, vector<int> section)
{
    int answer = 1;
    int paint = section.front();

    for (int sec : section)
    {
        if (paint + m <= sec)
        {
            paint = sec;
            ++answer;
        }
    }

    return answer;
}
