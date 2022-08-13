# Algorithm_Learn
### 2022-08-11 (목)
문자열 파싱과 조립
- 문자열
- 파싱

<br>

- #### stringstream, istringstream, ostringstream 의 차이
```
istringstream : 값을 입력받을 수 있는 입력 스트림

ostringstream : 값을 출력할 수 있는 출력 스트림

stringstream
- istringstream 과 ostringstream 의 다중 상속
- >>(입력) 과 <<(출력) 모두에 사용할 수 있지만, 입출력 방향을 헷갈린 경우 오류를 표시해주지 않는다.
- 위 2개에 비해 성능이 다소 떨어진다.
- istringstream 과 ostringstream 으로 명시적으로 사용하는 것이 좋다.
```
[Why not use stringstream in every case?](https://stackoverflow.com/questions/3292107/whats-the-difference-between-istringstream-ostringstream-and-stringstream-w#answer-3292157)

[What is the difference between istringstream, ostringstream and stringstream?](https://www.reddit.com/r/cpp_questions/comments/jq6pum/what_is_the_difference_between_istringstream/)

<br>

- #### [find 와 substr 을 활용해 파싱하는 방법](https://github.com/icarusw-code/AlgoStudy_Mtvs/blob/sj/%EA%B0%9C%EB%85%90%EC%A0%95%EB%A6%AC/%EB%AC%B8%EC%9E%90%EC%97%B4.md#split)<br>※ 하나의 문자가 아닌, 문자열로 이루어진 구분자에도 사용할 수 있다.

<br>

- #### 하나의 문자로 이루어진 구분자를 기준으로 파싱하는 방법<br>※ 구분자가 연속으로 있는 경우 빈 문자열이 저장되므로 주의
```
#include <vector>
#include <sstream>

vector<string> split(string input, char delimiter)
{
	string token;
	vector<string> ret;
	istringstream iss(input);
	
	while (getline(iss, token, delimiter))
		ret.push_back(token);

	return ret;
}
```

```
#include <iostream>

using namespace std;

void main()
{
	string input;
	vector<string> v;
	
	input = "aa,bb,cc,dd";
	v = split(input, ',');

	input = ",aa,,bb,,cc,,dd,,";
	v = split(input, ',');
}
```

실행 결과
```
"aa,bb,cc,dd"
["aa", "bb", "cc", "dd"]

",aa,,bb,,cc,,dd,,"
["", "aa", "", "bb", "", "cc", "", "dd", ""]
```

<br>

- #### 공백을 기준으로 파싱하는 방법<br>※ 앞/뒤 혹은 연속적인 공백이 존재해도 사용할 수 있다.
```
#include <vector>
#include <sstream>

vector<string> split_blank(string input)
{
	string token;
	vector<string> ret;
	istringstream iss(input);
	
	while (iss >> token)
		ret.push_back(token);

	return ret;
}
```

```
#include <iostream>

using namespace std;

void main()
{
	string input;
	vector<string> v;
	
	input = "aa bb cc dd";
	v = split_blank(input);

	input = " aa  bb  cc  dd  ";
	v = split_blank(input);
}
```

실행 결과
```
"aa bb cc dd"
["aa", "bb", "cc", "dd"]

" aa  bb  cc  dd  "
["aa", "bb", "cc", "dd"]
```

<br>

- #### 형이 다른 값들을 문자열로 합치는 방법
```
#include <sstream>

void example()
{
	string s	= "Hello";
	int i		= 123;
	string ss	= "World";
	float f		= 6.0;
	string sss	= "!!";
	double d	= 3.14;

	ostringstream oss;

	oss << s << i << ss << f << sss << d;

	cout << oss.str();
}
```

실행 결과
```
Hello123World6!!3.14
```
