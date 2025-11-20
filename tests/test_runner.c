#include <stdio.h>

// Declare the test runner functions from other test files
void run_creation_tests();
void run_deletion_tests();
void run_insertion_tests();

int main() {
    printf("--- Starting Comprehensive Singly Linked List Test Suite ---\\n");

    run_creation_tests();
    run_deletion_tests();
    run_insertion_tests();

    printf("\\n--- All Singly Linked List Tests Completed ---\\n");
    return 0;
}
