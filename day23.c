// ============================================================================
// Title: Summer Vacation Self Learning Assignments - Day 23
// Company Information: Microsoft, Adobe, Paytm
// ============================================================================
#include <stdio.h>

// --- FUNCTIONS FOR EACH ASSIGNMENT ---

// Q89: Write a program to Find first non-repeating character.
void solveQ89() {
    char str[200];
    int freq[256] = {0};
    printf("\n--- Q89: Find First Non-Repeating Character ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    // Step 1: Count frequency of all characters
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Step 2: Find the first character with frequency equal to 1
    int found = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1 && str[i] != ' ') {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("All characters are repeating or no unique character found.\n");
    }
}

// Q90: Write a program to Find first repeating character.
void solveQ90() {
    char str[200];
    int freq[256] = {0};
    printf("\n--- Q90: Find First Repeating Character ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    int found = 0;
    // Track count as we traverse; the first one to hit count > 1 sequentially is our target
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            freq[(unsigned char)str[i]]++;
            if (freq[(unsigned char)str[i]] > 1) {
                printf("The first repeating character is: '%c'\n", str[i]);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("No repeating characters found in the string.\n");
    }
}

// Q91: Write a program to Check anagram strings.
void solveQ91() {
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};
    int isAnagram = 1;

    printf("\n--- Q91: Check Anagram Strings ---\n");
    printf("Enter first string: ");
    scanf(" %[^\n]s", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]s", str2);

    // Count character frequencies for both strings
    for (int i = 0; str1[i] != '\0'; i++) if (str1[i] != ' ') freq1[(unsigned char)str1[i]]++;
    for (int i = 0; str2[i] != '\0'; i++) if (str2[i] != ' ') freq2[(unsigned char)str2[i]]++;

    // Two strings are anagrams if their character frequency profiles match exactly
    for (int i = 0; i < 256; i++) {
        if (freq1[i] != freq2[i]) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) {
        printf("The strings are Anagrams of each other.\n");
    } else {
        printf("The strings are NOT Anagrams.\n");
    }
}

// Q92: Write a program to Find maximum occurring character.
void solveQ92() {
    char str[200];
    int freq[256] = {0};
    printf("\n--- Q92: Find Maximum Occurring Character ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            freq[(unsigned char)str[i]]++;
        }
    }

    int maxCount = 0;
    char maxChar = ' ';

    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxChar = (char)i;
        }
    }

    printf("The maximum occurring character is '%c' (Appears %d times).\n", maxChar, maxCount);
}


// --- MAIN FUNCTION ---
int main() {
    int choice;

    printf("==================================================\n");
    printf("        DAY 23 ASSIGNMENTS (MENU DRIVEN)          \n");
    printf("==================================================\n");
    printf("89. Run Q89 (Find First Non-Repeating Character)\n");
    printf("90. Run Q90 (Find First Repeating Character)\n");
    printf("91. Run Q91 (Check Anagram Strings)\n");
    printf("92. Run Q92 (Find Maximum Occurring Character)\n");
    printf("==================================================\n");
    printf("Select a program to run (89-92): ");
    scanf("%d", &choice);

    switch(choice) {
        case 89: solveQ89(); break;
        case 90: solveQ90(); break;
        case 91: solveQ91(); break;
        case 92: solveQ92(); break;
        default: printf("Invalid choice! Please select a number between 89 and 92.\n");
    }

    return 0;
}