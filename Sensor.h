#include "HashTable.h"
#include <stdio.h>

#ifndef SENSOR_H
#define SENSOR_H




/**
*	Manager class
*	Manager struct
**/

struct Manager{
	struct HasTable * hashtable;
	void (*emitChar)(const char * key, const char * data);
	void (*emitInt)(const char * key, int data);
	void (*emitHash)(const char * key, struct HashTable * data);
	void (*emitList)(const char * key, struct List * data);
};


/**
*	Sensor class
*	Sensor struct
**/
struct Sensor{
	char name[10];
	char (*read)(struct Manager *);
	struct Sensor * next;
};


/**
*	Actuator class
*	Actuator struct
**/
struct Actuator{
	char name[10];
	char (*act)(struct KeyValue *);
	struct Actuator * next;
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
*	List actuator start
**/
struct Actuator * actuator_ptr;
/**
*	List actuator end
**/
struct Actuator * actuator_car;

struct Manager * create_manager();
/**
* void create_sensor(const char name[10], char (*read)(struct HashMap*));
* Create a Sensor struct
**/
void create_sensor(const char name[10], char (*read)(struct Manager*));
/**
* void create_actuator(const char name[10], char (*read)(struct HashMap*));
* Create a Sensor struct
**/
void create_actuator(const char name[10], char (*act)(struct KeyValue*));

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
* char read_sensor(struct Sensor * sensor, struct HashTable * hashtable);
* Read a Sensor struct
**/
char read_sensor(struct Sensor * sensor, struct HashTable * hashtable);
/**
* char config_actuators(struct HashTable * hashtable);
* Read a Sensor struct
**/
char config_actuators(struct HashTable * hashtable);

/**
* void read_sensors(struct HashTable * hashtable);
* Read all Sensor struct
**/
void read_sensors(struct HashTable * hashtable);
#endif
