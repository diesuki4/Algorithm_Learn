#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int answer = 0;
	vector<int> vec;

	cin >> N >> M;

	// 재료의 개수만큼 반복
	while (N--)
	{
		int num;

		// 현재 고유 번호 입력
		cin >> num;

		// 벡터를 순회
		for (int elem : vec) {
			// 벡터의 원소 + 현재 고유 번호 == 정답 고유 번호의 합
			if (elem + num == M) {
				// 정답 1 증가
				++answer;
				break;
			}
		}
		
		// 벡터에 고유 번호를 삽입
		vec.push_back(num);
	}

	cout << answer;

	return 0;
}
