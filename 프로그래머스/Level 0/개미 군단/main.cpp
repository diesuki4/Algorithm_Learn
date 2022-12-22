#include <iostream>

using namespace std;

int solution(int hp);

int main(int argc, char* argv[])
{
	cout << solution(23) << endl;
	cout << solution(24) << endl;
	cout << solution(999) << endl;

	return 0;
}

int solution(int hp)
{
	const int generalPwr = 5;
	const int soldierPwr = 3;
	int answer = 0;

	answer += hp / generalPwr;
	hp -= answer * generalPwr;

    return answer += hp / soldierPwr + hp % soldierPwr;
}
