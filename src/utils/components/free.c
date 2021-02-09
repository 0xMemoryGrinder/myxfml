/*
** EPITECH PROJECT, 2020
** free_components.c
** File description:
** header for free_components.c
*/

#include <stdlib.h>
#include "../../../include/types.h"
#include "../../../include/types_and_base/base_components.h"
#include "../../../include/my.h"

void free_text(texts_t *texts)
{
    for (int i = 0; i < texts->count; i++) {
        if (texts->text[i].string)
            free(texts->text[i].string);
        if (texts->text[i].text)
            sfText_destroy(texts->text[i].text);
        if (texts->text[i].font)
            sfFont_destroy(texts->text[i].font);
    }
    if (texts->text != NULL)
        free(texts->text);
    if (texts != NULL)
        free(texts);
    texts = NULL;
}

void free_rendersprite(render_sprite_t *render)
{
    if (render->sprite)
        sfSprite_destroy(render->sprite);
    if (render->texture)
        sfTexture_destroy(render->texture);
    if (render != NULL)
        free(render);
    render = NULL;
}

void free_sound_list(sfx_list_t *sounds)
{
    if (sounds == NULL)
        return;
    for (int i = 0; i < sounds->sfx_count; i++) {
        if (sounds->sfx[i].name)
            free(sounds->sfx[i].name);
        if (sounds->sfx[i].buff)
            sfSoundBuffer_destroy(sounds->sfx[i].buff);
        if (sounds->sfx[i].sfx)
            sfSound_destroy(sounds->sfx[i].sfx);
    }
    if (sounds->sfx != NULL)
        free(sounds->sfx);
    if (sounds != NULL)
        free(sounds);
    sounds = NULL;
}