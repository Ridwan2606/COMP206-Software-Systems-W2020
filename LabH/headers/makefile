#Author: Ridwan Kurmally
#Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

prog: linkedlist.o prog.o
	gcc -o prog linkedlist.o prog.o
linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c
prog.o: prog.c 
	gcc -c prog.c