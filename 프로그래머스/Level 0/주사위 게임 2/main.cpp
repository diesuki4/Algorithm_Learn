#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int a, int b, int c);

int main(int argc, char* argv[])
{
    cout << solution(2, 6, 1) << endl;
    cout << solution(5, 3, 3) << endl;
    cout << solution(4, 4, 4) << endl;

    return 0;
}

int solution(int a, int b, int c)
{
    unordered_set<int> uset;

    uset.emplace(a);
    uset.emplace(b);
    uset.emplace(c);
    
    if (uset.size() == 3)
        return (a + b + c);
    else if (uset.size() == 2)
        return (a + b + c) * (a*a + b*b + c*c);
    else
        return (a + b + c) * (a*a + b*b + c*c) * (a*a*a + b*b*b + c*c*c);
}
