#ifndef OBJECTS_H
#define OBJECTS_H

/* object prototypes */
int obj_in_ext(_st *nick);
int obj_in_cd(_st *nick);
int st_wk_dir(_st *nick, char *new_dir);
int obj_in_hlp(_st *nick);
int obj_in_alias(_st *nick);
int obj_in_env(_st *nick);
int obj_set_env(_st *nick);
int obj_in_unset_env(_st *nick);
int obj_in_lst(_st *nick);

#endif
