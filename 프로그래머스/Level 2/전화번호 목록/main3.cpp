#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book);

int main(int argc, char* argv[])
{
    cout << boolalpha << solution({"119", "97674223", "1195524421"}) << endl;
    cout << boolalpha << solution({"123", "456", "789"}) << endl;
    cout << boolalpha << solution({"12", "123", "1235", "567", "88"}) << endl;

    return 0;
}

bool solution(vector<string> phone_book)
{
    size_t size = phone_book.size();
    unordered_map<string, bool> umap;

    for (string& phone : phone_book)
        umap[phone] = true;

    for (string& phone : phone_book)
    {
        string t = "";

        for (char digit : phone)
        {
            t += digit;

            if (umap[t] && phone != t)
                return false;
        }
    }

    return true;
}
