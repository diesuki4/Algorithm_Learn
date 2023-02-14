#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> result);
vector<bool> toBinary(int n);
vector<string> solution(int n, vector<int> arr1, vector<int> arr2);

int main(int argc, char* argv[])
{
    print(solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28}));
    print(solution(6, {46, 33, 33 ,22, 31, 50}, {27 ,56, 19, 14, 14, 10}));

    return 0;
}

void print(vector<string> result)
{
    for (string s : result)
        cout << s << endl;

    cout << endl;
}

vector<bool> toBinary(int n, int value)
{
    vector<bool> v(n);

    for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
    {
        *rit = value & 1;
        value >>= 1;
    }

    return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n);

    for (int i = 0; i < n; ++i)
    {
        string s(n, ' ');
        vector<bool> binary = toBinary(n, (arr1[i] | arr2[i]));

        transform(binary.begin(), binary.end(), s.begin(), [](bool b) { return b ? '#' : ' '; });

        answer[i] = s;
    }

    return answer;
}
