// 틀린 풀이
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;

	cin >> T;

	// 테스트 케이스의 개수
	while (T--)
	{
		int N;
		int numZero = 0;
		// t 는 항상 끝 1자리만을 저장
		unsigned long long t = 1;

		// 현재 테스트 케이스
		cin >> N;

		do
		{
			// 끝 1자리에 곱함
			t *= N;

			// 오른쪽 끝이 0 이 아닐 때까지 반복
			while (!(t % 10))
			{
				// 0 을 1개 없애고
				t /= 10;
				// 0 개수 증가
				++numZero;
			}

			// 끝 1자리만 저장
			t %= 10;
		}
		while (--N);
		
		cout << numZero << '\n';
	}

	return 0;
}
