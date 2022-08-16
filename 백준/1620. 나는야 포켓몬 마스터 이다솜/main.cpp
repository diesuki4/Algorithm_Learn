#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	unordered_map<string, int> umap;
	string s, names[100001];

	cin >> n >> m;

	// 포켓몬의 개수만큼 입력
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;

		// 딕셔너리["포켓몬 이름"] = 인덱스
		umap[s] = i;
		// 배열[인덱스] = "포켓몬 이름"
		names[i] = s;
	}

	// 문제의 개수만큼 반복
	for (int i = 0; i < m; ++i)
	{
		cin >> s;

		// 첫 문자가 알파벳이면
		if ('A' <= s[0])
			// 인덱스 출력
			// 딕셔너리['포켓몬 이름']
			cout << umap[s] << '\n';
		// 첫 문자가 인덱스이면
		else
			// "포켓몬 이름" 출력
			// 배열[인덱스]
			cout << names[stoi(s)] << '\n';
	}

    return 0;
}
