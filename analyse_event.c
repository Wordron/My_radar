/*
** EPITECH PROJECT, 2022
** analyse_envents.c
** File description:
** analyse the events in a window
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my_graph.h"
#include "include/my_radar.h"

void analyse_events(sfRenderWindow *window, game_t *my_radar)
{
    if (my_radar->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (my_radar->event.type == sfEvtKeyReleased &&
    my_radar->event.key.code == sfKeyL)
        my_radar->is_l_pressed = my_radar->is_l_pressed * (-1);
    if (my_radar->event.type == sfEvtKeyReleased &&
    my_radar->event.key.code == sfKeyS)
        my_radar->is_s_pressed = my_radar->is_s_pressed * (-1);
    if (my_radar->event.type == sfEvtKeyReleased &&
    my_radar->event.key.code == sfKeyT)
        my_radar->is_t_pressed = my_radar->is_t_pressed * (-1);
}
