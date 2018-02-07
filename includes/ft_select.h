/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 19:18:19 by acottier          #+#    #+#             */
/*   Updated: 2016/10/04 14:18:56 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define RED			"\033[31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;3;33m"
# define NC				"\033[0m"
# define HI				"\033[7;31m"
# define UL				"\033[4;31m"
# define BO				"\033[1;31m"
# define HI_UL			"\033[4;7;31m"
# define HI_UL_BO		"\033[1;4;7;31m"

# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <termcap.h>
# include <errno.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct		s_elem
{
	char			*name;
	int				li;
	int				col;
	int				index;
	int				biggest;
	int				selected;
	int				current;
	int				null;
	int				mod;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_info
{
	t_elem			*lst;
	int				col;
	int				li;
	int				max_col;
	int				max_line;
	int				srchprompt;
	int				sleep;
	int				fd;
	struct termios	save;
	struct termios	term;
	char			*name;
}					t_info;

typedef struct		s_coord
{
	int				minli;
	int				maxli;
	int				mincol;
	int				maxcol;
}					t_coord;

enum				e_keys
{
	R_ARR = 4414235,
	L_ARR = 4479771,
	U_ARR = 4283163,
	D_ARR = 4348699,
	ESC = 27,
	ENTER = 10,
	CTRL_A = 1,
	CTRL_D = 4,
	SPACE = 32,
	BACKSPACE = 127,
	SEARCH = 58,
	DEL = 2117294875,
	U_CHU = 56,
	D_CHU = 50,
	L_CHU = 52,
	R_CHU = 54,
	MOD_SEL = 53,
	U_SEL = 1096489755,
	D_SEL = 1113266971,
	L_SEL = 1146821403,
	R_SEL = 1130044187,
}						;

/*
** MKLIST.C
*/
t_elem				*mk_elem_list(char **argv);
t_elem				*add_null_elem(t_elem *lst);
t_elem				*del_elem(t_elem *lst, t_info *info, int *over);
void				kill_blanks(t_elem *lst);

/*
** DISP_SETTING.C
*/
void				disp_settings(t_elem *lst, t_info *info);

/*
** SHELL_MODIFY.C
*/
void				shell_modify(struct termios *term, int create);
int					ft_useless(int c);

/*
** DISPLAY_ELEMS.C
*/
void				display_elems(t_elem *lst, t_info *info);
t_elem				*validation(t_elem *lst, t_info *info, int *over);

/*
** INIT.C
*/
int					term_init(t_info **info);

/*
** SELECTION.C
*/
void				commands(t_elem *lst, t_info *info);

/*
** UTILITIES.C
*/
t_elem				*to_cursor(t_elem *lst);
t_elem				*to_coords(t_elem *lst, t_elem *cur, int li, int col);
t_elem				*to_end(t_elem *cur);
t_elem				*to_start(t_elem *cur);
t_elem				*quit_all(t_elem *lst, t_info *info, int *over,
					char *stock);

/*
** SELECT_UTILITIES.C
*/
t_elem				*all_selection(int key, t_elem *lst);
t_elem				*row_selection(int key, t_elem *lst, t_elem *cur);
t_elem				*chunk_selection(int key, t_elem *lst, t_elem *cur);

/*
** MODULAR_SELECTION.C
*/
t_elem				*mod_selection(t_elem *lst, t_elem *cur);

/*
** SIG_HANDLER.C
*/
void				sig_handler(void);
void				sig_call(int sig_id);
t_info				*backup(t_info *to_save, int op);
void				suspend(int sig_id, t_info *info);

/*
** SEARCH.C
*/
t_elem				*search(t_elem *lst, t_info *info, int *over,
					char *stock);

/*
** ERROR.C
*/
void				error(char *str, int errnum);
#endif
