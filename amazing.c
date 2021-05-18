/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** test
*/

#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>

void description(void);

static sfRenderWindow *create_renderwindow(int x, int y, int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL));
}

int main(int ac, char **av)
{
    if (ac == 2)
        description();

    sfRenderWindow *win = create_renderwindow(1296, 720, 32, "My Hunter");
    sfEvent event;

    sfMusic *music = sfMusic_createFromFile("Audio/naruto_music.ogg");
    sfMusic_setVolume(music, 50);
    sfMusic_play(music);

    sfIntRect rectSprite = (sfIntRect) {0, 0, 110, 330};
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    sfTexture *texture = sfTexture_createFromFile("Sprite/oiseau.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    sfTexture *texture_back;
    texture_back = sfTexture_createFromFile("Sprite/background.png", NULL);
    sfSprite *sprite_back = sfSprite_create();
    sfSprite_setTexture(sprite_back, texture_back, sfTrue);

    sfTexture *cross_texture;
    cross_texture = sfTexture_createFromFile("Sprite/cross_air1.png", NULL);
    sfSprite *cross_sprite = sfSprite_create();
    sfSprite_setTexture(cross_sprite, cross_texture, sfTrue);

    sfVector2f pos_bird = {0, 0};
    sfVector2f mouse_pos = {242, 182.5};
    sfSprite_setOrigin(cross_sprite, mouse_pos);
    sfRenderWindow_setMouseCursorVisible(win, sfFalse);

    sfRenderWindow_setFramerateLimit(win, 60);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_display(win);

        while (sfRenderWindow_pollEvent(win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                write(1, "You win !!\n", 13);
            }
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, sprite_back, NULL);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_drawSprite(win, cross_sprite, NULL);

        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            rectSprite.left += 110;
            if (rectSprite.left >= 330)
                rectSprite.left = 0;

        sfSprite_setTextureRect(sprite, rectSprite);
        sfClock_restart(clock);
        }

        sfSprite_setPosition(sprite, pos_bird);
        if (clock)
            pos_bird.x += 10;
        if (pos_bird.x > 1296) {
            pos_bird.x = 0;
            pos_bird.y = (rand() % (900 - 0)) + 0;
            sfSprite_setPosition(sprite, pos_bird);
        }
        if (event.type == sfEvtMouseMoved) {
            mouse_pos.x = event.mouseMove.x;
            mouse_pos.y = event.mouseMove.y;
            sfSprite_setPosition(cross_sprite, mouse_pos);
        }
    }
    sfClock_destroy(clock);
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite_back);
    sfTexture_destroy(texture);
    sfTexture_destroy(texture_back);
    sfRenderWindow_destroy(win);
}