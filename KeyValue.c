#include "KeyValue.h"
#include <stdio.h>

void delete_keyvalue(struct KeyValue * keyvalue){
	if (keyvalue->next != NULL){
		delete_keyvalue(keyvalue->next);
	}
	free(keyvalue);
}

struct KeyValue * create_keyvalue(const char key[10], void * value, char type, void * parent_obj, void * parent_fnc){
    struct KeyValue * kv = malloc(sizeof(struct KeyValue));
	strcpy(kv->key, key);
	kv->value = value;
	kv->prev = NULL;
	kv->next = NULL;
	kv->type = type;
	kv->on_change = NULL;
	kv->parent_obj = parent_obj;
	kv->parent_fnc = parent_fnc;
	void notice (struct KeyValue * kv, void * value){
		if (kv->on_change != NULL){
			kv->on_change(kv, value);
		}
		if (kv->parent_obj != NULL && kv->parent_fnc != NULL){
			void (*parent)(void * obj, struct KeyValue * value);
			parent = kv->parent_fnc;
			parent(kv->parent_obj, kv);
		}
	}
	kv->notice = notice;
	return kv;
}


struct Value * create_value(void * value, char type, void * parent_obj, void * parent_fnc){
	struct Value * val = malloc(sizeof(struct Value));
	val->value = value;
	val->prev = NULL;
	val->next = NULL;
	val->type = type;
	val->on_change = NULL;
	val->parent_obj = parent_obj;
	val->parent_fnc = parent_fnc;
	void notice (struct Value * val, void * value){
		if (val->on_change != NULL){
			val->on_change(val, value);
		}
		if (val->parent_obj != NULL && val->parent_fnc != NULL){
			void (*parent)(void * obj, struct Value * value);
			parent = val->parent_fnc;
			parent(val->parent_obj, val);
		}
	}
	val->notice = notice;
	return val;
	
}

void delete_value(struct Value * value){
	if (value->next != NULL){
		delete_value(value->next);
	}
	free(value);
}

void update_keyvalue(struct KeyValue * keyvalue, void * value, char type){
	keyvalue->value = value;
	keyvalue->type = type;
	keyvalue->notice(keyvalue, value);
}

void update_value(struct Value * val, void * value, char type){
	val->value = value;
	val->type = type;
	val->notice(val, value);
}


