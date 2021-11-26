SHELL=/bin/sh
FLAGS=-g -Wall 
CC=gcc
OBJS= exercicio1.c exercicio2.c funcoesAux.c giveIDs.c main.c trees.c types.h

guiao1:
${CC} ${FLAGS} ${OBJS}