#include <iostream>

using namespace std;

int solution(int M, int N);

int main(int argc, char* argv[])
{
	cout << solution(2, 2) << endl;
	cout << solution(2, 5) << endl;
	cout << solution(1, 1) << endl;
}

int solution(int M, int N)
{
	return M * N - 1;
}
