#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e);

int main(int argc, char* argv[])
{
    cout << solution("Progra21Sremm3", 6, 12) << endl;
    cout << solution("Stanley1yelnatS", 4, 10) << endl;

    return 0;
}

string solution(string my_string, int s, int e)
{
    reverse(my_string.begin() + s, my_string.begin() + ++e);

    return my_string;
}
