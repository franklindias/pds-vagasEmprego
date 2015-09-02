#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>


using namespace std;


struct Candidato
{
    char nome[15];
    char funcaoDesejada[10];
    char telefoneCandidato[10];

    char user[5];
    char pass[5];
};

struct Vaga
{
    char funcaoVaga[15];
    char cargaHoraria[10];
    char salario[5];
    int quantCanditados = 0;
    Candidato canditados[5];
};


struct Empresa
{
    char nome[15];
    char endereco[10];
    char telefone[10];
    char user[5];
    char pass[5];
    int quantVagas = 0;
    Vaga vagas[5];
};

bool deletar(int id, int entidade);

Empresa empresas[50];
Candidato candidatos[50];

int opcao, quantEmpresas = 0, quantCandidatos = 0, aux;

bool verificar = true, verificaAdmin = true;

string user;
string pass;

int main()
{
    //vector<Vaga> vagas;

    string userlocal = "admin";
    string passlocal = "admin";


    do{
    printf("%s", "-----------------------------\n");
    printf("%s", "---   QUAL SEU PERFIL?    ---\n");
    printf("%s", "-----------------------------\n");
    printf("%s", "-    #1  Administrador      -\n");
    printf("%s", "-    #2  Empresa            -\n");
    printf("%s", "-    #3  Candidato          -\n");
    printf("%s", "-    #0  Fechar Programa    -\n");
    printf("%s", "-----------------------------\n\n");


    printf("%s", "\nDigite uma opcao: ");

    scanf("%d", &opcao);

    switch (opcao){
       //listar vagas de emprego cadatradas
        case 1:
            do{

            printf("%s", "USUARIO: ");
            scanf("%s", &user);
            printf("%s", "SENHA: ");
            scanf("%s", &pass);

            if ((strcasecmp(user, userlocal) != 0) or (strcasecmp(pass, passlocal) != 0)){
                system("clear");
                printf("%s", "Senha Incorreta!\n");
                break;
            }

            system("clear");

            printf("%s", "------------------------------\n");
            printf("%s", "------  ADMINISTRADOR   ------\n");
            printf("%s", "------------------------------\n");
            printf("%s", "---    ESCOLHA UMA OPCAO   ---\n");
            printf("%s", "------------------------------\n");
            printf("%s", "-    #1  Cadastrar Empresa   -\n");
            printf("%s", "-    #2  Listar Empresas     -\n");
            printf("%s", "-    #3  Cadastrar Candidato -\n");
            printf("%s", "-    #4  Listar Candidatos   -\n");
            printf("%s", "-    #9  Menu Principal      -\n");
            printf("%s", "-    #0  Fechar Programa     -\n");
            printf("%s", "------------------------------\n\n");

            printf("%s", "\nDigite uma opcao: ");

            scanf("%d", &opcao);

            switch(opcao){

            case 1:

                system("clear");

                printf("%s","\n CADASTRAR NOVA EMPRESA ");
                printf("%s","\n ---------------------- ");

                printf("%s","\n Digite o Nome da Empresa \n");
                scanf("%s", &empresas[quantEmpresas].nome);

                printf("%s","\n Digite o Endereco \n");
                scanf("%s", &empresas[quantEmpresas].endereco);

                printf("%s","\n Digite o Telefone \n");
                scanf("%s", &empresas[quantEmpresas].telefone);

                printf("%s","\n Digite o Usuario \n");
                scanf("%s", &empresas[quantEmpresas].user);

                printf("%s","\n Digite a Senha \n");
                scanf("%s", &empresas[quantEmpresas].pass);

                system("clear");

                printf("%s","\n Empresa Cadastrada Com Sucesso!! \n\n");

                quantEmpresas++;
                break;
            case 2:

                system("clear");

                if (quantEmpresas > 0){

                    printf("%s", "\n  EMPRESAS CADASTRADAS  ");
                    printf("%s", "\n ---------------------- ");

                    printf("%s", "\nID \t|\tNOME\t|\tENDERECO\t|\tTELEFONE\n");

                    for (int i=0;i<quantEmpresas; i++){
                        printf("%d", i+1);
                        printf("%s", "\t|\t");
                        printf("%s", empresas[i].nome);
                        printf("%s", "\t|\t");
                        printf("%s", empresas[i].endereco);
                        printf("%s", "\t|\t");
                        printf("%s", empresas[i].telefone );
                        printf("%s", "\n");
                    }


                    printf("%s", "\nDigite um [ID] para Deletar ou Editar ou [0] Para sair:\n");
                    scanf("%d", &aux);

                    if (aux > 0){

                        printf("%s", "\nDeseja [1]Editar ou [2]Deletar essa Empresa?\n");
                        scanf("%d", &aux);

                        switch(aux){
                            case 1:
                                break;
                            case 2:

                                deletar(aux, 1);

                                break;
                            default: break;
                        }
                    }

                    break;
                }

                break;
            case 3:
                printf("%s", "\nCadastrar Candidato: ");
                break;
            case 4:
                printf("%s", "\nListar Candidatos: ");
                break;
            case 9:
                verificaAdmin = false;
                break;
            case 0:
                verificaAdmin = false;
                verificar = false;

            default: break;

            }


            }while(verificaAdmin);

            break;
        case 2:

            system("clear");

            printf("%s", "------------------------------\n");
            printf("%s", "------     EMPRESA      ------\n");
            printf("%s", "------------------------------\n");
            printf("%s", "---   ESCOLHA UMA OPCAO    ---\n");
            printf("%s", "------------------------------\n");
            printf("%s", "-    #1  Cadastrar Vaga      -\n");
            printf("%s", "-    #2  Listar Vagas        -\n");
            printf("%s", "-    #3  Deletar Vaga        -\n");
            printf("%s", "-    #9  Menu Principal      -\n");
            printf("%s", "-    #0  Fechar Programa     -\n");
            printf("%s", "------------------------------\n\n");

            printf("%s", "\nDigite uma opcao: ");

            scanf("%d", &opcao);


            break;

        case 3:

            system("clear");

            printf("%s", "------------------------------\n");
            printf("%s", "------     CANDIDATO    ------\n");
            printf("%s", "------------------------------\n");
            printf("%s", "---   ESCOLHA UMA OPCAO    ---\n");
            printf("%s", "------------------------------\n");
            printf("%s", "-    #1  Listar Vagas        -\n");
            printf("%s", "-    #2  Candelar Candidatura-\n");
            printf("%s", "-    #9  Menu Principal      -\n");
            printf("%s", "-    #0  Fechar Programa     -\n");
            printf("%s", "------------------------------\n\n");

            printf("%s", "\nDigite uma opcao: ");

            scanf("%d", &opcao);


            break;

         case 9:

            system("clear");
            break;

        case 0:

            verificar = false;

            break;
        default :
            system("clear");
             printf("%s", "\nOpcao Invalida.\n ");
            break;
        }

}while(verificar);



    return 0;
}

//codigo de entidades
//1 - empresa
//2 - candidato
//3 - vaga

bool deletar(int id, int entidade){

    int posicaoRegistro = id -1;

switch (entidade){

    case 1:
      for (int i=posicaoRegistro; i<quantEmpresas;i++){
            empresas[i] = empresas[i+1];
      }
      quantEmpresas--;
      break;
}

}

