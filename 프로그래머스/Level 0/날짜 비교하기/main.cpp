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
    if (date1[0] < date2[0])
    {
        return 1;
    }
    else if (date1[0] > date2[0])
    {
        return 0;
    }
    else if (date1[1] < date2[1])
    {
        return 1;
    }
    else if (date1[1] > date2[1])
    {
        return 0;
    }
    else if (date1[2] < date2[2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
