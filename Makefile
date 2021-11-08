guiao-1: exercicio1.c exercicio2.c funcoesAux.c 
         gcc exercicio1.c funcoesAux.c -g exercicio2.c -o guiao-1
clean:
      rm -f exercicio-1
	  rm -f guiao-1.o
	  rm -f guiao-1

realy clean:clean
           rm -f guiao-1