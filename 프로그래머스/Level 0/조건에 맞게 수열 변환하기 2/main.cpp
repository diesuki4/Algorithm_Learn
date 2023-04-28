#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr);

int main(int argc, char* argv[])
{
    cout << solution({1, 2, 3, 100, 99, 98}) << endl;

    return 0;
}

int solution(vector<int> arr)
{
    int answer = -1;
    vector<int> prev;

    while (prev != arr)
    {
        prev = arr;

        ++answer;

        for_each(arr.begin(), arr.end(), [](int& e)
        {
            if (50 <= e && ~e & 1)
                e >>= 1;
            else if (e < 50 && e & 1)
                (e <<= 1)++;
        });
    }

    return answer;
}
