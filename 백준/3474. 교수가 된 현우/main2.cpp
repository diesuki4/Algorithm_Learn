#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	while (T--)
	{
		int N;
		int numZero = 0;

		cin >> N;

		// 5의 개수가 2의 개수보다 항상 적으므로 5만 세어도 된다.
		// 5, 25, 125, 625, ... 으로 나누어 떨어지는 수의 개수를 구해 더한다.
		for (int i = 5; i <= N; i *= 5)
			numZero += N / i;
		
		cout << numZero << '\n';
	}

	return 0;
}
