#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, int k);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 1, 2, 2, 3}, 3));
    print(solution({0, 1, 1, 1, 1}, 4));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, int k)
{
    int* p = new int[100'001]();
    vector<int> answer(k, -1);
    int i = 0;

    for (int e : arr)
    {
        if (k <= i)
            break;

        if (p[e] == 0)
        {
            ++p[e];
            answer[i++] = e;
        }
    }
    
    delete [] p;

    return answer;
}
