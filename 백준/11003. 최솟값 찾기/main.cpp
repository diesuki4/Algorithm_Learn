#include <iostream>
#include <queue>

using namespace std;

struct Elem
{
    int idx;
    int data;

    friend bool operator < (const Elem& A, const Elem& B) { return A.data > B.data; }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    priority_queue<Elem> prQue;

    cin >> N >> L;

    for (int i = 0; i < N; ++i)
    {
        int data;

        cin >> data;
        prQue.push({i, data});

        while (prQue.top().idx <= i - L)
            prQue.pop();

        cout << prQue.top().data << " ";
    }

    return 0;
}
