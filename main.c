#include <stdio.h>
#include <stdlib.h>
#include "Sensor.h"


char test(struct HashMap* map){
	set_keyvalue(map, "hola", "mundo", CHAR);
	return 1;
}

int main(int argc, char *argv[]) {
	struct HashMap * map = create_hashmap(); 
	
	create_sensor("s1", &test);
	create_sensor("s2", &test);
	read_sensors(map);
	
	struct ShortString * str = create_shortstring();
	hashmap_to_string(str, map, 3);
	struct Character * car = str->ptr;
	
	while (car != NULL){
		printf("%c", car->value);
		car = car->next;
	}
	
	delete_shortstring(str);
	
	delete_hashmap(map);
	return 0;
}
