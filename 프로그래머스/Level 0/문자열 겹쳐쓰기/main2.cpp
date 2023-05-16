#include <iostream>

using namespace std;

string solution(string my_string, string overwrite_string, int s);

int main(int argc, char* argv[])
{
    cout << solution("He11oWor1d", "lloWorl", 2) << endl;
    cout << solution("Program29b8UYP", "merS123", 7) << endl;

    return 0;
}

string solution(string my_string, string overwrite_string, int s)
{
    return my_string.replace(s, overwrite_string.length(), overwrite_string);
}
