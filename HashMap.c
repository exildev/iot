#include "HashMap.h"

struct HashMap * create_hashmap(){
	struct HashMap * hm =  malloc(sizeof(struct KeyValue));
	hm->ptr = NULL;
	return hm;
}

void delete_hashmap(struct HashMap * hashmap){
	if (hashmap->ptr != NULL){
		delete_keyvalue(hashmap->ptr);
	}
	free(hashmap);
}


void hashmap_to_string(struct ShortString * str, struct HashMap * hashmap, int max_inner){
	add_array(str, "{");
	if (max_inner > 0){
		struct KeyValue * car = hashmap->ptr;
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

void delete_keyvalue(struct KeyValue * keyvalue){
	if (keyvalue->next != NULL){
		delete_keyvalue(keyvalue->next);
	}
	free(keyvalue);
}

void keyvalue_to_string(struct ShortString * str, struct KeyValue * keyvalue, int max_inner){
	add_array(str, "\"");
	add_array(str, keyvalue->key);
	add_array(str, "\":");
	if (keyvalue->type == INT){
		char string[25];
		int * integer = keyvalue->value;
		itoa(*integer, string, 10);
		add_array(str, string);
		
	}else
	if (keyvalue->type == CHAR){
		char string[25];
		strcpy(string, keyvalue->value);
		add_array(str, "\"");
		add_array(str, string);
		add_array(str, "\"");
	}else
	if (keyvalue->type == HASH){
		struct HashMap * map = keyvalue->value;
		hashmap_to_string(str, map, max_inner);
	}
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

void set_keyvalue(struct HashMap * hashmap, const char key[10], void * value, char type){
	struct KeyValue * kv = find_keyvalue(hashmap, key);
	if (kv != NULL){
		kv->value = value;
	}else{
		kv = create_keyvalue(key, value, type);
		if (hashmap->ptr == NULL){
			hashmap->ptr = kv;
			hashmap->car = kv;
		}else{
			hashmap->car->next = kv;
			hashmap->car->next->prev = hashmap->ptr;
			hashmap->car = kv;
		}
	}
}

struct KeyValue * find_keyvalue(struct HashMap * hashmap, const char key[10]){
	struct KeyValue * car = hashmap->ptr;
	while (car != NULL){
		if (strcmp(car->key, key) == 0){
			return car;
		}
		car = car->next;
	}
	return NULL;
}

int * find_int(struct HashMap * hashmap, const char key[10]){
	struct KeyValue * keyvalue = find_keyvalue(hashmap, key);
	if (keyvalue != NULL){
		return  (int *)(keyvalue->value);
	}
	return NULL;
}

char * find_char(struct HashMap * hashmap, const char key[10]){
	struct KeyValue * keyvalue = find_keyvalue(hashmap, key);
	if (keyvalue != NULL){
		return  (char *)(keyvalue->value);
	}
	return NULL;
}

struct HashMap * find_hashmap(struct HashMap * hashmap, const char key[10]){
	struct KeyValue * keyvalue = find_keyvalue(hashmap, key);
	if (keyvalue != NULL){
		return  (struct HashMap *)(keyvalue->value);
	}
	return NULL;
}
