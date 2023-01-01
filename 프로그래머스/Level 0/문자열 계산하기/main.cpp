#include <iostream>
#include <sstream>

using namespace std;

int solution(string my_string);

int main(int argc, char* argv[])
{
	cout << solution("3 + 4") << endl;

	return 0;
}

int solution(string my_string)
{
	int result = 0, num;
	char op;
	istringstream iss(my_string);
	
	iss >> result;

	while (iss >> op >> num)
		result += (op == '+') ? num : -num;

    return result;
}
