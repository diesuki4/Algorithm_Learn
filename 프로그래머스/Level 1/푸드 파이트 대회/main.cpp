#include <iostream>
#include <vector>

using namespace std;

string solution(vector<int> food);

int main(int argc, char* argv[])
{
    cout << solution({1, 3, 4, 6}) << endl;
    cout << solution({1, 7, 1, 2}) << endl;

    return 0;
}

string solution(vector<int> food)
{
    string answer = "0";

    for (int i = food.size() - 1; 0 < i; --i)
    {
        string sub(food[i] / 2, '0' + i);

        answer = sub + answer + sub;
    }

    return answer;
}
