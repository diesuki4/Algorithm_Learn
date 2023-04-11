// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(phone_book.begin(), phone_book.end(), [](string a, string b) { return a.length() < b.length(); });

    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j)
            if (phone_book[j].find(phone_book[i]) == 0)
                return false;

    return true;
}
