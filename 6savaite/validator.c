#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALIDATION_LAYER_COUNT 5

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

void pop_validator_instance(validator_instance* validator) {
    free(validator->layers);
    validator->count = 0;
}

//lets for now assume that 'a' is integer
result_type input_integer(void *a) {
    void* value = malloc(sizeof(int));    
    bool scan_result = scanf("%d", value);
     fflush(stdin); //Lets clear error buffer here, because it can cause a lot of pain in the future

    if(scan_result == false) {
        free(value);
        return error_result("Error wrong type have been provided");
    }

    return success_result(value);
}

result_type is_positive(void* value) {
    if(*((int*)value) < 0)
        return error_result("Error provided value is not positive");

    return success_result(value);
}

result_type is_even(void* value) {
    if(*((int*)value) % 2 != 0)
        return error_result("Error provided value is not even");

    return success_result(value);
}

result_type is_in_limit(void* value) {
    if(*((int*)value) + 1 < *((int*)value))
        return error_result("Error provided value is not integer limit");

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

    printf("VALIDATING INPUT \n");

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


int p() {
    int value;
    int res = scanf("%d", &value);
    printf("%d", value);
    return res;
}

int main() {
    /*
    result_type res = ...

    res.value -> returns pointer to value(should be casted to needed type)
    res.failed -> Boolean true if failed, false if successful
    res.error -> Error message
    */
    
    validator_instance validator = create_validator_instance();
        add_layer(&validator, input_integer);
        add_layer(&validator, is_positive);
        add_layer(&validator, is_even);
        //add_layer(&validator, is_in_limit);
    
    while(true) {
        result_type res = validate_input(&validator);

        if(res.failed == true) {
            printf("FAILED %s \n", res.error);
        } else {
            printf("COOL \n");
            break;
        }

        pop_result(&res);
    }
    
    return 0;
};