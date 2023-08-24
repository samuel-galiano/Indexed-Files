#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Idiomas { int codigo_idioma;
                 char descricao_idioma[20]; };

struct Licoes { int codigo_licao;
                int codigo_idioma_fk;
                int total_niveis; };

struct Exercicios { int codigo_exercicio;
                    int nivel_dificuldade;
                    char descricao_exercicio[100];
                    int resposta_correta;
                    int pontuacao; };

struct Usuarios { int codigo_usuario;
                  char nome[100];
                  int codigo_idioma_fk;
                  int nivel_atual;
                  float pontuacao_total; };

void incluirIdiomas(struct Idiomas *listaDeIdiomas, int &tamanhoAtualLista, int limiteLista) {
    int i = 0;
    system("cls");
    cout << "=========== CADASTRAR IDIOMA ===========" << endl;
    cout << "========================================" << endl;
    cout << "!PARA PARAR DE CADASTRAR DIGITE CODIGO 0!" << endl;
    for (int saida = 1; i < limiteLista && saida != 0; i++){
        cout << "----" << endl;
        cout << "CODIGO DO IDIOMA " << (i+1) <<  ": ";
        cin >> listaDeIdiomas[i].codigo_idioma;
        cin.ignore();
        if (listaDeIdiomas[i].codigo_idioma > 0){ cout << "DESCRICAO: ";
                                                  gets(listaDeIdiomas[i].descricao_idioma);
                                                  tamanhoAtualLista = tamanhoAtualLista + 1; }
        else saida = 0;
    }
    cout << "----" << endl;
    cout << "========================================" << endl;
    cout << "PRESSIONE QUALQUER TECLA PARA RETORNAR" << endl;
    getch();
}

void verificarListaIdiomas(struct Idiomas *listaDeIdiomas, int &tamanhoAtualLista) {
    system("cls");
    cout << "========= LISTA DE IDIOMAS =========" << endl;
    cout << "====================================" << endl;
    for (int i = 0; i < tamanhoAtualLista; i++){
        cout << "----" << endl;
        cout << "CODIGO: " << listaDeIdiomas[i].codigo_idioma << endl;
        cout << "DESCRICAO: " << listaDeIdiomas[i].descricao_idioma << endl;
    }
    cout << "----" << endl;
    cout << "====================================" << endl;
    getch();
}

int main() {
    const int MAXIMO = 5;
    int tamanhoAtualLista = 0;
    int opcaoSelecionada;

    struct Idiomas listaDeIdiomas[MAXIMO];
    do { system("cls");
         cout << "======== BEM VINDO AO LINGOMAX ========" << endl;
         cout << "=======================================" << endl;
         cout << "[ 1 ] - INSERIR NOVO IDIOMA           |" << endl;
         cout << "[ 2 ] - VERIFICAR LISTA DE IDIOMAS    |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ ? ] - ???                           |" << endl;
         cout << "[ 0 ] - SAIR                          |" << endl;
         cout << "=======================================" << endl;
         cout << "SELECIONE UMA OPCAO: ";
         cin >> opcaoSelecionada;

         switch (opcaoSelecionada) {
             case 1:
                 incluirIdiomas(listaDeIdiomas, tamanhoAtualLista, MAXIMO);
                 break;
             case 2:
                 verificarListaIdiomas(listaDeIdiomas, tamanhoAtualLista);
                 break;
             case 0:
                 opcaoSelecionada = 0;
                 break;
             default:
                cout << "OPCAO INVALIDA" << endl;
                break; }
       }  while (opcaoSelecionada != 0);
}
