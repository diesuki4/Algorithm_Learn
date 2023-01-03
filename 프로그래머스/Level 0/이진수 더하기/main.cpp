#include <iostream>
#include <bitset>

using namespace std;

string solution(string bin1, string bin2);

int main(int argc, char* argv[])
{
	cout << solution("10", "11") << endl;
	cout << solution("1001", "1111") << endl;

	return 0;
}

string solution(string bin1, string bin2)
{
	const int bits = sizeof(unsigned long) << 3;

    unsigned long num1 = bitset<bits>(bin1).to_ulong();
	unsigned long num2 = bitset<bits>(bin2).to_ulong();

	string result = bitset<bits>(num1 + num2).to_string();
	size_t first1 = result.find_first_not_of('0');

    return (first1 == string::npos) ? "0" : result.substr(first1);
}
