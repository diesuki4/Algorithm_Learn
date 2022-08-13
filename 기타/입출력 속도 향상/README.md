# Algorithm_Learn
### 2022-08-13 (토)
입출력 속도 향상
- 팁

<br>

- #### cout << answer << endl 은 사실 다음과 같다.
```
cout << answer << '\n' << flush;
```
개행 문자 출력 후 매번 flush 를 수행하기 때문에, 시간 초과의 원인이 될 수 있다.

<br>

- #### ostringstream 을 이용해 개선하는 방법
```
#include <sstream>

void printA(int i)
{
    ostringstream oss;
    
    while (0 < i--)
        oss << "A" << endl;
      
    cout << oss.str();
}
```
flush 를 하되, 출력하지는 않다가 한 번에 출력하는 것이다.

<br>

- #### 더 좋은 방법은 그냥 '\n' 을 출력하는 것이다.
```
void printA(int i)
{
    while (0 < i--)
        cout << "A" << '\n';
}
```

<br>

- #### 추가적인 입출력 속도 최적화
C 와 C++ 의 입출력 동기화를 해제하고 독립적인 버퍼를 사용하도록 한다.<br>
입출력 속도는 향상되지만, cin/cout 을 scanf/printf/getchar 등과 함께 사용할 수 없게 된다.
```
ios_base::sync_with_stdio(false);
```
cin 이 입력을 받기 전에 cout 을 flush 하는 tie 동작을 수행하지 않도록 한다.
```
cin.tie(NULL);
```
[[C++] sync_with_stdio() 와 cin.tie()](https://nerdooit.github.io/2020/06/20/cpp_fastio.html)
[cout, cin 최적화 방법과 주의점](https://leeeegun.tistory.com/4)
