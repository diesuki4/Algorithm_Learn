#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string);

int main(int argc, char* argv[])
{
    cout << solution("jaron") << endl;
    cout << solution("bread") << endl;

    return 0;
}

string solution(string my_string)
{
	reverse(my_string.begin(), my_string.end());

    return my_string;
}
