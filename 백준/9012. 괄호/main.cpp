#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--)
	{
		string ps;
		stack<char> stck;

		cin >> ps;

		for (char ch : ps)
		{
			// 비어있거나 여는 괄호이면
			if (stck.empty() || ch == '(')
				// 삽입
				stck.push(ch);
			// 닫는 괄호이면
			else if (ch == ')')
				// 삭제
				stck.pop();

			// 현재 마지막 요소가 닫는 괄호이면
			// 짝을 맞출 수 없다.
			if (stck.size() && stck.top() == ')')
				break;
		}

		cout << (stck.empty() ? "YES\n" : "NO\n");
	}

	return 0;
}
