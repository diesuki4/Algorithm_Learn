#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void calculate_prefix_sum(int arr[], int index);

int main(int argc, char* argv[])
{
	int N, P[1000] = {0};

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> P[i];

	sort(P, P + N);

	calculate_prefix_sum(P, N - 1);

	/*
	#include <numeric>

	accumulate(int* 배열 시작, int* 배열 시작+크기, 초깃값)
	배열이면 포인터, 벡터 등이면 이터레이터 사용
	
	초깃값에 따라 오버로딩 되어 있으니 주의
	합이 매우 커질 수 있을 때는 0LL (long long) 으로 초깃값 설정
	*/
	cout << accumulate(P, P + N, 0);

	return 0;
}

// 각 인덱스 위치에 "0 ~ 인덱스" 까지의 합 저장하기
void calculate_prefix_sum(int arr[], int index)
{
	if (index == 0)
		return;

	calculate_prefix_sum(arr, index - 1);

	arr[index] += arr[index - 1];
}
