#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int tips[100000];
	unsigned long long answer = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> tips[i];

	sort(tips, tips + N, greater<int>()); // 역순 정렬

	for (int i = 0; i < N; ++i)	// 팁을 많이 줄 손님부터 순회
	{
		int tip = tips[i] - i;	// 받을 팁

		if (0 < tip)
			answer += tip;
		else
			break;
	}

	cout << answer;

	return 0;
}
