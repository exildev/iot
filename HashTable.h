#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "KeyValue.h"

/**
*	HashMap class
*	Has table struct
**/
struct HashTable{
	void * table[78914410];
	void (*on_change)(struct HashTable * hashtable, struct KeyValue * keyvalue);
	void (*notice)(struct HashTable * ht, struct KeyValue * keyvalue);
	void * parent;
	struct KeyValue * ptr;
	struct KeyValue * car;
};

struct List{
	void (*on_change)(struct List * list, struct Value * value);
	void (*notice)(struct List * list, struct Value * value);
	void * parent;
	struct Value * ptr;
	struct Value * car;
};

/**
* struct HashMap * create_hashmap(void);
* Create a HashMap struct
**/
struct HashTable * create_hashtable();

/**
* struct List * create_list(void);
* Create a List struct
**/
struct List * create_list();
/**
* struct hashtable * delete_hashtable(struct hashtable * hashtable);
* Delete a hashtable struct
* hashtable: hashtable to delete
**/
void delete_hashtable(struct HashTable * hashtable);
/**
* struct List * delete_list(struct hashtable * hashtable);
* Delete a list struct
* list: list to delete
**/
void delete_list(struct List * list);
/**
* void hashtable_to_string(struct hashtable * hashtable, int max_inner);
* show a hashtable struct
* hashtable: hashtable to shows
**/
void hashtable_to_string(struct ShortString * str, struct HashTable * hashtable, int max_inner);
/**
* void list_to_string(struct ShortString * str, struct List * list, int max_inner);
* show a hashtable struct
* hashtable: hashtable to shows
**/
void list_to_string(struct ShortString * str, struct List * list, int max_inner);

/**
* keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);
* show a KeyValue struct
* keyvalue: KeyValue to shows
**/
void keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner);

/**
* void value_to_string(struct ShortString * str, struct value * keyvalue, int max_inner);
* show a KeyValue struct
* keyvalue: KeyValue to shows
**/
void value_to_string(struct ShortString * str, struct Value * value, int max_inner);
/**
* void set_keyvalue(struct hashtable * hashtable, const char key[6], void * value);
* Set  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for hashtable
* value: value for hashtable
**/
void set_keyvalue_hashtable(struct HashTable * hashtable, const char key[6], void * value, char type);
/**
* void insert_value_list(struct List * List, int index, void * value);
* Set  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for hashtable
* value: value for hashtable
**/
void insert_value_list(struct List * list, int index, void * value, char type);
/**
* void set_value_list(struct List * List, int index, void * value);
* Set  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for hashtable
* value: value for hashtable
**/
void set_value_list(struct List * list, int index, void * value, char type);
/**
* void append_keyvalue(struct hashtable * hashtable, const char key[6], void * value);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where add the KeyValue
* key: key for map
* value: value for hashtable
**/
struct KeyValue * append_keyvalue(struct HashTable * hashtable, const char key[6], void * value, char type);
/**
* void append_value(struct hashtable * hashtable, const char key[6], void * value);
* Add  a Value to a list
* list: list where add the KeyValue
* value: value for list
**/
struct Value * append_value(struct List * list, void * value, char type);

/**
* void * find_keyvalue(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
struct KeyValue * find_keyvalue_hashtable(struct HashTable * hashtable, const char key[6]);
/**
* void * find_value(struct hashtable * hashtable, const char key[6]);
* Add  a KeyValue to a hashtable
* hashtable: hashtable where find the KeyValue
* key: key witch find
**/
struct Value * find_value_list(struct List * list, int index);
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
