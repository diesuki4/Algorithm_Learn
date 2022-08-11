#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int a, b;
    string s;
    
    cin >> a >> b;
    
    s = string(a, '*');
    
    for (int i = 0; i < b; ++i)
        cout << s << endl;   
    
    return 0;
}
