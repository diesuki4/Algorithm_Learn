// 미완성 풀이

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <climits>
#include <map>

#define HOLE -1

using namespace std;

void process_holes(int plate[][100], int row, int col);
void isHole(int plate[][100], bool visit[][100], int row, int col, int i, int j, vector<pair<int, int>>& positionsInHole, bool& result);
int melt_time(int plate[][100], int i, int j);
int distance(int plate[][100], int i, int j, int dirX, int dirY);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int row, col;
	int meltTime = 0;
	int cheeseRemain = 0;
	int plate[100][100];

	cin >> row >> col;
	cin.ignore();

	for (int i = 0; i < row; ++i)
	{
		string line;
		istringstream iss;

		getline(cin, line);

		iss = istringstream(line);

		for (int j = 0; j < col; ++j)
			iss >> plate[i][j];
	}

	process_holes(plate, row, col);

	for (int i = 1; i < row - 1; ++i)
	{
		for (int j = 1; j < col - 1; ++j)
		{
			if (plate[i][j])
			{
				int prv_meltTime = meltTime;
				int t_meltTime = melt_time(plate, i, j);

				meltTime = max(meltTime, t_meltTime);

				if (prv_meltTime != meltTime)
					cheeseRemain = 1;
				else if (t_meltTime == meltTime)
					++cheeseRemain;
			}
		}
	}

	cout << meltTime << '\n' << cheeseRemain;

	return 0;
}

void process_holes(int plate[][100], int row, int col)
{
	for (int i = 2; i < row - 2; ++i)
	{
		for (int j = 2; j < col - 2; ++j)
		{
			if (plate[i][j] == 0)
			{
				bool result = true;
				bool visit[100][100] = {false};
				vector<pair<int, int>> positionsInHole;

				isHole(plate, visit, row, col, i, j, positionsInHole, result);

				if (result)
				{
					set<pair<int, int>> st;
					map<pair<int, int>, int> mp;
					int minMeltTime = INT_MAX;

					for (pair<int, int> pr : positionsInHole)
						plate[pr.first][pr.second] = HOLE;

					for (pair<int, int> pr : positionsInHole)
					{
						if (plate[pr.first][pr.second + 1] != HOLE) st.insert(pr);
						if (plate[pr.first + 1][pr.second] != HOLE) st.insert(pr);
						if (plate[pr.first][pr.second - 1] != HOLE) st.insert(pr);
						if (plate[pr.first - 1][pr.second] != HOLE) st.insert(pr);
					}

					for (pair<int, int> pr : st)
					{
						set<int> distances;

						if (plate[pr.first][pr.second + 1] != HOLE) distances.insert(distance(plate, pr.first, pr.second, 0, 1));
						if (plate[pr.first + 1][pr.second] != HOLE) distances.insert(distance(plate, pr.first, pr.second, 1, 0));
						if (plate[pr.first][pr.second - 1] != HOLE) distances.insert(distance(plate, pr.first, pr.second, 0, -1));
						if (plate[pr.first - 1][pr.second] != HOLE) distances.insert(distance(plate, pr.first, pr.second, -1, 0));

						mp[pr] = *distances.begin();
						minMeltTime = min(minMeltTime, *distances.begin());
					}

					for (pair<int, int> pr : st)
						if (mp[pr] != minMeltTime)
							plate[pr.first][pr.second] += minMeltTime;
				}
			}
		}
	}
}

void isHole(int plate[][100], bool visit[][100], int row, int col, int i, int j, vector<pair<int, int>>& positionsInHole, bool& result)
{
	if (!result || visit[i][j] || plate[i][j])
		return;
	else if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
		result = false;

	visit[i][j] = true;
	positionsInHole.push_back({i, j});

	isHole(plate, visit, row, col, i, j + 1, positionsInHole, result);
	isHole(plate, visit, row, col, i + 1, j, positionsInHole, result);
	isHole(plate, visit, row, col, i, j - 1, positionsInHole, result);
	isHole(plate, visit, row, col, i - 1, j, positionsInHole, result);
}

int melt_time(int plate[][100], int i, int j)
{
	set<int> st;

	st.insert(distance(plate, i, j, 1, 0));
	st.insert(distance(plate, i, j, 0, 1));
	st.insert(distance(plate, i, j, -1, 0));
	st.insert(distance(plate, i, j, 0, -1));
	
	return *st.begin();
}

int distance(int plate[][100], int i, int j, int dirX, int dirY)
{
	int dist = 0;
	int t_plate[100][100];

	memcpy(t_plate, plate, sizeof(t_plate));	

	while (0 < t_plate[i][j]--)
	{
		if (t_plate[i][j] == 0)
			i += dirY,
			j += dirX;

		++dist;
	}

	return dist;
}
