#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>
#include <fstream>
#include <chrono>
#include <string.h>

bool isAlpha(std::string entry){
	int len = entry.length();
	char arr[len+1];
	strcpy(arr, entry.c_str());
	for(int i = 0; i < len; i++){
		if(!isalpha(arr[i])){
			return false;
		}
	}
	return true;
}

void generateData(int data_size, std::vector<std::string> dictionary, int passwordSize){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	
	std::ofstream outputFile;
	outputFile.open("passwords.txt");

	for(int i = 0; i < data_size; ++i){
		std::string entry;
		int pos;
		int size = passwordSize + 1;
		while(entry.size() != size){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
		}
		outputFile << entry << std::endl;

		int rand = std::rand() % 5 + 1;
		if(i % 5 == 0){
			outputFile << dictionary.at(i) << std::endl;
		}
	}
	outputFile.close();
}

void bruteForceAttack(char *perm, int startPos, std::string alphabet, std::string password, int passwordSize){
	if(startPos == passwordSize) {
		std::string permString(perm);
		if(password.compare(permString)== 0)
			return;
	}
	
	else{
		for(int i=0; i<alphabet.length(); i++){
			perm[startPos]=alphabet[i];
			bruteForceAttack(perm, startPos+1, alphabet, password, passwordSize);
			}
			
		}	
	
}
		
bool dictionaryAttack(std::vector<std::string>& dict, std::string& password){
	for(int i = 0; i < dict.size(); i++){
		if(dict.at(i).compare(password)==0){
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]){
	std::ifstream dictionary("dictionary.txt");
	std::vector<std::string> dict;
	std::string entry;
	while(getline(dictionary, entry)){
		if(entry.length() == 4 && isAlpha(entry)){
			dict.push_back(entry);
			}
	}

	int numPasswords = 0;
	int passwordSize = 0;

	if(isdigit(argv[1]) || isdigit(argv[2])){
		std::cout << "bad" << std::endl;
	}
	
	// convert args to ints
	for(int i = 2; i < argc; i++){
		numPasswords += std::atoi(argv[i-1]);
		passwordSize += std::atoi(argv[i]);
	}

	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	std::cout << "here" << std::endl;

       	generateData(numPasswords, dict, passwordSize);
	
	char permutation[5];
	std::ifstream passwords("passwords.txt");
	std::string password;

	auto bfStart = std::chrono::high_resolution_clock::now();
	std::cout << "----------Cracking Paswords Via Brute Force ----------" << std::endl;
	
	while(getline(passwords, password)){
		bruteForceAttack(permutation, 0, alphabet, password, passwordSize);
	}

	auto bfStop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> bfDiff= (bfStop - bfStart);
	auto bfTotalTime = bfDiff.count();
	auto bfAvgTime = bfTotalTime / numPasswords;

	std::cout << "---------- Brute Force Results ----------" << std::endl;
	std::cout << "Passwords Cracked: " << numPasswords << std::endl;
	std::cout << "Total Time to Crack Passwords (s): " << bfTotalTime << std::endl; 
	std::cout << "Time per Password Cracked (ms):  " << bfAvgTime << std::endl;


	std::ifstream file2("passwords.txt");
	std::string password2;
	int dictPasswordsCracked = 0;

	auto dictStart = std::chrono::high_resolution_clock::now();
	std::cout << "----------Cracking Paswords Via Dictionary ----------" << std::endl;

	while(getline(file2, password)){
		if(dictionaryAttack(dict, password))
			dictPasswordsCracked++;
	}

	auto dictStop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dictDiff = (dictStop - dictStart);
	auto dictTotalTime = dictDiff.count();
	auto dictAvgTime = dictTotalTime / numPasswords;

	std::cout << "---------- Dictionary ---------" << std::endl;
	std::cout << "Passwords Cracked: " << dictPasswordsCracked << std::endl;
	std::cout << "Total Time To Crack Passwords (s): " << dictTotalTime << std::endl;
	std::cout << "Time per Password Cracked (ms): " << dictAvgTime << std::endl;
	

	return 0;
	}

	
