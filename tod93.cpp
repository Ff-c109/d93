#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string to93(unsigned int d) {
	char res[6];
	int i;
	for(i=0; d != 0; i++) {
		res[i] = (d%93) + 33;
		d/=93;
	}
	res[i]=0;
	if(string(res).length() < 5) {
		res[i++] = ' ';
		res[i] = 0;
	}
	string retv=string(res);
	return retv;
}

int main() {
	unsigned int buffer[86];
	unsigned int* c = new unsigned int;
	bool endof=false;
	bool normal = true;
	while(normal) {
		for(int i = 0; i < 85; i++) {
			for(int i = 0; i < 4; i++) {
				((unsigned char*)c)[i]=( ( ((unsigned char*)c)[i] = getchar() ) == (unsigned char)-1 ? (endof=true),0 : ((unsigned char*)c)[i] );
			}
			//cout << *c << " ";
			if(*c == 0&&endof) {
				buffer[i] = 0;
				normal = false;
				break;
			}
			else {
				buffer[i] = *c;
			}
		}
		if(normal) {
			buffer[85] = 0;
		}
		for(int i=0; buffer[i] != 0; i++) {
			cout << to93(buffer[i]);
			//cout << buffer[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
