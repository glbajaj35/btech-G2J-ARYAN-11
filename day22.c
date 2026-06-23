// ============================================================================
// Title: Summer Vacation Self Learning Assignments - Day 22 (Advanced Strings)
// Company Information: Microsoft, Adobe, Paytm, TCS, Infosys, Wipro
// ============================================================================
#include <stdio.h>

// --- FUNCTIONS FOR EACH ASSIGNMENT ---

// Q85: Write a program to Check palindrome string.
void solveQ85() {
    char str[100];
    int length = 0, isPalindrome = 1;
    
    printf("\n--- Q85: Check Palindrome String ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    // Calculate length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Check characters from both ends moving towards the center
    int start = 0;
    int end = length - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            isPalindrome = 0; // Characters mismatch
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        printf("The string \"%s\" is a Palindrome.\n", str);
    } else {
        printf("The string \"%s\" is NOT a Palindrome.\n", str);
    }
}

// Q86: Write a program to Count words in a sentence.
void solveQ86() {
    char str[200];
    int words = 0, i = 0;
    
    printf("\n--- Q86: Count Words in a Sentence ---\n");
    printf("Enter a sentence: ");
    scanf(" %[^\n]s", str);

    // Traverse the string to count spaces
    while (str[i] != '\0') {
        // If current character is space and next character is not a space/null (handles standard words)
        if ((str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') || (i == 0 && str[i] != ' ')) {
            words++;
        }
        i++;
    }

    printf("Total number of words in the sentence: %d\n", words);
}

// Q87: Write a program to Character frequency.
void solveQ87() {
    char str[200];
    int freq[256] = {0}; // Integer array to store frequencies of all 256 ASCII characters
    
    printf("\n--- Q87: Character Frequency Check ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    // Count frequency of each character by using its ASCII value as index
    for (int i = 0; str[i] != '\0'; i++) {
        // Exclude spaces from calculation if you only want characters, or trace all
        if (str[i] != ' ') {
            freq[(unsigned char)str[i]]++;
        }
    }

    printf("Character frequencies (excluding spaces):\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' appears %d time(s)\n", i, freq[i]);
        }
    }
}


// --- MAIN FUNCTION ---
int main() {
    int choice;

    printf("==================================================\n");
    printf("        DAY 22 ASSIGNMENTS (MENU DRIVEN)          \n");
    printf("==================================================\n");
    printf("85. Run Q85 (Check Palindrome String)\n");
    printf("86. Run Q86 (Count Words in a Sentence)\n");
    printf("87. Run Q87 (Character Frequency)\n");
    printf("==================================================\n");
    printf("Select a program to run (85-87): ");
    scanf("%d", &choice);

    switch(choice) {
        case 85: solveQ85(); break;
        case 86: solveQ86(); break;
        case 87: solveQ87(); break;
        default: printf("Invalid choice! Please select a number between 85 and 87.\n");
    }

    return 0;
}