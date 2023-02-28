#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool students[31] = {false};

    for (int i = 0; i < 28; ++i)
    {
        int id;

        cin >> id;

        students[id] = true;
    }

    for (int i = 1; i <= 30; ++i)
        if (students[i] == false)
            cout << i << "\n";

    return 0;
}
