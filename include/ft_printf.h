
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_flag
{
	int				minus;
	int				zero;
	int				dot;
	int				star;
	int				width;
	int				count;
	long long int	num;
	int				minx;
	char			*ptr;
	char			ud;
}					t_flag;

void				ft_zstr(char **str, t_flag *flags);
void				ft_printproc(t_flag *flags, unsigned char c);
void				ft_putchar(char c);
int					ft_procxnum(t_flag *flags, int *tmp);
int					ft_hproc(t_flag *flags, int *dot);
void				ft_printp(t_flag *flags, int dot, int *tmp, int i);
int					ft_procpnum(unsigned long int *dig, int *tmp);
int					ft_pproc(unsigned long int *dig, t_flag *flags, int *dot);
void				ft_printxn(t_flag *flags, int dot, int *tmp, int i);
int					ft_procnum(t_flag *flags, int *tmp, int pos);
int					ft_proc(int *pos, t_flag *flags, int *dot);
void				ft_printn(t_flag *flags, int dot, int *tmp, int i);
int					ft_len(unsigned long dig, t_flag *flags);
void				ft_printwidth(t_flag *flags, char format, int lenwidth);
void				ft_printstr(t_flag *flags, char *str);
int					ft_uprocnum(t_flag *flags, int *tmp);
void				ft_printun(t_flag *flags, int dot, int *tmp, int i);
int					ft_uproc(t_flag *flags, int *dot);
void				ft_printnum(t_flag	*flags, int num);
void				ft_printunum(t_flag *flags, unsigned int num);
int					ft_lenhex(unsigned int dig, t_flag *flags);
void				ft_printx(int num, char ud);
void				ft_printhex(t_flag *flags, unsigned int dig, char ud);
void				ft_printptr(t_flag *flags, unsigned long int dig, char ud);
void				ft_printc(t_flag *flags, unsigned char c);
void				ft_init(t_flag *flags);
int					ft_parsstar(va_list aptr, t_flag *flags);
int					ft_parswidth(t_flag *flags, char *formstr, int i);
int					ft_parsdot(t_flag *flags, char *formstr, int i, \
					va_list aptr);
void				ft_format(va_list aptr, char *formstr, t_flag *flags, \
					int i);
int					ft_is_format(char c);
int					ft_parser(char *formstr, t_flag *flags, int i, \
					va_list aptr);
int					ft_preparser(va_list aptr, char *formstr);
int					ft_printf(const char *form, ...);

#endif
