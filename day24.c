// ============================================================================
// Title: Summer Vacation Self Learning Assignments - Day 24
// Company Information: Microsoft, Adobe, Paytm, TCS, Infosys, Wipro
// ============================================================================
#include <stdio.h>
#include <string.h>

// --- FUNCTIONS FOR EACH ASSIGNMENT ---

// Q93: Write a program to Check string rotation.
void solveQ93() {
    char str1[100], str2[100], temp[200] = "";
    printf("\n--- Q93: Check String Rotation ---\n");
    printf("Enter original string (str1): ");
    scanf(" %[^\n]s", str1);
    printf("Enter rotated string to check (str2): ");
    scanf(" %[^\n]s", str2);

    // If lengths are not equal, they cannot be rotations of each other
    if (strlen(str1) != strlen(str2)) {
        printf("The strings are NOT rotations of each other (Length mismatch).\n");
        return;
    }

    // Concatenate str1 with itself (str1 + str1)
    strcat(temp, str1);
    strcat(temp, str1);

    // If str2 is a substring of (str1 + str1), then it is a valid rotation
    if (strstr(temp, str2) != NULL) {
        printf("\"%s\" is a valid rotation of \"%s\".\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\".\n", str2, str1);
    }
}

// Q94: Write a program to Compress a string.
void solveQ94() {
    char str[150], compressed[300] = "";
    printf("\n--- Q94: Compress a String (e.g., aabcc -> a2b1c2) ---\n");
    printf("Enter a string to compress: ");
    scanf(" %[^\n]s", str);

    int length = strlen(str);
    int j = 0;

    for (int i = 0; i < length; i++) {
        int count = 1;
        // Count consecutive occurrences of the same character
        while (i < length - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        
        // Append character and its count to the compressed string representation
        j += sprintf(&compressed[j], "%c%d", str[i], count);
    }

    // If compressed string isn't actually shorter, standard practice prints it or returns as specified
    printf("Compressed String: %s\n", compressed);
}

// Q95: Write a program to Find longest word.
void solveQ95() {
    char str[300], longestWord[100] = "", currentWord[100] = "";
    printf("\n--- Q95: Find Longest Word in a Sentence ---\n");
    printf("Enter a sentence: ");
    scanf(" %[^\n]s", str);

    int i = 0, currLen = 0, maxLen = 0;
    int len = strlen(str);

    while (i <= len) {
        // If current character is an alphabet or number (not a space or null terminator)
        if (str[i] != ' ' && str[i] != '\0') {
            currentWord[currLen++] = str[i];
        } else {
            currentWord[currLen] = '\0'; // Terminate current word string
            
            // Check if current tracked word length is greater than max found so far
            if (currLen > maxLen) {
                maxLen = currLen;
                strcpy(longestWord, currentWord);
            }
            currLen = 0; // Reset for next word tracking
        }
        i++;
    }

    printf("The longest word in the sentence is: \"%s\" (Length: %d)\n", longestWord, maxLen);
}

// Q96: Write a program to Remove duplicate characters.
void solveQ96() {
    char str[200];
    int freq[256] = {0}; // Track lookup status for printed characters
    printf("\n--- Q96: Remove Duplicate Characters ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    printf("String after removing duplicate characters: ");
    for (int i = 0; str[i] != '\0'; i++) {
        // If the character hasn't been printed yet, display it and mark as processed
        if (freq[(unsigned char)str[i]] == 0) {
            printf("%c", str[i]);
            freq[(unsigned char)str[i]] = 1; // Mark as seen
        }
    }
    printf("\n");
}


// --- MAIN FUNCTION ---
int main() {
    int choice;

    printf("==================================================\n");
    printf("        DAY 24 ASSIGNMENTS (MENU DRIVEN)          \n");
    printf("==================================================\n");
    printf("93. Run Q93 (Check String Rotation)\n");
    printf("94. Run Q94 (Compress a String)\n");
    printf("95. Run Q95 (Find Longest Word)\n");
    printf("96. Run Q96 (Remove Duplicate Characters)\n");
    printf("==================================================\n");
    printf("Select a program to run (93-96): ");
    scanf("%d", &choice);

    switch(choice) {
        case 93: solveQ93(); break;
        case 94: solveQ94(); break;
        case 95: solveQ95(); break;
        case 96: solveQ96(); break;
        default: printf("Invalid choice! Please select a number between 93 and 96.\n");
    }

    return 0;
}