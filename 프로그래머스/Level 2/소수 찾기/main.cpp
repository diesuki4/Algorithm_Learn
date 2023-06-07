#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

vector<vector<char>> C(vector<char>& v, int n, int r);
bool is_prime(int num);
int solution(string numbers);

int main(int argc, char* argv[])
{
    cout << solution("17") << endl;
    cout << solution("011") << endl;

    return 0;
}

vector<vector<char>> C(vector<char>& v, int n, int r)
{
    set<vector<char>> st;
    vector<int> bitMask(n, 0);

    fill(bitMask.end() - r, bitMask.end(), 1);

    do
    {
        vector<char> t;

        for (auto it = find(bitMask.begin(), bitMask.end(), 1); it != bitMask.end(); it = find(++it, bitMask.end(), 1))
            t.emplace_back(v[it - bitMask.begin()]);

        sort(t.begin(), t.end());
        st.emplace(t);
    } while (next_permutation(bitMask.begin(), bitMask.end()));

    return vector<vector<char>>(st.begin(), st.end());
}

bool is_prime(int num)
{
    float last = sqrt(num);

    for (int i = 2; i <= last; ++i)
        if (num % i == 0)
            return false;

    return 1 < num;
}

int solution(string numbers)
{
    set<int> st;
    vector<char> v(numbers.begin(), numbers.end());

    for (int r = 1; r <= v.size(); ++r)
    {
        for (vector<char>& comb : C(v, v.size(), r))
        {
            do
            {
                int num = stoi(string(comb.begin(), comb.end()));

                if (is_prime(num))
                    st.emplace(num);
            }
            while (next_permutation(comb.begin(), comb.end()));
        }
    }

    return st.size();
}
