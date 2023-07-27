#include <iostream>
#include <algorithm>

using namespace std;

int solution(int storey);

int main(int argc, char* argv[])
{
    cout << solution(16) << endl;
    cout << solution(2554) << endl;

    return 0;
}

int solution(int storey)
{
    if (storey < 10)
        return min(storey, 11 - storey);

    int left = storey % 10;

    return min(left + solution(storey / 10), 10 - left + solution(storey / 10 + 1));
}
