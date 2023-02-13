#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "config.h"

#include "stack_list.hpp"
#include "stack_array.hpp"

#define RESET_CLOCK start_clock = clock()
#define MEASURE current_clock = clock()
#define DELTA_TIME current_clock - start_clock

#define _CONCAT(alpha, beta) alpha ## beta
#define CONCAT(alpha, beta) _CONCAT(alpha, beta)

#define RECREATE do {                   \
    array_stack_dtr(array_stack);       \
    list_stack_dtr(list_stack);         \
    list_stack   = list_stack_ctr(1);   \
    array_stack = array_stack_ctr(1);   \
} while (0)

int main() {
    clock_t start_clock   = 0;
    clock_t current_clock = 0;

    ListStack* list_stack   = list_stack_ctr(1);
    ArrayStack* array_stack = array_stack_ctr(1);

    FILE* output_log = fopen(OUTPUT_FILE, "w");
    assert(output_log);

    FILE* output_tbl = fopen(OUTPUT_TABLE, "w");
    assert(output_tbl);

    printf("Testing has started.\n");

    fprintf(output_tbl, "Test case,List,Array\n");

    fprintf(output_log, "Test 1:\n");

    RESET_CLOCK;
    #define TEST_SUBJECT list_stack
    #include "case1.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_log, "List-based stack:\t%ld\n", DELTA_TIME);
    fprintf(output_tbl, "Test 1,%ld,", DELTA_TIME);

    RESET_CLOCK;
    #define TEST_SUBJECT array_stack
    #include "case1.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_log, "Array-based stack:\t%ld\n", DELTA_TIME);
    fprintf(output_tbl, "%ld\n", DELTA_TIME);

    RECREATE;

    fprintf(output_log, "Test 2:\n");

    RESET_CLOCK;
    #define TEST_SUBJECT list_stack
    #include "case2.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_tbl, "Test 2,%ld,", DELTA_TIME);
    fprintf(output_log, "List-based stack:\t%ld\n", DELTA_TIME);

    RESET_CLOCK;
    #define TEST_SUBJECT array_stack
    #include "case2.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_tbl, "%ld\n", DELTA_TIME);
    fprintf(output_log, "Array-based stack:\t%ld\n", DELTA_TIME);

    RECREATE;

    fprintf(output_log, "Test 3 (1e6 random actions):\n");

    RESET_CLOCK;
    #define TEST_SUBJECT list_stack
    #include "case3.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_tbl, "Test 3 (1e6 random actions),%ld,", DELTA_TIME);
    fprintf(output_log, "List-based stack:\t%ld\n", DELTA_TIME);

    RESET_CLOCK;
    #define TEST_SUBJECT array_stack
    #include "case3.hpp"
    #undef TEST_SUBJECT
    MEASURE;
    fprintf(output_tbl, "%ld\n", DELTA_TIME);
    fprintf(output_log, "Array-based stack:\t%ld\n", DELTA_TIME);

    fclose(output_log);
    fclose(output_tbl);
    printf("Testing is over. Results were stored in the file \"" OUTPUT_FILE "\".\nHave a good day.\n");

    array_stack_dtr(array_stack);
    list_stack_dtr(list_stack);
}