#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(int order);

int main(int argc, char* argv[])
{
	cout << solution(3) << endl;
	cout << solution(29423) << endl;

	return 0;
}

int solution(int order)
{
	int answer = 0;
    string s = to_string(order);

	for_each(s.begin(), s.end(), [&answer](char c) { if (c == '3' || c == '6' || c == '9') ++answer; });

    return answer;
}
