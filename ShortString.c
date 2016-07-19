#include "ShortString.h"

struct ShortString * create_shortstring(){
	struct ShortString * str =  malloc(sizeof(struct ShortString));
	str->ptr = NULL;
	str->car = NULL;
	return str;
}


void delete_shortstring(struct ShortString * str){
	if (str->ptr != NULL){
		delete_character(str->ptr);
	}
	free(str);
}

struct Character * create_character(char value){
	struct Character * car =  malloc(sizeof(struct Character));
	car->next = NULL;
	car->value = value;
	return car;
}


void delete_character(struct Character * car){
	if (car->next != NULL){
		delete_character(car->next);
	}
	free(car);
}

void add_character(struct ShortString * str, char value){
	struct Character * car = create_character(value);
	if (str->ptr == NULL){
		str->ptr = car;
		str->car = car;
	}else{
		str->car->next = car;
		str->car = str->car->next;
	}
}


void add_array(struct ShortString * str, char * value){
	int i = 0;
	while (value[i] != '\0'){
		add_character(str, value[i]);
		i ++;
	}
}

