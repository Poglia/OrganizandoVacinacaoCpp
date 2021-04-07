struct pessoas
{
    string nome;
    int idade;
    string dataVacina;
    string tipoVacina;
    string tipo;
};


typedef struct registro
{
    pessoas dado;

} Registro;

typedef struct no
{
    Registro reg;
    no *prox;
}No;

typedef struct fila
{
    No *frente;
    No *re;
} Fila;

/// funcoes: initQ, enqueue, dequeue, showQ,  resetQ, peekQ

void initQ(Fila *f)
{
    f->frente = NULL;
    f->re = NULL;
}

bool isEmptyQ(Fila *f) // ve se a fila esta vazia
{
    if(  f->frente == NULL && f->re == NULL )
    return true;
    else 
    return false;
  
    
}

bool enqueue(Fila *f, Registro reg)
{
    No *novo = new No();
    if (novo == NULL) /// nao conseguiu alocar memoria
        return false;
    novo->reg = reg;
    novo->prox = NULL;
    if (f->frente == NULL)/// fila estava vazia
        f->frente = novo;
    else
        f->re->prox = novo;
    f->re = novo;
    return true;
}


bool dequeue(Fila *f, Registro *reg = NULL)
{
    if (f->frente == NULL)
        return false;
    if (reg != NULL)
        *reg = f->frente->reg;
    No *apagar = f->frente;
    f->frente = f->frente->prox; /// atualiza a frente da fila
    delete(apagar); /// apagar elemento
    if (f->frente == NULL)
        f->re = NULL;
    return true;
}

void showQ(Fila *f)/// mostrar a fila
{
    No *nodo = f->frente;
    cout << "\nFila: " << endl;
    while(nodo != NULL)
    {
        cout << "Nome: " << nodo->reg.dado.nome;
        cout << "\nIdade: " << nodo->reg.dado.idade ;
        cout << "\nData vacina: " << nodo->reg.dado.dataVacina;
        cout << "\nTipo vacina: " << nodo->reg.dado.tipoVacina;
        cout << "\nCategoria: " << nodo->reg.dado.tipo;
        cout<<"\n\n----------------------------------------------------\n\n";
        
        nodo = nodo->prox;
    }
    cout << "\n";
    
}


No *peekQ(Fila *f)
{
    No *nodo = f->frente;
    return nodo;
}

void resetQ(Fila *f) ///excluir todos os nodos da fila - liberar mem�ria
{
    No *nodo = f->frente;
    while (nodo != NULL)
    {
        No *apagar = nodo;
        nodo = nodo->prox;
        delete(apagar);
    }
    f->frente = NULL;
    f->re = NULL;
}









