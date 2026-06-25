// ============================================================================
// Title: Summer Vacation Self Learning Assignments - Day 25
// Company Information: Amazon, Deloitte, Capgemini, Microsoft, Adobe, Paytm
// ============================================================================
#include <stdio.h>
#include <string.h>

// --- FUNCTIONS FOR EACH ASSIGNMENT ---

// Q97: Write a program to Merge two sorted arrays.
void solveQ97() {
    int n1, n2;
    printf("\n--- Q97: Merge Two Sorted Arrays ---\n");
    printf("Enter the size of the first sorted array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements in SORTED order:\n", n1);
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    printf("Enter the size of the second sorted array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements in SORTED order:\n", n2);
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;

    // Linear merge operation (O(n1 + n2) time complexity)
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    printf("Merged Sorted Array: ");
    for (int x = 0; x < n1 + n2; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");
}

// Q98: Write a program to Find common characters in strings.
void solveQ98() {
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};

    printf("\n--- Q98: Find Common Characters in Strings ---\n");
    printf("Enter first string: ");
    scanf(" %[^\n]s", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]s", str2);

    // Count character frequencies for both strings
    for (int i = 0; str1[i] != '\0'; i++) if (str1[i] != ' ') freq1[(unsigned char)str1[i]]++;
    for (int i = 0; str2[i] != '\0'; i++) if (str2[i] != ' ') freq2[(unsigned char)str2[i]]++;

    printf("Common characters are: ");
    int found = 0;
    for (int i = 0; i < 256; i++) {
        // If a character exists in both frequency tables
        if (freq1[i] > 0 && freq2[i] > 0) {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None (No common characters found)");
    }
    printf("\n");
}

// Q99: Write a program to Sort names alphabetically.
void solveQ99() {
    int n;
    printf("\n--- Q99: Sort Names Alphabetically ---\n");
    printf("How many names do you want to sort? ");
    scanf("%d", &n);

    char names[n][50], temp[50];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]s", names[i]);
    }

    // Bubble Sort tracking to sort strings alphabetically using strcmp()
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j+1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nNames sorted in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}

// Q100: Write a program to Sort words by length.
void solveQ100() {
    int n;
    printf("\n--- Q100: Sort Words by Length ---\n");
    printf("How many words do you want to sort? ");
    scanf("%d", &n);

    char words[n][50], temp[50];
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Sort words based on their string lengths using strlen()
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap words[j] and words[j+1]
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Length: %d)\n", words[i], (int)strlen(words[i]));
    }
}


// --- MAIN FUNCTION ---
int main() {
    int choice;

    printf("==================================================\n");
    printf("        DAY 25 ASSIGNMENTS (MENU DRIVEN)          \n");
    printf("==================================================\n");
    printf("97. Run Q97 (Merge Two Sorted Arrays)\n");
    printf("98. Run Q98 (Find Common Characters in Strings)\n");
    printf("99. Run Q99 (Sort Names Alphabetically)\n");
    printf("100. Run Q100 (Sort Words by Length)\n");
    printf("==================================================\n");
    printf("Select a program to run (97-100): ");
    scanf("%d", &choice);

    switch(choice) {
        case 97: solveQ97(); break;
        case 98: solveQ98(); break;
        case 99: solveQ99(); break;
        case 100: solveQ100(); break;
        default: printf("Invalid choice! Please select a number between 97 and 100.\n");
    }

    return 0;
}