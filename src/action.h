#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED


//row action
int insertAction(char *, char *);

hashElem* selectAction(char *);

int updateAction(char *, char *);

int deleteAction(char *);

#include "action.c"

#endif // ACTION_H_INCLUDED
