#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<int> delete_list);

int main(int argc, char* argv[])
{
    print(solution({293, 1000, 395, 678, 94}, {94, 777, 104, 1000, 1, 12}));
    print(solution({110, 66, 439, 785, 1}, {377, 823, 119, 43}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    auto pred = [&delete_list](int num)
    {
        return find(delete_list.begin(), delete_list.end(), num) != delete_list.end();
    };

    arr.erase(remove_if(arr.begin(), arr.end(), pred), arr.end());

    return arr;
}
