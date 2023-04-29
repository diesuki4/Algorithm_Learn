#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2);

int main(int argc, char* argv[])
{
    cout << solution({2021, 12, 28}, {2021, 12, 29}) << endl;
    cout << solution({1024, 10, 24}, {1024, 10, 24}) << endl;

    return 0;
}

int solution(vector<int> date1, vector<int> date2)
{
    auto days = [](vector<int>& date) { return date[0] * 12 * 31 + date[1] * 31 + date[2]; };

    return days(date1) < days(date2);
}
