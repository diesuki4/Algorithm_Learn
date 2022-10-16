#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int to_sec(string timestamp);
string to_timestamp(int sec);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	int playTime = to_sec("48:00");
	int winTime1 = 0, winTime2 = 0;
	int diffScore = 0;
	map<int, int> mp;

	cin >> N;

	// 해당 시간에서의 득점 팀 정보를 저장
	while (N--)
	{
		int teamNo;
		string timestamp;

		cin >> teamNo >> timestamp;

		// mp[to_sec("01:14")] = 2;
		// 74초에 2팀이 득점 함
		mp[to_sec(timestamp)] = teamNo;
	}

	// 게임 진행 (diffScore 는 1팀 기준)
	for (int i = 0; i < playTime; ++i)
	{
		// 현재 시간에서 1팀 득점 정보가 있으면
		if (mp[i] == 1)
			// 점수 차 증가
			++diffScore;
		// 현재 시간에서 2팀 득점 정보가 있으면
		else if (mp[i] == 2)
			// 점수 차 감소
			--diffScore;

		// 1팀이 이기고 있으면
		if (0 < diffScore)
			// 1팀 승리 시간 증가
			++winTime1;
		// 2팀이 이기고 있으면
		else if (diffScore < 0)
			// 2팀 승리 시간 증가
			++winTime2;
	}

	cout << to_timestamp(winTime1) << '\n' << to_timestamp(winTime2);

	return 0;
}

// "01:14" -> 74
int to_sec(string timestamp)
{
	return stoi(timestamp.substr(0, 2)) * 60 + stoi(timestamp.substr(3, 2));
}

// 74 -> "01:14"
string to_timestamp(int sec)
{
	ostringstream oss;
	int min = sec / 60;

	sec %= 60;

	oss << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec;

	return oss.str();
}
