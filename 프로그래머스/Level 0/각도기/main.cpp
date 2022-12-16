#include <iostream>

using namespace std;

int solution(int angle);

int main(int argc, char* argv[])
{
	cout << solution(70) << endl;
	cout << solution(91) << endl;
	cout << solution(180) << endl;

	return 0;
}

int solution(int angle)
{
    return	(angle < 90)	? 1 :
			(angle == 90)	? 2 :
			(angle < 180)	? 3 : 4;
}
