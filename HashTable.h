#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "KeyValue.h"


/**
*	HashMap class
*	Has table struct
**/
struct HashTable{
	void * table[78914410];
	struct KeyValue * ptr;
	struct KeyValue * car;
};

/**
* struct HashMap * create_hashmap(void);
* Create a HashMap struct
**/
struct HashTable * create_hashtable();
/**
* struct hashtable * delete_hashtable(struct hashtable * hashtable);
* Delete a hashtable struct
* hashtable: hashtable to delete
**/
void delete_hashtable(struct HashTable * hashtable);
/**
* void hashtable_to_string(struct hashtable * hashtable, int max_inner);
* show a hashtable struct
* hashtable: hashtable to shows
**/
void hashtable_to_string(struct ShortString * str, struct HashTable * hashtable, int max_inner);

/**
* struct KeyValue * keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);
* show a KeyValue struct
* keyvalue: KeyValue to shows
**/
void keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);

/**
* void add_keyvalue(struct hashtable * hashtable, const char key[6], void * value);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for map
* value: value for map
**/
void set_keyvalue_hashtable(struct HashTable * hashtable, const char key[6], void * value, char type);
struct KeyValue * append_keyvalue(struct HashTable * hashtable, const char key[6], void * value, char type);

/**
* void * find_keyvalue(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
struct KeyValue * find_keyvalue_hashtable(struct HashTable * hashtable, const char key[6]);
/**
* int * find_keyvalue_as_int(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
int * find_int_hashtable(struct HashTable * hashtable, const char key[6]);
/**
* int * find_keyvalue_as_char(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
char * find_char_hashtable(struct HashTable * hashtable, const char key[6]);
/**
* int * find_keyvalue_as_hashtable(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
struct HashTable * find_hashtable(struct HashTable * hashtable, const char key[6]);

/**
* void * find_keyvalue(struct HashMap * hashmap, const char key[10]);
* Add  a KeyValue to a HashMap
* hashmap: HashMap where find the KeyValue
* key: key witch find
**/
struct KeyValue * find_keyvalue_tree(struct HashTable * hashmap, const char key[6]);

/**
* void set_keyvalue_tree(struct hashtable * hashtable, const char key[6], void * value);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for map
* value: value for map
**/
void set_keyvalue_tree(struct HashTable * hashtable, const char key[6], void * value, char type);

/**
* int * find_keyvalue_as_hashtable(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
struct HashTable * find_hashtable(struct HashTable * hashtable, const char key[6]);
#endif
