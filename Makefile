PS_NAME = push_swap
CK_NAME = checker

CC = cc
RMF = rm -f

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -MMD -MP

DEBUGFILES = 

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
				ft_sort_2.c	\
				ft_sort.c	\
				ft_push_swap_utils.c	\
				ft_quad_insert.c
PS_PATH		=	${addprefix $(PS_DIR)/, $(PS_FILES)}
PS_SRCS		=	${addprefix $(SDIR)/, $(PS_PATH)}
PS_OBJS		=	$(PS_PATH:%.c=$(BDIR)/%.o)
PS_DEPS		=	$(PS_PATH:%.c=$(DDIR)/%.d)

CK_DIR		=	checker
CK_FILES	=	checker.c	
CK_PATH		=	${addprefix $(CK_DIR)/, $(CK_FILES)}
CK_SRCS		=	${addprefix $(SDIR)/, $(CK_PATH)}
CK_OBJS		=	$(CK_PATH:%.c=$(BDIR)/%.o)
CK_DEPS		=	$(CK_PATH:%.c=$(DDIR)/%.d)

LIBFTDIR = libft
LIBFTNAME = ft
LIBFTAR = libft.a
LIBFTPATH = $(LIBFTDIR)/$(LIBFTAR)
LIBFTINCLUDES =  -I $(LIBFTDIR)/includes/
LIBFTFLAGS = -L $(LIBFTDIR)/ -l $(LIBFTNAME) $(LIBFTINCLUDES)

all		:	$(PS_NAME)

bonus	:	$(CK_NAME)

$(PS_NAME)	: lib	$(PS_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) -o $@ $(PS_OBJS) $(CMN_OBJS) -I $(HDIR)/ $(LIBFTFLAGS)

$(CK_NAME)	:	$(CK_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CK_OBJS) $(CMN_OBJS) -I $(HDIR)/ $(LIBFTFLAGS)

-include $(CK_DEPS) $(CMN_DEPS) $(PS_DEPS)

$(BDIR)/%.o		:	$(SDIR)/%.c $(LIBFTPATH)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIBFTINCLUDES)

fclean	:	clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	$(RMF) $(PS_NAME) $(CK_NAME)

clean	:
	$(RMF) $(CK_OBJS) $(CMN_OBJS) $(PS_OBJS) $(CK_DEPS) $(CMN_DEPS) $(PS_DEPS)

re		:	fclean
	@$(MAKE) all

lib:
	$(MAKE) -C $(LIBFTDIR)

libdebug:
	$(MAKE) -C $(LIBFTDIR) debug

.PHONY	:	all	fclean	clean	re	lib libdebug

.PHONY : test_alloc
test_alloc	:	CFLAGS = -g3
test_alloc	:	DEBUGFILES = test_alloc.c
test_alloc	:	lib	$(PS_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ $(PS_OBJS) $(DEBUGFILES) $(CMN_OBJS) -I $(HDIR)/ $(LIBFTFLAGS)
