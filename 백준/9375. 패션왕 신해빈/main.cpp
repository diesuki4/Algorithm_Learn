#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	// 테스트 케이스의 개수만큼 반복
	while (N--)
	{
		int M;
		int cases = 1;
		unordered_map<string, int> umap;

		cin >> M;

		// 의상의 수만큼 반복
		while (M--)
		{
			// 의상의 종류
			string type;

			// 의상의 이름은 중요하지 않다.
			cin >> type >> type;

			// 해당 종류의 의상 수를 1 증가시킨다.
			++umap[type];
		}

		// 의상의 종류만큼 반복
		for (pair<string, int> pr : umap)
			// 각 종류의 (아무것도 선택하지 않은 경우 + 하나를 선택한 경우) 를 곱한다.
			cases *= (1 + pr.second);

		// 아무 의상도 선택하지 않은 경우를 빼준 후 출력한다.
		cout << --cases << '\n';
	}

	return 0;
}
