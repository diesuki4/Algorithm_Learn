#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> array, int n);

int main(int argc, char* argv[])
{
    cout << solution({3, 10, 28}, 20) << endl;
    cout << solution({10, 11, 12}, 13) << endl;

    return 0;
}

int solution(vector<int> array, int n)
{
    int answer = array[0];
    int dist = abs(n - array[0]);
    size_t size = array.size();

    for (int i = 1; i < size; ++i)
    {
        int t_dist = abs(n - array[i]);

        if (t_dist <= dist)
        {
            answer = (t_dist < dist) ? array[i] : min(answer, array[i]);
            dist = t_dist;
        }
    }

    return answer;
}
