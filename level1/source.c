#include <stdio.h>
#include <stdlib.h>

void run(void) {
    printf("Good... Wait what?\n");
    system("/bin/sh");
}

int main(void) {
    char buffer[80]; 
    
    gets(buffer);
    
    return 0;
}