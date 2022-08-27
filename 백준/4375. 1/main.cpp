#include <iostream>
#include <string>

using namespace std;

int solution(int num, int multiple);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	// 입력 스트림에 더 이상 값이 없으면 false
	while (cin >> s)
	{
		// #include <string>
		int num = stoi(s);

		cout << solution(num, 1) << '\n';
	}

	return 0;
}

/*
        0
       ___
    3 | 1
        0
       ___
        1
*/
/*
        0 2
       _____
    3 | 1
        0
       _____
        1 1
          9
       _____
          2
*/
/*
        0 2 7
       _______
    3 | 1
        0
       _______
        1 1
          9
       _______
          2 1
          2 1
       _______
            0
*/
int solution(int num, int multiple)
{
	int mod = multiple % num;

	// 배수가 아니면
	if (mod)
		return 1 + solution(num, mod * 10 + 1);
	// 배수이면
	else
		return 1;
}
