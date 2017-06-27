/*
** list.h for libmy in /home/onehandedpenguin/CPool_evalexpr/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Tue Oct 25 17:01:55 2016 Paul Laffitte
** Last update Fri Jan  6 17:53:16 2017 Paul Laffitte
*/

#ifndef LIST_H_
# define LIST_H_

typedef enum		e_type_list
{
  LINKED_LIST = 0, CIRCULAR_LIST = 1
}			t_type_list;

typedef enum		e_order
{
  ASC = -1, DESC = 1
}			t_order;

typedef struct		s_list_elem
{
  void			*data;
  struct s_list_elem	*prev;
  struct s_list_elem	*next;
}			t_list_elem;

typedef struct		s_list
{
  t_list_elem		*front;
  t_list_elem		*back;
  int			size;
  t_type_list		type;
}			t_list;

typedef struct		s_list_finder
{
  t_list		*found;
  void			*data;
}			t_list_finder;

typedef struct		s_tabber
{
  void			**tab;
  int			index;
}			t_tabber;

typedef int		(*t_list_func)(t_list *list, t_list_elem *list_elem,
			 void *data);
typedef int		(*t_list_cmp)(void *data1, void *data2);

t_list			*create_list(t_type_list type);
int			exec_list(t_list *list, t_list_func func, void *data);
t_list			*rev_list(t_list *list);
int			print_list(t_list *list);
int			free_list(t_list *list);

int			push_back(t_list *list, void *data);
int			push_front(t_list *list, void *data);
int			pop(t_list *list, t_list_elem *list_elem);
int			print_list_elem(t_list *list, t_list_elem *list_elem);
t_list			*find(t_list *list, t_list_func finder_func,
			      t_list_finder *finder);

void			set_list_type(t_list *list, t_type_list type);
int			turn_list_left(t_list *list);
int			turn_list_right(t_list *list);
void			**list_to_tab(t_list *list);

void			sort_list(t_list *list, t_list_cmp comparator,
				  t_order order);

void			clear_list(t_list *list);

#endif /* !LIST_H_ */
