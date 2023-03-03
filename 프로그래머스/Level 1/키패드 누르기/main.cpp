#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x;
    int y;

    int operator - (const Pos& p)
    {
        return abs(x - p.x) + abs(y - p.y);
    }
};

Pos position(int key)
{
    key = (key == 0) ? 11 : key;

    return Pos{--key % 3, key / 3};
}

int distance(int x, int y)
{
    return position(x) - position(y);
}

string solution(vector<int> numbers, string hand);

int main(int argc, char* argv[])
{
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;
    cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left") << endl;
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right") << endl;

    return 0;
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int L = 10, R = 12;

    for (int num : numbers)
    {
        switch (num)
        {
        case 1: case 4: case 7:
            L = num;
            answer += "L";
            break;
        case 3: case 6: case 9:
            R = num;
            answer += "R";
            break;
        case 2: case 5: case 8: case 0:
        {
            int distL = distance(L, num);
            int distR = distance(R, num);

            if (distL < distR)
            {
                L = num;
                answer += "L";
            }
            else if (distL > distR)
            {
                R = num;
                answer += "R";
            }
            else if (hand == "left")
            {
                L = num;
                answer += "L";
            }
            else if (hand == "right")
            {
                R = num;
                answer += "R";
            }
            break;
        }
        default:
            break;
        }
    }

    return answer;
}
