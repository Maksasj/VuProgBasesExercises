#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALIDATION_LAYER_COUNT 5

/*
result_type res = ...

res.value -> returns pointer to value(should be casted to needed type)
res.failed -> Boolean true if failed, false if successful
res.error -> Error message
*/

typedef struct result_type {
    void* value;
    bool failed;
    char* error;
} result_type;

typedef struct validator_instance {
    result_type (*layers[MAX_VALIDATION_LAYER_COUNT]) (void *x);
    int count;
} validator_instance;

result_type success_result(void *value) {
    result_type res;
    res.value = value;
    res.failed = false;
    return res;
}

result_type error_result(char* error_message) {
    result_type res;
    res.error = error_message;
    res.failed = true;
    return res;
}

validator_instance create_validator_instance() {
    validator_instance validator;
    validator.count = 0;

    return validator;
}

result_type input_integer(void *a) {
    void* value = malloc(sizeof(int));
    bool scan_result = scanf("%d", value);
    fflush(stdin); //Lets clear error buffer here, because it can cause a lot of pain in the future
    
    if(scan_result == false)
        return error_result("Error wrong type have been provided");

    return success_result(value);
}

result_type is_positive(void* value) {
    if(*((int*)value) < 0)
        return error_result("Error provided value is not positive");

    return success_result(value);
}

void add_layer(validator_instance* validator, result_type (*layer)(void*)) {

    int n = validator->count;

    if(n > MAX_VALIDATION_LAYER_COUNT)
        return;

    validator->layers[n] = layer;
    validator->count = n + 1;
}

result_type validate_input(validator_instance* validator_instance) {
    result_type result;
    result.failed = false;

    for(int i = 0; i < validator_instance->count; ++i) {
        result_type res = (*validator_instance->layers[i]) (result.value);
        if(res.failed == true) {
            result = res;
            break;
        }

        result.value = res.value;
    }

    return result;
}

void pop_result(result_type* result) {
    free(result->error);
    free(result->value);
}

void pop_validator_instance(validator_instance* validator) {
    free(validator->layers);
    validator->count = 0;
}

int factorial(int value) {
    return (value == 1 ? 1 : value * factorial(value - 1));
}

int main() {
    printf("This program calculates factorial of provided integer\n");
    printf("Please enter one positive integer: \n");
    
    validator_instance validator = create_validator_instance();
    add_layer(&validator, input_integer);
    add_layer(&validator, is_positive);

    while (true) {
        result_type res = validate_input(&validator);

        if(res.failed == true) {
            pop_result(&res);
            printf("%s \n", res.error);
            printf("Please enter one positive integer: \n");
            continue;
        }

        int value = *((int*)res.value);
        int fact = factorial(value);

        printf("Factorial of %d is %d \n", value, fact);

        printf("Saving result to out.txt \n");
        FILE* file = fopen("out.txt", "w");
        fprintf(file, "%d", fact);
        fclose(file);

        break;
    }
    printf("Program successfully finished\n");
    pop_validator_instance(&validator);
    return 0;
};