#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print(vector<string> result);
vector<string> solution(vector<string> files);

int main(int argc, char* argv[])
{
    print(solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"}));
    print(solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"}));

    return 0;
}

void print(vector<string> result)
{
    for (string e : result)
        cout << e << ", ";

    cout << endl;
}

vector<string> solution(vector<string> files)
{
    auto parse = [](const string& s) -> pair<string, int>
    {
        pair<string, int> pr;

        auto it = find_if(s.begin(), s.end(), ::isdigit);
        pr.first = string(s.begin(), it);
        transform(pr.first.begin(), pr.first.end(), pr.first.begin(), ::tolower);

        auto it2 = find_if_not(it, s.end(), ::isdigit);
        pr.second = stoi(string(it, it2));

        return pr;
    };

    stable_sort(files.begin(), files.end(), [&parse](const string& a, const string& b)
    {
        pair<string, int> prA = parse(a), prB = parse(b);

        if (prA.first == prB.first)
            return prA.second < prB.second;
        else
            return prA.first < prB.first;
    });

    return files;
}
