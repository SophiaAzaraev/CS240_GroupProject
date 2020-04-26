#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>

#define PASSWORD_LEN 6

// Generate random data to feed to simple brute force and dictionary brute force password crackers
std::vector<std::string> generate_data(int len){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::vector<std::string> data;
	for(int i = 0; i <= len; ++i){
		std::string entry;
		int pos;
		while(entry.size() != PASSWORD_LEN){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
			}
		data.push_back(entry);
		}
	return data;
	 
}
//simple brute force
//lowercase letters
const char lowerCase[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void options(unsigned int length, std::vector<std::string> password){
  if(length==0){
    std::cout <<password <<"\n";
    return;
  }
  for(unsigned int i = 0; i<26; i++){
    std::vector<std::string> appended = password.push_back (lowerCase[i]);
    options(length-1, appended);
  }
}
void crackPassword(){
  while(1){
    static unsigned int stringlength = 1;
    options(stringlength, {""});
    stringlength++;
  }
}


int main(int argc, char *argv[]){
        std::vector<std::string> data = generate_data(6);
	for(std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++){
		// call simple brute force
	  
	  crackPassword();
	  return 0;
	}
}

	
