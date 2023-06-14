#include <iostream>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4);

int main(int argc, char* argv[])
{
    cout << boolalpha << solution(false, true, true, true) << endl;
    cout << boolalpha << solution(true, false, false, false) << endl;

    return 0;
}

bool solution(bool x1, bool x2, bool x3, bool x4)
{
    return (x1 | x2) & (x3 | x4);
}
