/*
** EPITECH PROJECT, 2022
** check_colisions.c
** File description:
** check_colisions
*/
#include <math.h>
#include "include/my_radar.h"

sfVector2f get_center(sfCircleShape *circle, double radius)
{
    sfVector2f position_circle;

    position_circle.x = sfCircleShape_getPosition(circle).x + radius;
    position_circle.y = sfCircleShape_getPosition(circle).y + radius;
    return (position_circle);
}

void aircraft_inside_tower_area(control_tower *tower, aircraft *plane,
t__time *clock_take_off)
{
    int collision = 0;
    double rad = 0;
    sfVector2f center_circle;
    sfVector2f vector;

    if (plane->is_done == 0 && get_seconds(clock_take_off) >=
    plane->delay_take_off) {
        rad = pow(10 + tower->radius_final, 2);
        center_circle = get_center(tower->control_area, tower->radius_final);
        vector.x = pow((plane->position.x + 10) - center_circle.x, 2);
        vector.y = pow((plane->position.y + 10) - center_circle.y, 2);
        if (vector.x + vector.y <= rad)
            collision = 1;
        if (collision == 1)
            plane->is_inside_area = 1;
    }
}

void aircraft_are_touching(aircraft *plane_one, aircraft *plane_two,
t__time *take_off)
{
    int collision_x = 0;
    int collision_y = 0;

    if (plane_two->is_inside_area == 0 && plane_two->is_done == 0 &&
    get_seconds(take_off) >= plane_two->delay_take_off) {
        if (plane_one->position.x + 20 >= plane_two->position.x
        && plane_two->position.x + 20 >= plane_one->position.x)
            collision_x = 1;
        if (plane_one->position.y + 20 >= plane_two->position.y
        && plane_two->position.y + 20 >= plane_one->position.y)
            collision_y = 1;
        if (collision_x == 1 && collision_y == 1) {
            plane_one->is_done = 1;
            plane_two->is_done = 1;
        }
    }
}

void get_position(game_t *my_radar)
{
    for (int i = 0; i < my_radar->nb_aircraft; i++)
        my_radar->aircraft_array[i]->position = sfRectangleShape_getPosition(
            my_radar->aircraft_array[i]->hit_box);
    for (int i = 0; i < my_radar->nb_tower; i++)
        my_radar->control_array[i]->area_position = sfCircleShape_getPosition(
            my_radar->control_array[i]->control_area);
}

void check_colision(game_t *my_radar)
{
    get_position(my_radar);
    for (int i = 0; i < my_radar->nb_aircraft; i++) {
        for (int j = 0; j < my_radar->nb_tower; j++) {
            aircraft_inside_tower_area(my_radar->control_array[j],
            my_radar->aircraft_array[i], my_radar->take_off);
        }
    }
    for (int i = 0; i < my_radar->nb_aircraft - 1; i++) {
        for (int j = i + 1; j < my_radar->nb_aircraft &&
        my_radar->aircraft_array[i]->is_inside_area == 0
        && my_radar->aircraft_array[i]->is_done == 0 &&
        get_seconds(my_radar->take_off) >=
        my_radar->aircraft_array[i]->delay_take_off; j++) {
            aircraft_are_touching(my_radar->aircraft_array[i],
            my_radar->aircraft_array[j], my_radar->take_off);
        }
    }
    for (int i = 0; i < my_radar->nb_aircraft; i++)
        my_radar->aircraft_array[i]->is_inside_area = 0;
}
