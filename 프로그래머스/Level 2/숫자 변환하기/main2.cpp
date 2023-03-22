#include <iostream>
#include <set>
#include <utility>

using namespace std;

int solution(int x, int y, int n);

int main(int argc, char* argv[])
{
    cout << solution(10, 40, 5) << endl;
    cout << solution(10, 40, 30) << endl;
    cout << solution(2, 5, 4) << endl;

    return 0;
}

int solution(int x, int y, int n)
{
    int answer = 0;
    auto op1 = [n](int x) { return x + n; };
    auto op2 = [ ](int x) { return x + x; };
    auto op3 = [ ](int x) { return x + x + x; };
    set<int> st1, st2;

    st1.emplace(x);

    while (!st1.empty() || !st2.empty())
    {
        set<int>& st = (st1.empty()) ? st2 : st1;
        set<int>& stE = (st1.empty()) ? st1 : st2;

        for (int e : st)
        {
            if (e == y)
                return answer;
            else if (y < e)
                continue;

            stE.emplace(op1(e)),
            stE.emplace(op2(e)),
            stE.emplace(op3(e));
        }

        st.clear();
        ++answer;
    }

    return -1;
}
