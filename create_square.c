/*
** EPITECH PROJECT, 2022
** create_square.c
** File description:
** create_square
*/
#include "include/my_graph.h"

sfRectangleShape *create_square(sfVector2f position, float size_side)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfVector2f size;

    size.x = size_side;
    size.y = size_side;
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOutlineThickness(square, 2);
    sfRectangleShape_setOutlineColor(square, sfGreen);
    sfRectangleShape_setFillColor(square, sfTransparent);
    sfRectangleShape_setPosition(square, position);
    return (square);
}
