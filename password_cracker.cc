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

void  generateData(int data_size, std::vector<std::string> dictionary){
	std::string str = "abcdefghijklmnopqrstuvwxyz";
	
	std::ofstream outputFile;
	outputFile.open("passwords.txt");

	for(int i = 0; i < data_size; ++i){
		std::string entry;
		int pos;
		int size = 4;
		while(entry.size() != size){
			pos = ((rand() % (str.size() - 1)));
			entry += str.substr(pos,1);
		}
		outputFile << entry << std::endl;
		
		// randomly add dictionary keyword
		int rand = std::rand() % 5 + 1;
		if(i % 5 == 0){
			outputFile << dictionary.at(i) << std::endl;
		}
	}
	outputFile.close();
}

//generate permutations of length 6 from alphabet and feed to brute force checker 
void bruteForce(char *perm, int startPos, std::string alphabet, std::string password){
	if(startPos == 4) {
		std::string permString(perm);
		if(password.compare(permString)== 0)
			return;
	}
	
	else{
		for(int i=0; i<alphabet.length(); i++){
			perm[startPos]=alphabet[i];
			bruteForce(perm, startPos+1, alphabet, password);
			}
			
		}	
	
}
		

bool dictionaryMethod(std::vector<std::string>& dict, std::string& password){
	for(int i = 0; i < dict.size(); i++){
		if(dict.at(i).compare(password)==0){
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]){
	// populate dictionary from dictionary.txt
	std::ifstream dictionary("dictionary.txt");
	std::vector<std::string> dict;
	std::string entry;
	while(getline(dictionary, entry)){
		if(entry.length() == 4 && isAlpha(entry)){
			dict.push_back(entry);
			//std::cout << entry << std::endl;
		}
	} 
	

	int numPasswords = 50;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

       	generateData(numPasswords, dict);
	
	char permutation[5];
	std::ifstream passwords("passwords.txt");
	std::string password;
	//int bfPasswordsCracked = 0;

	auto bfStart = std::chrono::high_resolution_clock::now();
	std::cout << "----------Cracking Paswords Via Brute Force ----------" << std::endl;
	
	while(getline(passwords, password)){
		bruteForce(permutation, 0, alphabet, password);
	}

	auto bfStop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> bfDiff= (bfStop - bfStart);
	auto bfTotalTime = bfDiff.count();
	auto bfAvgTime = bfTotalTime / numPasswords;

	std::ifstream file2("passwords.txt");
	std::string password2;
	int dictPasswordsCracked = 0;

	auto dictStart = std::chrono::high_resolution_clock::now();
	std::cout << "----------Cracking Paswords Via Dictionary ----------" << std::endl;

	while(getline(file2, password)){
		if(dictionaryMethod(dict, password))
			dictPasswordsCracked++;
	}

	auto dictStop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dictDiff = (dictStop - dictStart);
	auto dictTotalTime = dictDiff.count();
	auto dictAvgTime = dictTotalTime / numPasswords;

	
	std::cout << "---------- Brute Force ----------" << std::endl;
	std::cout << "Passwords Cracked: " << numPasswords << std::endl;
	std::cout << "Total Time to Crack Passwords (s): " << bfTotalTime << std::endl; 
	std::cout << "Time per Password Cracked (ms):  " << bfAvgTime << std::endl;

	std::cout << "---------- Dictionary ---------" << std::endl;
	std::cout << "Passwords Cracked: " << dictPasswordsCracked << std::endl;
	std::cout << "Total Time To Crack Passwords (s): " << dictTotalTime << std::endl;
	std::cout << "Time per Password Cracked (ms): " << dictAvgTime << std::endl;
	

	return 0;
	}

	
