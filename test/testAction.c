#include "test.h"

void insertActionTest(){
    char *key,*value;
    hashElem *t;
    /**
     * base insert test
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="a";
    value="1";
    //can insert
    assertEqaulTrue(insertAction(key,value));
    t = selectAction(key);
    //insert right
    assertEqauls((*t).value,value);
    /**
     * insert test: if other key make the same hash key, can it insert
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="b";
    value="2";
    t = selectAction(key);
    assertEqauls((*t).value,value);
    /**
     * insert test: if the same key do an insert action, if ignore
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="a";
    value="2";
    t = selectAction(key);
    assertNotEquals((*t).value,value);
}

void selectActionTest(){
    char *key,*value;
    int i;
    hashElem *t;
    /**
     * base select test
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="a";
    value="1";
    t = selectAction(key);
    assertEqauls((*t),NULL);
    insertAction(key,value);
    t = selectAction(key);
    assertEqauls((*t).value,value);
}

void updateActionTest(){
    char *key,*value;
    int i;
    hashElem *t;
    /**
     * base update test
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="a";
    value="1";
    insertAction(key,value);
    value=(char *)malloc(255 * sizeof(char));
    value="2";
    updateAction(key,value);
    t = selectAction(key);
    assertEqauls((*t).value,value);
}

void deleteActionTest(){
    char *key,*value;
    int i;
    hashElem *t;
    /**
     * base delete test
     */
    key=(char *)malloc(255 * sizeof(char));
    value=(char *)malloc(255 * sizeof(char));
    key="a";
    value="1";
    insertAction(key,value);
    deleteAction(key,value);
    t = selectAction(key);
    assertEqauls((*t).value,NULL);
}

