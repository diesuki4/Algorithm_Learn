#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// 트럭 대수에 따른 분당 가격을 저장 (0번째 요소는 사용하지 않는다)
	int price[4] = {0};
	// 매분의 트럭 대수를 저장
	int trucksInMinute[101] = {0};
	// 답 (최종 금액)
	int totalPrice = 0;

	// 가격 입력
	cin >> price[1] >> price[2] >> price[3];

	for (int i = 0; i < 3; ++i)
	{
		// 도착 시각, 떠난 시각
		int from, to;

		cin >> from >> to;

		// 도착한 시각 1분 이후부터 떠난 시각까지
		// 있었던 트럭 대수를 1 증가시킨다.
		for (int j = ++from; j <= to; ++j)
			++trucksInMinute[j];
	}

	// 매분의 트럭 대수에, 대수에 따른 가격을 곱해
	// 최종 금액을 구한다.
	for (int truck : trucksInMinute)
		totalPrice += truck * price[truck];

	cout << totalPrice;

	return 0;
}
