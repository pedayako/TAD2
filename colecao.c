//Trabalho realizado por:
//Pedro Alexandre Ferreira França
//Valter Abreu Silva Junior

#include "colecao.h"
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

struct _cofo_{
  int tamanho_maximo;
  int numero_itens;
  int item_atual;
  void ** itens;
};

COFO *criarCofo(int tamanho_maximo){
  COFO *cofo = malloc(sizeof(COFO));

  cofo->tamanho_maximo = tamanho_maximo;
  cofo->numero_itens = 0;
  cofo->itens = malloc(sizeof(void *) * tamanho_maximo);

  for(int i = 0; i < tamanho_maximo; i++){
    cofo->itens[i] = NULL;
  }
  
  return cofo;
}
int destruirCofo(COFO *cofo){
  if ( cofo != NULL && cofo->numero_itens == 0){
    free(cofo->itens);
    free(cofo);
    return TRUE;
  }
  return FALSE;
}
int inserirNoCofo(COFO *cofo, void * item){
  if( cofo != NULL && cofo->numero_itens < cofo->tamanho_maximo){
    cofo->itens[cofo->numero_itens] = item;
    cofo->numero_itens += 1;
    
    return TRUE;
  }
  return FALSE;
}
int removerNoCofo(COFO *cofo, void * item, int (cmp) (void *, void *)){
    if( cofo != NULL && cofo->numero_itens > 0){
        for (int i = 0; i < cofo->numero_itens; i++){
            int resultado = cmp(cofo->itens[i], item);
            if (resultado){
                for (int j = i; j < cofo->numero_itens; j++){
                    cofo->itens[j] = cofo->itens[j+1];
                }
                cofo->numero_itens -= 1;
                return resultado; 
            }
        }
    }
    return FALSE;
}
int procurarNoCofo(COFO *cofo, void * item, int (cmp) (void *, void *), int (show) (void *)){
    if(cofo != NULL && cofo->numero_itens > 0){
        for (int i = 0; i < cofo->numero_itens; i++){
            int resultado = cmp(cofo->itens[i], item);
            if (resultado){
              show(cofo->itens[i]);
              return TRUE;
            }
        }
    }
    return FALSE;
}
int limparCofo(COFO *cofo){
    if(cofo != NULL && cofo->numero_itens > 0){
        for(int i = 0; i < cofo->numero_itens; i++){
            cofo->itens[i] = NULL;
        }
        cofo->numero_itens = 0;
        return TRUE;
    }
    return FALSE;
}
void * getFirst(COFO *cofo){
  if(cofo != NULL && cofo->numero_itens > 0){
    cofo->item_atual = 0;
    return cofo->itens[cofo->item_atual];
  }
  return NULL;
}
void * getNext(COFO *cofo){
  cofo->item_atual += 1;
  if(cofo != NULL && cofo->item_atual < cofo->numero_itens){
    return cofo->itens[cofo->item_atual];
  }
  return NULL;
}


