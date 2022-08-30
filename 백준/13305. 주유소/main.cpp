#include <iostream>
#include <climits>

using namespace std;

long long solution(long cost[], long distance[], size_t N, long i, long minCost);

int main(int argc, char* argv[])
{
	// 주유소의 개수
	int N;
	// 리터당 가격들, 주요소 간 거리들
	long cost[100000], distance[99999];

	cin >> N;

	for (int i = 0; i < N - 1; ++i)
		cin >> distance[i];

	for (int i = 0; i < N; ++i)
		cin >> cost[i];

	cout << solution(cost, distance, N, 0, LONG_MAX);

	return 0;
}

long long solution(long cost[], long distance[], size_t N, long i, long minCost)
{
	// 마지막 주유소이면
	if (i == N - 1)
		// 종료 조건
		return 0;

	// 현재 주유소의 리터당 가격이 이전까지의 최소 가격보다 저렴하면
	if (cost[i] < minCost)
		// 최소 가격 갱신
		minCost = cost[i];

	// 다음 주유소까지의 비용을 더하고
	// 다음 주유소로 넘김
	return distance[i] * minCost + solution(cost, distance, N, i + 1, minCost);
}
