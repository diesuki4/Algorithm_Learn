#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int mat[15000];
	int front, rear, answer = 0;

	cin >> N >> M;
	front = 0;
	rear = N - 1;

	for (int i = 0; i < N; ++i)
		cin >> mat[i];

	sort(mat, mat + N);

	while (front < rear)
	{
		int sum = mat[front] + mat[rear];

		if (sum == M)
			++front, --rear, ++answer;
		else if (sum < M)
			++front;
		else
			--rear;
	}

	cout << answer;

	return 0;
}
