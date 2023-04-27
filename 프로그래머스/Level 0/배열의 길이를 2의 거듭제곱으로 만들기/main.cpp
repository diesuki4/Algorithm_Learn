#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 4, 5, 6}));
    print(solution({58, 172, 746, 89}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr)
{
    size_t o_size = arr.size();
    size_t new_size = 0b1;

    while (new_size < o_size)
        new_size <<= 1;

    arr.resize(new_size);
    fill(arr.begin() + o_size, arr.end(), 0);

    return arr;
}
