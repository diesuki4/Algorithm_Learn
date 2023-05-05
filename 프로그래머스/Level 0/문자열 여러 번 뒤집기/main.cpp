#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    cout << solution("rermgorpsam", {{2, 3}, {0, 7}, {5, 9}, {6, 10}}) << endl;

    return 0;
}

string solution(string my_string, vector<vector<int>> queries)
{
    for (vector<int>& query : queries)
        reverse(my_string.begin() + query[0], my_string.begin() + ++query[1]);

    return my_string;
}
