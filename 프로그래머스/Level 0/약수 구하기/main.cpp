#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(24));
    print(solution(29));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << ' ';
    cout << endl;
}

vector<int> solution(int n)
{
    float square_root = sqrt(n);
    set<int> st = {1, n};

    for (int i = 2; i <= square_root; ++i)
        if ( (n % i) == 0 )
            st.insert({i, n / i});

    return vector<int>(st.begin(), st.end());
}
