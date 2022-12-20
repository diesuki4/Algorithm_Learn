#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int money);

int main(int argc, char* argv[])
{
	print(solution(5500));
	print(solution(15000));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(int money)
{
	int quotient = money / 5500;

    return vector({quotient, money - quotient * 5500});
}
