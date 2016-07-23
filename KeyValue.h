#ifndef KEYVALUE_H
#define KEYVALUE_H

#define INT   1
#define CHAR  2
#define HASH  3
#define LIST  4
#define CCHAR 5
#define CINT  6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShortString.h"

/**
*	KeyValue class
*	key value relations struct
**/
struct KeyValue {
	struct KeyValue * prev;
	struct KeyValue * next;
	void (*on_change)(struct KeyValue * keyvalue, void * value);
	void (*notice)(struct KeyValue * kv, void * value);
	void * parent_obj;
	void * parent_fnc;
	char type;
	char key[10];
	void * value;
};

/**
*	Value class
*	Kalue relations struct
**/
struct Value {
	struct Value * prev;
	struct Value * next;
	void (*on_change)(struct Value * val, void * value);
	void (*notice)(struct Value * val, void * value);
	void * parent_obj;
	void * parent_fnc;
	char type;
	void * value;
};

/**
* struct KeyValue * create_keyvalue(const char * key[10], void * value);
* Create a KeyValue struct
* key: key for map
* value: value for map
**/
struct KeyValue * create_keyvalue(const char key[10], void * value, char type, void * parent_obj, void * parent_fnc);
/**
* void delete_keyvalue(void);
* Delete a KeyValue struct
* KeyValue: KeyValue to delete
**/
void delete_keyvalue(struct KeyValue * keyvalue);
/**
* struct Value * create_value(void * value);
* Create a KeyValue struct
* value: value for list
**/
struct Value * create_value( void * value, char type, void * parent_obj, void * parent_fnc);
/**
* void delete_keyvalue(void);
* Delete a KeyValue struct
* KeyValue: KeyValue to delete
**/
void delete_value(struct Value * value);

void update_keyvalue(struct KeyValue * keyvalue, void * value, char type);
void update_value(struct Value * val, void * value, char type);

#endif
