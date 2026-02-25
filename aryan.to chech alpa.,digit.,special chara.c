#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);   // space before %c to handle newline

    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        printf("'%c' is an Alphabet.\n", ch);
    }
    else if (ch >= '0' && ch <= '9') {
        printf("'%c' is a Digit.\n", ch);
    }
    else {
        printf("'%c' is a Special Character.\n", ch);
    }

    return 0;
}