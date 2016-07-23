#include <stdio.h>
#include <stdlib.h>
#include "Sensor.h"

char test(struct Manager * man){
	man->emitChar("hola", "mundo");
	return 1;
}

char test2(struct Manager * man){
	
	struct HashTable * hs = create_hashtable();
	set_keyvalue_hashtable(hs, "pet", "kitty", CCHAR);
	man->emitHash("hola", hs);
	return 1;
}

char test3(struct Manager * man){
	
	struct List * li = create_list();
	append_value(li, "dog", CCHAR);
	append_value(li, "dog", CCHAR);
	append_value(li, "dog", CCHAR);
	append_value(li, "dog", CCHAR);
	set_value_list(li, 3, "cat", CCHAR);
	man->emitList("hola", li);
	return 1;
}

char set(struct KeyValue * kv){
	printf("El actuador se mueve porque cambio la key %s\n", kv->key);
	return 1;
}

int main(int argc, char *argv[]) {
	struct HashTable * map = create_hashtable();
	config_actuators(map);
	
	create_sensor("s1", &test);
	create_sensor("s2", &test2);
	create_sensor("s3", &test3);
	
	create_actuator("s1", &set);
	
	//set_keyvalue_hashtable(map, "a1", "ok", CCHAR);
	
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
