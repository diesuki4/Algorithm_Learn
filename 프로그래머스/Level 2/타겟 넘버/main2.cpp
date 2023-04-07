#include <iostream>
#include <vector>

using namespace std;

int rDFS(vector<int>& numbers, int target, int sum, int n);
int solution(vector<int> numbers, int target);

int main(int argc, char* argv[])
{
    cout << solution({1, 1, 1, 1, 1}, 3) << endl;
    cout << solution({4, 1, 2, 1}, 4) << endl;

    return 0;
}

int rDFS(vector<int>& numbers, int target, int sum, int n)
{
    if (numbers.size() <= n)
        return (sum == target);

    return rDFS(numbers, target, sum + numbers[n], n + 1) +
           rDFS(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target)
{
    return rDFS(numbers, target, 0, 0);
}
