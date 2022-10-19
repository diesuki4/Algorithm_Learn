#include <iostream>
#include <cstring>
#include <set>

using namespace std;

// 열의 개수가 6일 때, (1, 2) ==> 8
#define serializeIndex(nCol, i, j) ((nCol) * (i) + (j))

void deserializeIndex(int nCol, int iSerialized, int& i, int& j);
int countSafeSpaces(int space[][8], int N, int M);
void simulatePollution(int space[][8], int N, int M);
void rDFS(int space[][8], int N, int M, int i, int j);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int space[8][8] = {0};
	int lastSerializedIndex;
	set<int> st;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> space[i][j];

	// 2차원 배열을 직렬화했을 때 가장 마지막 인덱스
	lastSerializedIndex = serializeIndex(M, N - 1, M - 1);

	for (int i = 0; i <= lastSerializedIndex - 2; ++i)
		for (int j = i + 1; j <= lastSerializedIndex - 1; ++j)
			for (int h = j + 1; h <= lastSerializedIndex; ++h)
				// 서로 다른 위치일 때
				if (i != j && j != h && i != h)
				{
					// 직렬화 인덱스 역직렬화
					int iA, jA;	deserializeIndex(M, i, iA, jA);
					int iB, jB;	deserializeIndex(M, j, iB, jB);
					int iC, jC;	deserializeIndex(M, h, iC, jC);

					// 모두 0 (빈 칸)이면 벽을 세울 수 있다.
					if (!space[iA][jA] && !space[iB][jB] && !space[iC][jC])
					{
						// 시뮬레이션을 위한 임시 배열
						int t_space[8][8];

						memcpy(t_space, space, sizeof(space));

						// 벽을 3개 세우고
						t_space[iA][jA] = t_space[iB][jB] = t_space[iC][jC] = 1;

						// 오염을 진행
						simulatePollution(t_space, N, M);
						// 안전 영역의 개수를 set 에 삽입
						st.insert(countSafeSpaces(t_space, N, M));
					}
				}

	// rbegin() 은 보통 end() - 1
	cout << *st.rbegin();

	return 0;
}

// 열의 개수가 6일 때, 8 ==> (1, 2)
void deserializeIndex(int nCol, int iSerialized, int& i, int& j)
{
	i = iSerialized / nCol;
	j = iSerialized % nCol;
}

// 0 (안전 영역)의 개수를 반환
int countSafeSpaces(int space[][8], int N, int M)
{
	int numSafeSpaces = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			numSafeSpaces += (space[i][j]) ? 0 : 1;

	return numSafeSpaces;	
}

// 2 (바이러스 영역)을 찾아 오염을 진행
void simulatePollution(int space[][8], int N, int M)
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (space[i][j] == 2)
				rDFS(space, N, M, i, j);
}

void rDFS(int space[][8], int N, int M, int i, int j)
{
	space[i][j] = 2;

	if (j + 1 < M && space[i][j + 1] == 0) rDFS(space, N, M, i, j + 1);
	if (i + 1 < N && space[i + 1][j] == 0) rDFS(space, N, M, i + 1, j);
	if (0 <= j - 1 && space[i][j - 1] == 0) rDFS(space, N, M, i, j - 1);
	if (0 <= i - 1 && space[i - 1][j] == 0) rDFS(space, N, M, i - 1, j);
}
