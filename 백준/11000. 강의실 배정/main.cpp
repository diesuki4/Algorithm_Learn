#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    // 강의의 시작 시간, 종료 시간을 저장
    vector<pair<int, int>> lecture;
    // 종료가 빠른 시간이 우선순위를 갖는 큐
    priority_queue <int, vector<int>, greater<int>> prQueue;
    
    cin >> N;
    lecture = vector<pair<int, int>>(N);
    
    while (N--)
        cin >> lecture[N].first >> lecture[N].second;
    
    // 시작 시간을 기준으로 정렬 (같으면 종료 시간 기준)
    sort(lecture.begin(), lecture.end());
	
    // 시작 시간이 가장 빠른 강의를 우선순위 큐에 삽입
    prQueue.push(lecture[0].second);
    
    // 시작 시간이 빠른 순으로 2번 째부터 순회
    for (auto it = next(lecture.begin()); it != lecture.end(); ++it)
    {
        // 큐에서 종료가 가장 빠른 시간보다 시작 시간이 크거나 같으면
        // (강의 시간이 겹치지 않으면)
        if (prQueue.top() <= it->first)
            // 강의 배정 가능
            prQueue.pop();

        // 시작 시간을 큐에 삽입
        prQueue.push(it->second);
    }
    
    cout << prQueue.size();
    
    return 0;
}
