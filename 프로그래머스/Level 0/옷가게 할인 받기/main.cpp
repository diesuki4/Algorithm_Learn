#include <iostream>

using namespace std;

int solution(int price);

int main(int argc, char* argv[])
{
	cout << solution(150'000) << endl;
	cout << solution(580'000) << endl;

	return 0;
}

int solution(int price)
{
    return	(price < 100'000) ? price :
			(price < 300'000) ? price * 0.95 :
			(price < 500'000) ? price * 0.9 : price * 0.8;
}
