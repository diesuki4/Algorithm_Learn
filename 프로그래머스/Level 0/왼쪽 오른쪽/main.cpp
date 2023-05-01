#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> str_list);

int main(int argc, char* argv[])
{
    print(solution({"u", "u", "l", "r"}));
    print(solution({"l"}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> solution(vector<string> str_list)
{
    auto it_l = find(str_list.begin(), str_list.end(), "l");
    auto it_r = find(str_list.begin(), str_list.end(), "r");

    if (it_l < it_r)
        str_list.erase(it_l, str_list.end());
    else if (it_r < it_l)
        str_list.erase(str_list.begin(), ++it_r);
    else
        return vector<string>();

    return str_list;
}
