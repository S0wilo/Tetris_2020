/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** tetris
*/

#ifndef H_GLOBAL
#define H_GLOBAL

#include <stddef.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

typedef struct command
{
    int level;
    char k_left;
    char k_right;
    char k_turn;
    char k_drop;
    char k_quit;
    char k_restart;
    int m_size_x;
    int m_size_y;
    int hide_next;
    int debug_mode;
    int high_score;
    int restart;
    int help;
}command_t;

int def_level(char **, command_t *, int *);
int def_k_left(char **, command_t *, int *);
int def_k_right(char **, command_t *, int *);
int def_k_turn(char **, command_t *, int *);
int def_k_drop(char **, command_t *, int *);
int def_k_quit(char **, command_t *, int *);
int def_k_restart(char **, command_t *, int *);
int def_hide_next(char **, command_t *, int *);
int def_debug_mode(char **, command_t *, int *);

typedef struct arg_type
{
    char *s1;
    char *s2;
    int (*f)(char **, command_t *, int *);
}arg_type_t;

arg_type_t static arg_list[] = {
    {"-L", "--level=", &def_level},
    {"-l", "--key-left=", &def_k_left},
    {"-r", "--key-right=", &def_k_right},
    {"-t", "--key-turn=", &def_k_turn},
    {"-d", "--key-drop=", &def_k_drop},
    {"-q", "--key-quit=", &def_k_quit},
    {"-p", "--key-restart=", &def_k_restart},
    {"-w", "--without-next", &def_hide_next},
    {"-D", "--debug", &def_debug_mode}
};

typedef struct tetro
{
    int color;
    int x;
    int y;
    char *name;
    char **form;
    struct tetro *next;
    struct tetro *prev;
}tetro_t;

typedef struct piece
{
    int color;
    char **form;
    int pos_x;
    int pos_y;
}piece_t;

typedef struct objects
{
    command_t *command;
    char **map;
    tetro_t *form;
    piece_t *actl;
    int level;
    clock_t time;
    clock_t real_time;
}objects_t;

int handle_arg(char **, command_t *);
char **create_map(command_t);
tetro_t *read_forms(void);
char **read_form_shape(FILE *, int *);
void debug_mode(tetro_t *, command_t);
void debug_mode_tetri(tetro_t *);
int game_loop(command_t *, char **, tetro_t *);
void game_render(objects_t *);
void display_interface(objects_t *);
void game_event(objects_t *);
int game_event_move(int, objects_t *, command_t *);
void game_event_rotate_piece(objects_t *);
void game_handling_piece(objects_t *);
int check_go_right(objects_t *);
int check_go_left(objects_t *);
void place_piece(objects_t *);
void delete_full_line(objects_t *);

#define ERROR 84

#endif
