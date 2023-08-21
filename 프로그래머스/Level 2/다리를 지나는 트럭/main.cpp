#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(int argc, char* argv[])
{
    cout << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;

    return 0;
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int nTrucks = truck_weights.size(), nPassed = 0, nWeight = 0;
    deque<int> trucks(truck_weights.begin(), truck_weights.end()), bridge(bridge_length, 0);

    while (nPassed != nTrucks)
    {
        if (int elem = bridge.front())
            ++nPassed, nWeight -= elem;

        bridge.pop_front();

        if (trucks.empty())
        {
            ;
        }
        else if (nWeight + trucks.front() <= weight)
        {
            nWeight += trucks.front();
            bridge.emplace_back(trucks.front());
            trucks.pop_front();
        }
        else
        {
            bridge.emplace_back(0);
        }

        ++answer;
    }

    return answer;
}
