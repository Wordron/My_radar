/*
** EPITECH PROJECT, 2023
** create_aircraft.c
** File description:
** create_aircraft
*/
#include <math.h>
#include "include/my_radar.h"
/* rotation :
sfSprite_setRotation(aircraft_array->aircraft_object->sprite, angle);
sfRectangleShape_setRotation(aircraft_array->hit_box, angle);
*/

int create_aircraft_sprite(aircraft *aircraft_array, double angle)
{
    sfVector2f scale;

    scale.x = 0.07;
    scale.y = 0.07;
    aircraft_array->aircraft_object->texture =
    sfTexture_createFromFile("./texture/plane.png", NULL);
    aircraft_array->aircraft_object->sprite = sfSprite_create();
    sfSprite_setPosition(aircraft_array->aircraft_object->sprite,
        aircraft_array->departure);
    sfSprite_setScale(aircraft_array->aircraft_object->sprite, scale);
    aircraft_array->aircraft_time->clock = sfClock_create();
    aircraft_array->hit_box = create_square(aircraft_array->departure, 20);
}

void get_offset_vector(aircraft *aircraft_array)
{
    aircraft_array->offset_vector.x = (aircraft_array->arrival.x -
        aircraft_array->departure.x) / sqrt(pow(aircraft_array->arrival.x -
        aircraft_array->departure.x, 2) + pow(aircraft_array->arrival.y -
        aircraft_array->departure.y, 2));
    aircraft_array->offset_vector.y = (aircraft_array->arrival.y -
        aircraft_array->departure.y) / sqrt(pow(aircraft_array->arrival.x
        - aircraft_array->departure.x, 2) + pow(aircraft_array->arrival.y -
        aircraft_array->departure.y, 2));
}

double get_angle(aircraft *aircraft_array)
{
    return (acos((aircraft_array->arrival.x - aircraft_array->departure.x) /
        sqrt(pow(aircraft_array->arrival.x - aircraft_array->departure.x, 2) +
        pow(aircraft_array->arrival.y - aircraft_array->departure.y, 2))
        ) * (180.0 / 3.1415926535));
}

int create_aircraft(aircraft *aircraft_array)
{
    double angle = get_angle(aircraft_array);

    get_offset_vector(aircraft_array);
    if (angle < 100)
        angle = angle * (-1);
    if (aircraft_array->offset_vector.x == 0 &&
    aircraft_array->offset_vector.y > 0)
        angle = angle * (-1);
    aircraft_array->is_done = 0;
    aircraft_array->is_inside_area = 0;
    create_aircraft_sprite(aircraft_array, angle);
}
