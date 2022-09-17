#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void BFS(int height[][100], bool visit[][100], int N, int i, int j, int h);

int main()
{
	int N;
	int height[100][100];
	int maxHeight = 0;
	int answer = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> height[i][j],
			maxHeight = max(maxHeight, height[i][j]);

	// 낮은 높이부터 물에 잠기지 않은 영역의 개수를 구한다.
	for (int h = 0; h < maxHeight; ++h)
	{
		int numArea = 0;
		bool visit[100][100] = {false};

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				// 방문한 적이 없고, 물에 잠기지 않은 부분이면
				if (!visit[i][j] && h < height[i][j])
					// BFS 로 방문 상태 갱신
					BFS(height, visit, N, i, j, h),
					// 현재 높이에서 물에 잠기지 않은 영역 +1
					++numArea;

		// 물에 잠기지 않은 영역의 최댓값
		answer = max(answer, numArea);
	}

	cout << answer;
}

void BFS(int height[][100], bool visit[][100], int N, int i, int j, int h)
{
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	queue<pair<int, int>> que;

	que.push({ i, j });

	while (!que.empty())
	{
		int Tx = que.front().first;
		int Ty = que.front().second;

		que.pop();

		// 방문한 적이 없고, 물에 잠기지 않은 부분이면
		if (!visit[Tx][Ty] && h < height[Tx][Ty])
		{
			visit[Tx][Ty] = true;

			for (int i = 0; i < 4; ++i)
			{
				int nx = Tx + dx[i];
				int ny = Ty + dy[i];

				if (0 <= nx && 0 <= ny && nx < N && ny < N)
					que.push({nx, ny});
			}
		}
	}
}
