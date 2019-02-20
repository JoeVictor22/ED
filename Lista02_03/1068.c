#include <stdio.h>
#include <stdlib.h>

int main() {

	char string[1001];
	int i, par,exist;

	while (scanf("%s", string) != EOF) {

		i = 0,par =0, exist = 0;
		while (string[i] != '\0') {
			if (string[i] == '(') {
				par++;
			}
			if (string[i] == ')' && par!=0) {
				par--;
			}else if(string[i] == ')' && par == 0){
			    exist++;
			}
			i++;
		}

		printf("%s\n", (par == 0 && exist == 0 ? "correct" : "incorrect"));

	}
	return 0;
}
