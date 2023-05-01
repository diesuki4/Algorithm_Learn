#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, vector<int> slicer, vector<int> num_list);

int main(int argc, char* argv[])
{
    print(solution(3, {1, 5, 2}, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
    print(solution(4, {1, 5, 2}, {1, 2, 3, 4, 5, 6, 7, 8, 9}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    vector<int> answer;
    int a = slicer[0], b = slicer[1] + 1, c = slicer[2];

    switch (n)
    {
    case 1:
    {
        answer = vector<int>(num_list.begin(), num_list.begin() + b);
        break;
    }
    case 2:
    {
        answer = vector<int>(num_list.begin() + a, num_list.end());
        break;
    }
    case 3:
    {
        answer = vector<int>(num_list.begin() + a, num_list.begin() + b);
        break;
    }
    case 4:
    {
        int cnt = 0;
        auto pred = [c, &cnt](int e) { return (cnt++ % c) == 0; };
        copy_if(num_list.begin() + a, num_list.begin() + b, back_inserter(answer), pred);
        break;
    }
    }

    return answer;
}
