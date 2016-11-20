#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "globle.h"

int assertEquals(char *, char *);

int assertNotEquals(char *, char *);

int assertEqualTrue(int);

int assertEqualFalse(int);

#include "test.c"

#endif // TEST_H_INCLUDED
