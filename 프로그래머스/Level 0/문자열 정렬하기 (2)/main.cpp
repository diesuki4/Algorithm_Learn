#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("Bcad") << endl;
	cout << solution("heLLo") << endl;
	cout << solution("Python") << endl;

	return 0;
}

string solution(string my_string)
{
	transform(my_string.begin(), my_string.end(), my_string.begin(), tolower);
	sort(my_string.begin(), my_string.end());

    return my_string;
}
