#include "d93-tool.h"
#include <string>
#include <iostream>

int main() {
	std::string str = "1145141919810aetfoiebXx[[980123456789";
	std::string enc = d93::enc(str);
	std::string dec = d93::dec(enc);
	std::cout << enc << std::endl << dec << std::endl;
	return 0;
}
