#include <iostream>
using namespace std;
int main() {
	const int Size=15;
	char name1[Size];
	char name2[Size] = "C++programing";

	cout << "안녕하세요, 저는 " << name2 << "입니다. 당신의 이름은? " << endl;
	cin.getline(name1,Size) >> name1;
	cout << name1 << "님의 이름이 " << Size << "바이트 크기의 배열에 저장되었습니다." << endl;
	cout << "이름이 " << name1[0] << "자로 시작하는군요." << endl;
	cout << "제 이름의 첫글자는 " << name2[0] << "이랍니다." << endl;

	return 0;
}