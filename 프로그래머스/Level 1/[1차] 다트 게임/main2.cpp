#include <iostream>
#include <sstream>
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
    int points[4] = {0};
    istringstream iss(dartResult);

    for (int i = 1; i <= 3; i++)
    {
        int point;

        iss >> point;

        switch (iss.get())
        {
        case 'S': points[i] = pow(point, 1); break;
        case 'D': points[i] = pow(point, 2); break;
        case 'T': points[i] = pow(point, 3); break;
        default: break;
        }

        switch (iss.get())
        {
        case '*': points[i - 1] *= 2; points[i] *= 2; break;
        case '#': points[i] *= -1; break;
        default: iss.unget(); break;
        }
    }

    return points[1] + points[2] + points[3];
}
