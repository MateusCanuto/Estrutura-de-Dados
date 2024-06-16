/*
Autor...: Mateus Canuto Araujo.
Data....: 17/06/2024.
Objetivo: Sistema de controle de estoque.
*/

//Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

//Função para posicionar o cursor em um determinado ponto da tela.
void gotoxy(int x, int y){
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Fnção Tela
void tela()
{
    int t;
    system("color 1F");
    system("cls");
    gotoxy(01, 01);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(20, 02);
    printf("SISTEMA DE CONTROLE DE ESTOQUE");
    gotoxy(61,02);
    printf("Estrutura de dados |");
    gotoxy(01, 03);
    printf("|");
    gotoxy(67, 03);
    printf("Prof. Rodney |");
    gotoxy(01, 04);
    printf("+------------------------------------------------------------------------------+");
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(80, t);
        printf("|");
    }

    gotoxy(01, 22);
    printf("+------------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.: ");
    gotoxy(01, 24);
    printf("+------------------------------------------------------------------------------+");
}

//Estruturas

typedef struct
{
    int    cd_produto;
    char   ds_protuto[50];
    char   ds_unid_me[5];
    char   dt_validade[11];
    float  qt_produto;
    float  vl_custoMedio;
    float  vl_total;
} reg_protuto;


typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{
    reg_protuto conteudo;
    TipoApontador proximo;
} TipoItem;


typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
}TipoLista;

void CadastrarMovimentacao(){
    system ("cls");
    tela();
    gotoxy(30, 03);
    printf("CADASTRAR MOVIMENTACAO");
    gotoxy(12, 18);
    printf("+----------------+---------------------+-----------------+");
    gotoxy(12, 19);
    printf("|   Quantidade   |      Custo Medio    |    Valor Total  |");
    gotoxy(12, 20);
    printf("+----------------+---------------------+-----------------+");
    gotoxy(12, 21);
    printf("|                |                     |                 |");
    gotoxy(12, 22);
    printf("+----------------+---------------------+-----------------+");

}

void MenuMovimentacao(){

int opc;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 10);
        printf("1 - Cadastra Movimentacao de Estoque");
        gotoxy(20, 12);
        printf("2 - Lista Movmentacao de Estoque");
        gotoxy(20, 14);
        printf("3 - Retornar ao Menu Principal");
        gotoxy(8, 23);
        printf("Digite sua Opcao: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            //Cadastrar
            break;
        
        case 2:
            //Listas
            break;

        case 3:
            //Menu
            break;
        
        default:
            gotoxy(8, 23);
            printf("Opcao invalida! Tente novamente.");
            _getch();
            break;
        }
        
    } while (opc < 3);
    


}

void AlterarDadosProduto(TipoLista *L, int codigo) {

    if (L->Primeiro == NULL) {
        gotoxy(8, 23);
        printf("Nenhum produto cadastrado.");
    } else {
        TipoApontador atual = L->Primeiro;
        int encontrado = 0;

        while (atual != NULL) {
            if (atual->conteudo.cd_produto == codigo) {
                encontrado = 1;
                system("cls");
                tela();
                gotoxy(27, 03);
                printf("ALTERAR DADOS DO PRODUTO");
                gotoxy(12, 14);
                printf("+--------------------------------------------------------+");
                gotoxy(12, 15);
                printf("|");
                gotoxy(69, 15);
                printf("|");
                gotoxy(27, 15);
                printf("SALDO DO ESTOQUE DO PRODUTO");
                gotoxy(12, 16);
                printf("+--------------------------------------------------------+");
                gotoxy(12, 18);
                printf("+----------------+---------------------+-----------------+");
                gotoxy(12, 19);
                printf("|   Quantidade   |     Custo Medio     |    Valor Total  |");
                gotoxy(12, 20);
                printf("+----------------+---------------------+-----------------+");
                gotoxy(12, 21);
                printf("|                |                     |                 |");
                gotoxy(12, 22);
                printf("+--------------------------------------------------------+");
                gotoxy(12, 06);
                printf("Codigo do Produto......:%d", atual->conteudo.cd_produto);
                gotoxy(9, 8);
                printf("1- Descricao do Produto...:");
                gotoxy(9, 10);
                printf("2- Unidade de Medida......:");
                gotoxy(9, 12);
                printf("3- Data de Validade.......:");
                gotoxy(13, 21);
                printf("%.2f", atual->conteudo.qt_produto);
                gotoxy(30, 21);
                printf("%.2f", atual->conteudo.vl_custoMedio);
                gotoxy(52, 21);
                printf("%.2f", atual->conteudo.vl_total);

                gotoxy(36, 8);
                fflush(stdin);
                gets(atual->conteudo.ds_protuto);
                gotoxy(36, 10);
                fflush(stdin);
                gets(atual->conteudo.ds_unid_me);
                gotoxy(36, 12);
                fflush(stdin);
                gets(atual->conteudo.dt_validade);
                atual->conteudo.vl_total = atual->conteudo.qt_produto * atual->conteudo.vl_custoMedio;

                gotoxy(8, 23);
                printf("Produto alterado com sucesso!");
                break;
            }
            atual = atual->proximo;
        }

        if (!encontrado) {
            gotoxy(8, 23);
            printf("Produto com codigo %d nao encontrado.", codigo);
        }
    }

    _getch();
}


void ConsultarPorCodigo(TipoLista *L) {
    int codigo;
    system("cls");
    tela();
    gotoxy(27, 03);
    printf("CONSULTA PRODUTO POR CODIGO");
    gotoxy(02, 05);
    printf(" Cd Descricao do Produto         Unid Data Valid Qtde     Vl. Unit. Vl Total");
    gotoxy(01, 06);
    printf("+--- ---------------------------- ---- ---------- -------- --------- ----------+");

    if (L->Primeiro == NULL) {
        gotoxy(8, 23);
        printf("Nenhum produto cadastrado.");
    } else {
        gotoxy(8, 23);
        printf("Codigo do Produto: ");
        scanf("%d", &codigo);
        TipoApontador atual = L->Primeiro;
        int encontrado = 0;

        while (atual != NULL) {
            if (atual->conteudo.cd_produto == codigo) {
                encontrado = 1;
                int linha = 7;
                gotoxy(02, linha);
                printf("%03d", atual->conteudo.cd_produto);
                gotoxy(06, linha);
                printf("%-28s", atual->conteudo.ds_protuto);
                gotoxy(35, linha);
                printf("%-4s", atual->conteudo.ds_unid_me);
                gotoxy(40, linha);
                printf("%-10s", atual->conteudo.dt_validade);
                gotoxy(51, linha);
                printf("%8.2f", atual->conteudo.qt_produto);
                gotoxy(60, linha);
                printf("%9.2f", atual->conteudo.vl_custoMedio);
                gotoxy(70, linha);
                printf("%10.2f", atual->conteudo.vl_total);
                break;
            }
            atual = atual->proximo;
        }

        if (!encontrado) {
            gotoxy(8, 23);
            printf("Produto com codigo %d nao encontrado.", codigo);
        }
    }

    _getch();
}


int ListaParaArrayAlf(TipoLista *L, reg_protuto **array) {
    int count = 0;
    TipoApontador atual = L->Primeiro;

    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    *array = (reg_protuto *)malloc(count * sizeof(reg_protuto));
    if (*array == NULL) {
        return 0; // Erro de alocação de memória
    }

    atual = L->Primeiro;
    for (int i = 0; i < count; i++) {
        (*array)[i] = atual->conteudo;

        (*array)[i].ds_protuto[28];
        (*array)[i].ds_unid_me[4];
        (*array)[i].dt_validade[10];

        atual = atual->proximo;
    }

    return count;
}

int compararDescricao(const void *a, const void *b) {
    reg_protuto *produtoA = (reg_protuto *)a;
    reg_protuto *produtoB = (reg_protuto *)b;
    return strcmp(produtoA->ds_protuto, produtoB->ds_protuto);
}

void ConsultarEmOrdemAlfabetica(TipoLista *L) {
    system("cls");
    tela();
    gotoxy(27, 03);
    printf("CONSULTA PRODUTOS EM ORDEM ALFABETICA");
    gotoxy(02, 05);
    printf(" Cd Descricao do Produto         Unid Data Valid Qtde     Vl. Unit. Vl Total");
    gotoxy(01, 06);
    printf("+--- ---------------------------- ---- ---------- -------- --------- ----------+");

    if (L->Primeiro == NULL) {
        gotoxy(8, 23);
        printf("Nenhum produto cadastrado.");
    } else {
        reg_protuto *array;
        int count = ListaParaArrayAlf(L, &array);

        if (count > 0) {
            qsort(array, count, sizeof(reg_protuto), compararDescricao);

            for (int i = 0; i < count; i++) {
                int linha = 7 + i;
                gotoxy(02, linha);
                printf("%03d", array[i].cd_produto);
                gotoxy(06, linha);
                printf("%-28s", array[i].ds_protuto);
                gotoxy(35, linha);
                printf("%-4s", array[i].ds_unid_me);
                gotoxy(40, linha);
                printf("%-10s", array[i].dt_validade);
                gotoxy(51, linha);
                printf("%8.2f", array[i].qt_produto);
                gotoxy(60, linha);
                printf("%9.2f", array[i].vl_custoMedio);
                gotoxy(70, linha);
                printf("%10.2f", array[i].vl_total);
            }

            free(array);
        }
    }

    _getch();
}


int ListaParaArray(TipoLista *L, reg_protuto **array) {
    int count = 0;
    TipoApontador atual = L->Primeiro;

    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    *array = (reg_protuto *)malloc(count * sizeof(reg_protuto));
    if (*array == NULL) {
        return 0; // Erro de alocação de memória
    }

    atual = L->Primeiro;
    for (int i = 0; i < count; i++) {
        (*array)[i] = atual->conteudo;
        atual = atual->proximo;
    }

    return count;
}

int compararCodigo(const void *a, const void *b) {
    reg_protuto *produtoA = (reg_protuto *)a;
    reg_protuto *produtoB = (reg_protuto *)b;
    return produtoA->cd_produto - produtoB->cd_produto;
}

void ConsultarEmOrdemDeCodigo(TipoLista *L) {
    system("cls");
    tela();
    gotoxy(27, 03);
    printf("CONSULTA PRODUTOS EM ORDEM DE CODIGO");
    gotoxy(02, 05);
    printf(" Cd Descricao do Produto         Unid Data Valid Qtde     Vl. Unit. Vl Total");
    gotoxy(01,06);
    printf("+--- ---------------------------- ---- ---------- -------- --------- ----------+");

    if (L->Primeiro == NULL) {
        gotoxy(8,23);
        printf("Nenhum produto cadastrado.");
    } else {
        reg_protuto *array;
        int count = ListaParaArray(L, &array);

        if (count > 0) {
            qsort(array, count, sizeof(reg_protuto), compararCodigo);

            for (int i = 0; i < count; i++) {
                int linha = 7 + i;
                gotoxy(02, linha);
                printf("%03d", array[i].cd_produto);
                gotoxy(06, linha);
                printf("%-28s", array[i].ds_protuto);
                gotoxy(35, linha);
                printf("%-4s", array[i].ds_unid_me);
                gotoxy(40, linha);
                printf("%-10s", array[i].dt_validade);
                gotoxy(51, linha);
                printf("%8.2f", array[i].qt_produto);
                gotoxy(60, linha);
                printf("%9.2f", array[i].vl_custoMedio);
                gotoxy(70, linha);
                printf("%10.2f", array[i].vl_total);
            }

            free(array);
        }
    }

    _getch();
}


void ConsultarFicharioGeral(TipoLista *L) {
    system("cls");
    tela();
    gotoxy(27, 03);
    printf("CONSULTA PRODUTOS");
    gotoxy(02, 05);
    printf(" Cd Descricao do Produto         Unid Data Valid Qtde     Vl. Unit. Vl Total");
    gotoxy(01,06);
    printf("+--- ---------------------------- ---- ---------- -------- --------- ----------+");
    

    if (L->Primeiro == NULL) {
        gotoxy(8,23);
        printf("Nenhum produto cadastrado.");
    } else {
        TipoApontador atual = L->Primeiro;
        int count = 1;
        int linha = 7;

        while (atual != NULL) {
            int i;       
            gotoxy(02, linha);
            printf("%d", atual->conteudo.cd_produto);
            gotoxy(06, linha);
            printf("%s", atual->conteudo.ds_protuto);
            gotoxy(35, linha);
            printf("%s", atual->conteudo.ds_unid_me);
            gotoxy(39, linha);
            printf(" %s", atual->conteudo.dt_validade);
            gotoxy(51, linha);
            printf("%.2f", atual->conteudo.qt_produto);
            gotoxy(60, linha);
            printf("%.2f", atual->conteudo.vl_custoMedio);
            gotoxy(70, linha);
            printf("%.2f", atual->conteudo.vl_total);

            atual = atual->proximo;
            count++;
            linha++;
            
        }
    }

    _getch();
}


void MenuListar(TipoLista *L)
{
    int opc;
    do
    {    
     system("cls");
     tela();
     gotoxy(27, 03);
     printf("CONSULTA PRODUTOS");
     gotoxy(20, 8);
     printf("1 - Consultar Fichario do Produto Geral");
     gotoxy(20, 10);
     printf("2 - Consultar em Ordem de Codigo");
     gotoxy(20, 12);
     printf("3 - Consultar em Ordem Alfabetica");
     gotoxy(20, 14);
     printf("4 - Consultar o Codigo Especifico");
     gotoxy(20, 16);
     printf("5 - Voltar ao Menu Principal");
     gotoxy(8,23);
     printf("Digite uma opcao: ");
     scanf("%d", &opc);
      switch (opc)
        {
            case 1:
                ConsultarFicharioGeral(L);
                break;

            case 2:
                ConsultarEmOrdemDeCodigo(L);
                break;

            case 3:
                ConsultarEmOrdemAlfabetica(L);
                break;

            case 4:
                ConsultarPorCodigo(L);
                break;

            case 5:
                
                return;

            default:
                gotoxy(8, 23);
                printf("Opcao invalida! Tente novamente.");
                _getch();
                break;
        }
    } while (opc != 5);
}
     

void IncluirNoFinal(TipoLista *L)
{
    TipoApontador novo;
    novo = (TipoApontador)malloc(sizeof(TipoItem));

    if (novo == NULL){
        gotoxy(8, 23);
        printf("Erro na alocacao de memoria.");
        return;
    }else{
        novo->conteudo.qt_produto = 0;
        novo->conteudo.vl_custoMedio = 0;
        novo->conteudo.vl_total = 0;
        system("cls");
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO");
        gotoxy(12, 14);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 15);
        printf("|");
        gotoxy(69, 15);
        printf("|");
        gotoxy(27, 15);
        printf("SALDO DO ESTOQUE DO PRODUTO");
        gotoxy(12, 16);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 18);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 19);
        printf("|   Quantidade   |     Custo Medio     |    Valor Total  |");
        gotoxy(12, 20);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 21);
        printf("|                |                     |                 |");
        gotoxy(12, 22);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 06);
        printf("Codigo do Produto......:");
        gotoxy(9, 8);
        printf("1- Descricao do Produto...:");
        gotoxy(9, 10);
        printf("2- Unidade de Medida......:");
        gotoxy(9, 12);
        printf("3- Data de Validade.......:");
        gotoxy(13, 21);
        printf("%.2f", novo->conteudo.qt_produto);
        gotoxy(30, 21);
        printf("%.2f", novo->conteudo.vl_custoMedio);
        gotoxy(52, 21);
        printf("%.2f", novo->conteudo.vl_total);

        //Entrada de dados.
        gotoxy(36, 06);
        scanf("%d", &novo->conteudo.cd_produto);
        gotoxy(36, 8);
        fflush(stdin);
        gets(novo->conteudo.ds_protuto);
        gotoxy(36, 10);
        fflush(stdin);
        gets(novo->conteudo.ds_unid_me);
        gotoxy(36, 12);
        fflush(stdin);
        gets(novo->conteudo.dt_validade);
        
        novo->proximo = NULL;
    }
    if (L->Primeiro == NULL) {
        L->Primeiro = novo;
    } else {
        L->Ultimo->proximo = novo;
    }
    L->Ultimo = novo;
    gotoxy(8, 23);
    printf("Produto Cadastrado com sucesso!");
    _getch();
}

void IncluirNoInicio(TipoLista *L)
{
    TipoApontador novo;
    novo = (TipoApontador)malloc(sizeof(TipoItem));

    if (novo == NULL){
        gotoxy(8, 23);
        printf("Erro na alocacao de memoria.");
        return;
    }else{
        novo->conteudo.qt_produto = 0;
        novo->conteudo.vl_custoMedio = 0;
        novo->conteudo.vl_total = 0;
        system("cls");
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO");
        gotoxy(12, 14);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 15);
        printf("|");
        gotoxy(69, 15);
        printf("|");
        gotoxy(27, 15);
        printf("SALDO DO ESTOQUE DO PRODUTO");
        gotoxy(12, 16);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 18);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 19);
        printf("|   Quantidade   |     Custo Medio     |    Valor Total  |");
        gotoxy(12, 20);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 21);
        printf("|                |                     |                 |");
        gotoxy(12, 22);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 06);
        printf("Codigo do Produto......:");
        gotoxy(9, 8);
        printf("1- Descricao do Produto...:");
        gotoxy(9, 10);
        printf("2- Unidade de Medida......:");
        gotoxy(9, 12);
        printf("3- Data de Validade.......:");
        gotoxy(13, 21);
        printf("%.2f", novo->conteudo.qt_produto);
        gotoxy(30, 21);
        printf("%.2f", novo->conteudo.vl_custoMedio);
        gotoxy(52, 21);
        printf("%.2f", novo->conteudo.vl_total);

        //Entrada de dados:
        gotoxy(36, 06);
        scanf("%d", &novo->conteudo.cd_produto);
        gotoxy(36, 8);
        fflush(stdin);
        gets(novo->conteudo.ds_protuto);
        gotoxy(36, 10);
        fflush(stdin);
        gets(novo->conteudo.ds_unid_me);
        gotoxy(36, 12);
        fflush(stdin);
        gets(novo->conteudo.dt_validade);

    }
    if (L->Primeiro == NULL) {
        L->Primeiro = novo;
    } else {
        novo->proximo = L->Primeiro;
    }
    L->Primeiro = novo;
    gotoxy(8, 23);
    printf("Produto Cadastrado com sucesso!");
    _getch();
}

void IncluirNaPosicao(TipoLista *L) {
    TipoApontador novo, atual, anterior;
    int i, pos;
    novo = (TipoApontador)malloc(sizeof(TipoItem));

    if (novo == NULL) {
        gotoxy(8, 23);  
        printf("Erro na alocacao de memoria.");
        return;
    } else {
        novo->conteudo.qt_produto = 0;
        novo->conteudo.vl_custoMedio = 0;
        novo->conteudo.vl_total = 0;
        system("cls");
        tela();
        gotoxy(30, 03);
        printf("CADASTRAR PRODUTO");
        gotoxy(12, 14);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 15);
        printf("|");
        gotoxy(28, 15);
        printf("SALDO DO ESTOQUE DO PRODUTO");
        gotoxy(69, 15);
        printf("|");
        gotoxy(12, 16);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 18);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 19);
        printf("|   Quantidade   |     Custo Medio     |    Valor Total  |");
        gotoxy(12, 20);
        printf("+----------------+---------------------+-----------------+");
        gotoxy(12, 21);
        printf("|                |                     |                 |");
        gotoxy(12, 22);
        printf("+--------------------------------------------------------+");
        gotoxy(12, 06);
        printf("Codigo do Produto......:");
        gotoxy(9, 8);
        printf("1- Descricao do Produto...:");
        gotoxy(9, 10);
        printf("2- Unidade de Medida......:");
        gotoxy(9, 12);
        printf("3- Data de Validade.......:");
        gotoxy(13, 21);
        printf("%.2f", novo->conteudo.qt_produto);
        gotoxy(30, 21);
        printf("%.2f", novo->conteudo.vl_custoMedio);
        gotoxy(52, 21);
        printf("%.2f", novo->conteudo.vl_total);
        
        //Entrada de dados.
        gotoxy(36, 06);
        scanf("%d", &novo->conteudo.cd_produto);
        gotoxy(36, 8);
        fflush(stdin);
        gets(novo->conteudo.ds_protuto);
        gotoxy(36, 10);
        fflush(stdin);
        gets(novo->conteudo.ds_unid_me);
        gotoxy(36, 12);
        fflush(stdin);
        gets(novo->conteudo.dt_validade);
        
        gotoxy(8, 23);
        printf("Posicao a inserir: ");
        scanf("%d", &pos);

        novo->proximo = NULL;
    }

    if (pos == 1) {
        // Inserir no início
        if (L->Primeiro == NULL) {
            L->Ultimo = novo;
        } else {
            novo->proximo = L->Primeiro;
        }
        L->Primeiro = novo;
    } else {
        // Navegar até a posição
        anterior = NULL;
        atual = L->Primeiro;
        for (i = 1; i < pos && atual != NULL; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            // Inserir no final se a posição especificada for maior que o tamanho da lista
            if (L->Primeiro == NULL) {
                L->Primeiro = novo;
            } else {
                L->Ultimo->proximo = novo;
            }
            L->Ultimo = novo;
        } else {
            // Inserir no meio
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }

    gotoxy(8, 23);
    printf("Produto Cadastrado com sucesso!");
    _getch();
}

void RemoverNoFinal(TipoLista *L) {
    if (L->Primeiro == NULL) {
        // Lista vazia, nada para remover
        gotoxy(8, 23);
        printf("Lista vazia, nada para remover.");
        _getch();
        return;
    }
    
    TipoApontador atual = L->Primeiro;
    TipoApontador anterior = NULL;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        // Só há um elemento na lista
        L->Primeiro = NULL;
        L->Ultimo = NULL;
    } else {
        // Há mais de um elemento na lista
        anterior->proximo = NULL;
        L->Ultimo = anterior;
    }

    free(atual);

    gotoxy(8, 23);
    printf("Produto removido com sucesso!");
    _getch();
}


void RemoverNoInicio(TipoLista *L) {
    if (L->Primeiro == NULL) {
        // Lista vazia, nada para remover
        gotoxy(8, 23);
        printf("Lista vazia, nada para remover.");
        _getch();
        return;
    }
    
    TipoApontador temp = L->Primeiro;
    L->Primeiro = L->Primeiro->proximo;
    
    if (L->Primeiro == NULL) {
        // Se a lista ficou vazia, atualizar o ponteiro do último elemento
        L->Ultimo = NULL;
    }
    
    free(temp);
    
    gotoxy(8, 23);
    printf("Produto removido com sucesso!");
    _getch();
}

void RemoverNaPosicao(TipoLista *L) {
    if (L->Primeiro == NULL) {
        // Lista vazia, nada para remover
        gotoxy(8, 23);
        printf("Lista vazia, nada para remover.");
        _getch();
        return;
    }

    int pos, i;
    TipoApontador atual, anterior;
    gotoxy(8, 23);
    printf("Posicao a remover: ");
    scanf("%d", &pos);

    if (pos == 1) {
        // Remover do início
        atual = L->Primeiro;
        L->Primeiro = atual->proximo;
        if (L->Primeiro == NULL) {
            L->Ultimo = NULL;
        }
        free(atual);
    } else {
        // Navegar até a posição
        anterior = NULL;
        atual = L->Primeiro;
        for (i = 1; i < pos && atual != NULL; i++) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            // Posição especificada é maior que o tamanho da lista
            gotoxy(8, 23);
            printf("Posicao invalida.");
            _getch();
            return;
        } else {
            // Remover no meio ou no final
            anterior->proximo = atual->proximo;
            if (atual == L->Ultimo) {
                L->Ultimo = anterior;
            }
            free(atual);
        }
    }

    gotoxy(8, 23);
    printf("Produto removido com sucesso!");
    _getch();
}



    

void MenuProduto(TipoLista *L)
{
    int codigo;
    int opc;
    do
    {    
     system("cls");
     tela();
     gotoxy(30, 03);
     printf("MENU PRODUTO");
     gotoxy(20, 8);
     printf("1 - Cadastrar Produto no Final da Lista");
     gotoxy(20, 9);
     printf("2 - Cadastrar Produto no Inicio da Lista");
     gotoxy(20, 10);
     printf("3 - Cadastrar Produto em uma Posicao da Lista");
     gotoxy(20, 11);
     printf("4 - Remover Produto no Final da Lista");
     gotoxy(20, 12);
     printf("5 - Remover Produto no Inicio da Lista");
     gotoxy(20, 13);
     printf("6 - Remover Produto em uma Posicao da Lista");
     gotoxy(20, 14);
     printf("7 - Consultar Todos os Produtos");
     gotoxy(20, 15);
     printf("8 - Altera Dados do Produto");
     gotoxy(20, 16);
     printf("9 - Retornar ao Menu Principal");
     gotoxy(8, 23);
     printf("Digite uma opcao: ");
     scanf("%d", &opc);
     switch (opc)
     {
        case 1:
            IncluirNoFinal(L);
            break;

        case 2:
            IncluirNoInicio(L);
            break;

        case 3:
            IncluirNaPosicao(L);
            break;

        case 4:
            RemoverNoFinal(L);
            break;
        
        case 5:
            RemoverNoInicio(L);
            break;
        
        case 6:
            RemoverNaPosicao(L);
            break;

        case 7:
            MenuListar(L);
            break;

        case 8:
            gotoxy(8, 23);
            printf("Codigo do Produto a ser Alterado:");
            scanf("%d", &codigo);
            AlterarDadosProduto(L, codigo);
            break;
        
        case 9:
            return;
            
      default:
            gotoxy(8, 23);
            printf("Opcao invalida! Tente novamente.");
            _getch();
            break;
      
         break;
     }
     }while (opc < 9);

}


//Programa Principal.
int main()
{
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    int opc;

    do
    {
        tela();
        gotoxy(30, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 10);
        printf("1 - Menu Cadastro de Produto");
        gotoxy(20, 12);
        printf("2 - Menu Movimentacao de estoque");
        gotoxy(20, 14);
        printf("3 - Finalizar o Programa");
        gotoxy(8, 23);
        printf("Digite sua Opcao: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            MenuProduto(&L);
            break;
        
        case 2:
            MenuMovimentacao();
        
        default:
            gotoxy(8, 23);
            printf("Opcao invalida! Tente novamente.");
            _getch();
            break;
        }
        
    } while (opc < 3);
    


}