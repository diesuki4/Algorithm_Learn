#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> keyinput, vector<int> board);

int main(int argc, char* argv[])
{
	print(solution({"left", "right", "up", "right", "right"}, {11, 11}));
	print(solution({"down", "down", "down", "down", "down"}, {7, 9}));
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << ' ';
	cout << endl;
}

vector<int> solution(vector<string> keyinput, vector<int> board)
{
	map<string, vector<int>> mp = {{"left", {-1, 0}}, {"right", {1, 0}}, {"up", {0, 1}}, {"down", {0, -1}}};
	vector<int> answer = {0, 0};
	vector<int> limit = {board[0] / 2, board[1] / 2};

	for (string key : keyinput)
	{
		answer[0] = max(-limit[0], min(answer[0] + mp[key][0], limit[0]));
		answer[1] = max(-limit[1], min(answer[1] + mp[key][1], limit[1]));
	}

	return answer;
}
