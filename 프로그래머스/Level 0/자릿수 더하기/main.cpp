#include <iostream>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
	cout << solution(1234) << endl;
	cout << solution(930211) << endl;

	return 0;
}

int solution(int n)
{
    int answer = 0;

	do { answer += n % 10; }
	while (n /= 10);

    return answer;
}
