#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> v(N + 1, 0);
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    int M;
    cin >> M;

    while (M--)
    {
        int s, e;
        cin >> s >> e;
        
        cout << (v[e] - v[s - 1]) << "\n";
    }

    return 0;
}
