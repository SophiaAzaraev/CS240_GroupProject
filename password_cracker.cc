#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string_view>
#include<bits/stdc++.h>

#define PASSWORD_LIMIT 6

// Generate random data to feed to simple brute force and dictionary brute force 
// password crackers. Function returns a vector of lowercase alphabetic passwords
// of length 6.
std::vector<std::string> generate_data(int data_size){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::vector<std::string> data;
	for(int i = 0; i <= data_size; ++i){
		std::string entry;
		int pos;
		int size = (rand() % 7) + 1;
		while(entry.size() != size){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
			}
		data.push_back(entry);
		}
	return data;
	 
}


std::string permute(char[] alphabet, std::string prefix, int n, int k){
	if(k == 0){
		return prefix;
	}
	for(int i = 0; i < n; i++){
		std::string newPrefix;
		newPrefix = prefix + alphabet[i];
		permute(alphabet, newPrefix, n, k - 1);
	}
}

void print(char[] alphabet, int k, int n){
	permute(alphabet, "", n, k);
}
/*
// Simple brute-force password cracker
// Given: A list of 1000 password to crack
// String: If password is cracked
void simple_brute_force(std::string password){
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	//char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int len = 7;
	std::string prefix = "";
	if(k == 0){
		return;
	}
	for(int i = 0; i < len; i++){
		std::string new;
		new = prefix + alphabet[i];


	int n = 26;
	for(int i = 0; i < n; i++){
		for(int len = 1; len <= n - i ; len++){
			std::string_view guess = alphabet.substr(i,len);
			if(password == guess){
				std::cout << password << std::endl;
			}
		}
	}
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
*/

int main(int argc, char *argv[]){
        std::vector<std::string> data = generate_data(5000);
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int k = 1;
	print(alphabet, k, 5); 

	/*
	for(int i = 0; i < data.size(); i++){
		simple_brute_force(data.at(i));
	}
	*/
	return 0;
}

	
