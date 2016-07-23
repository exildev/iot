#include "HashTable.h"
#include <math.h>

struct KeyValue * create_keyvalue_this(const char key[10], void * value, char type, struct HashTable * parent){
	struct KeyValue * keyvalue = create_keyvalue(key, value, type, parent, parent->notice);
	if (type == HASH){
		struct HashTable * hashtable = value;
		hashtable->parent = keyvalue->notice;
	}else
	if (type == LIST){
		struct List * list = value;
		list->parent = keyvalue->notice;
	}
	return keyvalue;
}

struct Value * create_value_this(void * value, char type, struct List * parent){
	struct Value * val = create_value(value, type, parent, parent->notice);
	if (type == HASH){
		struct HashTable * hashtable = value;
		hashtable->parent = val->notice;
	}else
	if (type == LIST){
		struct List * list = value;
		list->parent = val->notice;
	}
	return val;
}


struct HashTable * create_hashtable(){
	struct HashTable * ht =  malloc(sizeof(struct HashTable));
	ht->ptr = NULL;
	ht->car = NULL;
	ht->on_change = NULL;
	
	void notice (struct HashTable * ht, struct KeyValue * keyvalue){
		if (ht->on_change != NULL){
			ht->on_change(ht, keyvalue);
		}
		if (ht->parent != NULL){
			void (*parent)(void * value);
			parent = ht->parent;
			parent(ht);
		}
	}
	ht->notice = notice;
	ht->parent = NULL;
	return ht;
}

struct List * create_list(){
	struct List * list =  malloc(sizeof(struct List));
	list->ptr = NULL;
	list->car = NULL;
	list->on_change = NULL;
	void notice (struct List * list, struct Value * value){
		if (list->on_change != NULL){
			list->on_change(list, value);
		}
		if (list->parent != NULL){
			void (*parent)(void * value);
			parent = list->parent;
			parent(list);
		}
	}
	list->notice = notice;
	list->parent = NULL;
	return list;
}

void delete_hashtable(struct HashTable * ht){
	if (ht->ptr != NULL){
		delete_keyvalue(ht->ptr);
	}
	free(ht);
}


void delete_list(struct List * list){
	if (list->ptr != NULL){
		delete_value(list->ptr);
	}
	free(list);
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

void list_to_string(struct ShortString * str, struct List * list, int max_inner){
	add_array(str, "[");
	if (max_inner > 0){
		struct Value * car = list->ptr;
		while (car != NULL){
			value_to_string(str, car, max_inner - 1);
			if (car->next != NULL){
				add_array(str, ", ");
			}
			car = car->next;
		}
	}
	add_array(str, "]");
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
	}else
	if (keyvalue->type == LIST){
		struct List * list = keyvalue->value;
		list_to_string(str, list, max_inner);
	}
}


void value_to_string(struct ShortString * str, struct Value * value, int max_inner){
	if (value->type == INT || value->type == CINT){
		char string[25];
		int * integer = value->value;
		itoa(*integer, string, 10);
		add_array(str, string);
		
	}else
	if (value->type == CHAR || value->type == CCHAR){
		char string[25];
		strcpy(string, value->value);
		add_array(str, "\"");
		add_array(str, string);
		add_array(str, "\"");
	}else
	if (value->type == HASH){
		struct HashTable * map = value->value;
		hashtable_to_string(str, map, max_inner);
	}else
	if (value->type == LIST){
		struct List * list = value->value;
		list_to_string(str, list, max_inner);
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
		if (kv->type == HASH){
			delete_hashtable(kv->value);
		}else
		if (kv->type == LIST){
			delete_list(kv->value);
		}else{
			if (kv->type != CINT && kv->type != CCHAR){
				free(kv->value);
			}
		}
	}
	update_keyvalue(kv, value, type);

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
	struct KeyValue * kv = create_keyvalue_this(key, value, type, hashtable);
	if (hashtable->ptr == NULL){
		hashtable->ptr = kv;
		hashtable->car = kv;
	}else{
		hashtable->car->next = kv;
		hashtable->car->next->prev = hashtable->car;
		hashtable->car = kv;
	}
	return kv;
}


struct Value * append_value(struct List * list, void * value, char type){
	struct Value * val = create_value_this(value, type, list);
	if (list->ptr == NULL){
		list->ptr = val;
		list->car = val;
	}else{
		list->car->next = val;
		list->car->next->prev = list->car;
		list->car = val;
	}
	list->notice(list, value);
	return val;
}

void set_keyvalue_tree(struct HashTable * hashtable, const char key[10], void * value, char type){
	struct KeyValue * kv = find_keyvalue_tree(hashtable, key);
	if (kv != NULL){
		kv->value = value;
	}else{
		append_keyvalue(hashtable, key, value, type);
	}
	kv->notice(kv, value);
}

void insert_value_list(struct List * list, int index, void * value, char type){
	struct Value * car = list->ptr;
	int i = 0;
	while (car != NULL){
		if (i >= index){
			struct Value * val = create_value_this(value, type, list);
			struct Value * aux = car;
			if (car != list->ptr){
				car->prev->next = val;
				val->prev = car->prev;
			}else{
				list->ptr = val;
			}
			val->next = car;
			car->prev = val;
			list->notice(list, value);
			return;
		}
		car = car->next;
		i ++;
	}
}

void set_value_list(struct List * list, int index, void * value, char type){
	struct Value * car = list->ptr;
	int i = 0;
	while (car != NULL){
		if (i >= index){
			if (car->type == HASH){
				delete_hashtable(car->value);
			}else
			if (car->type == LIST){
				delete_list(car->value);
			}else
			if (car->type != CINT && car->type != CCHAR){
				free(car->value);
			}
			update_value(car, value, type);
			return;
		}
		car = car->next;
		i ++;
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


struct Value * find_value_list(struct List * list, int index){
	struct Value * car = list->ptr;
	int i = 0;
	while (car != NULL){
		if (index >= i){
			return car;
		}
		car = car->next;
		i ++;
	}
	return NULL;
}


