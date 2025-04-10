#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHANUM "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define ALNUM_LEN 62

// funkcia generuje nahodny alfanumericky znak vacsi alebo rovny min
char nahodny_znak (char min){
	char c;
	do {
		c = ALPHANUM[rand() % ALNUM_LEN];
	} while (c < min);
	return c;
}

// funkcia prepisuje str nahodnym rastucim retazcem rovnakej dlzky
void nahodny_rastuci_retazec(char *str){
	if (!str) return;
	
	char min = '0'; //majmensi povoleny znak
	for(size_t i = 0; str[i]; i++){
		str[i] = nahodny_znak(min);
		min = str[i]; //aktualizacia minimumu
	}
}

int main(){
	srand(time(NULL));
	
	char retazec[11] = "abcdefghij"; // 10 znakov + '\0'
	printf("Povodny: %s\n", retazec);
	
	nahodny_rastuci_retazec(retazec);
	printf("Rastuci: %s\n", retazec);
	
	return 0;
	
}