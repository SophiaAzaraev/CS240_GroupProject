#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string_view>

#include <chrono>
#include <string.h>

#define PASSWORD_LIMIT 6

// Generate random data to feed to simple brute force and dictionary brute force 
// password crackers. Function returns a vector of lowercase alphabetic passwords
// of length 6.
void  generate_data(int data_size){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	std::ofstream outputFile;
	outputFile.open("passwords.txt");
	for(int i = 0; i < data_size; ++i){
		std::string entry;
		int pos;
		int size = 6;
		while(entry.size() != size){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
			}
		outputFile << entry;
		outputFile << "\n";
	}
	outputFile.close();
}

//generate permutations of length 6 from alphabet and feed to brute force checker 
void  brute_force(char *perm, int startPos, std::string alphabet, std::string password){
	if(startPos == 6) {
		std::string permString(perm);
		
		if(password.compare(permString )== 0)
			return;
	}
	else{
		for(int i=0; i<alphabet.length(); i++){
			perm[startPos]=alphabet[i];
			brute_force(perm, startPos+1, alphabet, password);
		}
	}

}

int main(int argc, char *argv[]){
	// generate n passwords
	int num_passwords = 1000;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

       	generate_data(num_passwords);

	char permutation[7];
	std::ifstream file("passwords.txt");
	std::string guess;
	auto start = std::chrono::high_resolution_clock::now();

	std::cout << "----------Cracking paswords via brute force----------" << std::endl;

	while(getline(file, guess)){
		brute_force(permutation, 0, alphabet, guess);

	}
	
	std::cout << num_passwords << " passwords cracked!" << std::endl;
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff= (stop - start);
	auto totalTimeBF = diff.count();
	auto avgTimeBF = diff.count()/ 5000;

	std::cout << "Total time to crack passwords: " << totalTimeBF << std::endl; 
	std::cout << "brute force average time per password is " << std::to_string(avgTimeBF) << " seconds" << std::endl;

	return 0;
}

	
