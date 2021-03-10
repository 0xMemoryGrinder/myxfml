##
## EPITECH PROJECT, 2020
## Makefile for matchstick project
## File description:
## compilation control
##


UTILS_PATH	=	src/engine/utils/

INIT_PATH	=	src/engine/utils/init/

ENTITY_I_PATH	=	src/engine/utils/init/entity/
COMPONENTS_I_PATH	=	src/engine/utils/init/entity/components/
ANIM_I_PATH	=	src/engine/utils/init/entity/components/animation/
COLLIDER_I_PATH	=	src/engine/utils/init/entity/components/collider/
INTER_I_PATH	=	src/engine/utils/init/entity/components/interactive/
RENDER_I_PATH	=	src/engine/utils/init/entity/components/render/
SCRIPTS_I_PATH	=	src/engine/utils/init/entity/components/scripts/
SOUNDS_I_PATH	=	src/engine/utils/init/entity/components/sounds/
TEXTS_I_PATH	=	src/engine/utils/init/entity/components/texts/
TRANS_I_PATH	=	src/engine/utils/init/entity/components/transform/

GLOBALS_I_PATH	=	src/engine/utils/init/global_entity/

SCENE_I_PATH	=	src/engine/utils/init/scene/


INIT_COMPONENTS	=	$(COMPONENTS_I_PATH)load_components.c\
					$(ANIM_I_PATH)load_anim_properties.c\
					$(ANIM_I_PATH)load_anim_properties2.c\
					$(ANIM_I_PATH)load_animation_component.c\
					$(ANIM_I_PATH)load_animation_properties.c\
					$(COLLIDER_I_PATH)load_collider_component.c\
					$(COLLIDER_I_PATH)load_collider_form.c\
					$(INTER_I_PATH)load_interactive_component.c\
					$(RENDER_I_PATH)load_render_component.c\
					$(SCRIPTS_I_PATH)load_script_properties.c\
					$(SCRIPTS_I_PATH)load_scripts_components.c\
					$(SOUNDS_I_PATH)load_sound_properties.c\
					$(SOUNDS_I_PATH)load_sounds_component.c\
					$(TEXTS_I_PATH)load_text_properties.c\
					$(TEXTS_I_PATH)load_text_properties2.c\
					$(TEXTS_I_PATH)load_texts_component.c\
					$(TRANS_I_PATH)load_transform_component.c

INIT_ENTITY	=	$(ENTITY_I_PATH)load_entity.c\
				$(ENTITY_I_PATH)load_entity_properties.c\
				$(ENTITY_I_PATH)modify_loaded.c\
				$(ENTITY_I_PATH)modify_values.c\
				$(INIT_COMPONENTS)

INIT	=	$(INIT_PATH)common_tags.c\
			$(INIT_PATH)malloc_game.c\
			$(INIT_PATH)init_game.c\
			$(SCENE_I_PATH)load_scene.c\
			$(GLOBALS_I_PATH)get_globals.c\
			$(GLOBALS_I_PATH)insert_globals.c\
			$(INIT_ENTITY)



TIME_UTILS	=	$(UTILS_PATH)time/clock.c


SCENE_UTILS	=	$(UTILS_PATH)scene/components_parsing.c\
				$(UTILS_PATH)scene/create.c\
				$(UTILS_PATH)scene/free.c

GAME_UTILS	=	$(UTILS_PATH)game/create.c\
				$(UTILS_PATH)game/destroy_game.c

ENTITY_UTILS	=	$(UTILS_PATH)entity/alloc_nodes.c\
					$(UTILS_PATH)entity/destroy_pt2.c\
					$(UTILS_PATH)entity/free_entity.c\
					$(UTILS_PATH)entity/kill.c\
					$(UTILS_PATH)entity/remove.c\
					$(UTILS_PATH)entity/entity_fonctions.c

COMPONENTS_UTILS	=	$(UTILS_PATH)components/animation_utils.c\
						$(UTILS_PATH)components/script_utils.c\
						$(UTILS_PATH)components/script_data_utils.c\
						$(UTILS_PATH)components/text_utils.c\
						$(UTILS_PATH)components/sfx_utils.c\
						$(UTILS_PATH)components/components_utils.c\
						$(UTILS_PATH)components/create.c\
						$(UTILS_PATH)components/create_pt2.c\
						$(UTILS_PATH)components/create_pt3.c\
						$(UTILS_PATH)components/free.c\
						$(UTILS_PATH)components/free_pt2.c\



UTILS		=			$(UTILS_PATH)colliders.c\
						$(UTILS_PATH)converter.c\
						$(UTILS_PATH)my_puterr.c\
						$(UTILS_PATH)set_sprites_pos.c\
						$(TIME_UTILS)\
						$(SCENE_UTILS)\
						$(COMPONENTS_UTILS)\
						$(ENTITY_UTILS)\
						$(GAME_UTILS)\
						$(UTILS_PATH)audio_and_video/create.c\
						$(UTILS_PATH)audio_and_video/destroy.c\
						$(INIT)

ENGINE	=	src/engine/audio_engine/music_engine.c\
			src/engine/audio_engine/sfx_updates.c\
			src/engine/graphic_engine/animation_updates.c\
			src/engine/graphic_engine/background_rendering.c\
			src/engine/graphic_engine/render_updates.c\
			src/engine/graphic_engine/texts_updates.c\
			src/engine/graphic_engine/y_sorting_sprites.c\
			src/engine/input_engine/input_engine.c\
			src/engine/physics_engine/circle_and_circle.c\
			src/engine/physics_engine/circle_and_rectangle.c\
			src/engine/physics_engine/collison.c\
			src/engine/physics_engine/rectangle_and_rectangle.c\
			src/engine/physics_engine/trajectories.c\
			src/engine/physics_engine/transforming.c\
			src/engine/scripts_engine/scripts_updates.c

SRC	=	src/engine/core_engine.c\
		src/engine/free_entities_to_free.c\
		$(UTILS)\
		$(ENGINE)

NAME = libmy_xfml.a

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I ./include -Wall

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar -rc $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	:	all clean fclean re