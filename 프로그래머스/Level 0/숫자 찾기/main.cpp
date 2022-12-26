#include <iostream>
#include <string>

using namespace std;

int solution(int num, int k);

int main(int argc, char* argv[])
{
	cout << solution(29183, 1) << endl;
	cout << solution(232443, 4) << endl;
	cout << solution(123456, 7) << endl;

	return 0;
}

int solution(int num, int k)
{
	string s = to_string(num);
	char c = '0' + k;
	size_t result = s.find(c);

    return (result == string::npos) ? -1 : result + 1;
}
