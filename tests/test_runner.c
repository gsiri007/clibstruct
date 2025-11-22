#include <stdio.h>

// Declare the test runner functions from other test files
void run_creation_tests();
void run_deletion_tests();
void run_insertion_tests();
void run_data_types_tests();
void run_stack_tests();

int main() {
    printf("--- Starting Comprehensive Test Suite ---\\n");

    run_creation_tests();
    run_deletion_tests();
    run_insertion_tests();
    run_data_types_tests();
    run_stack_tests();

    printf("\\n--- All Tests Completed ---\\n");
    return 0;
}
