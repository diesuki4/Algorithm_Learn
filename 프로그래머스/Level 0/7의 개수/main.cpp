#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> array);

int main(int argc, char* argv[])
{
	cout << solution({7, 77, 17}) << endl;
	cout << solution({10, 29}) << endl;

	return 0;
}

int solution(vector<int> array)
{
    int answer = 0;

	for_each(array.begin(), array.end(), [&answer](int n) { string s = to_string(n); answer += count(s.begin(), s.end(), '7'); });

    return answer;
}
