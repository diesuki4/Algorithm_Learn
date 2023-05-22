#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<string> result);
vector<string> solution(string myString);

int main(int argc, char* argv[])
{
    print(solution("axbxcxdx"));
    print(solution("dxccxbbbxaaaa"));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> solution(string myString)
{
    multiset<string> mset;
    size_t last = 0;

    do
    {
        size_t first = myString.find_first_not_of('x', last);
        last = myString.find('x', first);

        if (first != string::npos)
            mset.emplace(myString.substr(first, last - first));
    }
    while (last != string::npos);

    return vector<string>(mset.begin(), mset.end());
}
