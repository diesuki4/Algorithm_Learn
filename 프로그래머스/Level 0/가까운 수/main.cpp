#include <iostream>
#include <vector>
#include <algorithm>

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
    sort(array.begin(), array.end(), [n](const int a, const int b)
    {
        int distA = abs(n - a);
        int distB = abs(n - b);

        return (distA == distB) ? (a < b) : (distA < distB);
    });

    return array[0];
}
