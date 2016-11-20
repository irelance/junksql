#include "globle.h"

int insertAction(char *key, char *value){
	int i;
	hashElem *h=(hashElem *)malloc(sizeof(hashElem)), *temp;
	(*h).key = key;
	(*h).value = value;
	(*h).next=NULL;
	i = HASH_METHOD(key);
	if(hash_table[i].head==NULL){
		(*h).prev=NULL;
		hash_table[i].head=h;
	} else {
		temp = hash_table[i].head;
		while(strcmp((*temp).key,key)!=0){
			if((*temp).next==NULL){
				break;
			}
			(*h).prev=temp;
			temp = (*temp).next;
		}
		if(strcmp((*temp).key,key)!=0){
			(*temp).next=h;
		} else {
			return FALSE;
		}
	}
	return TRUE;
}

hashElem* selectAction(char *key){
	int i;
	hashElem *temp;
	i = HASH_METHOD(key);
	temp=hash_table[i].head;
	if(strcmp((*temp).key,key)==0){
		return temp;
	}else{
		while((*temp).next!=NULL){
			temp=(*temp).next;
			if(strcmp((*temp).key,key)==0){
				return temp;
			}
		}
	}
	return NULL;
}

int updateAction(char *key, char *value){
	hashElem *temp=selectAction(key);
	if(temp==NULL){
		printf("not such key\n");
		return FALSE;
	}
	free((*temp).value);
	(*temp).value=value;
	return TRUE;
}

int deleteAction(char *key){
	hashElem *temp, *prev, *next;
	temp=selectAction(key);
	if(temp==NULL){
		printf("not such key\n");
		return FALSE;
	}
	prev = (*temp).prev;
	next = (*temp).next;
	if(prev!=NULL){
		(*prev).next = next;
	}
	if(next!=NULL){
		(*next).prev = prev;
	}
	free((*temp).key);
	free((*temp).value);
	free(temp);
	return TRUE;
}
