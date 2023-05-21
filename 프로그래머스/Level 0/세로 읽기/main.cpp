#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c);

int main(int argc, char* argv[])
{
    cout << solution("ihrhbakrfpndopljhygc", 4, 2) << endl;
    cout << solution("programmers", 1, 1) << endl;

    return 0;
}

string solution(string my_string, int m, int c)
{
    string answer = "";
    size_t n = my_string.length() / m;
    vector<string> v(n, string(m, '\0'));

    for (int i = 0; i < n; ++i)
        copy(my_string.data() + i * m, my_string.data() + (i + 1) * m, &v[i][0]);

    for (int i = 0; i < n; ++i)
        answer += v[i][c - 1];

    return answer;
}
