#include <iostream>
#include <unordered_map>

using namespace std;

string solution(string s, string skip, int index);

int main(int argc, char* argv[])
{
    cout << solution("aukks", "wbqd", 5) << endl;

    return 0;
}

string solution(string s, string skip, int index)
{
    unordered_map<char, bool> umap;

    for (char c : skip)
        umap[c] = true;

    for (char& c : s)
    {
        int n = index;

        while (n)
            if (umap[c = 'a' + (++c - 'a') % 26] == false)
                --n;
    }

    return s;
}
