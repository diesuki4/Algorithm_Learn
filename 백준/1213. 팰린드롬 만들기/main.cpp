#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	char ch;
	int numAlpha[26] = {0};
	// 앞 부분을 의미
	// [AAB] C BAA
	string subFront;

	// 알파벳을 1개씩 입력받으며 개수를 저장한다.
	while ((ch = getchar()) != '\n')
		++numAlpha[ch - 'A'];

	// A - Z 까지 반복
	// 팰린드롬의 앞 부분을 만드는 과정
	for (int i = 0; i < 26; ++i)
	{
		// 현재 알파벳 개수의 반
		// 6 개일 경우 3
		// 5 개일 경우 2
		int half = numAlpha[i] * 0.5;

		// 현재 알파벳을 half 개수만큼 문자열로 만들어 붙인다.
		// AAAABBC
		// -> AA + B
		subFront += string(half, 'A' + i);

		// 현재 알파벳의 개수에서
		// 앞 부분을 만드는데 사용된 개수의 2배를 빼준다.
		// 2배인 이유는 뒷 부분을 만들었을 때를 고려했기 때문
		// 5 개는 1 이 된다.
		// 8 개는 0 이 된다.
		numAlpha[i] -= half * 2;
	}
	
	// 남은 개수가 1개인 (개수가 홀수였던) 알파벳이
	// 2개 이상이면 팰린드롬을 만들 수 없다.
	if (2 <= count(numAlpha, numAlpha + 26, 1))
	{
		cout << "I'm Sorry Hansoo";
	}
	// 남은 개수가 1개인 알파벳 하나를 중간에 삽입하여
	// 앞 부분, 중간 알파벳, 앞 부분의 역순을 결합해 출력한다.
	else
	{
		// 남은 개수가 1개인 알파벳의 인덱스
		int indexOne = find(numAlpha, numAlpha + 26, 1) - numAlpha;

		// 문자열의 길이가 짝수 였으면 ""
		// 홀수 였으면 중간 알파벳
		string middleChar = (indexOne == 26) ? ("") : (string(1, 'A' + indexOne));

		// 앞 부분 문자열의 역순
		string reverseFront = subFront;
		reverse(reverseFront.begin(), reverseFront.end());

		cout << subFront +
				middleChar +
				reverseFront;
	}
	
	return 0;
}
