#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int answer = 0;
	vector<int> vec;

	cin >> N >> M;

	while (N--)
	{
		int num;

		cin >> num;

		for (int elem : vec) {
			if (elem + num == M) {
				++answer;
				break;
			}
		}
		
		vec.push_back(num);
	}

	cout << answer;

	return 0;
}
