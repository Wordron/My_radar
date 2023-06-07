/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** destroy
*/
#include "include/my_radar.h"

void destroy_start(game_t *my_radar, sfRenderWindow *window)
{
    for (int i = 0; i < my_radar->nb_aircraft; i++)
        free(my_radar->aircraft_array[i]);
    free(my_radar->aircraft_array);
    for (int i = 0; i < my_radar->nb_tower; i++)
        free(my_radar->control_array[i]);
    free(my_radar->control_array);
    free(my_radar->take_off);
    free(my_radar);
    sfRenderWindow_destroy(window);
}

void destroy_aircraft(aircraft *aircraft_array)
{
    destroy_sprite(aircraft_array->aircraft_object->texture,
        aircraft_array->aircraft_object->sprite);
    free(aircraft_array->aircraft_object);
    sfClock_destroy(aircraft_array->aircraft_time->clock);
    free(aircraft_array->aircraft_time);
    sfRectangleShape_destroy(aircraft_array->hit_box);
    free(aircraft_array);
}

void destroy_tower(control_tower *control_array)
{
    destroy_sprite(control_array->control_tower_object->texture,
        control_array->control_tower_object->sprite);
    sfCircleShape_destroy(control_array->control_area);
    free(control_array->control_tower_object);
    free(control_array);
}

void destroy_everything(game_t *my_radar, sfRenderWindow *window)
{
    sfClock_destroy(my_radar->take_off->clock);
    free(my_radar->take_off);
    for (int i = 0; i < my_radar->nb_aircraft; i++)
        destroy_aircraft(my_radar->aircraft_array[i]);
    free(my_radar->aircraft_array);
    for (int i = 0; i < my_radar->nb_tower; i++)
        destroy_tower(my_radar->control_array[i]);
    free(my_radar->control_array);
    sfText_destroy(my_radar->chrono);
    sfFont_destroy(my_radar->font);
    free(my_radar);
    sfRenderWindow_destroy(window);
}
