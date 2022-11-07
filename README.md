## Refactor inachevé

Reste à faire :

- [x] `cub3d.c` n'est pas complètement réécrit
- [x] Rajouter les fonctions dans un header, puisqu'elles ont été déplacées dans d'autre sources
- [x] Rajouter les nouveaux fichiers source dans le Makefile
- [x] `cub3D` en sortie au lieu de `cub3d`
- [x] Afficher un msg d'erreur quand une texture est definie deux fois (ko_all_fullspace_between_texture_shuffled_duplicate.cub)
- [x] Erreur quand il n'y a pas de map (ko_map_no_definition.cub)
- [x] Erreur quand il n'y a pas de joueur sur la map
(ko_all_mini_size_1.cub)
- [x] msg d'erreur apres echec du parsing des couleurs
(ko_F_char_x.cub, x = 1,...,6)
- [x] segfault while trying to destroy game (ok_SO_space_before_type_1.cub)
- [x] number of rgb values (ko_F_too_many_value_1.cub)
- [x] tabs at end of line (ko_map_space_end_tab_nl_etc.cub)