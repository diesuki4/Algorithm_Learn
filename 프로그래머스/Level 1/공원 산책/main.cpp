#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> park, vector<string> routes);

int main(int argc, char* argv[])
{
    print(solution({"SOO", "OOO", "OOO"}, {"E 2", "S 2", "W 1"}));
    print(solution({"SOO", "OXX", "OOO"}, {"E 2", "S 2", "W 1"}));
    print(solution({"OSO", "OOO", "OXO", "OOO"}, {"E 2", "S 3", "W 1"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> current(2);
    int H = park.size(), W = park.front().length();

    auto dir = [](string& s) -> vector<int>
    {
        switch (s[0])
        {
        case 'E': return vector<int> {0, 1};
        case 'W': return vector<int> {0, -1};
        case 'S': return vector<int> {1, 0};
        case 'N': return vector<int> {-1, 0};
        }
    };

    auto dist = [](string& s) { return s[2] - '0'; };

    auto check_obstacle = [](vector<int>& current, vector<string>& park, vector<int>& direction) -> bool
    {
        int start = (0 <= direction[0]) ? current[0] : current[0] + direction[0];
        int end   = (0 <= direction[0]) ? current[0] + direction[0] : current[0];

        for (int h = start; h <= end; ++h)
            if (park[h][current[1]] == 'X')
                return true;

        start = (0 <= direction[1]) ? current[1] : current[1] + direction[1];
        end   = (0 <= direction[1]) ? current[1] + direction[1] : current[1];

        for (int w = start; w <= end; ++w)
            if (park[current[0]][w] == 'X')
                return true;

        return false;
    };

    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            if (park[h][w] == 'S')
            {
                current[0] = h;
                current[1] = w;
                h = H;
                w = W;
            }
        }
    }

    for (string& route : routes)
    {
        vector<int> direction = dir(route);
        int distance = dist(route);
        
        direction[0] *= distance;
        direction[1] *= distance;

        if (current[0] + direction[0] < 0 || H <= current[0] + direction[0])
            continue;
        else if (current[1] + direction[1] < 0 || W <= current[1] + direction[1])
            continue;
        else if (check_obstacle(current, park, direction))
            continue;

        current[0] += direction[0];
        current[1] += direction[1];
    }

    return current;
}
