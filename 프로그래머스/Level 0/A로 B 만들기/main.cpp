#include <iostream>
#include <algorithm>

using namespace std;

int solution(string before, string after);

int main(int argc, char* argv[])
{
	cout << solution("olleh", "hello") << endl;
	cout << solution("allpe", "apple") << endl;

	return 0;
}

int solution(string before, string after)
{
	sort(before.begin(), before.end());
	sort(after.begin(), after.end());

    return before == after;
}
