/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:58:54 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/10 14:53:28 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

# define F_ZR		19584
# define F_ZR_ROT	50688
# define F_ZL		35904
# define F_ZL_ROT	27648
# define F_GL_U		57856
# define F_GL_L		51328
# define F_GL_D		36352
# define F_GL_R		17600
# define F_GR_U		59392
# define F_GR_L		35008
# define F_GR_D		11776
# define F_GR_R		50240
# define F_T_L		35968
# define F_T_U		58368
# define F_T_R		19520
# define F_T_D		19968
# define F_BLOCK	52224
# define F_LINE_U	61440
# define F_LINE_L	34952

typedef struct		s_tet
{
	char			id;
	int				fig;
	struct s_tet	*next;
}					t_tet;

int					validation_1(const int fd);
t_tet				*validation(int fd, char *file);
void				ft_exit(void);
void				tetadd(t_tet **alst, t_tet *new);
t_tet				*tetnew(int id, int a);
void				tetclr(t_tet **lst);
#endif
