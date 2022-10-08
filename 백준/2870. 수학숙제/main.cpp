#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string ltrim(string s);
void push_string(vector<string> &vec, string s);
bool compare(string a, string b);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	vector<string> vec;

	cin >> M;

	while (M--)
	{
		char ch;
		string line;
		string strNum;
		istringstream iss;

		cin >> line;
		iss = istringstream(line);

		while (iss >> ch)
			// 숫자면 무조건 붙인다
			if (isdigit(ch))
				strNum += ch;
			// 문자가 들어왔을 때 길이가 1 이상이면,
			else if (0 < strNum.length())
				// 문자열 추가
				push_string(vec, ltrim(strNum)),
				// 문자열 초기화
				strNum = "";

		// 마지막 부분이 숫자일 경우 들어가지 않았으므로
		if (strNum.length())
			// 삽입
			push_string(vec, ltrim(strNum));
	}

	sort(vec.begin(), vec.end(), compare);

	for (string s : vec)
		cout << s << '\n';

	return 0;
}

string ltrim(string s)
{
	int idx;
	int length = s.length();

	for (idx = 0; idx < length; ++idx)
		if (s[idx] != '0')
			break;

	return s.substr(idx);
}

// ltrim 결과가 "" 이면 기존 문자열이 0으로만 이루어졌다는 뜻
void push_string(vector<string> &vec, string s)
{
	vec.push_back(s == "" ? "0" : s);
}

// 오름차순 정렬
bool compare(string a, string b)
{
	int lenA = a.length();
	int lenB = b.length();

	if (lenA == lenB)
		return 0 < b.compare(a);
	
	return lenA < lenB;
}
