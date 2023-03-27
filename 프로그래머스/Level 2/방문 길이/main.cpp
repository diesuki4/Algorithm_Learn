#include <iostream>
#include <utility>

#define I(x) ((x) + 5)

using namespace std;

int solution(string dirs);

int main(int argc, char* argv[])
{
    cout << solution("ULURRDLLU") << endl;
    cout << solution("LULLLLLLU") << endl;

    return 0;
}

int solution(string dirs)
{
    int answer = 0;
    bool visited[11][11][11][11] = {false};
    pair<int, int> current = {I(0), I(0)};

    for (char c : dirs)
    {
        pair<int, int> t = current;

        switch (c)
        {
        case 'U':
            if (current.second < I(5))
                current.second += 1;
            break;
        case 'D':
            if (I(-5) < current.second)
                current.second -= 1;
            break;
        case 'R':
            if (current.first < I(5))
                current.first += 1;
            break;
        case 'L':
            if (I(-5) < current.first)
                current.first -= 1;
            break;
        }

        if (t != current && visited[t.first][t.second][current.first][current.second] == false)
        {
            visited[t.first][t.second][current.first][current.second] =
            visited[current.first][current.second][t.first][t.second] = true;

            ++answer;
        }
    }

    return answer;
}
