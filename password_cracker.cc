#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>

std::vector<std::string> generate_data(int len){
	//static const char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::vector<std::string> data;
	for(int i = 0; i <= len; ++i){
		std::string entry;
		int pos;
		data.push_back(entry);
		}
		data.push_back(entry);
		}
	return data;
	 
}

int main(int argc, char *argv[]){
	std::vector<std::string> data = generate_data(10);
	for(std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++){
		std::cout << *it << std::endl;
	}
}

	
