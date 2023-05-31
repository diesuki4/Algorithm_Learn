#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations);

int main(int argc, char* argv[])
{
    cout << solution({3, 0, 6, 1, 5}) << endl;
    
    return 0;
}

int solution(vector<int> citations)
{
    for (int i = *max_element(citations.begin(), citations.end()); 0 <= i ; --i)
    {
        int t = 0;

        for (int cit : citations)
            t += (i <= cit);

        if (i <= t)
            return i;
    }
}
