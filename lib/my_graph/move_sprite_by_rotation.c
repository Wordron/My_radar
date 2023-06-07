/*
** EPITECH PROJECT, 2022
** move_sprite_by_rotation
** File description:
** move_sprite_by_rotation
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void move_sprite_by_rotation(sfSprite *sprite, float angle)
{
    sfSprite_rotate(sprite, angle);
}
