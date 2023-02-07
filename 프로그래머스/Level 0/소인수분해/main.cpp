#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(12));
    print(solution(17));
    print(solution(420));

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
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            set<int> st = {i};
            vector<int> v = solution(n / i);

            st.insert(v.begin(), v.end());

            return vector<int>(st.begin(), st.end());
        }
    }

    return vector<int>({n});
}
