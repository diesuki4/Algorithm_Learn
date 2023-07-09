#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

struct music_info;
int to_seconds(string time);
string convert_sheet(string sheet);
music_info parse_info(string info);
bool is_match(string m, music_info info);
string solution(string m, vector<string> musicinfos);

int main(int argc, char* argv[])
{
    cout << solution("ABCDEFG", {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << endl;
    cout << solution("CC#BCC#BCC#BCC#B", {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"}) << endl;
    cout << solution("ABC", {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << endl;

    return 0;
}

struct music_info
{
    int time;
    string name;
    string sheet;
};

int to_seconds(string time)
{
    return stoi(time) * 60 + stoi(time.substr(3));
}

string convert_sheet(string sheet)
{
    string s;

    for (char c : sheet)
        if (c == '#')
            s.back() = tolower(s.back());
        else
            s += c;

    return s;
}

music_info parse_info(string info)
{
    int p = info.find(',');
    music_info msc_info;

    msc_info.time = to_seconds(info.substr(6, 5)) - to_seconds(info.substr(0, 5));
    msc_info.name = info.substr(12, info.find(',', 12) - 12);
    msc_info.sheet = convert_sheet(info.substr(info.find(',', 12) + 1));

    return msc_info;
}

bool is_match(string m, music_info info)
{
    string s;
    int time = info.time;
    int len_sheet = info.sheet.length();
    
    while (0 < time)
    {
        s += string(info.sheet, 0, min(time, len_sheet));

        time -= len_sheet;
    }

    return s.find(m) != string::npos;
}

string solution(string m, vector<string> musicinfos)
{
    map<int, string> mp;

    for (string info : musicinfos)
    {
        music_info msc_info = parse_info(info);

        if (is_match(convert_sheet(m), msc_info))
            if (mp.find(msc_info.time) == mp.end())
                mp[msc_info.time] = msc_info.name;
    }

    return mp.empty() ? "(None)" : mp.rbegin()->second;
}
