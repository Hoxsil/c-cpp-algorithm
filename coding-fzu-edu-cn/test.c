#include <stdio.h>

int main(){
    char line[105]; 
    fgets(line, 100, stdin);
    printf("read sentence");
    return 0;
}