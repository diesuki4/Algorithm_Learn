#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    vector<pair<int, int>> vec;
    priority_queue <int, vector<int>, greater<int>> prQueue;
    
    cin >> N;
    vec = vector<pair<int, int>>(N);
    
    while (N--)
        cin >> vec[N].first >> vec[N].second;
    
    sort(vec.begin(), vec.end());
	
    prQueue.push(vec[0].second);
    
    for (auto it = next(vec.begin()); it != vec.end(); ++it)
    {
        if (prQueue.top() <= it->first)
            prQueue.pop(),
            prQueue.push(it->second);
        else
            prQueue.push(it->second);
    }
    
    cout << prQueue.size();
    
    return 0;
}
