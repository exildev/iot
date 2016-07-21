#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"


char test(struct HashTable* map){
	set_keyvalue_hashtable(map, "hola", "mundo", CHAR);
	return 1;
}


int main(int argc, char *argv[]) {
	struct HashTable * map = create_hashtable(); 
	
	create_sensor("s1", &test);
	create_sensor("s2", &test);
	read_sensors(map);
	
	struct ShortString * str = create_shortstring();
	hashtable_to_string(str, map, 3);
	struct Character * car = str->ptr;
	
	while (car != NULL){
		printf("%c", car->value);
		car = car->next;
	}
	
	delete_shortstring(str);
	
	delete_hashtable(map);
}

