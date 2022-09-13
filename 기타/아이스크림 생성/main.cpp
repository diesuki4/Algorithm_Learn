#include <iostream>
#include <vector>

using namespace std;

void rDFS(vector<vector<int>>& vec2D, int i, int j);

int main(int argc, char* argv[])
{
	int N, M;
	int answer = 0;
	// 2차원 벡터
	vector<vector<int>> vec2D;

	cin >> N >> M;

	vec2D = vector<vector<int>>(N);

	for (vector<int>& vec : vec2D)
	{
		vec = vector<int>(M);

		for (int& e : vec)
			cin >> e;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			// 뚫린 부분이 있으면
			if (vec2D[i][j] == 0)
				// DFS 수행
				rDFS(vec2D, i, j),
				// 아이스크림 생성 가능
				++answer;

	cout << answer << endl;

	return 0;
}

void rDFS(vector<vector<int>>& vec2D, int i, int j)
{
	// 세로 크기
	int N = vec2D.capacity();
	// 가로 크기
	int M = vec2D[0].capacity();

	// 범위를 벗어났거나, 뚫린 부분이 아니면
	if (i < 0 || N <= i || j < 0 || M <= j || vec2D[i][j] == 1)
		// 종료
		return;
	// 범위 내에 있고 뚫린 부분이면
	else
		// 방문
		vec2D[i][j] = 1;

	rDFS(vec2D, i - 1, j);	// 위쪽부터 DFS
	rDFS(vec2D, i + 1, j);	// 아래쪽부터 DFS
	rDFS(vec2D, i, j - 1);	// 왼쪽부터 DFS
	rDFS(vec2D, i, j + 1);	// 오른쪽부터 DFS

	return;
}
