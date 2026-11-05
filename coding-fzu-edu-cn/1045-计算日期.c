#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool judge_legal_format(char date[]){
    if (strlen(date) != 10)
        return false;
    if (date[2] == '/' && date[5] == '/'){
        char tmp[11];
        tmp[0] = date[6];
        tmp[1] = date[7];
        tmp[2] = date[8];
        tmp[3] = date[9];
        tmp[4] = '-';
        tmp[5] = date[0];
        tmp[6] = date[1];
        tmp[7] = '-';
        tmp[8] = date[3];
        tmp[9] = date[4];
        tmp[10] = '\0';
        strcpy(date, tmp);
    }
    if (!(date[4] == '-' && date[7] == '-'))
        return false;
    for (int i = 0; i < 4; i++)
        if (date[i] < '0' || date[i] > '9') return false;
    for (int i = 5; i <= 6; i++)
        if (date[i] < '0' || date[i] > '9') return false;
    for (int i = 8; i <= 9; i++)
        if (date[i] < '0' || date[i] > '9') return false;
    return true;
}

bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year){
    if (month < 1 || month > 12)
        return -1;
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        return 31;
    if (month == 2)
        return is_leap_year(year) ? 29 : 28;
    return 30;
}

long long count_total(int y, int m, int d){
    long long sum = 0;
    for(int i = 1; i < y; i++){
        if(is_leap_year(i)) sum += 366;
        else sum += 365;
    }
    for(int i = 1; i < m; i++)
        sum += days_in_month(i, y);
    sum += d;
    return sum;
}

int main(){
    char raw_date[10005];
    while (scanf("%s", raw_date) != EOF){
        if (judge_legal_format(raw_date)){
            int year = 0, month = 0, day = 0;
            for (int i = 0; i < 4; i++)
                year = year * 10 + (raw_date[i] - '0');
            for (int i = 5; i <= 6; i++)
                month = month * 10 + (raw_date[i] - '0');
            for (int i = 8; i <= 9; i++)
                day = day * 10 + (raw_date[i] - '0');
            int dim = days_in_month(month, year);
            if (dim == -1 || day < 1 || day > dim){
                printf("Error\n");
                continue;
            }
            long long base = count_total(2004, 3, 1);
            long long now = count_total(year, month, day);
            long long ans = now - base;
            printf("%lld\n", ans);
        }
        else
            printf("Error\n");
    }
    return 0;
}