# CS240 Team Project: Password Cracking Algorithms
## Abigail McHugh, Amelia Chesebro, and Sophia Azaraev

**In 2019, over 160 million sensitive records were exposed as the result of data breaches (statistica.com). Password cracking is a common strategy for gaining access to user's information.
For our project, we compared two types of brute force attacks: a simple brute force attack, and a
dictionary attack.**

### _Generating fake data_
We created fake, random passwords of six lowercase letters in the `generate_data()` function, which wrote passwords to a text file:

	void generate_data(int datasize){
		std::string str = "abcdefghjklimnopqrstuvwxyz";
		std::ofstream outputFile;
		...
		for(int i = 0; i < datasize; ++i){
			std::string entry;
			int pos;
			int size = 6; // our chosen password length
			while(entry.size() != size){
				pos == (rand() % (str.size() - 1));
				entry += str.subtr(pos,1);
			}
		}
		outputFile << entry;
		...
	}

This function allowed us to control the number of passwords we wanted to crack as well as the length of each password.

### _Simple brute force password cracker_
The `brute_force()` function shows our simple brute force algorithmn. In main, we called `generate_data()` with the number of passwords we wanted to generate. Then we created a char array of length 7, so that the permutations would be 6 characters long. We then opened up the passwords.txt file written to by `generate__data()`, and looped through each line in passwords.txt, calling `permute(permutation, startPosition, alphabet, guess)`, with alphabet being the letters used to make the permutations, the startPosition being set to 0, and the password being read from passwords.txt.

The `brute_force()` function used a recursive call. If the position of the string = 6, that meant a permutation of length 6 was created, and it compared the current password to this permtuation. If it was not, the start position was incremented and moved to the next letter of the alphabet. This way, it generated all permutations of the alphabet at length six, starting with a, b, c.. and moving through the rest of the alphabet.

	void brute_force(char *perm, int startPos, std::string alphabet, std::string password){
		if(startPos == 6){
			std::string permString(perm);
		}
		if(password.compare(permString) == 0){
			return;
		}
		else{
			for(int i = 0; i < alphabet.length(); i++){
				perm[startPos] = alphabet[i];
				permute(perm, startPos+1, alphabet, password);
			}
		}
	}

