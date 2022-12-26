#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> s1, vector<string> s2);

int main(int argc, char* argv[])
{
	cout << solution({"a", "b", "c"}, {"com", "b", "d", "p", "c"}) << endl;
	cout << solution({"n", "omg"}, {"m", "dot"}) << endl;

	return 0;
}

int solution(vector<string> s1, vector<string> s2)
{
	set<string> st(s1.begin(), s1.end());

	st.insert(s2.begin(), s2.end());

    return s1.size() + s2.size() - st.size();
}
