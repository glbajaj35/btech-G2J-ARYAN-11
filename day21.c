// ============================================================================
// Title: Summer Vacation Self Learning Assignments - Day 21 (Strings Basics)
// Company Information: Microsoft, Adobe, Paytm, TCS, Infosys, Wipro
// ============================================================================
#include <stdio.h>

// --- FUNCTIONS FOR EACH ASSIGNMENT ---

// Q81: Write a program to Find string length without strlen().
void solveQ81() {
    char str[100];
    int length = 0;
    
    printf("\n--- Q81: Find String Length without strlen() ---\n");
    printf("Enter a string: ");
    // Clear input buffer and read string with spaces using scanset
    scanf(" %[^\n]s", str); 

    // Loop until null character '\0' is encountered
    while (str[length] != '\0') {
        length++;
    }

    printf("The length of the string is: %d\n", length);
}

// Q82: Write a program to Reverse a string.
void solveQ82() {
    char str[100];
    int length = 0;
    
    printf("\n--- Q82: Reverse a String ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    // First, find the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Swap characters from start and end to reverse in-place
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    printf("Reversed string is: %s\n", str);
}

// Q83: Write a program to Count vowels and consonants.
void solveQ83() {
    char str[100];
    int vowels = 0, consonants = 0;
    
    printf("\n--- Q83: Count Vowels and Consonants ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        // Check if character is an alphabet
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            // Convert to lowercase check for simplicity
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);
}

// Q84: Write a program to Convert lowercase to uppercase.
void solveQ84() {
    char str[100];
    
    printf("\n--- Q84: Convert Lowercase to Uppercase ---\n");
    printf("Enter a string in lowercase/mixed case: ");
    scanf(" %[^\n]s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        // If character is in lowercase, subtract 32 to get uppercase ASCII value
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    printf("String in UPPERCASE: %s\n", str);
}


// --- MAIN FUNCTION ---
int main() {
    int choice;

    printf("==================================================\n");
    printf("        DAY 21 ASSIGNMENTS (MENU DRIVEN)          \n");
    printf("==================================================\n");
    printf("81. Run Q81 (Find String Length without strlen)\n");
    printf("82. Run Q82 (Reverse a String)\n");
    printf("83. Run Q83 (Count Vowels and Consonants)\n");
    printf("84. Run Q84 (Convert Lowercase to Uppercase)\n");
    printf("==================================================\n");
    printf("Select a program to run (81-84): ");
    scanf("%d", &choice);

    switch(choice) {
        case 81: solveQ81(); break;
        case 82: solveQ82(); break;
        case 83: solveQ83(); break;
        case 84: solveQ84(); break;
        default: printf("Invalid choice! Please select a number between 81 and 84.\n");
    }

    return 0;
}