#include <stdio.h>
#include <sys/stat.h>   // stat
#include <stdbool.h>    // bool type


int main() {
    char filename[40];
    scanf("%s", filename);
    if(file_exists(filename))
        printf("existe");
    else
        printf("não existe");
}