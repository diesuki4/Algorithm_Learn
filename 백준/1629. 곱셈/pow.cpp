#include <iostream>

using namespace std;

// n 이 2 의 몇 승인지 반환
int pow_of_2(int n)
{
	int cnt = 0;

	while (n >>= 1)
		++cnt;
	
	return cnt;
}

// 거듭 제곱을 반환
int pow(int base, int exp)
{
	int result = 1;

	cout << "base\t" << "exp\t" << "result" << endl;
	// base	^  exp * result
	// 2    ^  11
	// 4    ^  5   *  2
	// 16   ^  2   *  2  *  4
	// 256  ^  1   *  2  *  4

	// 거듭 제곱 계산이 끝날 때까지 반복
	while (exp)
	{
		cout << 2 << "," << pow_of_2(base) << "\t" << exp << "\t" << 2 << "," << pow_of_2(result) << endl;

		// 지수가 홀수일 때만
		// 현재 base 를 결과에 곱한다.
		// 마지막인 지수가 1 일 때, 지금 껏 곱했던 2 * 4 와
		// 최종 base 인 2^8 을 곱하여 계산이 끝난다.
		if (exp & 1)
			// (2)^(11) -> (2)^(10) * (2)
			result *= base;

		// base 를 제곱하고
		base *= base;
		// 지수를 2로 나눈다.
		exp >>= 1;

		// (2)^(11) --> (2^2)^(5) * 2
	}

	cout << "-\t" << exp << "\t" << 2 << "," << pow_of_2(result) << endl << endl;

	return result;
}

int main(int argc, char* argv[])
{
	cout << pow(2, 11) << endl;

	return 0;
}
