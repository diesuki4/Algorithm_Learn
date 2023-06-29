#include <iostream>

using namespace std;

string solution(string str1, string str2);

int main(int argc, char* argv[])
{
    cout << solution("aaaaa", "bbbbb") << endl;

    return 0;
}

string solution(string str1, string str2)
{
    size_t n = str1.size();
    str1.resize(n * 2);

    for (int i = n - 1; 0 <= i; --i)
        str1[i * 2] = str1[i],
        str1[i * 2 + 1] = str2[i];

    return str1;
}
