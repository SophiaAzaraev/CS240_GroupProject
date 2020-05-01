#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string_view>
#include<bits/stdc++.h>
#include <chrono>
#include <string.h>

#define PASSWORD_LIMIT 6

// Generate random data to feed to simple brute force and dictionary brute force 
// password crackers. Function returns a vector of lowercase alphabetic passwords
// of length 6.
void  generate_data(int data_size){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::vector<std::string> data;
	std::ofstream outputFile;
	outputFile.open("passwords.txt");
	for(int i = 0; i < data_size; ++i){
		std::string entry;
		int pos;
		int size = 3;
		while(entry.size() != size){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
			}
		data.push_back(entry);
		outputFile << entry;
		outputFile << "\n";
	}
	//outputFile << data;
	outputFile.close();
	//return data;
	 
}


//takes permutations as permute generates them and compares to password until it gets a match
void brute_force(char *perm, std::string fileName){

	std::ifstream file("passwords.txt");
	std::string currentPass;
	
	getline(file, currentPass);
	std::string attempt(perm);
//	std::cout << currentPass << std::endl;

	if(attempt.compare(currentPass) == 0)
		std::cout << "correct" << std::endl;
}

//generate permutations of length 6 from alphabet and feed to brute force checker 
void  permute(char *perm, int startPos, std::string alphabet, std::string password){
	if(startPos == 3) {
		//give to brute force
		//std::cout << perm << std::endl;
		//brute_force(perm, "passwords.txt");
		std::string permString(perm);
		if(password.compare(permString)==0){}
			//std::cout << password << " was cracked successfully" << std::endl;
	}
	else{
		for(int i=0; i<alphabet.length(); i++){
			perm[startPos]=alphabet[i];
			permute(perm, startPos+1, alphabet, password);
		}
	}

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
        //std::vector<std::string> data = 
	generate_data(5000);
	//char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	//int k = 1;
	//print(alphabet, k, 5); 

	/*
	for(int i = 0; i < data.size(); i++){
		simple_brute_force(data.at(i));
	}
	*/
	char permutation[4];
//	permute(permutation, 0, "abcdefghijklmnopqrstuvwxyz");

	std::ifstream file("passwords.txt");
	std::string guess;
	auto start = std::chrono::high_resolution_clock::now();
	while(getline(file, guess)){
	
		permute(permutation, 0, "abcdefghijklmnopqrstuvwxyz", guess);

	}
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff= (stop - start);
	auto avgBF = diff.count()/ 5000;

	std::cout << "brute force average time per password is " << std::to_string(avgBF) << " seconds" << std::endl;

	return 0;
	



}

	
