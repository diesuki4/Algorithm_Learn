#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr);

int main(int argc, char* argv[])
{
    cout << solution({"a", "bc", "d", "efg", "hi"}) << endl;

    return 0;
}

int solution(vector<string> strArr)
{
    int answer = 0;
    int *arr = new int[100'001]();

    for (string s : strArr)
        answer = max(answer, ++arr[s.length()]);

    delete[] arr;

    return answer;
}
