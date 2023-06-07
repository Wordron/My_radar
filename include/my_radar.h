/*
** EPITECH PROJECT, 2022
** my_radar.h
** File description:
** my_radar
*/
#include "./my_graph.h"

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    typedef struct aircraft {
        object_t *aircraft_object;
        sfRectangleShape *hit_box;
        t__time *aircraft_time;
        sfVector2f departure;
        sfVector2f arrival;
        sfVector2f offset_vector;
        sfVector2f position;
        int is_inside_area;
        int wich_part;
        int is_done;
        int speed;
        int delay_take_off;
    } aircraft;

    typedef struct control_tower {
        object_t *control_tower_object;
        sfCircleShape *control_area;
        sfVector2f tower_position;
        sfVector2f area_position;
        int radius;
        double radius_final;
    } control_tower;

    typedef struct game {
        sfEvent event;
        aircraft **aircraft_array;
        control_tower **control_array;
        object_t *map;
        t__time *take_off;
        sfText *chrono;
        sfFont *font;
        int curent_aircaft;
        int curent_tower;
        int nb_aircraft;
        int nb_tower;
        int is_l_pressed;
        int is_s_pressed;
        int is_t_pressed;
    } game_t;

    void analyse_events(sfRenderWindow *window, game_t *my_radar);
    void display(void);
    void display_error(void);
    int check_char(char buffer);
    int get_objects_info(game_t *my_radar, char *filepath);
    int get_info_aircraft(game_t *my_radar, char *buffer, int i);
    int get_info_tower(game_t *my_radar, char *buffer, int i);
    sfCircleShape *create_circle(sfVector2f position, float radius);
    sfRectangleShape *create_square(sfVector2f position, float size_side);
    int create_objects(game_t *my_radar);
    int create_aircraft(aircraft *aircraft_array);
    void check_colision(game_t *my_radar);
    int init_display_sprite(game_t *my_radar, sfRenderWindow *window);
    void move_aircraft(aircraft *plane, t__time *take_off);
    void destroy_start(game_t *my_radar, sfRenderWindow *window);
    void destroy_everything(game_t *my_radar, sfRenderWindow *window);
    sfVector2f get_position_circle(sfVector2f position_tower, float radius);

#endif /* !MY_RADAR_H_ */
