#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> picture, int k);

int main(int argc, char* argv[])
{
    print(solution({".xx...xx.",
                    "x..x.x..x",
                    "x...x...x",
                    ".x.....x.",
                    "..x...x..",
                    "...x.x...",
                    "....x...."}, 2));

    print(solution({"x.x",
                    ".x.",
                    "x.x"}, 3));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << endl;

    cout << endl;
}

vector<string> solution(vector<string> picture, int k)
{
    for (string& pic : picture)
    {
        pic.resize(pic.length() * k);

        for (int i = pic.length(); 0 < i; i -= k)
            fill(pic.begin() + i - k, pic.begin() + i, pic[i / k - 1]);
    }

    picture.resize(picture.size() * k);

    for (int i = picture.size(); 0 < i; i -= k)
        fill(picture.begin() + i - k, picture.begin() + i, picture[i / k - 1]);

    return picture;
}
