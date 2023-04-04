#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> A, vector<int> B);

int main()
{
    cout << solution({1, 4, 2}, {5, 4, 4}) << endl;
    cout << solution({1, 2}, {3, 4}) << endl;

    return 0;
}

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
  
    return inner_product(A.begin(), A.end(), B.begin(), 0);
}
