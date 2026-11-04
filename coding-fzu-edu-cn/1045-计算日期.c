#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int date_num_index[8] = {0, 1, 2, 3, 5, 6, 8, 9};

bool judge_ligal_date(char date[]){
    if(date[2] == '/' || date[5] == '/'){
        char year[4]={date[6], date[7], date[8], date[9]};
        date[5] = date[0]; date[6] = date[1];
        date[8] = date[3], date[9] = date[4];
        for(int i=0;i < 4;i++) date[i] = year[i];
        date[4] = '-'; date[7] = '-';
    }
    return true;
    // if(date[4] != '-' || date[7] != '-'){
    //     if(date[2] != '/' || date[5] != '/') return false;
    //     else{

    //     }
    // }
    // else{
    //     return true;
    // }
}

int main(){
    char raw_date[1005];
    scanf("%s", &raw_date);
    judge_ligal_date(raw_date);
    for(int i=0;i < 10;i++) printf("%c", raw_date[i]);
    return 0;
}