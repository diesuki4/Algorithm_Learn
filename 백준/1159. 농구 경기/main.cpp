#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int numAlpha[26] = {0};
	bool isPredaja = true;

	// 이름의 개수
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;

		cin >> s;

		// 0(a) ~ 25(z) 를 나타내는 배열의
		// 해당 위치에 +1
		++numAlpha[s[0] - 'a'];
	}

	// a 부터 z 까지
	for (int i = 0; i < 26; ++i) {
		// 해당 알파벳으로 시작하는 성이 5명 이상이면
		if (5 <= numAlpha[i]) {
			// 알파벳을 출력한다.
			cout << static_cast<char>('a' + i);
			// 선수 선발이 불가능하지 않다
			isPredaja = false;
		}
	}

	// 선수 선발이 불가능하면 출력
	if (isPredaja)
		cout << "PREDAJA";

	return 0;
}
