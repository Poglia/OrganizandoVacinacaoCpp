#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

#include "fila_dinamica.hpp"
#include "pilha_dinamica.hpp"

int main()
{

    // DECLARAÇAO E INICIALIZACAO DAS FILAS

    Fila fServidores, fEstudantes;
    initQ(&fServidores);
    initQ(&fEstudantes);

    // DECLARAÇAO E INICIALIZAÇOA DA PILHA

    Pilha pVacinados;
    init(&pVacinados);

    // Declaraçao do registro que vai armazenar temporariamente os dados

    Registro reg;

   

    // Colocaçao manual para teste

 

    // reg.dado.nome = "Pedro" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "Sputnik_V";
    // reg.dado.tipo = "Estudante";

    //  enqueue(&fEstudantes, reg);

    //   reg.dado.nome = "Joao" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "Coronavac";
    // reg.dado.tipo = "Servidor";

    // enqueue(&fServidores, reg);

    //  reg.dado.nome = "Artur" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "Sputnik_V";
    // reg.dado.tipo = "Servidor";

    // enqueue(&fServidores, reg);

    // reg.dado.nome = "Jorge" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "ButanVac";
    // reg.dado.tipo = "Estudante";

    // enqueue(&fEstudantes, reg);

    // reg.dado.nome = "Augusto" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "AZD1222";
    // reg.dado.tipo = "Estudante";

    // enqueue(&fEstudantes, reg);

    // reg.dado.nome = "Silas" ;
    // reg.dado.idade = 20;
    // reg.dado.dataVacina = "20/10";
    // reg.dado.tipoVacina = "ButanVac";
    // reg.dado.tipo = "Servidor";

    // enqueue(&fServidores, reg);




     // VARIAVEIS PARA FACILITAR O PROGRAMA

    
    int codTipoPessoa; // recebe o cod do servidor/estudante
    int codTipoVacina;
    int contVacinados=0; 
    int somaIdades=0; 
    string vacinaNome; 

    //ARQUIVO TEXTO para armazenar os dados

    ofstream arquivoEscrita;
    ifstream arquivoLeitura;
    string linha;

 int menu=-1;

   

     do{
        system("CLS");
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"| 0  - Sair                                             |"<<endl;
        cout<<"| 1  - Iniciar um cadastro                              |"<<endl;
        cout<<"| 2  - Vacinar o proximo                                |"<<endl;
        cout<<"| 3  - Listar servidores                                |"<<endl;
        cout<<"| 4  - Listar estudantes                                |"<<endl;
        cout<<"| 5  - Listar TODOS os vacinados                        |"<<endl;
        cout<<"| 6  - Listar SERVIDORES vacinados                      |"<<endl;
        cout<<"| 7  - Listar ESTUDANTES vacinados                      |"<<endl;
        cout<<"| 8  - Mostrar media de idade dos vacinados             |"<<endl;
        cout<<"| 9  - Mostrar vacinados pelo tipo de vacina            |"<<endl;
        cout<<"| 10 - Mostrar dados do arquivo                         |"<<endl;
        cout<<"|                                                       |"<<endl;
        cout<<"| Digite um numero:";   cin>>menu;
        cout<<"|-------------------------------------------------------|"<<endl;

        switch (menu)
        {
            case 0:
                cout<<"\nPrograma finalizado\n";

                break;

            case 1:

                    cout<<"\nDigite o nome: ";
                    cin>> reg.dado.nome;
                    fflush(stdin); 
                    cout<<"\nDigite a idade: ";
                    cin >> reg.dado.idade;
                    fflush(stdin);
                    cout<<"\nDigite a data da vacina: ";
                    cin >> reg.dado.dataVacina;
                    fflush(stdin); 
                    cout<<"\nDigite o  numero correspondente ao tipo da vacina:\n[1]CoronaVac \n[2]ButanVac \n[3]Sputnik_V \n[4]AZD1222\n[?]: ";
                    cin >>  codTipoVacina;
                    fflush(stdin); 
                    cout<<"\nDigite o numero correspondente a pessoa:\n[1]Servidor\n[2]Estudante\n: ";
                    cin >> codTipoPessoa;
                     fflush(stdin); 

                    codTipoPessoa == 1 ?  reg.dado.tipo = "Servidor" :  reg.dado.tipo = "Estudante";
                   
                    if( reg.dado.tipo == "Servidor"){
                        
                        enqueue(&fServidores, reg);
                    }
                    else
                        enqueue(&fEstudantes, reg);

                   // pessoa.tipo == 1 ? enqueue(&servidores, pessoa) : enqueue(&estudantes, pessoa);

                   switch (codTipoVacina)
                   {
                   case 1:
                        reg.dado.tipoVacina == "CoronaVac";
                       break;
                   case 2:
                        reg.dado.tipoVacina == "ButanVac";
                        break;
                   case 3:
                        reg.dado.tipoVacina == "Sputnik_V";
                        break;
                   case 4:
                        reg.dado.tipoVacina == "AZD1222";
                        break;
                   }
                                      
                    system("pause");

                break;

            case 2: // RETIRA DAS FILAS E COLOCA NA PILHA

                     if(isEmptyQ(&fServidores) && !isEmptyQ(&fEstudantes)){

                         cout<<"\nEstudante VACINADO\n\n";
                         dequeue(&fEstudantes, &reg);
                         push(&pVacinados, reg);
                         
                     }else if(!isEmptyQ(&fServidores)){

                         cout<<"\nServidor VACINADO\n\n";
                         dequeue(&fServidores, &reg);
                         push(&pVacinados, reg);
                     }else{

                         cout<<"Nao existem mais pessoas na fila de vacinacao\n\n";
                     }

                     // INCLUSAO NO ARQUIVO TEXTO

                        arquivoEscrita.open("vacinados.txt", ios::app);

                        arquivoEscrita << reg.dado.nome << "; " << reg.dado.idade << "; " << reg.dado.dataVacina << "; " << reg.dado.tipoVacina << "; " << reg.dado.tipo <<"\n";

                        arquivoEscrita.close();

                    // PARA CALCULAR A MEDIA DAS IDADES 

                    contVacinados++;
                    somaIdades = somaIdades + reg.dado.idade;

                    system("pause");

                break;

            case 3: // LISTA OS SERVIDORES
                    
                if(isEmptyQ(&fServidores))
                    cout<<"\nA FILA DOS SERVIDORES ESTA VAZIA NO MOMENTO!\n";

                else
                    showQ(&fServidores);

                    system("pause");

                break;

            case 4: // LISTA OS ESTUDANTES

                if(isEmptyQ(&fEstudantes))
                    cout<<"\nA FILA DOS ESTUDANTES ESTA VAZIA NO MOMENTO!\n";

                else
                    showQ(&fEstudantes);

                    system("pause");

                break;
            
             case 5: // LISTA OS DADOS DA PILHA 

                if(isEmpty(&pVacinados))
                    cout<<"\nAINDA NAO EXISTEM PESSOAS VACINADAS\n\n";
                else
                    show(&pVacinados);

                    system("pause");

                break;

            case 6: // LISTA OS VACINADOS SERVIDORES

                    showServidores(&pVacinados);
                    system("pause");

                break;

             case 7: // LISTA OS VACINADOS ESTUDANTES

                    showEstudantes(&pVacinados);
                    system("pause");

                break;
            
            case 8: // CALCULA A MEDIA DAS IDADES

                int mediaIdade;
                mediaIdade = (somaIdades/contVacinados);
                cout<<"\n A media das idades dos vacinados e de: " << mediaIdade << endl;

                    system("pause");

                break;

            case 9:

                codTipoVacina = 0;
                cout<<"\nDigite o  numero correspondente ao tipo da vacina:\n[1]CoronaVac \n[2]ButanVac \n[3]Sputnik_V \n[4]AZD1222\n[?]: ";
                cin >>  codTipoVacina;

                switch (codTipoVacina)
                   {
                   case 1:
                       vacinaNome = "CoronaVac";
                       break;
                   case 2:
                        vacinaNome = "ButanVac";
                        break;
                   case 3:
                        vacinaNome = "Sputnik_V";
                        break;
                   case 4:
                       vacinaNome = "AZD1222";
                        break;
                   }

                        showFiltroVacina(&pVacinados,vacinaNome);
                

                    system("pause");

                break;

            case 10:

                     arquivoLeitura.open("vacinados.txt", ios::app);
                     if(arquivoLeitura.is_open()){

                         cout<<"ARQUIVO DOS VACINADOS: \n";

                         while(getline(arquivoLeitura, linha)){
                             cout<<linha << endl;
                         }

                     }else cout<<"ERRO: Nao foi possivel abrir arquivo";


                    system("pause");

                break;

            default:
                cout<<"\n Esse numero não esta funcionando, tente outro! \n";

                    system("pause");

                break;
            }


    }while (menu != 0);

}

   

   

  






