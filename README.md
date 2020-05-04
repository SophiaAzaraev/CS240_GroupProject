# CS240 Team Project: Password Cracking Algorithms
## Abigail McHugh, Amelia Chesebro, and Sophia Azaraev

**In 2019, over 160 million sensitive records were exposed as the result of data breaches (statistica.com). Password cracking is a common strategy for gaining access to user's information.
For our project, we compared two types of brute force attacks: a simple brute force attack, and a
dictionary attack.**

### _Generating fake data_
We created fake, random passwords of lowercase letters, passwordSize length in the `generate_data()` function, which wrote passwords to the text file "passwords.txt": 

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

This function allowed us to control the number of passwords we wanted to crack as well as the length of each password. Additionally, by utilizing `rand()`, we were able to randomly add a password from the most common 10,000 passwords, found online (xato.net). This allowed us to test out `dictionaryAttack()` function.

### _Simple brute force attack password cracker_
The `bruteForceAttack()` function shows our simple brute force algorithmn.

In main, we called `generateData()` with the number of passwords we wanted to generate. We then opened up the passwords.txt file written to by `generateData()`, and looped through each line in passwords.txt, calling `bruteForceAttack(permutation, startPosition, alphabet, guess, passwordSize)`, with alphabet being the letters used to make the permutations, the startPosition being set to 0, the password being read from passwords.txt, and the passwordSize specified in main.

The `bruteforceAttack()` function used a recursive call. If the position of the string = passwordSize, that meant a permutation of length passwordSize was created, and it compared the current password to this permtuation. If it was not, the start position was incremented and moved to the next letter of the alphabet. This way, it generated all permutations of the alphabet at length six, starting with a, b, c.. and moving through the rest of the alphabet.

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

### _Dictionary attack password cracker_
The `dictionaryAttack()` method is simple. It loops through each line in the dictionary vector, and if the password matches dictionary.at(i), it returns. If the password goes through the entire vector without a match, the function returns false.

	bool dictionaryAttack(std::vector<std::string>& dict, std::string& password){
		for(int i = 0; i < dict.size(); i++){
			if(dict.at(i).compare(password)==0){
				return true;
			}
		}
		return false;
	}

While the `bruteForceAttack()` function was void, `dictionaryAttack()` returns a bool. This is because `bruteForceAttack()` generates all permutations, so there is guarenteed to be a match. However, `dictionaryAttack()` only has finite set of guesses, which no guarentee that it will match our random strings created in `generateData()`. 

## _Main and program flow_

