#include <iostream>

using namespace std;

void solution(int a, int b);

int main(int argc, char* argv[])
{
    int a, b;
    
    cin >> a >> b;
    
    solution(a, b);

    return 0;
}

void solution(int a, int b)
{
    string s = string(a, '*');

    for (int i = 0; i < b; ++i)
        cout << s << endl;   
}
