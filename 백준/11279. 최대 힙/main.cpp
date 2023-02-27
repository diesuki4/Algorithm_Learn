#include <iostream>
#include <queue>
#include <sstream>

using namespace std;
using uint = unsigned int;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<uint> prque;
    ostringstream oss;

    cin >> N;

    while (N--)
    {
        uint num;
        cin >> num;

        if (num)
        {
            prque.emplace(num);
        }
        else if (prque.empty())
        {
            oss << 0 << "\n";
        }
        else
        {
            oss << prque.top() << "\n";
            prque.pop();
        }
    }

    cout << oss.str();

    return 0;
}
