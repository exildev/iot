#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SHORTSTRING_H
#define SHORTSTRING_H

/**
*	HashMap class
*	Character struct
**/
struct Character{
	struct Character * next;
	char value;
};

/**
*	ShortString class
*	Short String struct
**/
struct ShortString{
	struct Character * ptr;
	struct Character * car;
};

/**
* struct ShortString * create_shortstring(void);
* Create a ShortString struct
**/
struct ShortString * create_shortstring();

/**
* void delete_shortstring(struct ShortString * str);
* Delete a ShortString struct
**/
void delete_shortstring(struct ShortString * str);

/**
* struct ShortString * create_character(void);
* Create a ShortString struct
**/
struct Character * create_character(char value);

/**
* void delete_character(struct Character * car);
* Delerte a ShortString struct
**/
void delete_character(struct Character * car);
/**
* void add_character(struct ShortString * str, char value);
* Add a character to a ShortString struct
**/
void add_character(struct ShortString * str, char value);

/**
* void add_character(struct ShortString * str, char value);
* Add a character array to a ShortString struct
**/
void add_array(struct ShortString * str, char * value);
#endif
