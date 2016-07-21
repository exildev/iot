#include "KeyValue.h"

void delete_keyvalue(struct KeyValue * keyvalue){
	if (keyvalue->next != NULL){
		delete_keyvalue(keyvalue->next);
	}
	free(keyvalue);
}

struct KeyValue * create_keyvalue(const char key[10], void * value, char type){
    struct KeyValue * kv = malloc(sizeof(struct KeyValue));
	strcpy(kv->key, key);
	kv->value = value;
	kv->prev = NULL;
	kv->next = NULL;
	kv->type = type;
	return kv;
}

