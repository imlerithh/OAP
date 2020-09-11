#include<iostream>
using namespace std;
#define THROW01 "Create: Превышен размер имени словаря"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL,"rus");
	char c = 'Е';
	unsigned char cc = c;
	cout << (int)c << "  " << (int)(unsigned char)c;

	return 0;

}