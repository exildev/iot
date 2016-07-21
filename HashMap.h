#ifndef HASHMAP_H
#define HASHMAP_H

#define INT  1
#define CHAR 2
#define HASH 3

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
*	HashMap class
*	Has map struct
**/
struct HashMap{
	struct KeyValue * ptr;
	struct KeyValue * car;
};

/**
* struct HashMap * create_hashmap(void);
* Create a HashMap struct
**/
struct HashMap * create_hashmap();
/**
* struct HashMap * delete_hashmap(struct HashMap * hashmap);
* Delete a HashMap struct
* hashmap: HashMap to delete
**/
void delete_hashmap(struct HashMap * hashmap);
/**
* void hashmap_to_string(struct HashMap * hashmap, int max_inner);
* show a HashMap struct
* hashmap: HashMap to shows
**/
void hashmap_to_string(struct ShortString * str, struct HashMap * hashmap, int max_inner);

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
/**
* struct KeyValue * keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);
* show a KeyValue struct
* keyvalue: KeyValue to shows
**/
void keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);

/**
* void add_keyvalue(struct HashMap * hashmap, const char key[10], void * value);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where add the KeyValue
* key: key for map
* value: value for map
**/
void set_keyvalue(struct HashMap * hashmap, const char key[10], void * value, char type);

/**
* void * find_keyvalue(struct HashMap * hashmap, const char key[10]);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where find the KeyValue
* key: key witch find
**/
struct KeyValue * find_keyvalue(struct HashMap * hashmap, const char key[10]);
/**
* int * find_keyvalue_as_int(struct HashMap * hashmap, const char key[10]);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where find the KeyValue
* key: key witch find
**/
int * find_int(struct HashMap * hashmap, const char key[10]);
/**
* int * find_keyvalue_as_char(struct HashMap * hashmap, const char key[10]);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where find the KeyValue
* key: key witch find
**/
char * find_char(struct HashMap * hashmap, const char key[10]);
/**
* int * find_keyvalue_as_hashmap(struct HashMap * hashmap, const char key[10]);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where find the KeyValue
* key: key witch find
**/
struct HashMap * find_hashmap(struct HashMap * hashmap, const char key[10]);
#endif
