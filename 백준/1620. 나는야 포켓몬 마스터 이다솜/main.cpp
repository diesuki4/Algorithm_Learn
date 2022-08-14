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

	for (int i = 1; i <= n; ++i)
	{
		cin >> s;

		umap[s] = i;
		names[i] = s;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> s;

		if ('A' <= s[0])
			cout << umap[s] << '\n';
		else
			cout << names[stoi(s)] << '\n';
	}

    return 0;
}
