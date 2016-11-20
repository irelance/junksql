#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#define ACSII_UNSIGN 7

typedef struct hash hash;
typedef struct hashElem hashElem;

struct hash{
    int length;
    hashElem *head;
};

struct hashElem{
    char *key, *value;
    hashElem *prev, *next;
};

int str2int(char *, int);

int crc16(char *);

int divHash(char  *, int);

int mutiHash(char *, float, int);

int fibonacci16(char *);

int nohash(char *);

#include "hash.c"

#endif // HASH_H_INCLUDED
