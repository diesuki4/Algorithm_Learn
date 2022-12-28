#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

string solution(string s);

int main(int argc, char* argv[])
{
	cout << solution("abcabcadc") << endl;
	cout << solution("abdc") << endl;
	cout << solution("hello") << endl;

	return 0;
}

string solution(string s)
{
	set<char> st;

	for_each(s.begin(), s.end(), [s, &st](char c) { if (count(s.begin(), s.end(), c) == 1) st.insert(c); });

    return accumulate(st.begin(), st.end(), string(""));
}
