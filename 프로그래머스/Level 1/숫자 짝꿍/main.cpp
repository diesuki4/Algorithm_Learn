#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y);

int main(int argc, char* argv[])
{
	cout << solution("12321", "42531") << endl;
	cout << solution("5525", "1255") << endl;

	return 0;
}

string solution(string X, string Y)
{
    string answer = "";
	int numNumbersX[10] = {0};	// X 내의 0~9 까지의 숫자의 개수
	int numNumbersY[10] = {0};	// Y 내의 0~9 까지의 숫자의 개수

	// X, Y 내의 0~9 까지의 숫자의 개수를 각각 센다
	for (char c : X) ++numNumbersX[c - '0'];
	for (char c : Y) ++numNumbersY[c - '0'];

	// 9~1 까지 X, Y 중 숫자의 개수가 적은 쪽의 개수만큼 각 숫자를 붙인다
	for (int i = 9; 1 <= i; --i)
		answer += string(min(numNumbersX[i], numNumbersY[i]), '0' + i);

	// 0 밖에 붙일 게 없으면
	if (answer == "")
		// 적은 쪽의 개수가 0 이면 안 붙이고, 그 이상이면 1개만 붙인다
		answer += string(clamp(min(numNumbersX[0], numNumbersY[0]), 0, 1), '0');
	// 앞에 먼저 붙여진 숫자가 있으면
	else
		// 적은 쪽의 개수만큼 0을 붙인다
		answer += string(min(numNumbersX[0], numNumbersY[0]), '0');

	// 겹치는 숫자가 있으면 만든 문자열을, 없으면 -1 반환
    return (0 < answer.length()) ? answer : "-1";
}
