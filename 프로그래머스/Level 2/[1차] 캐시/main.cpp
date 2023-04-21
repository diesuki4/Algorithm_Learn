#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities);

int main(int argc, char* argv[])
{
    cout << solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl;
    cout << solution(3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}) << endl;
    cout << solution(2, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl;
    cout << solution(5, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl;
    cout << solution(2, {"Jeju", "Pangyo", "NewYork", "newyork"}) << endl;
    cout << solution(0, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl;

    return 0;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    list<string> lst;

    if (cacheSize == 0)
        return cities.size() * 5;

    for (string& city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        auto it = find(lst.begin(), lst.end(), city);

        if (it == lst.end())
        {
            answer += 5;

            if (cacheSize <= lst.size())
                lst.erase(lst.begin());
        }
        else
        {
            answer += 1;

            lst.erase(it);
        }

        lst.emplace_back(city);
    }

    return answer;
}
