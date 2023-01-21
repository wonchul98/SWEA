#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream fout;
	fout.open("input2.txt");
	for (int i = 0; i < 99999; i++) {
		fout << i + 2 << ' ';
	}
	return 0;
}