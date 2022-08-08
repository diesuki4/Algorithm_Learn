#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// 중간 지점(middle)까지 반복에 사용
	int i;
	// 문자열 길이, 중간 지점 (길이 / 2)
	int length, middle;
	string s;

	// 문자열 입력
	cin >> s;

	// 길이
	length = s.length();
	// 중간 지점
	middle = length / 2;

	// 중간 지점까지
	// 앞에서는 앞으로 한 칸, 뒤에서는 뒤로 한 칸
	// 이동하며 두 문자가 같은 동안 i를 증가시킨다.
	for (i = 0; (i < middle) && (s[i] == s[--length]); ++i);

	// 확인한 모든 문자가 같았는지 출력
	// 같으면 true(1), 다르면 (0)
	cout << (i == middle);

	return 0;
}
