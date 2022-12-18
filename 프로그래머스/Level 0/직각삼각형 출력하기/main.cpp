#include <iostream>
#include <sstream>

using namespace std;

string solution(int n);

int main(int argc, char* argv[])
{
    int n;

    cin >> n;

    cout << solution(n);

    return 0;
}

string solution(int n)
{
	ostringstream oss;
    
	for (int i = 1; i <= n; ++i)
		oss << string(i, '*') << endl;

	return oss.str();
}
