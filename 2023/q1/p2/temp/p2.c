#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int i;
    int val;
} StrIndex;

void findOccurances
    (const char* str, const char* p, int digit, StrIndex* minIndex, StrIndex* maxIndex,
     int* isInit);


void setIndices(StrIndex* minIndex, StrIndex* maxIndex, int i, int digit, int* isInit);

int main(void) {

    StrIndex minIndex = { .i = 0, .val = 0 }, maxIndex = { .i = 0, .val = 0};
    int isInit = 0;

    int sum = 0;

    char buf[255];

    while(fgets(buf, sizeof(buf), stdin)) {
        buf[strlen(buf)-1] = '\0';

        findOccurances(buf, "zero", 0, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "one", 1, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "two", 2, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "three", 3, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "four", 4, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "five", 5, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "six", 6, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "seven", 7, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "eight", 8, &minIndex, &maxIndex, &isInit);
        findOccurances(buf, "nine", 9, &minIndex, &maxIndex, &isInit);

        sum += minIndex.val * 10 + maxIndex.val;

        minIndex.i = 0;
        minIndex.val = 0;
        maxIndex.i = 0;
        maxIndex.val = 0;
        isInit = 0;

    }

    printf("sum=%d\n", sum);

    return 0;
}

void findOccurances
    (const char* str, const char* p, int digit, StrIndex* minIndex, StrIndex* maxIndex,
     int* isInit) {

    for(int i = 0; i < strlen(str); i++) {
        if (str[i] == '0' + digit) {
            setIndices(minIndex, maxIndex, i, digit, isInit);
            continue;
        }

        for (int p_i = 0; p_i < strlen(p); p_i++) {
            if (tolower(str[i + p_i]) != p[p_i]) {
                break;
            }

            if (p_i == strlen(p) - 1) {
                setIndices(minIndex, maxIndex, i, digit, isInit);
            }
        }



    }

}

void setIndices(StrIndex* minIndex, StrIndex* maxIndex, int i, int digit, int* isInit) {
    if ( *isInit == 0 ) {
        minIndex->i = i;
        minIndex->val = digit;
        maxIndex->i = i;
        maxIndex->val = digit;

        *isInit = 1;

    } else {
        if (minIndex->i > i) {
            minIndex->i = i;
            minIndex->val = digit;
        }

        if (maxIndex->i < i) {
            maxIndex->i = i;
            maxIndex->val = digit;
        }

    }

}

