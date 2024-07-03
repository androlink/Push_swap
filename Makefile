PS_NAME = push_swap
CK_NAME = checker

CC = cc
RMF = rm -f

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -MMD -MP

HDIR	=	includes
SDIR	=	srcs
BDIR	=	build
DDIR	=	build

HFILES	=	

CMN_DIR		=	common
CMN_FILES	=	ft_load.c		\
				ft_utils.c		\
				ft_operation.c	\
				ft_load_utils.c	\
				ft_operation_utils.c
CMN_PATH	=	${addprefix $(CMN_DIR)/, $(CMN_FILES)}
CMN_SRCS	=	$(CMN_PATH:%=$(SDIR)/%)
CMN_OBJS	=	$(CMN_PATH:%.c=$(BDIR)/%.o)
CMN_DEPS	=	$(CMN_PATH:%.c=$(DDIR)/%.d)

PS_DIR		=	push_swap
PS_FILES	=	push_swap.c		\
				ft_radix_sort.c	\
				ft_double_insert_sort.c	\
				ft_resolve.c	\
				ft_sort_utils.c	\
				ft_quad_insert_with_pivot.c	\
				ft_sort.c	\
				ft_push_swap_utils.c	\
				ft_quad_insert.c		\
				ps_stalinsort.c			\
				ft_sort_3.c		
PS_PATH		=	${addprefix $(PS_DIR)/, $(PS_FILES)}
PS_SRCS		=	${addprefix $(SDIR)/, $(PS_PATH)}
PS_OBJS		=	$(PS_PATH:%.c=$(BDIR)/%.o)
PS_DEPS		=	$(PS_PATH:%.c=$(DDIR)/%.d)

CK_DIR		=	checker
CK_FILES	=	checker.c	\
				ft_apply_op.c	\
				ft_get_operation.c	
CK_PATH		=	${addprefix $(CK_DIR)/, $(CK_FILES)}
CK_SRCS		=	${addprefix $(SDIR)/, $(CK_PATH)}
CK_OBJS		=	$(CK_PATH:%.c=$(BDIR)/%.o)
CK_DEPS		=	$(CK_PATH:%.c=$(DDIR)/%.d)

LIBFTDIR = libft-1.1
LIBFTNAME = ft
LIBFTAR = libft.a
LIBFTPATH = $(LIBFTDIR)/$(LIBFTAR)
LIBFTINCLUDES =  -I $(LIBFTDIR)/includes/
LIBFTFLAGS = -L $(LIBFTDIR)/ -l $(LIBFTNAME) $(LIBFTINCLUDES)

all		:	$(PS_NAME) $(CK_NAME)

bonus 	: $(CK_NAME)

$(PS_NAME)	: $(LIBFTPATH) $(PS_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) -o $@ $(PS_OBJS) $(CMN_OBJS) -I $(HDIR)/ $(LIBFTFLAGS)

$(CK_NAME)	: $(LIBFTPATH) $(CK_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CK_OBJS) $(CMN_OBJS) -I $(HDIR)/ $(LIBFTFLAGS)

-include $(CK_DEPS) $(CMN_DEPS) $(PS_DEPS)

$(BDIR)/%.o		:	$(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIBFTINCLUDES)

fclean	:	clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	$(RMF) $(PS_NAME) $(CK_NAME)

clean	:
	$(RMF) $(CK_OBJS) $(CMN_OBJS) $(PS_OBJS) $(CK_DEPS) $(CMN_DEPS) $(PS_DEPS)

re		:	fclean
	$(MAKE) all

$(LIBFTPATH)	: force
	$(MAKE) -C $(LIBFTDIR)

force	:


.PHONY	:	all\
			fclean\
			clean\
			re\
			bonus
			