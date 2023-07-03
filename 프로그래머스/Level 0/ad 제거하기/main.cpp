#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> strArr);

int main(int argc, char* argv[])
{
    print(solution({"and", "notad", "abcd"}));
    print(solution({"there", "are", "no", "a", "ds"}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> solution(vector<string> strArr)
{
    auto new_end = remove_if(strArr.begin(), strArr.end(), [](string& s) { return s.find("ad") != string::npos; });
    strArr.erase(new_end, strArr.end());

    return strArr;
}
