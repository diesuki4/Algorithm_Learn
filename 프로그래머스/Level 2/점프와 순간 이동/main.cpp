// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <set>

using namespace std;

void rSolution(int bat, int cur, int n, set<int>& st);
int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    cout << solution(5000) << endl;
    
    return 0;
}

void rSolution(int bat, int cur, int n, set<int>& st)
{
    if (n <= cur)
    {
        if (n == cur)
            st.emplace(bat);

        return;
    }

    for (int i = 1; i <= n - cur; ++i)
        rSolution(bat + i, cur + i, n, st);

    if (cur)
        rSolution(bat, cur * 2, n, st);
}

int solution(int n)
{
    set<int> st;

    rSolution(0, 0, n, st);

    return *st.begin();
}
