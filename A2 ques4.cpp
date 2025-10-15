#include<stdio.h>
#include<string.h>
int main(){
	char str1[50],str2[50];
	
	printf("Enter first string");
	gets(str1);
	
	printf("Enter the secong string");
	gets(str2);
	
	strcat(str1,str2);
	printf("after concatenation: %s",str1);
	return 0;
}

//part b
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    printf("Reversed string: ");
    for (i = len- 1; i>= 0;i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

//part c
#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, j = 0;

    printf("Enter a string: ");
    gets(str1);

    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != 'a' && str1[i] != 'e' && str1[i] != 'i' && str1[i] != 'o' && str1[i] != 'u' &&
            str1[i] != 'A' && str1[i] != 'E' && str1[i] != 'I' && str1[i] != 'O' && str1[i] != 'U') {
            str2[j++] = str1[i];
        }
    }

   str2[j] = '\0';  // Null terminate the new string

    printf("String after removing vowels: %s\n", str2);
    return 0;
}

//part d
#include <stdio.h>
#include <string.h>

int main() {
    char str[10][50], temp[50];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // to consume newline after scanf

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        gets(str[i]);
    }

    // Sorting (Bubble Sort logic)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
//part e
#include <stdio.h>

int main() {
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  
        printf("Lowercase character: %c\n", ch);
    } else {
        printf("The character is not uppercase.\n");
    }

    return 0;
}

