/*
** EPITECH PROJECT, 2022
** inti_display_sprite.c
** File description:
** start_display_sprites
*/
#include "include/my_radar.h"
#include "include/my.h"

void get_is_done(aircraft *aircraft_array)
{
    sfVector2f position;

    position = sfRectangleShape_getPosition(
        aircraft_array->hit_box);
    if (!(((position.x <= aircraft_array->arrival.x
    && (position.x + 20) <= aircraft_array->arrival.x)
    || (position.x >= aircraft_array->arrival.x
    && (position.x + 20) >= aircraft_array->arrival.x))
    && ((position.y <= aircraft_array->arrival.y
    && (position.y + 20) <= aircraft_array->arrival.y)
    || (position.y >= aircraft_array->arrival.y
    && (position.y + 20) >= aircraft_array->arrival.y))))
        aircraft_array->is_done = 1;
}

int display_aircraft(game_t *my_radar, sfRenderWindow *window, int i)
{
    if (get_seconds(my_radar->take_off) >=
    my_radar->aircraft_array[i]->delay_take_off &&
    my_radar->aircraft_array[i]->is_done == 0) {
        if (my_radar->is_s_pressed == 1) {
            display_sprite(
            my_radar->aircraft_array[i]->aircraft_object->texture,
            my_radar->aircraft_array[i]->aircraft_object->sprite, window);
        }
        if (my_radar->is_l_pressed == 1) {
            sfRenderWindow_drawRectangleShape(
            window, my_radar->aircraft_array[i]->hit_box, NULL);
        }
    }
}

void update_timer(sfText *chrono, t__time *clock)
{
    int nb = (int) get_seconds(clock);
    int nb_two = nb;
    int temp = 0;
    char *nbstr = malloc(sizeof(char) * 11);
    int j = 0;
    for (int i = 1; nb != 0; i++) {
        temp = nb % my_compute_power_rec(10, i);
        nb = nb - temp;
        if (i == 1)
            nbstr[j] = temp + '0';
        else
            nbstr[j] = ((temp / my_compute_power_rec(10, i - 1)) + '0');
        j++;
    }
    nbstr[j] = '\0';
    my_revstr(nbstr);
    if (nb_two == 0)
        my_strcpy(nbstr, "0");
    sfText_setString(chrono, nbstr);
    free(nbstr);
}

int init_display_sprite(game_t *my_radar, sfRenderWindow *window)
{
    display_sprite(my_radar->map->texture, my_radar->map->sprite, window);
    for (int i = 0; i < my_radar->curent_tower; i++) {
        if (my_radar->is_s_pressed == 1) {
            display_sprite(
            my_radar->control_array[i]->control_tower_object->texture,
            my_radar->control_array[i]->control_tower_object->sprite, window);
        }
        if (my_radar->is_l_pressed == 1) {
            sfRenderWindow_drawCircleShape(
            window, my_radar->control_array[i]->control_area, NULL);
        }
    }
    for (int i = 0; i < my_radar->nb_aircraft; i++) {
        get_is_done(my_radar->aircraft_array[i]);
        display_aircraft(my_radar, window, i);
    }
    if (my_radar->is_t_pressed == 1) {
        update_timer(my_radar->chrono, my_radar->take_off);
        sfRenderWindow_drawText(window, my_radar->chrono, NULL);
    }
}
