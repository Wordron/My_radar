/*
** EPITECH PROJECT, 2022
** move_aircraft.c
** File description:
** move_aircraft
*/
#include <math.h>
#include "include/my_radar.h"

void move_aircraft(aircraft *plane, t__time *take_off)
{
    sfVector2f position = sfRectangleShape_getPosition(plane->hit_box);

    if (get_seconds(plane->aircraft_time) > ((double) 1 / plane->speed)) {
        if (get_seconds(take_off) > plane->delay_take_off &&
        plane->is_done == 0) {
            sfSprite_move(plane->aircraft_object->sprite, plane->offset_vector);
            sfRectangleShape_move(plane->hit_box, plane->offset_vector);
            sfClock_restart(plane->aircraft_time->clock);
        }
    }
}
