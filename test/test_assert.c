
int assertEquals(char *result1, char *result2){
    if(strcmp(result1,result2)==0){
        printf(".");
        return TRUE;
    } else {
        printf("E");
        return FALSE;
    }
}

int assertNotEquals(char *result1, char *result2){
    if(strcmp(result1,result2)!=0){
        printf(".");
        return TRUE;
    } else {
        printf("E");
        return FALSE;
    }
}

int assertEqualTrue(int result){
    if(result==TRUE){
        printf(".");
        return TRUE;
    } else {
        printf("E");
        return FALSE;
    }
}

int assertEqualFalse(int result){
    if(result==FALSE){
        printf(".");
        return TRUE;
    } else {
        printf("E");
        return FALSE;
    }
}
