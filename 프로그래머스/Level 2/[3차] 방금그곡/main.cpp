// 이 풀이는 오답 처리된다.
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
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

    cout << solution("ABCDEFG", {"11:50,12:04,HELLO,CDEFGAB", "12:57,13:11,BYE,CDEFGAB"}) << endl;

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
    vector<string> v;
    istringstream iss(regex_replace(info, regex(","), " "));

    while (iss >> info)
        v.emplace_back(info);

    music_info msc_info;
    msc_info.time = to_seconds(v[1]) - to_seconds(v[0]);
    msc_info.name = v[2];
    msc_info.sheet = convert_sheet(v[3]);

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
