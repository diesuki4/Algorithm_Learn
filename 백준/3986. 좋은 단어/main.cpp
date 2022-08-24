#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, answer = 0;

	cin >> N;

	// 테스트 케이스 개수만큼 반복
	while (N--)
	{
		string s;
		int len;
		stack<char> stck;
		
		cin >> s;
		len = s.length();

		// 현재 문자열의 모든 문자를 순회
		for (int i = 0; i < len; ++i)
		{
			// 스택이 비었으면 삽입
			if (stck.empty())
				stck.push(s[i]);
			// 남은 것 중에 가장 마지막에 들어간 문자와
			// 짝이 맞으면 삭제
			else if (stck.top() == s[i])
				stck.pop();
			// 안 맞으면 삽입
			else
				stck.push(s[i]);
		}

		// 짝이 잘 맞아서 스택이 비었으면
		if (stck.empty())
			// 좋은 단어
			++answer;
	}

	cout << answer;

	return 0;
}
