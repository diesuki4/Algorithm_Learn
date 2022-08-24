#include <iostream>

using namespace std;

// (1)                       2      ^     6      %     5
// (2)                       2      ^     3      %     5
// (3)                       2      ^     1      %     5
long long solution(long long A, long long B, long long C)
{
	// (3) 2 ^ 1 % 5
	if (B == 1)
		// (3) 2 % 5
		return A % C;

	// (1)                  2 ^ 3 % 5
	// (2)                  2 ^ 1 % 5
	// (2) 2 ^ 1 % 5
	// (1) 2 ^ 3 % 5
	long long ll = solution(A, B/2, C);
	
	// 현재 지수가 짝수이면
	if (~B & 1)
		// (1) ( 2 ^ 3 % 5 ) * ( 2 ^ 3 % 5 ) % 5
		return (     ll    ) * (     ll    ) % C;
	// 현재 지수가 홀수이면
	else
		// (2) ( 2 ^ 1 % 5 ) * ( 2 ^ 1 % 5 ) % 5 * 2 % 5 
		return (     ll    ) * (     ll    ) % C * A % C ;
}

/*
	3 개의 수를 곱했을 때의 나머지
	https://stackoverflow.com/questions/20930741/calculating-product-of-3-numbers-modulo-m#answer-20930787
*/

int main(int argc, char* argv[])
{
	long long A, B, C;

	cin >> A >> B >> C;

	cout << solution(A, B, C);

	return 0;
}
