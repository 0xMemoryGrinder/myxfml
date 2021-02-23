/*
** EPITECH PROJECT, 2020
** load_text_component.c
** File description:
** load_text_component.c
*/

#include "utils/init/entity/components/texts/load_texts_component_tabs.h"
#include "utils/init/load_file.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/common_tags.h"

void load_texts_toggle(char *content, int *i, texts_t *texts)
{
    texts->toggle = fill_toogle(content, i);
}

void load_text_rs_linked(char *content, int *i, text_t *text)
{
    text->is_rslinked = fill_toogle(content, i);
}

text_t load_text(char *content, int *i)
{
    text_t text;
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</text>", 7)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (text_conf_tag_action[k].tag && my_strncmp(content + *i,
        text_conf_tag_action[k].tag, text_conf_tag_action[k].tag_len))
            k++;
        if (!text_conf_tag_action[k].tag)
            my_puterr("Unrecognized text tag", __FILE__, __LINE__);
        *i += text_conf_tag_action[k].tag_len;
        text_conf_tag_action[k].action(content, i, &text);
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
    }
    text.text = sfText_create();
    return text;
}

void load_texts_list(char *content, int *i, texts_t *texts)
{
    texts->count = my_getnbr(content + *i);
    texts->text = malloc_text_array(texts->count);

    for (int n = 0; n < texts->count; n++) {
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
        *i += 1;
        skip_to_next_tag(content, i, OPEN);
        texts->text[n] = load_text(content, i);
        skip_to_next_tag(content, i, CLOSE);
    }
    *i += 1;
    skip_to_next_tag(content, i, CLOSE);
}

void load_texts_component(char *content, int *i, components_t *components)
{
    components->texts = malloc_text_struct();
    int k;

    skip_to_next_tag(content, i, NEXT);
    while (my_strncmp(content + *i, "</texts>", 8)) {
        k = 0;
        skip_to_next_tag(content, i, OPEN);
        while (texts_conf_tag_action[k].tag && my_strncmp(content + *i,
        texts_conf_tag_action[k].tag, texts_conf_tag_action[k].tag_len))
            k++;
        if (!texts_conf_tag_action[k].tag)
            my_puterr("Unrecognized texts tag", __FILE__, __LINE__);
        *i += texts_conf_tag_action[k].tag_len;
        texts_conf_tag_action[k].action(content, i, components->texts);
        *i += 1;
        skip_to_next_tag(content, i, NEXT);
    }
}