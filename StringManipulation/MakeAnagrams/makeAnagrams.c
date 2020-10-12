#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>


const char* sortString(char* string)
{
    int i, j;
    int n = strlen(string);
    char temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    return string;
}

int makeAnagram(char* a, char* b)
{
    // get the length of both strings
    int lenA = strlen(a);
    int lenB = strlen(b);
    // sort the two strings 
    const char* sortA = sortString(a);
    const char* sortB = sortString(b);
    int commLen;
    if (lenA > lenB)
    {
        printf("lenA: %d > lenB: %d\n", lenA, lenB);
        commLen = lenA;
    }
    else
    {
        printf("lenA: %d < lenB: %d\n", lenA, lenB);
        commLen = lenB;
    }
    char common[2*commLen];
    int i, j, index;
    index = 0;
    // note to self -> need to make sure that we pad the end of the shorter string
    for (i = 0; i < lenA; i++)
    {
        common[i] = sortA[i];
        index++;
    }
    common[index+1] = '-';
    for (j = 0; j < lenB; j++)
    {
        common[++index] = sortB[j];
    }
    for (i = 0; i < 2*commLen; i++)
    {
        printf("common[%d]: %c\n", i, common[i]);
    }
    //

    return 0;
}

int main()
{
    char* a = "cde";
    char* b = "abcgj";

    int result = makeAnagram(a, b);
    printf("The number of deletions is: %d\n", result);
}
