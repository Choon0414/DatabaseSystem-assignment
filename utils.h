#ifndef UTILS_H
#define UTILS_H

#include <string>

// SUPPLIER 고정길이 구조체
struct Supplier {
    int suppKey;                   // 4 bytes
    char name[20];                 // 20 bytes
    char address[50];              // 50 bytes
    int nationKey;                 // 4 bytes
    char phone[15];                // 15 bytes
    double acctBal;                // 8 bytes
    char comment[100];             // 100 bytes
};

// NATION 고정길이 구조체
struct Nation {
    int nationKey;                 // 4 bytes
    char name[20];                 // 20 bytes
    int regionKey;                 // 4 bytes
    char comment[100];             // 100 bytes
};

#endif // UTILS_H