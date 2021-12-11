#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parsing.h"
#include "QueryID3.h"
#include "funcoesAux.h"
int procuraRepo_id(int a[], int n, int elem){
  int i = 0;
  while(i<n){
    if(a[i]==elem) return 1;
    else i++;
  }
  return 0;
}
int NdeReposComBot(aCommit aC,aUsers aU){
    int res=0;
    int N=84900;
    int v[N];
    int i=0;
    int index;//indice para percorrer o array dos commits 
    for (index=0;index<celulasOcupC(aC);index++){
        int e1,e2;
        e1=binarySearchU(aU,0,celulasOcupU(aU)-1,getAuthorID(giveCommit(aC,index)));
        e2=binarySearchU(aU,0,celulasOcupU(aU)-1,getCommitterID(giveCommit(aC,index)));
        if ( (e1==e2 && e1!=0 && e2!=0) && procuraRepo_id(v,N,getRepoID(giveCommit(aC,index)))==0) 
        {
            res++;
            v[i]=getRepoID(giveCommit(aC,index));
            i++;
        }
    }
  return res;
}