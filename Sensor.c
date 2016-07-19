#include "Sensor.h"

struct Sensor * sensor_ptr = NULL;
struct Sensor * sensor_car = NULL;

void create_sensor(const char name[10], char (*read)(struct HashMap*)){
	struct Sensor * se = malloc(sizeof(struct Sensor));
	se->read = read;
	strcpy(se->name, name);
	se->next = NULL;
	if (sensor_ptr == NULL){
		sensor_ptr = se;
		sensor_car = se;
	}else{
		sensor_car->next = se;
		sensor_car = sensor_car->next;
	}
}

void delete_sensor(struct Sensor * sensor){
	if (sensor->next != NULL){
		delete_sensor(sensor->next);
	}
	free(sensor);
}

void delete_sensors(){
	delete_sensor(sensor_ptr);
}

char read_sensor(struct Sensor * sensor, struct HashMap * hashmap){
	struct HashMap * hm = find_hashmap(hashmap, sensor->name);
	if (hm == NULL){
		hm = create_hashmap();
		set_keyvalue(hashmap, sensor->name, hm, HASH);
	}
	return sensor->read(hm);
}

void read_sensors(struct HashMap * hashmap){
	struct Sensor * car = sensor_ptr;
	while (car != NULL){
		read_sensor(car, hashmap);
		car = car->next;
	}
}
