#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Record;

void print(vector<int> result);
vector<int> solution(vector<int> fees, vector<string> records);

int main(int argc, char* argv[])
{
    print(solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"}));
    print(solution({120, 0, 60, 591}, {"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"}));
    print(solution({1, 461, 1, 10}, {"00:00 1234 IN"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

struct Record
{
    int time;
    int carId;
    bool isIn;

    Record(string record)
    {
        time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        carId = stoi(record.substr(6, 4));
        isIn = (record[11] == 'I');
    }
};

vector<int> solution(vector<int> fees, vector<string> records)
{
    int defaultTime = fees[0], defaultFee = fees[1];
    float extraTime = fees[2], extraFee = fees[3];
    auto calculateFee = [&](int totalTime) -> int
    {
        return defaultFee + max(0.F, ceil((totalTime - defaultTime) / extraTime)) * extraFee;
    };

    vector<int> answer;
    map<int, int> inTime;
    map<int, int> fee;

    for (string record : records)
    {
        Record r(record);

        if (r.isIn)
        {
            inTime[r.carId] = r.time;
        }
        else
        {
            fee[r.carId] += r.time - inTime[r.carId];

            inTime[r.carId] = -1;
        }
    }

    answer.reserve(fee.size());

    for (auto& pr : inTime)
    {
        if (pr.second != -1)
            fee[pr.first] += (1439 - pr.second);

        answer.emplace_back(calculateFee(fee[pr.first]));
    }

    return answer;
}
