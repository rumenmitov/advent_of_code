#include <stdio.h>
#include <string.h>

void arrPush(int* arr, int n, int* isInit);
int getTraj(char* str);

int main(void) {

    char buf[255];

    int sum = 0;
    while (fgets(buf, sizeof(buf), stdin)) {
        buf[strlen(buf)-1] = '\0';
        sum += getTraj(buf);
    }
    printf("sum=%d\n", sum);
    return 0;
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

void arrPush(int* arr, int n, int* isInit) {
    if (*isInit) {
        arr[1] = n;
    } else {
        arr[0] = n;
        arr[1] = n;
        *isInit = 1;
    }
}
