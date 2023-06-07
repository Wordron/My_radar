/*
** EPITECH PROJECT, 2022
** diplays_sprite.c
** File description:
** display a sprite on the window
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void display_sprite(sfTexture *texture_ship, sfSprite *sprite_ship,
    sfRenderWindow *window)
{
    sfSprite_setTexture(sprite_ship, texture_ship, sfTrue);
    sfRenderWindow_drawSprite(window, sprite_ship, NULL);
}
