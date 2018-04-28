#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char lowerCase () {
	char lc[] = "abcdefghijklmnopqrstuvwxyz";
	return lc[rand() % 26];
}

char upperCase () {
	char uc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        return uc[rand() % 26];
}

char number () {
	char num[] = "1234567890";
	return num[rand() % 10];
}

char symbol () {
	char sym[] = "@':;.,/?<>#~[]{}";
	return sym[rand() % 16];
}

int main () {
	int length = 37;
	int inc[] = {1, 1, 0};
	srand(time(NULL)); // Generate seed

	printf("PassGen: Password Generator \n");

	printf("Length: ");
	//while (!length && length != 0)
	scanf("%i", &length);

	char password[length];

	printf("Letters? (1/0) ");
	scanf("%i", &inc[0]);
	printf("Numbers? (1/0) ");
	scanf("%i", &inc[1]);
	printf("Symbols? (1/0) ");
	scanf("%i", &inc[2]);

	for (int i = 0; i < length; i++) {
		PICK: switch (rand() % 4) { // Random number 0 - 1
			case 0:
			if (inc[0]) password[i] = upperCase();
			else goto PICK;
				break;
			case 1:
				if (inc[0]) password[i] = lowerCase();
				else goto PICK;
				break;
			case 2:
				if (inc[1]) password[i] = number();
				else goto PICK;
				break;
			case 3:
				if (inc[2]) password[i] = symbol();
				else goto PICK;
		}
	}

	printf("Password: %s\n", password);
}
