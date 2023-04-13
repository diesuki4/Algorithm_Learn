#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int brown, int yellow);

int main(int argc, char* argv[])
{
    print(solution(10, 2));
    print(solution(8, 1));
    print(solution(24, 24));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int brown, int yellow)
{
    float h = 0;

    while (2 * ++h + 2 * yellow / h + 4 != brown);

    return vector<int> {yellow / int(h) + 2, int(h) + 2};
}
