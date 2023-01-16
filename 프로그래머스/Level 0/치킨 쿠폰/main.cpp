#include <iostream>

using namespace std;

int solution(int chicken);

int main(int argc, char* argv[])
{
	cout << solution(100) << endl;
	cout << solution(1081) << endl;
}

int solution(int chicken)
{
	int answer = 0;

	do
	{
		int t = chicken % 10;

		answer += (chicken /= 10);

		chicken += t;
	}
	while (10 <= chicken);

	return answer;
}
