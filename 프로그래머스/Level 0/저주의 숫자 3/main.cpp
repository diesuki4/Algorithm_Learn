#include <iostream>
#include <string>

using namespace std;

bool is3x(int n);
int solution(int n);

int main(int argc, char* argv[])
{
	cout << solution(15) << endl;
	cout << solution(40) << endl;
}

bool is3x(int n)
{
	for (char c : to_string(n))
		if (c == '3')
			return true;

	return !(n % 3);
}

int solution(int n)
{
	int t = 1;
	int answer = 0;

	do
		t += !is3x(++answer);
	while (t <= n);

	return answer;
}
