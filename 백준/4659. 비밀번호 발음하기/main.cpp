#include <iostream>
#include <algorithm>

using namespace std;

bool isConsonant(char ch);
bool isVowel(char ch);
bool hasConsonant(string passwd);
bool isThreeConVowConsecutive(string passwd);
bool isTwoLettersConsecutive(string passwd);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string passwd;

	cin >> passwd;

	while (passwd != "end")
	{
		cout << '<' << passwd << '>' << " is ";

		if (!hasConsonant(passwd) || isThreeConVowConsecutive(passwd) || isTwoLettersConsecutive(passwd))
			cout << "not ";

		cout << "acceptable.\n";

		cin >> passwd;
	}

	return 0;
}

bool isConsonant(char ch)
{
	char consonant[] = {'a', 'e', 'i', 'o', 'u'};
	int N = sizeof(consonant) / sizeof(char);

	return find(consonant, consonant + N, ch) != consonant + N;
}

bool isVowel(char ch)
{
	if ('a' <= ch && ch <= 'z')
		return !isConsonant(ch);
	else
		return false;
}

bool hasConsonant(string passwd)
{
	for (char ch : passwd)
		if (isConsonant(ch))
			return true;

	return false;
}

bool isThreeConVowConsecutive(string passwd)
{
	int end;

	passwd += (passwd.length() < 3) ? "!@" : "";
	end = passwd.length() - 2;

	for (int i = 0; i < end; ++i)
		if (isConsonant(passwd[i]) && isConsonant(passwd[i + 1]) && isConsonant(passwd[i + 2]))
			return true;
		else if (isVowel(passwd[i]) && isVowel(passwd[i + 1]) && isVowel(passwd[i + 2]))
			return true;

	return false;
}

bool isTwoLettersConsecutive(string passwd)
{
	int end;
	
	passwd += (passwd.length() < 2) ? " " : "";
	end = passwd.length() - 1;

	for (int i = 0; i < end; ++i)
		if (passwd[i] != 'e' && passwd[i] != 'o')
			if (passwd[i] == passwd[i + 1])
				return true;

	return false;
}
