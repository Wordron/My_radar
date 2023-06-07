/*
** EPITECH PROJECT, 2022
** destroy_sprite.c
** File description:
** destroy the given sprite
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void destroy_sprite(sfTexture *texture, sfSprite *sprite)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
