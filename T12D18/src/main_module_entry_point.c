#include <stdio.h>

#ifdef PRINT_MODULE
#include "print_module.h"
#endif  //  PRINT_MODULE
#ifdef DOCUMENTATION_MODULE
#include "documentation_module.h"
#endif  //  DOCUMENTATION_MODULE

int main() {
    #ifdef PRINT_MODULE
    print_log(print_char, Module_load_success_message);
    #endif  //  PRINT_MODULE
    #ifdef DOCUMENTATION_MODULE
    int availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output(availability_mask, Documents_count, Documents);
    #endif  //  DOCUMENTATION_MODULE
    return 0;
}
