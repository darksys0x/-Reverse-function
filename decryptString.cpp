// Reverse a decryptFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <Windows.h>
#include <stdint.h>

char* DecryptString(int a1)
{
    int i; // edx
    int v2; // eax
    char v4[76]; // [esp+10h] [ebp-4Ch] BYREF

    static uint8_t key[64] = {
        0x5F, 0x42, 0x71, 0x77, 0x48, 0x61, 0x46, 0x38, 0x54, 0x6B, 0x4B, 0x44, 0x4D, 0x66, 0x4F, 0x7A,
        0x51, 0x41, 0x53, 0x78, 0x34, 0x56, 0x75, 0x58, 0x64, 0x5A, 0x69, 0x62, 0x55, 0x49, 0x65, 0x79,
        0x6C, 0x4A, 0x57, 0x68, 0x6A, 0x30, 0x6D, 0x35, 0x6F, 0x32, 0x45, 0x72, 0x4C, 0x74, 0x36, 0x76,
        0x47, 0x52, 0x4E, 0x39, 0x73, 0x59, 0x31, 0x6E, 0x33, 0x50, 0x70, 0x63, 0x37, 0x67, 0x2D, 0x43 };

    memcpy(v4, key, 64);

    static char output[250];
    memcpy(output, (char*)a1, strlen((char*)a1));

    for (i = (int)&output; *(BYTE*)i; ++i)
    {
        v2 = 0;
        while (*(BYTE*)i != v4[v2])
        {
            if (++v2 == 64)
                goto LABEL_7;
        }
        *(BYTE*)i = v4[(v2 + 6) & 0x3F];
    LABEL_7:
        printf("test1\n");
    }
    return output;
}

char* DecryptString(char* encryptedStr)
{
    static uint8_t key[64] = {
        0x5F, 0x42, 0x71, 0x77, 0x48, 0x61, 0x46, 0x38, 0x54, 0x6B, 0x4B, 0x44, 0x4D, 0x66, 0x4F, 0x7A,
        0x51, 0x41, 0x53, 0x78, 0x34, 0x56, 0x75, 0x58, 0x64, 0x5A, 0x69, 0x62, 0x55, 0x49, 0x65, 0x79,
        0x6C, 0x4A, 0x57, 0x68, 0x6A, 0x30, 0x6D, 0x35, 0x6F, 0x32, 0x45, 0x72, 0x4C, 0x74, 0x36, 0x76,
        0x47, 0x52, 0x4E, 0x39, 0x73, 0x59, 0x31, 0x6E, 0x33, 0x50, 0x70, 0x63, 0x37, 0x67, 0x2D, 0x43 };

    static uint8_t output[250];
    memcpy(output, encryptedStr, strlen(encryptedStr));

    for (int i = 0; i < strlen(encryptedStr); i++) {
        if (output[i] == '\0')
            break;
        for (int j = 0; j < 64; j++) {
            if (output[i] == key[j]) {
                output[i] = key[(j + 6) & 0x3F];
                break;
            }
        }

    }
    return (char*)output;
}



int __cdecl strchr(unsigned __int8 a1, char* pStr)
{
    int i; // eax
    bool isStrNull; // zf
    char v4; // cl

    i = 0;
    isStrNull = pStr == 0;
    while (!isStrNull)
    {
        v4 = pStr[i];
        if (!v4)
            return -1;
        isStrNull = v4 == (char)a1;
        ++i;
    }
    return i;
}

unsigned int __cdecl sub_4129FB(char* in, char a2, int inputSize, char* output, unsigned int outputSize)
{
    int v6; // ebp
    int v7; // eax
    int i; // ecx
    unsigned int j; // ecx
    int v10; // [esp+10h] [ebp-14h]

    if (!in)
        return -1;
    v6 = 0;
    memset(output, 0, outputSize);
    v7 = strchr(a2, in);                     // the first occurrence of the character
    for (i = 0; i < inputSize - 1; i = v10 + 1)
    {
        v10 = i;
        if (v7 == -1)
            return -1;
        v6 += v7;
        v7 = strchr(a2, &in[v6]);
    }
    printf("v6 = %d, v7 = %d\n", v6, v7);
    int ccc = 0;
    for (j = 0; v6 + v7 - 1 > j + v6 && j < outputSize; ++j) {
        output[j] = in[v6 + j];
    }
    output[j] = '\0';
    return j;
}

int main() {

    char in[] = "C:/Users/DFIR/Desktop/folder1/folder2/folderOIP/folderk/folder6/uik.exe";
    char output[150];
    sub_4129FB(in, '/', 1, output, sizeof(in));
    printf("in = %s\n", in);
    printf("ouput = %s\n", output);

    uint8_t strBytes[] = {
0x45,0x64,0x35,0x46,0x57,0x53,0x51,0x69,0x64,0x5F,0x34,0x69,0x64,0x4C,0x43,0x6C,
0x64,0x6A,0x66,0x44,0x00,0x70,0x73,0x61,0x70,0x69,0x2E,0x64,0x6C,0x6C,0x00,0x6B
    };
    char* str = DecryptString((char*)strBytes);
    printf("str = %s\n", str);
    return 0;
}