#include <iostream>

using namespace std;

void rDFS(char gray[][64], int i, int j, int size);
bool IsAllElements(char gray[][64], int fromX, int toX, int fromY, int toY, char cValue);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	char gray[64][64];

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> gray[i][j];

	rDFS(gray, 0, 0, N);

	return 0;
}

void rDFS(char gray[][64], int x, int y, int size)
{
	int endX = x + size;
	int endY = y + size;

	if (IsAllElements(gray, x, endX, y, endY, '1'))
	{
		cout << 1;
		return;
	}
	else if (IsAllElements(gray, x, endX, y, endY, '0'))
	{
		cout << 0;
		return;
	}

	size *= 0.5;

	cout << "(";
	rDFS(gray, x, y, size);
	rDFS(gray, x, y + size, size);
	rDFS(gray, x + size, y, size);
	rDFS(gray, x + size, y + size, size);
	cout << ")";
}

bool IsAllElements(char gray[][64], int fromX, int toX, int fromY, int toY, char cValue)
{
	for (int i = fromX; i < toX; ++i)
		for (int j = fromY; j < toY; ++j)
			if (gray[i][j] != cValue)
				return false;

	return true;
}
