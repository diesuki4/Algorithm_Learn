#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string dartResult);

int main(int argc, char* argv[])
{
    cout << solution("1S2D*3T") << endl;
    cout << solution("1D2S#10S") << endl;
    cout << solution("1D2S0T") << endl;
    cout << solution("1S*2T*3S") << endl;
    cout << solution("1D#2S*3S") << endl;
    cout << solution("1T2D3D#") << endl;
    cout << solution("1D2S3T*") << endl;

    return 0;
}

int solution(string dartResult)
{
    char prev = '\0';
    vector<int> points;

    for (char c : dartResult)
    {
        if (isdigit(c))
        {
            if (isdigit(prev))
                points.back() = points.back() * 10 + (c - '0');
            else
                points.emplace_back(c - '0');
        }
        else if (c == '#')
        {
            points.back() *= -1;
        }
        else if (c == '*')
        {
            points.back() *= 2;

            if (2 <= points.size())
                points[points.size() - 2] *= 2;
        }
        else
        {
            int exp = 1;

            switch (c)
            {
            case 'S': exp = 1; break;
            case 'D': exp = 2; break;
            case 'T': exp = 3; break;
            default: break;
            }

            points.back() = pow(points.back(), exp);
        }

        prev = c;
    }

    return points[0] + points[1] + points[2];
}
