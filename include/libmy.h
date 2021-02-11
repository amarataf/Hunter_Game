/*
** EPITECH PROJECT, 2020
** my
** File description:
** header file
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

int show_error(int, int);
int my_count(char const*);
int compare_strings(char const*, char const*, int);
int my_count_two(char const*);
int count_long_string(char*, int);

void my_putchar(char);
int my_putstr(char*);
int my_put_nbr(int);

int my_strlen(char*);
char *my_strcpy(char*);
char *my_strncpy(char*);
char *my_revstr(char*);
char *my_strstr(char*, char const*);
int my_strcmp(char const*, char const*);
int my_strncmp(char const*, char const*, int);

char *my_strupcase(char*);
char *my_strlowcase(char*);
char *my_strcapitalize(char*);

char *my_strcat(char*, char const*);
char *my_strncat(char*, char const*, int);

int my_str_isalpha(char const*);
int my_str_isnum(char const*);
int my_str_islower(char const*);
int my_str_isupper(char const*);
int my_str_isprintable(char const*);

//int my_showstr(char const*);
//int my_showmem(char const*, int);

void my_sort_int_array(int*, int);
int my_isneg(int);
void my_swap(int*, int*);
int my_find_prime_sup(int);
int my_is_prime(int);
int my_compute_square_root(int);
int my_compute_power_rec(int, int);
int my_getnbr(char const*);

int my_getnbr_from_char(char);
char *my_strdup(char *);

char *my_malloc(int);

void translation(float x, float y, float i, float j);
void scaling(float x, float y, float i, float j);
void rotation(float x, float y, int a);
void reflection(float x, float y, int a);

sfVector2f handle_events(sfEvent event, sfVector2f pos);
void move_rect(sfIntRect *rect, int offset, int max_value);

#endif
