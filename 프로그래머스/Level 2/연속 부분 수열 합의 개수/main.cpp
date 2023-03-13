#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int solution(vector<int> elements);

int main(int argc, char* argv[])
{
    cout << solution({7, 9, 1, 1, 4}) << endl;

    return 0;
}

int solution(vector<int> elements)
{
    size_t size = elements.size();
    unordered_set<int> uset;

    elements.insert(elements.end(), elements.begin(), elements.end());

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            uset.emplace(accumulate(elements.begin() + j, elements.begin() + i + j, 0));

    return uset.size();
}
