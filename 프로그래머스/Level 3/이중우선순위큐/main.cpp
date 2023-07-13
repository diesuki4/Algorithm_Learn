#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> operations);

int main(int argc, char* argv[])
{
    print(solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"}));
    print(solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> operations)
{
    multiset<int> mset;
    
    for (string& op : operations)
    {
        int num = stoi(op.substr(2));

        switch (op[0])
        {
        case 'I':
            mset.emplace(num);
            break;
        case 'D':
            if (mset.empty())
                continue;
            else if (0 < num)
                mset.erase(*mset.rbegin());
            else
                mset.erase(mset.begin());
            break;
        default:
            break;
        }
    }

    return mset.empty() ? vector<int>{0, 0} : vector<int>{*mset.rbegin(), *mset.begin()};
}
