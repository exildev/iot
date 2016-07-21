#include "HashTable.h"
#include <stdio.h>

#ifndef SENSOR_H
#define SENSOR_H


/**
*	Sensor class
*	Sensor struct
**/
struct Sensor{
	char name[10];
	char (*read)(struct HashTable*);
	struct Sensor * next;
};


/**
*	List sensors start
**/
struct Sensor * sensor_ptr;
/**
*	List sensors end
**/
struct Sensor * sensor_car;


/**
* void create_sensor(const char name[10], char (*read)(struct HashMap*));
* Create a Sensor struct
**/
void create_sensor(const char name[10], char (*read)(struct HashTable*));

/**
* void delete_sensor(struct Sensor * sensor);
* Delete a Sensor struct
**/
void delete_sensor(struct Sensor * sensor);

/**
* void delete_sensor(void);
* Delete all Sensor struct
**/
void delete_sensors();


/**
* char read_sensor(struct Sensor * sensor, struct HashMap * hashmap);
* Read a Sensor struct
**/
char read_sensor(struct Sensor * sensor, struct HashTable * hashtable);

/**
* void read_sensors(struct HashMap * hashmap);
* Read all Sensor struct
**/
void read_sensors(struct HashTable * hashtable);
#endif
