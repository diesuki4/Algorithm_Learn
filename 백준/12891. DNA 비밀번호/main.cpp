#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int SlidingWindow(string& DNA, int P, unordered_map<char, int>& umap)
{
    auto check = [&umap]() { for (auto& pr : umap) if (0 < pr.second) return false; return true; };

    int answer = 0;
    
    for (int i = 0; i < P; ++i)
        --umap[DNA[i]];

    answer += check();

    for (int i = P; i < DNA.length(); ++i)
    {
        ++umap[DNA[i - P]];
        --umap[DNA[i]];

        answer += check();
    }

    return answer;
}

int main(int argc, char* argv[])
{
    int P;
    string DNA;
    cin >> P >> P >> DNA;

    unordered_map<char, int> umap;
    cin >> umap['A'] >> umap['C'] >> umap['G'] >> umap['T'];

    cout << SlidingWindow(DNA, P, umap);

    return 0;
}
