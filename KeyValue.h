#ifndef KEYVALUE_H
#define KEYVALUE_H

#define INT   1
#define CHAR  2
#define HASH  3
#define CCHAR 4
#define CINT  5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShortString.h"
/**
*	KeyValue class
*	key value relations struct
**/
struct KeyValue{
	struct KeyValue * prev;
	struct KeyValue * next;
	
	char type;
	char key[10];
	void * value;
};

/**
* struct HashMap * create_keyvalue(const char * key[10], void * value);
* Create a KeyValue struct
* key: key for map
* value: value for map
**/
struct KeyValue * create_keyvalue(const char key[10], void * value, char type);
/**
* struct HashMap * delete_keyvalue(void);
* Delete a KeyValue struct
* KeyValue: KeyValue to delete
**/
void delete_keyvalue(struct KeyValue * keyvalue);

#endif
