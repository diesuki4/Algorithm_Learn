#include <iostream>
#include <queue>

using namespace std;

int BFS(int maze[][101], int N, int M);

int main(int argc, char* argv[])
{
	int N, M;
	int maze[101][101];

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);

	cout << BFS(maze, N, M) << endl;

	return 0;
}

int BFS(int maze[][101], int N, int M)
{
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> que;
	bool visit[101][101] = { false };
	int distance[101][101] = { 0 };

	visit[0][0] = true;
	que.push(make_pair(0, 0));

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) 
		{
			int Tx = x + dx[i];
			int Ty = y + dy[i];

			if (0 <= Tx && Tx < N && 0 <= Ty && Ty < M)
			{
				if (maze[Tx][Ty] == 1 && visit[Tx][Ty] == false)
				{
					distance[Tx][Ty] = distance[x][y] + 1;
					visit[Tx][Ty] = true;

					que.push(make_pair(Tx, Ty));
				}
			}
		}
	}

	return distance[N - 1][M - 1] + 1;
}
