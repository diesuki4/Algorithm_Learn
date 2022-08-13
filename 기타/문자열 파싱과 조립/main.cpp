#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char sep)
{
	int pos;
	vector<string> v;

	// 구분자가 없을 때까지 반복
	while ((pos = str.find(sep)) != string::npos)
	{
		// 가장 앞의 단어를 벡터에 삽입
		v.push_back(str.substr(0, pos));
		// 찾은 구분자 다음 위치부터 다시 탐색
		str = str.substr(++pos);
	}

	// 마지막 단어를 삽입
	v.push_back(str);

	return v;
}

int main(int argc, char* argv[])
{
	///////////////////////////////////
	// 일반적인 입출력
	///////////////////////////////////
	int n1, n2;

	cin >> n1 >> n2;

	cout << n1 << " " << n2 << endl;

	///////////////////////////////////
	// 특정 구분자로 파싱할 때 istringstream 을 사용할 수 있다.
	// 공백을 기준으로 할 경우
	///////////////////////////////////
	string s1, s2;

	string line = "Hello world 12 34";

	/* 입력 스트림을 만들고 */
	istringstream iss(line);

	/* cin 대신 istringstream 을 통해 입력받는다. */
	/* (자동으로 공백/개행 등으로 구분) */
	iss >> s1 >> s2 >> n1 >> n2;

	cout << s1 << " " << s2 << " " << n1 << " " << n2 << endl;

	///////////////////////////////////
	// 이외의 구분자로 파싱할 경우
	///////////////////////////////////
	string str;
	line = "aaa,bbb,1234,!!";

	/* 입력 스트림을 만들고 */
	iss = istringstream(line);

	/* , 을 구분자로 하여 입력 */
	while (getline(iss, str, ','))
		cout << str << " ";
	cout << endl;

	for (string s : split(line, ','))
		cout << s << " ";
	cout << endl;

	///////////////////////////////////
	// 다른 형식의 값들을 문자열로 합칠 때 ostringstream 을 사용할 수 있다.
	///////////////////////////////////
	s1 = "abc";
	s2 = "bcd";
	float f = 6;
	double d = 3.14;

	/* 출력 스트림을 만들고 */
	ostringstream oss;

	/* cout 대신 ostringstream 에 출력한다. */
	oss << s1 << " " << s2 << " " << f << " " << d;

	/* oss 에 출력한 것들을 문자열로 변환 */
	cout << oss.str() << endl;

	return 0;
}
