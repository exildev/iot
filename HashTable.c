#include "HashTable.h"
#include <math.h>

struct HashTable * create_hashtable(){
	struct HashTable * ht =  malloc(sizeof(struct HashTable));
	return ht;
}

void delete_hashtable(struct HashTable * ht){
	if (ht->ptr != NULL){
		delete_keyvalue(ht->ptr);
	}
	free(ht);
}

void hashtable_to_string(struct ShortString * str, struct HashTable * hashtable, int max_inner){
	add_array(str, "{");
	if (max_inner > 0){
		struct KeyValue * car = hashtable->ptr;
		while (car != NULL){
			keyvalue_to_string(str, car, max_inner - 1);
			if (car->next != NULL){
				add_array(str, ", ");
			}
			car = car->next;
		}
	}
	add_array(str, "}");
}


void keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner){
	add_array(str, "\"");
	add_array(str, keyvalue->key);
	add_array(str, "\":");
	if (keyvalue->type == INT || keyvalue->type == CINT){
		char string[25];
		int * integer = keyvalue->value;
		itoa(*integer, string, 10);
		add_array(str, string);
		
	}else
	if (keyvalue->type == CHAR || keyvalue->type == CCHAR){
		char string[25];
		strcpy(string, keyvalue->value);
		add_array(str, "\"");
		add_array(str, string);
		add_array(str, "\"");
	}else
	if (keyvalue->type == HASH){
		struct HashTable * map = keyvalue->value;
		hashtable_to_string(str, map, max_inner);
	}
}

int hash(const  char * str) {
	int i = 0;
	int hash = 0;
	int val;
	while (str[i] != '\0'){
		if (str[i] > 32 && str[i] <= 126) {
			val = pow(94, i)*(str[i] - 32);
			hash += val;
		}
		i++;
	}
	return hash;
}

void set_keyvalue_hashtable(struct HashTable * hashtable, const char key[6], void * value, char type){
	int hashVal = hash(key);
	struct KeyValue * kv;
	if (hashtable->table[hashVal] == NULL){
		kv = append_keyvalue(hashtable, key, value, type);
		hashtable->table[hashVal] = kv;
	}else{
		kv = hashtable->table[hashVal];
		if (type == HASH){
			delete_hashtable(kv->value);
		}else{
			if (kv->type != CINT && kv->type != CCHAR){
				free(value);
			}
		}
		kv->type = type;
		kv ->value = value;
	}
}

struct KeyValue * find_keyvalue_hashtable(struct HashTable * hashtable, const char key[6]){
	int hashVal = hash(key);
	return (struct KeyValue *)hashtable->table[hashVal];
}

int * find_int_hashtable(struct HashTable * hashtable, const char key[6]){
	struct KeyValue * keyvalue = find_keyvalue_hashtable(hashtable, key);
	if (keyvalue != NULL){
		return  (int *)(keyvalue->value);
	}
	return NULL;
}

char * find_char_hashtable(struct HashTable * hashtable, const char key[6]){
	struct KeyValue * keyvalue = find_keyvalue_hashtable(hashtable, key);
	if (keyvalue != NULL){
		return  (char *)(keyvalue->value);
	}
	return NULL;
}

struct HashTable * find_hashtable(struct HashTable * hashtable, const char key[6]) {
	struct KeyValue * keyvalue = find_keyvalue_hashtable(hashtable, key);
	if (keyvalue != NULL){
		return  (struct HashTable *)(keyvalue->value);
	}
	return NULL;
}

struct KeyValue * append_keyvalue(struct HashTable * hashtable, const char key[6], void * value, char type){
	struct KeyValue * kv = kv = create_keyvalue(key, value, type);
	if (hashtable->ptr == NULL){
		hashtable->ptr = kv;
		hashtable->car = kv;
	}else{
		hashtable->car->next = kv;
		hashtable->car->next->prev = hashtable->ptr;
		hashtable->car = kv;
	}
	return kv;
}

void set_keyvalue_tree(struct HashTable * hashtable, const char key[10], void * value, char type){
	struct KeyValue * kv = find_keyvalue_tree(hashtable, key);
	if (kv != NULL){
		kv->value = value;
	}else{
		append_keyvalue(hashtable, key, value, type);
	}
}

struct KeyValue * find_keyvalue_tree(struct HashTable * hashtable, const char key[10]){
	struct KeyValue * car = hashtable->ptr;
	while (car != NULL){
		if (strcmp(car->key, key) == 0){
			return car;
		}
		car = car->next;
	}
	return NULL;
}


