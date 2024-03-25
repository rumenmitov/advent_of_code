#include <stdio.h>
#include <string.h>

void arrPush(int* arr, int n, int* isInit);
void replaceWithDigit(char* str, int strIndex, int p_size, int num);
void strSearch(char* str, char* p, int p_size, int digit);
int getTraj(char* str);


int main(void) {

    char buf[255];

    int sum = 0;

    while (fgets(buf, sizeof(buf), stdin)) {
        buf[strlen(buf)-1] = '\0';

        strSearch(buf, "zero", strlen("zero"), 0);
        strSearch(buf, "one", strlen("one"), 1);
        strSearch(buf, "two", strlen("two"), 2);
        strSearch(buf, "three", strlen("three"), 3);
        strSearch(buf, "four", strlen("four"), 4);
        strSearch(buf, "five", strlen("five"), 5);
        strSearch(buf, "six", strlen("six"), 6);
        strSearch(buf, "seven", strlen("seven"), 7);
        strSearch(buf, "eight", strlen("eight"), 8);
        strSearch(buf, "nine", strlen("nine"), 9);

        sum += getTraj(buf);
    }

    printf("sum=%d\n", sum);

    return 0;
}

void arrPush(int* arr, int n, int* isInit) {
    if (*isInit) {
        arr[1] = n;
    } else {
        arr[0] = n;
        arr[1] = n;
        *isInit = 1;
    }
}

void strSearch(char* str, char* p, int p_size, int digit) {

    char* cursor = str;

    int strIndex = 0;
    while (*cursor != '\0') {
        for (int i = 0; i < p_size; ++i) {
            if (*cursor != p[i]) {
                strIndex++;
                cursor++;
                break;
            }

            if (i == p_size - 1) {
                replaceWithDigit(str, strIndex, p_size, digit);
                cursor -= strIndex - p_size + 2;
                printf("string=%s\n", str);
            }

            strIndex++;
            cursor++;
        }

    }
}

void replaceWithDigit(char* str, int strIndex, int p_size, int num) {

    str[strIndex - p_size + 1] = '0' + num;

}

int getTraj(char* str) {

    int arr[2];
    int isInit = 0;

    while (*str != '\0') {
       
        switch (*str) {

            case '0':
                arrPush(arr, 0, &isInit);
                break;

            case '1':
                arrPush(arr, 1, &isInit);
                break;

            case '2':
                arrPush(arr, 2, &isInit);
                break;

            case '3':
                arrPush(arr, 3, &isInit);
                break;

            case '4':
                arrPush(arr, 4, &isInit);
                break;
                
            case '5':
                arrPush(arr, 5, &isInit);
                break;

            case '6':
                arrPush(arr, 6, &isInit);
                break;

            case '7':
                arrPush(arr, 7, &isInit);
                break;
        
            case '8':
                arrPush(arr, 8, &isInit);
                break;

            case '9':
                arrPush(arr, 9, &isInit);
                break;

            default:
                break;
        }

        str++;
    }

    return arr[0] * 10 + arr[1];
}
