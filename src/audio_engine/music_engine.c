/*
** EPITECH PROJECT, 2020
** music_engine.c
** File description:
** header for music_engine.c
*/

#include "../../include/my_csfml.h"
#include "../../include/audio_engine/audio_engine.h"
#include "../../include/my.h"

void check_music_state(game_data_t *data, audio_data_t *audio, int actual)
{
    if (audio->musics[actual].music == NULL) {
        audio->musics[actual].music =
        sfMusic_createFromFile(audio->musics[actual].path);
        sfMusic_play(audio->musics[actual].music);
        sfMusic_setLoop(audio->musics[actual].music, sfTrue);
        sfMusic_setVolume(audio->musics[actual].music, G_MUSCIV);
    }
}

void change_theme(game_data_t *data, char *new_theme)
{
    if (G_AUDIO->musics[G_AUDIO->actual_theme].music != NULL) {
        if (sfMusic_getStatus(G_AUDIO->musics[G_AUDIO->actual_theme].music) !=
            sfStopped)
            sfMusic_stop(G_AUDIO->musics[G_AUDIO->actual_theme].music);
        sfMusic_destroy(G_AUDIO->musics[G_AUDIO->actual_theme].music);
    }
    for (int i = 0; i < G_AUDIO->musics_count ; i++) {
        if (!my_strcmp(G_AUDIO->musics[i].name, new_theme)) {
            G_AUDIO->actual_theme = i;
            check_music_state(data, G_AUDIO, i);
            break;
        }
    }
}

void music_engine(game_data_t *data, audio_data_t *audio)
{
    if (audio->sounds && audio->sounds->toggle == ON)
        sfx_array_updates(data, audio->sounds);
    if (G_AUDIO->actual_theme == -1)
        return;
    check_music_state(data, G_AUDIO, G_AUDIO->actual_theme);
    sfMusic_setVolume(audio->musics[G_AUDIO->actual_theme].music, G_MUSCIV);
}

