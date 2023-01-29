#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sides);

int main(int argc, char* argv[])
{
    cout << solution({1, 2}) << endl;
    cout << solution({3, 6}) << endl;
    cout << solution({11, 7}) << endl;

    return 0;
}

int solution(vector<int> sides)
{
    return (sides[0] + sides[1]) - abs(sides[0] - sides[1]) - 1;
}
