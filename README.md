# acceleratedCplus
- - -
## study1
- - - 
C++ 수업의 연장이다.  
C++ 기본 문법을 끝내고 앤드류 쾨니히의
"Accelerated C++ " 내용의 문법을  
공부함.

- - - 
greeting.cpp 문자 입/출력 기본.
- - - 
clion 을 이용해서 코딩 하는 중.
sudo snap install clion --classic 
으로 코딩.
https://cryptosalamander.tistory.com/135
여러개의 실행 포인트 설정. 
- - -
Clion 에서는 cmake 버전이 3.23 인데 우분투에서는 3.16 이어서 커맨드 라인에선  
실행이 안됨. 
cmake 업데이트를 하려고 햇느데 yum 을 설치 해야 되고 yum 을 설치 하기 위해서  
openssl 을 설치해야함... 그지 같네..
- - - 
개인 노트북에서 wsl2 환경에서 Clion 을 설치 함. 
화면 왼쪽 끝이 모니터 위로 올라가서 불편한 점이 있다.
버츄어 박스에서는 snap 으로 잘 설치가 되던데, wsl2 에서는 snap이 안된다. 설치 파일을 받아서 설치
- - -
## Study2
- - -
* 학생 성적 처리 프로그램을 만듬 score3. 
* 함수로 성적을 처리 . cin 으로 데이터를 입력 받으면서 while 문으로 처리 하는 
연습을 함 레퍼런스의 적절한 이용. 
* auto 키워드에 대한 활용. 범위지정 포문을 쓸 때 안쪽에서 iterator 를 쓰면 
범위가 넘치는 오류가 날 수 도 있다. 
* argument parameter 차이 
* 여러명의 학생 성적을 입력 받아서 처리.
* 분할 컴파일 score4 파일을 median 과 student_info 로 나누어 컴파일.
* 구조체 자료 안에 연산자 중복으로 algorithm 의 sort 사용. 
* algorithm 의 max 사용.
- - -
## Study3
- - -
* 과제 ex4_6 
* 컨테이너 학습. 일관된 아키텍쳐를 사용. iterator.
- - -
## Study4
- - -
* center 함수 추가. study3  split 파일
* algorithm numeric 함수 공부.
  * capacity, reserve, shrink_to_fit
  * remove, remove_if, erase
  * remove_copy, accumulate, transform
  * crbegin() crend() reverse iterator 사용.
- - -
## Study5
- - - 
* 연관 컨테이너 복습 map 사용. pair
* 학생 성적 프로그램을 class 로 변경. 
* 