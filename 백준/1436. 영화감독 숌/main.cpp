#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	int i, N;

	cin >> N;

	for (i = 666; 0 < N; ++i)
		if (to_string(i).find("666") != string::npos)
			--N;

	cout << --i;

	return 0;
}
