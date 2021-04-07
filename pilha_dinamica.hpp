//pilha_dinamica.hpp

typedef struct pilha
{
    No *topo;
} Pilha;

void init(Pilha *p)
{
    p->topo = NULL; ///pilha vazia /// (*p).topo
}

bool isEmpty(Pilha *p) /// verifica se a pilha esta vazia
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

bool push(Pilha *p, Registro registro) /// empilhar
{
    No *novo =  new No();
    if (!novo) /// sistema nao conseguiu alocar a memoria
        return false;
    novo->reg = registro;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop (Pilha *p, Registro *reg) /// desempilhar
{
    if (isEmpty(p))
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;  /// libera a memoria
    return true;
}

void show(Pilha *p)
{
    No *no = p->topo;
    cout << "\n VACINADOS: \n";
    while (no != NULL)
    {
        cout << "Nome: " <<         no->reg.dado.nome;
        cout << "\nIdade: " <<        no->reg.dado.idade ;
        cout << "\nData vacina: " <<  no->reg.dado.dataVacina;
        cout << "\nTipo vacina: " <<  no->reg.dado.tipoVacina;
        cout << "\nCategoria: " <<    no->reg.dado.tipo;
        cout<<"\n\n----------------------------------------------------\n\n";
        no = no->prox;
    }
    cout << " \n";
}
void showFiltroVacina(Pilha *p, string vacina)
{
    No *no = p->topo;
    cout << "\n VACINADOS: \n";
    while (no != NULL)
    {
        //cout<<"vacina da variavel: "<<vacina<<endl;
        //cout<<"vacina da funçao: "<<no->reg.dado.tipoVacina<<endl;
        if(no->reg.dado.tipoVacina == vacina){
        cout << "Nome: " <<         no->reg.dado.nome;
        cout << "\nIdade: " <<        no->reg.dado.idade ;
        cout << "\nData vacina: " <<  no->reg.dado.dataVacina;
        cout << "\nTipo vacina: " <<  no->reg.dado.tipoVacina;
        cout << "\nCategoria: " <<    no->reg.dado.tipo;
        cout<<"\n\n----------------------------------------------------\n\n";
        }
        no = no->prox;
    }
    cout << " \n";
}


void showServidores(Pilha *p)
{
    No *no = p->topo;
    cout << "\n SERVIODRES VACINADOS:  \n\n ";
    while (no != NULL)
    {
        if(no->reg.dado.tipo == "Servidor"){
        cout << "Nome: " <<         no->reg.dado.nome;
        cout << "\nIdade: " <<        no->reg.dado.idade ;
        cout << "\nData vacina: " <<  no->reg.dado.dataVacina;
        cout << "\nTipo vacina: " <<  no->reg.dado.tipoVacina;
        cout << "\nCategoria: " <<    no->reg.dado.tipo;
        cout<<"\n\n----------------------------------------------------\n\n";
        
        }
        no = no->prox;
    }
    cout << " \n";
}

void showEstudantes(Pilha *p)
{
    No *no = p->topo;
    cout << "\n ESTUDANTES VACINADOS: \n\n ";
    while (no != NULL)
    {
        if(no->reg.dado.tipo == "Estudante"){
        cout << "Nome: " <<         no->reg.dado.nome;
        cout << "\nIdade: " <<        no->reg.dado.idade ;
        cout << "\nData vacina: " <<  no->reg.dado.dataVacina;
        cout << "\nTipo vacina: " <<  no->reg.dado.tipoVacina;
        cout << "\nCategoria: " <<    no->reg.dado.tipo;
        cout<<"\n\n----------------------------------------------------\n\n";
        
        }
        no = no->prox;
    }
    cout << "\n";
}

bool peek(Pilha* p, Registro *reg)
{
    if (p->topo != NULL)
    {
        *reg= p->topo->reg;
        return true;
    }
    else
        return false;
}


