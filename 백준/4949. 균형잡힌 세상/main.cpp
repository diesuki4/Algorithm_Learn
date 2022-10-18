#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_bracket(char ch);
bool is_pair(char a, char b);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	getline(cin, s);

	while (s.length() != 1)
	{
		stack<char> stck;

		for (char ch : s)
		{
			// 괄호 문자만 확인
			if (is_bracket(ch))
			{
				// 비어있거나 여는 괄호거나 짝을 맞출 수 없으면
				if (stck.empty() || ch == '(' || ch == '[' || !is_pair(stck.top(), ch))
					// 삽입
					stck.push(ch);
				// 짝을 맞출 수 있으면
				else if (is_pair(stck.top(), ch))
					// 삭제
					stck.pop();
					
				// 현재 마지막 요소가 닫는 괄호이면
				// 짝을 맞출 수 없다.
				if (stck.size() && (stck.top() == ')' || stck.top() == ']'))
					break;
			}
		}

		cout << (stck.empty() ? "yes\n" : "no\n");

		getline(cin, s);
	}

	return 0;
}

bool is_bracket(char ch)
{
	return (ch == '(' || ch ==')' || ch == '[' || ch == ']');
}

bool is_pair(char a, char b)
{
	if (a == '(')
		return b == ')';
	else if (a == '[')
		return b == ']';
	else
		return false;
}
