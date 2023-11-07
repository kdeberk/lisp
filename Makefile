
all:
	clang -Weverything -Wno-padded -Wno-poison-system-directories result.c error.c repl.c read.c sexp.c string.c type.c linked_list.c binary_search_tree.c main.c -lreadline
