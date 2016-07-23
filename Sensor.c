#include "Sensor.h"

struct Sensor * sensor_ptr = NULL;
struct Sensor * sensor_car = NULL;

struct Actuator * actuator_ptr = NULL;
struct Actuator * actuator_car = NULL;


struct Manager * create_manager(){
	struct Manager * man = malloc(sizeof(struct Manager));
	return man;
}

void create_sensor(const char name[10], char (*read)(struct Manager*)){
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

void create_actuator(const char name[10], char (*act)(struct KeyValue*)){
	struct Actuator * actuator = malloc(sizeof(struct Actuator));
	strcpy(actuator->name, name);
	actuator->act = act;
	actuator->next = NULL;
	if (actuator_ptr == NULL){
		actuator_ptr = actuator;
		actuator_car = actuator;
	}else{
		actuator_car->next = actuator;
		actuator_car = actuator_car->next;
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

char read_sensor(struct Sensor * sensor, struct HashTable * hashtable){
	struct HashTable * hm = find_hashtable(hashtable, sensor->name);
	if (hm == NULL){
		hm = create_hashtable();
		set_keyvalue_hashtable(hashtable, sensor->name, hm, HASH);
	}
	void emitInt(const char * key, int data){
		int * data_int = malloc(sizeof(int));
		*data_int = data;
		void * data_void = (void*)data_int;
		set_keyvalue_hashtable(hm, key, data_void, INT);
	}
	void emitChar(const char * key, const char * data){
		void * data_void = (void*)data;
		set_keyvalue_hashtable(hm, key, data_void, CCHAR);
	}
	void emitHash(const char * key, struct HashTable * data){
		void * data_void = (void*)data;
		set_keyvalue_hashtable(hm, key, data_void, HASH);
	}
	void emitList(const char * key, struct List * data){
		void * data_void = (void*)data;
		set_keyvalue_hashtable(hm, key, data_void, LIST);
	}
	struct Manager * man = create_manager();
	man->emitInt = emitInt;
	man->emitChar = emitChar;
	man->emitHash = emitHash;
	man->emitList = emitList;
	return sensor->read(man);
}

void read_sensors(struct HashTable * hashtable){
	struct Sensor * car = sensor_ptr;
	while (car != NULL){
		read_sensor(car, hashtable);
		car = car->next;
	}
}


char config_actuators(struct HashTable * hashtable){
	void on_change(struct HashTable * hashtable, struct KeyValue * keyvalue){
		struct Actuator * car = actuator_ptr;
		while (car != NULL){
			if (strcmp(keyvalue->key, car->name) == 0){
				car->act(keyvalue);
			}
			car = car->next;
		}
	}
	hashtable->on_change = on_change;
}
