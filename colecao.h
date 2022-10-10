//Trabalho realizado por:
//Pedro Alexandre Ferreira França
//Valter Abreu Silva Junior

typedef struct _cofo_ COFO;

COFO * criarCofo(int tamanho_maximo);

int inserirNoCofo(COFO *cofo, void * item);
int removerNoCofo(COFO *cofo, void * item, int (cmp) (void *, void *));
int procurarNoCofo(COFO *cofo, void * item, int (cmp) (void *, void *), int (show) (void *));
int limparCofo(COFO *cofo);
int destruirCofo(COFO *cofo);
void *getFirst(COFO *cofo);
void *getNext(COFO *cofo);
