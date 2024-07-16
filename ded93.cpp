#include <iostream>
#include <string>
#include <math.h>

using namespace std;

unsigned int de93(char* d93) {
	unsigned int d=0;
	for(int i=0; d93[i] != 0; i++) {
		d += (d93[i]-33)*pow(93, i);
	}
	return d;
}
		

int main() {
	char d93[6];
	int c;
	int counter = 0;
	while(c = getchar(), c!=-1) {
		if(c == ' ') {
			d93[counter++] = 0;
			auto outputBuffer = new unsigned int;
			*outputBuffer = de93(d93);
			for(int i=0; i<4; i++) {
				cout << ((unsigned char*)outputBuffer)[i];
			}
			//cout << d93 << " ";
			//cout << *outputBuffer << " ";
			counter=0;
		}
		else if(counter < 5) {
			d93[counter++] = c;
		}
		else {
			d93[counter++]=0;
			auto outputBuffer = new unsigned int;
			*outputBuffer = de93(d93);
			for(int i=0; i<4; i++) {
				cout << ((unsigned char*)outputBuffer)[i];
			}
			//cout << d93 << " ";
			//cout << *outputBuffer << " ";
			counter=0;
			d93[counter++]=c;
		}
	}
	return 0;
}
