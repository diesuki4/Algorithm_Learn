#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b);

int main(int argc, char* argv[])
{
    cout << solution({1, 2, 3, 4}, {-3, -1, 0, 2}) << endl;
    cout << solution({-1, 0, 1}, {1, 0, -1}) << endl;

    return 0;
}

int solution(vector<int> a, vector<int> b)
{
    int dot = 0;
    size_t size = a.size();
    
    for (int i = 0; i < size; ++i)
        dot += a[i] * b[i];
        
    return dot;
}
