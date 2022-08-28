#include <iostream>
#include <algorithm>

using namespace std;

int solution(int coin[], int N, int K);

int main(int argc, char* argv[])
{
	int N, K;
	int coin[10];

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> coin[i];

	cout << solution(coin, N, K);

	return 0;
}

// 1, 5, 10, 50, 100, 500, 1000, 5000
// K = 4200
int solution(int coin[], int N, int K)
{
	// K 보다 작거나 같은 가장 큰 수
	// K 가 4200 이면 1000
	int largestLessThanK = *(upper_bound(coin, coin + N, K) - 1);
	// 몫
	// 4200 / 1000 = 4
	int quotient = K / largestLessThanK;
	// K 에서 뺄 값
	// 1000 * 4 = 4000
	int sub = largestLessThanK * quotient;

	// 뺐을 때 더 이상 나머지가 없으면
	if (K == sub)
		// 방금 사용된 동전 개수 반환
		// 4
		return quotient;
	// 아직 남은 돈이 있으면
	else
		// 방금 사용된 동전 개수 + 남은 돈의 결과 개수
		// 4 + solution(coin, N, 4200 - 4000);
		return quotient + solution(coin, N, K - sub);
}
