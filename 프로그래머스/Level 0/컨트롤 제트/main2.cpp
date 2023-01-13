#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <numeric>

using namespace std;

template <typename T>
class mystack : public stack <T>
{
public :
    auto begin()    { return this->c.begin(); }
    auto end()      { return this->c.end(); }
};

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("1 2 Z 3") << endl;
    cout << solution("10 20 30 40") << endl;
    cout << solution("10 Z 20 Z 1") << endl;
    cout << solution("10 Z 20 Z") << endl;
    cout << solution("-1 -2 -3 Z") << endl;
}

int solution(string s)
{
    string str;
    istringstream iss(s);
    mystack<int> mstk;

    while (iss >> str)
        if (str == "Z")
            mstk.pop();
        else
            mstk.push(stoi(str));

    return accumulate(mstk.begin(), mstk.end(), 0);
}
