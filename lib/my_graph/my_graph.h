/*
** EPITECH PROJECT, 2022
** my_graph.h
** File description:
** my_graph
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

#ifndef MY_GRAPH_H_
    #define MY_GRAPH_H_

    typedef struct time {
        sfClock *clock;
        sfTime time;
        float seconds;
    } t__time;

    typedef struct object {
        sfIntRect rect;
        sfTexture *texture;
        sfSprite *sprite;
    } object_t;

    sfRenderWindow *create_window(unsigned int width, unsigned int height);
    void display_sprite(sfTexture *texture_ship, sfSprite *sprite_ship,
        sfRenderWindow *window);
    void destroy_sprite(sfTexture *texture, sfSprite *sprite);
    void move_sprite_by_translation(sfSprite *sprite, float x, float y);
    void move_sprite_by_rotation(sfSprite *sprite, float angle);
    float get_seconds(struct time *time);

#endif /* !MY_GRAPH_H_ */
