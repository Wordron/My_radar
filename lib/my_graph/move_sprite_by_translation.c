/*
** EPITECH PROJECT, 2022
** move_sprite_by_translation
** File description:
** move_sprite_by_translation
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void move_sprite_by_translation(sfSprite *sprite, double x, double y)
{
    sfVector2f offset;

    offset.x = x;
    offset.y = y;
    sfSprite_move(sprite, offset);
}
