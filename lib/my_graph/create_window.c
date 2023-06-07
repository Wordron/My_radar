/*
** EPITECH PROJECT, 2022
** create_window.c
** File description:
** create a window
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My_hunter",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
