#include <iostream>
#include <set>

using namespace std;

int rDFS(bool grid[][101], int M, int N, int i, int j);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N, K;
	bool grid[101][101] = {false};
	multiset<int> divAreas;

	cin >> M >> N >> K;

	for (int k = 0; k < K; ++k)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; ++i)
			for (int j = x1; j < x2; ++j)
				grid[i][j] = true;
	}

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (!grid[i][j])
				divAreas.insert(rDFS(grid, M, N, i, j));

	cout << divAreas.size() << endl;

	for (int e : divAreas)
		cout << e << " ";

	return 0;
}

int rDFS(bool grid[][101], int M, int N, int i, int j)
{
	if (i < 0 || M <= i || j < 0 || N <= j || grid[i][j])
		return 0;

	grid[i][j] = true;

	return 1 + rDFS(grid, M, N, i, j + 1)
			+ rDFS(grid, M, N, i - 1, j)
			+ rDFS(grid, M, N, i, j - 1)
			+ rDFS(grid, M, N, i + 1, j);
}
