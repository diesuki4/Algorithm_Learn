#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int dot = 0;
    size_t size = a.size();
    
    for (int i = 0; i < size; ++i)
        dot += a[i] * b[i];
        
    return dot;
}
