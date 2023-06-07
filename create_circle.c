/*
** EPITECH PROJECT, 2022
** create_circle.c
** File description:
** draw a circle on a window
*/
#include "include/my_graph.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    sfCircleShape_setPosition(circle, position);
    return (circle);
}
