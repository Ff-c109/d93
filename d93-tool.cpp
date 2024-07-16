#include <iostream>
#include <string>
#include <math.h>

namespace d93 {
	using namespace std;
	string to93(unsigned int d) {
		char res[6];
		int i;
		for(i=0; d!=0; i++) {
			res[i] = (d%93) + 33;
			d/=93;
		}
		res[i]=0;
		if(string(res).length() < 5) {
			res[i++] = ' ';
			res[i] = 0;
		}
		string retv=res;
		return retv;
	}
	string enc(string input) {
		unsigned int buffer[86];
		auto c = new unsigned int;
		bool endOfFile=false;
		bool normal=true;
		string retv;
		int p=0;
		auto getchar = [&]() {
			if(input[p] == 0)  {
				return -1;
			}
			else {
				return (int)(input[p++]);
			}
		};
		while(normal) {
			for(int i = 0; i < 85; i++) {
				for(int i = 0; i < 4; i++) {
					((unsigned char*)c)[i]=( ( ((unsigned char*)c)[i] = getchar() ) == (unsigned char)-1 ? (endOfFile=true),0 : ((unsigned char*)c)[i] );
				}
				if(*c == 0&&endOfFile) {
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
				retv += to93(buffer[i]);
			}
		}
		return retv;
	}
	unsigned int de93(char* d93) {
		unsigned int d=0;
		for(int i=0; d93[i] != 0; i++) {
			d += (d93[i]-33)*pow(93, i);
		}
		return d;
	}
	
	string dec(string input) {
		char d93[6];
		int c;
		int counter = 0;
		string retv;
		int p = 0;
		auto getchar = [&]() {
			if(input[p]==0)
				return -1;
			else {
				return (int)(input[p++]);
			}
		};
		while(c = getchar(), c!=-1) {
			if(c == ' ') {
				d93[counter++] = 0;
				auto outputBuffer = new unsigned int;
				*outputBuffer = de93(d93);
				for(int i=0; i<4; i++) {
					retv += ((unsigned char*)outputBuffer)[i];
				}
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
					retv += ((unsigned char*)outputBuffer)[i];
				}
				counter=0;
				d93[counter++]=c;
			}
		}
		return retv;
	}
}

