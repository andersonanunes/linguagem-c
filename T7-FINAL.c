/**
  * ENUNCIADO: Considere a necessidade de elaborar um programa em C para cadastrar dois tipos diferentes de entidades (representadas por estruturas).
  * Desenvolver a descricao de um problema que exige a necessidade de armazenamento de duas entidades, e nesse caso,
  * sera necessario utilizar duas estruturas (ex: Aluno e Curso);
  * Desenvolver duas funcionalidades (funcoes) associadas a dois tipos diferentes de pesquisa para cada entidade
  * (ex: listar todos os alunos cujo nome comeca com a letra A, listar todos os alunos com uma determinada idade,
  * listar o nome do curso e carga horaria de determinado codigo)
  * Realizar o relacionamento entre as entidades e imprimir uma relacao desse relacionamento (ex: Listar todos os alunos de um determinado curso).

  * @authr
  * ALUNO:      Anderson Anselmi Nunes - RA 1430481923044
  * DISCIPLINA: Linguagem de Programacao
  * PROF:       SANDRA
*/

// declaracao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tam 10
#define arqProduto "produto.dat"
#define arqFornecedor "fornecedor.dat"
#define arqConsulta

// definicao das estruturas
typedef struct {
    int codigo;
    char razaoSocial[50];
    char CNPJ[15];
    char telefone[11];
    char endereco[50];
} Fornecedor;

typedef struct{
    int codigo;
    char nome[30];
    int qtde;
    float preco;
    Fornecedor pFornecedor;
} Produto;

// declaracao de prototipo
void criarMenu();
void CadastroFornecedor();
void CadastroProduto();
void ConsultarProdutoTotal();
void ConsultarProdutoCodigo();
void ConsultarProdutoNome();
void ConsultarFornecedorTotal();
void ConsultarFornecedorCNPJ();
void ConsultarFornecedorNome();
void ConsultarProdutoFornecedor();

// funcao principal
int main(){
    criarMenu();
    return 0;
}

/**
  * FUNCAO          : funcao para criar o menu
  * AUTOR           : Anderson
  * DATA            : 01 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void criarMenu (){

    int opcao;

    do {
        //montagem do menu de opcoes
        printf("\n\n\t\t    ========================================\n");
        printf("\t\t        Selecione uma das opcoes abaixo\n");
        printf("\t\t    ========================================\n");
        printf("\n\t\t    1 - Cadastrar Produto");
        printf("\n\t\t    2 - Cadastrar Fornecedor");
        printf("\n\t\t    3 - Consultar Todos Produtos");
        printf("\n\t\t    4 - Consultar Produto por Codigo");
        printf("\n\t\t    5 - Consultar Produto por Nome");
        printf("\n\t\t    6 - Consultar Todos Fornecedores");
        printf("\n\t\t    7 - Consultar Fornecedor por CNPJ");
        printf("\n\t\t    8 - Consultar Fornecedor por Nome");
        printf("\n\t\t    9 - Consultar Produto por Fornecedor");
        printf("\n\t\t    0 - Sair do Sistema\n\n");
        printf("\t\t    Qual a opcao desejada? ");
        scanf("%d", &opcao);

        // verifica qual a opcao selecionada
        switch(opcao){
            case 1:
                system("cls");
                CadastroProduto();
                break;
            case 2:
                system("cls");
                CadastroFornecedor();
                break;
            case 3:
                system("cls");
                ConsultarProdutoTotal();
                break;
            case 4:
                system("cls");
                ConsultarProdutoCodigo();
                break;
            case 5:
                system("cls");
                ConsultarProdutoNome();
                break;
            case 6:
                system("cls");
                ConsultarFornecedorTotal();
                break;
            case 7:
                system("cls");
                ConsultarFornecedorCNPJ();
                break;
            case 8:
                system("cls");
                ConsultarFornecedorNome();
                break;
            case 9:
                system("cls");
                ConsultarProdutoFornecedor();
                break;
            case 0:
                system("cls");
                break;
            default:
                printf("Opcao invalida!");
                system("cls");
                break;
        }
    } while (opcao != 0);
    return;
}

/**
  * FUNCAO          : 1 - CadastroProduto
  * AUTOR           : Anderson
  * DATA            : 01 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void CadastroProduto(){

    FILE * arq;
    Produto item;
    int num = 0;

    do {
        arq = fopen(arqProduto, "a + b"); // A Add o item no final do arquivo. Se o arquivo nao existir, a funcao o cria. B define que e .dat
        system("cls");
        // cabecalho da tela de cadastro de produtos
        printf("\n\n\t========================================\n");
        printf("\t1 - Cadastro de Produtos\n");
        printf("\t========================================\n");

        // se o arquivo nao existe exibe erro
        if(arq == NULL){
            fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arqProduto);
        }

        // reposiciona o ponteiro
        fseek(arq, 0, SEEK_END);

        // inicia o contador do codigo do produto
        item.codigo = ftell(arq) / sizeof(Produto) + 1;

        // BEGIN ENTRADA DE DADOS
        printf("\tEntre com os dados do produto:\n");

        printf("\n\tCodigo: %d", item.codigo);
        fflush(stdin);

        printf("\n\tNome: ");
        fflush(stdin);
        gets(item.nome);

        printf("\n\tQuantidade em estoque: ");
        fflush(stdin);
        scanf("%d", &item.qtde);

        printf("\n\tValor: ");
        fflush(stdin);
        scanf("%f", &item.preco);

        printf("\n\t Fornecedor: ");
        fflush(stdin);
        gets(item.pFornecedor.razaoSocial);
        // END ENTRADA DE DADOS

        // grava no arquivo
        fwrite(&item, sizeof(Produto), 1, arq);
        system("cls");
        printf("\n\n\t *** Produto Cadastrado com Sucesso! ***\n\n");

        // fecha o arquivo
        fclose(arq);

        // verifica se o usuario deseja cadastrar um novo produto
        printf("\n\tDeseja Cadastrar outro Produto ?\n\n\t1 - SIM\n\n\t2 - NAO\n\n ");
        scanf("%d", &num);
        while(num < 0 || num > 2){
            system("cls");
            printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1 - SIM\n\n\t\t2 - NAO\n");
            scanf("%d", &num);
        }

    } while (num == 1); // se a opcao for 1 continua cadastrando
    system("cls");
    return;
}

/**
  * FUNCAO          : 2 - CadastroFornecedor
  * AUTOR           : Anderson
  * DATA            : 01 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void CadastroFornecedor(){

    FILE * arq;
    Fornecedor fornecedor;
    int num = 0;

    do {
        arq = fopen(arqFornecedor, "a + b"); // A Add o item no final do arquivo. Se o arquivo nao existir, a funcao o cria. B define que e .dat
        system("cls");
        // cabecalho da tela de cadastro de fornecedores
        printf("\n\n\t========================================\n");
        printf("\t2 - Cadastro de Fornecedores\n");
        printf("\t========================================\n");

        // se o arquivo nao existe exibe erro
        if(arq == NULL){
            fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arqFornecedor);
        }

        // reposiciona o ponteiro
        fseek(arq, 0, SEEK_END);

        // inicia o contador do codigo do fornecedor
        fornecedor.codigo = ftell(arq) / sizeof(Fornecedor) + 1;

        // BEGIN ENTRADA DE DADOS
        printf("\tEntre com os dados do fornecedor:\n");

        printf("\n\tCodigo: %d", fornecedor.codigo);
        fflush(stdin);

        printf("\n\tRazao Social: ");
        fflush(stdin);
        //fgets(fornecedor.razaoSocial, 50, stdin);
        gets(fornecedor.razaoSocial);

        printf("\n\tCNPJ: ");
        fflush(stdin);
        //fgets(fornecedor.CNPJ, 15, stdin);
        gets(fornecedor.CNPJ);

        printf("\n\tTelefone: ");
        fflush(stdin);
        //fgets(fornecedor.telefone, 11, stdin);
        gets(fornecedor.telefone);

        printf("\n\tEndereco: ");
        fflush(stdin);
        //fgets(fornecedor.endereco, 50, stdin);
        gets(fornecedor.endereco);
        // END ENTRADA DE DADOS

        // grava no arquivo
        fwrite(&fornecedor, sizeof(Fornecedor), 1, arq);
        printf("\n\n\t *** Fornecedor Cadastrado com Sucesso! ***\n\n");

        // fecha o arquivo
        fclose(arq);

        // verifica se o usuario deseja cadastrar um novo fornecedor
        printf("\n\tDeseja Cadastrar outro Fornecedor? 1 - SIM   2 - NAO \t DIGITE: ");
        scanf("%d", &num);
        while(num < 0 || num > 2){
            system("cls");
            printf("\n\tOpcao Invalida!!\n\n Digite novamente: 1 - SIM   2 - NAO \t DIGITE: ");
            scanf("%d", &num);
        }
    } while (num == 1); // se a opcao for 1 continua cadastrando

    system("cls");
    return;
}

/**
  * FUNCAO          : 3 - ConsultarProdutoTotal
  * AUTOR           : Anderson
  * DATA            : 01 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarProdutoTotal(){

    system("cls");

    FILE * arq1;
    FILE * arq2;

    Produto pConsulta;
    int num;

    //arq1 = fopen(arqProduto, "rb");
    //arq2 = fopen(arqConsulta"cProdutoGeral.txt", "w");

    // se o arquivo for nulo
    if ((arq1 = fopen(arqProduto, "rb")) == NULL){
        fprintf(stderr, "\n\tNao existem produtos cadastrados!\n");
        printf("\n\n");
        system("pause");
        return;
    }
    // se o arquivo for nulo
    if ((arq2 = fopen(arqConsulta"cProdutoGeral.txt", "w")) == NULL){
        fprintf(stderr, "\n\tErro ao abrir o arquivo %s!\n", arqConsulta"cProdutoGeral.txt");
        printf("\n\n");
        system("pause");
        return;
    }

    // cabecalho
    printf("\n\n CONSULTA DE PRODUTOS\n\n");
    printf(" ============================================================================\n");
    printf(" CODIGO\t NOME                            QTDE       VALOR(R$)  FORNECEDOR\n");
    printf(" ============================================================================\n\n");
    printf(" ----------------------------------------------------------------------------\n");

    while (fread(&pConsulta, sizeof(Produto), 1, arq1) > 0) {
        printf(" %06d %-30s   %-10d %-10.2f %-15s \n",pConsulta.codigo, pConsulta.nome, pConsulta.qtde, pConsulta.preco, pConsulta.pFornecedor.razaoSocial);
        printf(" ----------------------------------------------------------------------------\n");
    }

    // posiciona o ponteiro no inicio do arquivo
    fseek(arq1, 0, SEEK_SET);

    printf("\n\n Deseja gerar um relatorio ? 1 - SIM  2 - NAO \t DIGITE: ");
    scanf("%d", &num);
    while(num < 1 || num > 2){
        system ("cls");
        printf("\n\tOpcao Invalida!!!");
        printf("\n\n Deseja gerar um relatorio ? 1 - SIM   2 - NAO \t DIGITE: ");
        scanf("%d", &num);
    }

    // se quiser gerar o relatorio
    if(num == 1){

        // cabecalho do relatorio
        fprintf(arq2,"\n\n RELATORIO DE PRODUTOS CADASTRADOS\n\n");
        fprintf(arq2," ============================================================================\n");
        fprintf(arq2," CODIGO\t NOME                            QTDE       VALOR(R$) FORNECEDOR\n");
        fprintf(arq2," -----------------------------------------------------------------------\n");

        // enquanto nao chegou no final do arquivo
        while (fread(&pConsulta, sizeof(Produto), 1, arq1) > 0) {
            fprintf(arq2," %06d %-30s %-10d %-10.2f \n", pConsulta.codigo, pConsulta.nome, pConsulta.qtde, pConsulta.preco);
            fprintf(arq2," ----------------------------------------------------------------------------\n");
        }

        fprintf(arq2," ============================================================================\n");
        system ("cls");
        printf("\n\n\tRelatorio gerado com sucesso!\n\n");

    } else if(num == 2){ // volta para tela inicial
        system ("cls");
        return;
    }

    //reseta as telas
    system("pause");
    system("cls");

    // fecha o BD
    fclose(arq1);
    fclose(arq2);

    return;
}

/**
  * FUNCAO          : 4 - ConsultarProdutoCodigo
  * AUTOR           : Anderson
  * DATA            : 03 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarProdutoCodigo(){
    //Declara��es de vari�veis (Com TypeDef e abertura de File)
    Produto pItem;
    int i=0, codpesq, j=0, achei, num=0, num2=0;
    FILE * arq;

    //Laco para executar a condicao ao menos uma vez antes de verificar
    do{
        achei = 0;
        //Atribuicao/Abertura do arquivo e verificacao se ha conteudo
        if ((arq = fopen(arqProduto, "rb")) == NULL) {
            fprintf(stderr, "\n\tErro: Nao existe nenhum produto cadastrado!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            return;
        }
        printf("\n\n *** CONSULTA DE PRODUTO POR CODIGO ***\n\n");
        //Laco para executar a condicao ao menos uma vez antes de verificar (busca do codigo digitado pelo usuario)
        do {
            printf(" Digite o Codigo do Produto que deseja pesquisar: ");
            //fflush(stdin);
            scanf("%d", &codpesq);
            printf("\n\n");
            rewind(arq); //Retoma o inicio do arquivo

            // cabecalho
            printf(" ============================================================================\n");
            printf(" CODIGO\t NOME                         QTDE        VALOR(R$)  FORNECEDOR\n");
            printf(" ============================================================================\n\n");

            while(fread(&pItem, sizeof(Produto), 1, arq) > 0) {//Laco para leitura do bloco Produto
                //Condicao para verificar codigo igual ao digitado e impressao dos dados
                if(codpesq == pItem.codigo){
                    printf(" %06d %-30s %-10d %-10.2f %-15s \n", pItem.codigo, pItem.nome, pItem.qtde, pItem.preco, pItem.pFornecedor.razaoSocial);
                    printf(" ----------------------------------------------------------------------------\n");
                    achei = 1;
                }
            }

            if (!achei){ //se nao encontrou produto imprime mensagem
                printf("\n\n Nao existe produto cadastrado com esse codigo: %d\n\n", codpesq);
                printf("\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
                scanf("%d", &num);
                while(num < 1 || num > 2){
                    printf("\n\n Opcao Invalida!!!");
                    printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
                    scanf("%d", &num);
                    system("cls");
                }
            }
        } while(!achei);

        fseek(arq, 0, SEEK_SET);//Volta ao inicio do arquivo
        fclose(arq);//Fecha o arquivo aberto

        // realiza uma nova consulta
        printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
        while(num < 1 || num > 2){
            system ("cls");
            printf("\n\n Opcao Invalida!!!");
            printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
            scanf("%d", &num);
        }
    } while(num2 == 1);
    system("cls");
    return;
}

/**
  * FUNCAO          : 5 - ConsultarProdutoNome
  * AUTOR           : Anderson
  * DATA            : 03 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarProdutoNome(){
    //Declaracoes de variaveis (Com TypeDef e abertura de File)
    FILE * arq;
    Produto pItem;
    char nome[50];
    int achei, i=0, j=0, num=0, num2=0;

    do{//La�o para executar a condicao ao menos uma vez antes de verificar
        system("cls");
        achei = 0;
        if ((arq = fopen(arqProduto, "rb")) == NULL) {//Atribuicao/Abertura do arquivo e verificacao se ha conteudo
            printf("\n\tNao existe nenhum produto cadastrado!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            return;
        }
        printf("\n\n *** CONSULTA DE PRODUTOS POR NOME ***\n\n");
        do{//Laco para executar a condicao ao menos uma vez antes de verificar (busca do nome digitado pelo usuario)
            printf("\n Digite o Nome do Produto que deseja pesquisar: ");
            scanf(" %50[^\n]", nome);
            printf("\n\n");
            rewind(arq);//Retorma inicio do arquivo

            // cabecalho
            printf(" ==========================================================================\n");
            printf(" CODIGO\t NOME                          QTDE       VALOR(R$)  FORNECEDOR\n");
            printf(" ==========================================================================\n");

            //La�o para leitura do bloco Produto
            while(fread(&pItem, sizeof(Produto), 1, arq) > 0){
                for(i=0;i<(strlen(nome));i++)//La�o no comprimento do nome
                {
                    nome[i]=toupper(nome[i]);//Atribui a variavel nome a letra maiuscula do nome digitado
                    for(j=0;j<(strlen(pItem.nome));j++)//La�o no comprimento do membro nome
                    {
                        pItem.nome[j]=toupper(pItem.nome[j]);//Membro nome recebe nome em maiuusculo
                    }
                }

                if(strncmp(nome,pItem.nome, strlen(nome)) == 0){//Se o comprimento forem iguais, imprime
                    printf(" %06d %-30s %-10d %-10.2f %-15s \n", pItem.codigo, pItem.nome, pItem.qtde, pItem.preco, pItem.pFornecedor.razaoSocial);
                    printf(" -----------------------------------------------------------------------------\n");
                    achei = 1;
                }
            }
            if (!achei){//Verifica se achou algum produto e imprime mensagem
              printf("\n\n\tNao existe produto cadastrado com esse nome: %s\n\n",nome);
              printf("\n\tDigite Novamente !\n\n");
            }
        } while(!achei);

        fseek(arq,0,SEEK_SET);//Volta ao inicio do arquivo
        fclose(arq);//Fecha arquivo

        // realiza uma nova consulta
        printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
        while(num < 1 || num > 2){
            system ("cls");
            printf("\n\n Opcao Invalida!!!");
            printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
            scanf("%d", &num);
        }
    } while(num == 1);
    system("cls");
}

/**
  * FUNCAO          : 6 - ConsultaFornecedorTotal
  * AUTOR           : Anderson
  * DATA            : 01 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarFornecedorTotal(){

    system("cls");

    FILE * arq1;
    FILE * arq2;

    Fornecedor pFornecedor;
    int num;

    // se o arquivo for nulo
    if ((arq1 = fopen(arqFornecedor, "rb")) == NULL){
        fprintf(stderr, "\n\tNao existem fornecedores cadastrados!\n");
        printf("\n\n");
        system("pause");
        system("cls");
        return;
    }
    // se o arquivo for nulo
    if ((arq2 = fopen(arqFornecedor"cFornecedoresGeral.txt", "w")) == NULL){
        fprintf(stderr, "\n\tErro ao abrir o arquivo %s!\n", arqFornecedor"cFornecedoresGeral.txt");
        printf("\n\n");
        system("pause");
        return;
    }

    // cabecalho
    printf("\n\n *** CONSULTA DE FORNECEDORES ***\n\n");
    printf(" ============================================================================\n");
    printf(" CODIGO RAZAO SOCIAL\t     CNPJ\t     TELEFONE\n");
    printf(" ============================================================================\n");

    while (fread(&pFornecedor, sizeof(Fornecedor), 1, arq1) > 0) {
        printf(" %06d %-20s %-15s %-11s \n",pFornecedor.codigo, pFornecedor.razaoSocial, pFornecedor.CNPJ, pFornecedor.telefone);
        printf(" ----------------------------------------------------------------------------\n");
    }

    // posiciona o ponteiro no inicio do arquivo
    fseek(arq1, 0, SEEK_SET);

    printf("\n\n Deseja gerar um relatorio ?\t 1 - SIM   2 - NAO\t DIGITE: ");
    scanf("%d", &num);
    while(num < 1 || num > 2){
        system ("cls");
        printf("\n\tOpcao Invalida!!!");
        printf("\n\n Deseja gerar um relatorio ?\t 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
    }

    // se quiser gerar o relatorio
    if(num == 1){

        // cabecalho do relatorio
        fprintf(arq2,"\n\nRelatorio de Fornecedores Cadastrados\n\n");
        fprintf(arq2,"============================================================================\n");
        fprintf(arq2,"Codigo \t Razao Social\t\t CNPJ\t Telefone\t Endereco\n");
        fprintf(arq2,"--------------------------------------------------------------------------------------\n");

        // enquanto nao chegou no final do arquivo
        while (fread(&pFornecedor, sizeof(Fornecedor), 1, arq1) > 0) {
            fprintf(arq2,"%06d %-30s %-15s %-11s %-30s \n", pFornecedor.codigo, pFornecedor.razaoSocial, pFornecedor.CNPJ, pFornecedor.telefone, pFornecedor.endereco);
            fprintf(arq2,"--------------------------------------------------------------------------------------\n");
        }

        fprintf(arq2,"============================================================================\n");
        system ("cls");
        printf("\n\n\tRelatorio gerado com sucesso!\n\n");

    } else if(num == 2){ // volta para tela inicial
        system ("cls");
        return;
    }

    //reseta as telas
    system("pause");
    system("cls");

    // fecha o BD
    fclose(arq1);
    fclose(arq2);

    return;
}

/**
  * FUNCAO          : 7 - ConsultarFornecedorCNPJ
  * AUTOR           : Anderson
  * DATA            : 05 JUL 2020
  * ALTERADO        : 06 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarFornecedorCNPJ(){

    FILE * arq;
    Fornecedor fornecedor;
    char CNPJ[15];
    char numeros[12]="0123456789";
    int achei, i=0, j=0, num=0, num2=0;

    do{// Laco para a condicao ir ao menos uma vez antes de verificar
        system("cls");
        achei = 0;
        if ((arq = fopen(arqFornecedor, "rb")) == NULL) { //Atribuicao/Abertura do arquivo e verificacao se ha conteudo
            printf("\n\tNao existe nenhum Fornecedor cadastrado!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            return;
        }

        printf("\n\n\tConsulta de Fornecedores por CNPJ\n\n");
        do{//Laco para executar a condicao ao menos uma vez antes de verificar (busca do CNPJ digitado pelo usuario)
            printf("\tCNPJ do Fornecedor: ");
            scanf(" %15[^\n]", CNPJ);
            rewind(arq);//Retorma inicio do arquivo

            printf(" ============================================================================\n");
            printf(" Codigo Razao Social \t\t       CNPJ            Telefone\n");
            printf(" ============================================================================\n");

            //La�o para leitura do bloco Fornecedor
            while(fread(&fornecedor, sizeof(Fornecedor), 1, arq) > 0){
                if(strncmp(CNPJ,fornecedor.CNPJ, strlen(CNPJ)) == 0){
                printf(" %06d %-30s %-15s %-11s \n", fornecedor.codigo, fornecedor.razaoSocial, fornecedor.CNPJ, fornecedor.telefone);
                printf(" ----------------------------------------------------------------------------\n");
                achei = 1;
              }
            }

            if (!achei){//Verifica se achou algum produto e imprime mensagem
              printf("\n\n\tNao existe Fornecedor cadastrado com esse CNPJ: %s\n\n",CNPJ);
              printf("\n\tDigite Novamente !\n\n");
            }
        } while(!achei);

        fseek(arq,0,SEEK_SET);//Volta ao inicio do arquivo
        fclose(arq);//Fecha arquivo

        // realiza uma nova consulta
        printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
        while(num < 1 || num > 2){
            system ("cls");
            printf("\n\n Opcao Invalida!!!");
            printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
            scanf("%d", &num);
        }
    } while(num == 1);
    system ("cls");
    return;
}

/**
  * FUNCAO          : 8 - ConsultarProdutoNome
  * AUTOR           : Anderson
  * DATA            : 03 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarFornecedorNome(){
    //Declaracoes de variaveis (Com TypeDef e abertura de File)
    FILE * arq;
    Fornecedor fornecedor;
    int num=0, num2=0, achei, i=0, j=0;
    char nome[50];

    do{ //Laco para executar a condicao ao menos uma vez antes de verificar
        system("cls");
        achei = 0;
        if ((arq = fopen(arqFornecedor, "rb")) == NULL) { //Atribuicao/Abertura do arquivo e verificacao se ha conteudo
            printf("\n\tNao existe nenhum fornecedor cadastrado!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            return;
        }

        printf("\n\n *** Consulta Fornecedor por Razao Social *** \n\n");
        do{ //Laco para executar a condicao ao menos uma vez antes de verificar (busca do nome digitado pelo usuario)
            printf(" Digite a Razao Social do Fornecedor desejado: ");
            scanf(" %50[^\n]", nome);
            printf("\n\n");
            rewind(arq);//Retorna inicio do arquivo

            printf(" ============================================================================\n");
            printf(" Codigo Razao Social \t\t       CNPJ            Telefone\n");
            printf(" ============================================================================\n");

            while(fread(&fornecedor, sizeof(Fornecedor), 1, arq) > 0) //Laco para leitura do bloco Fornecedor
            {   //Laco no comprimento do nome
                for(i=0;i<(strlen(nome));i++)
                {
                    nome[i]=toupper(nome[i]); //Atribui a variavel nome a letra maiuscula do nome digitado
                    for(j = 0; j<(strlen(fornecedor.razaoSocial)); j++) //Laco no comprimento do membro razao social
                    {
                        fornecedor.razaoSocial[j]=toupper(fornecedor.razaoSocial[j]); //Membro razao social recebe razao social em maiuusculo
                    }
                }
                if(strncmp(nome,fornecedor.razaoSocial, strlen(nome)) == 0){ //Se comprimento for igual, imprime
                    printf(" %06d %-30s %-15s %-11s \n", fornecedor.codigo, fornecedor.razaoSocial, fornecedor.CNPJ, fornecedor.telefone);
                    printf("--------------------------------------------------------------------------\n");
                    achei = 1;
                }
            }

            if (achei!=1){ //Verifica se achou algum fornecedor e imprime mensagem
              printf("\n\n\tNao existe fornecedor cadastrado com essa Razao Social: %s\n\n",nome);
              printf("\n\tDigite Novamente !\n\n");
            }
        } while(!achei);

        fseek(arq, 0, SEEK_SET); //Retoma inicio do arquivo
        fclose(arq); //fecha arquivo

        // realiza uma nova consulta
        printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
        while(num < 1 || num > 2){
            system ("cls");
            printf("\n\n Opcao Invalida!!!");
            printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
            scanf("%d", &num);
        }
    } while(num == 1);
    system("cls");
    return;
}

/**
  * FUNCAO          : 9 - ConsultarProdutoFornecedor
  * AUTOR           : Anderson
  * DATA            : 03 JUL 2020
  * ALTERADO        : 04 JUL 2020
  * DT ALTERACAO    : 07 JUL 2020
  * REVISADO POR    : Anderson
*/
void ConsultarProdutoFornecedor(){
    //Declaracoes de variaveis (Com TypeDef e abertura de File)
    FILE * arq;
    Produto pItem;
    int num=0, achei, i=0, j=0;
    char nome[50];

    do{ //Laco para executar a condicao ao menos uma vez antes de verificar
        system("cls");
        achei = 0;
        if ((arq = fopen(arqProduto, "rb")) == NULL) { //Atribuicao/Abertura do arquivo e verificacao se ha conteudo
            printf("\n\tDados nao encontrados!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            return;
        }

        printf("\n\n *** CONSULTA PRODUTO POR FORNECEDOR ***\n\n");
        do{ //Laco para executar a condicao ao menos uma vez antes de verificar (busca do nome digitado pelo usuario)
            printf("\n Digite o nome do Fornecedor desejado: ");
            scanf(" %50[^\n]", nome);
            printf("\n\n");
            rewind(arq);//Retorna inicio do arquivo

            printf(" ============================================================================\n");
            printf(" Codigo Produto \t\t       Valor      Qtde          Fornecedor\n");
            printf(" ============================================================================\n");

            while(fread(&pItem, sizeof(Produto), 1, arq) > 0) //Laco para leitura do bloco Fornecedor
            {   //Laco no comprimento do nome
                for(i=0;i<(strlen(nome));i++)
                {
                    nome[i]=toupper(nome[i]); //Atribui a variavel nome a letra maiuscula do nome digitado
                    for(j = 0; j<(strlen(pItem.pFornecedor.razaoSocial)); j++) //Laco no comprimento do membro razao social
                    {
                        pItem.pFornecedor.razaoSocial[j]=toupper(pItem.pFornecedor.razaoSocial[j]); //Membro razao social recebe razao social em maiusculo
                    }
                }
                if(strncmp(nome,pItem.pFornecedor.razaoSocial, strlen(nome)) == 0){ //Se comprimento for igual, imprime
                    printf(" %06d %-30s %-10d %-5.2f %15s \n", pItem.codigo, pItem.nome, pItem.qtde, pItem.preco, pItem.pFornecedor.razaoSocial);
                    printf("--------------------------------------------------------------------------\n");
                    achei = 1;
                }
            }

            if (achei!=1){ //Verifica se achou algum fornecedor e imprime mensagem
              printf("\n\n\tNao existe fornecedor cadastrado com essa Razao Social: %s\n\n",nome);
              printf("\n\tDigite Novamente !\n\n");
              achei = 1;
            }

        } while(!achei);

        fseek(arq, 0, SEEK_SET); //Retoma inicio do arquivo
        fclose(arq); //fecha arquivo

        // realiza uma nova consulta
        printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
        scanf("%d", &num);
        while(num < 1 || num > 2){
            system ("cls");
            printf("\n\n Opcao Invalida!!!");
            printf("\n\n Deseja realizar uma nova consulta? 1 - SIM   2 - NAO\t DIGITE: ");
            scanf("%d", &num);
        }

    } while(num == 1);
    system("cls");
    return;
}
