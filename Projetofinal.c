#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura veículo
typedef struct{
    int ano;
    char proprietario[10], combustivel[10], modelo[10], cor[10], chassi[30], placa[8];
    struct Veiculo* proximo;
}Veiculo;

// Estrutura da lista de veículos
typedef struct{
    Veiculo *veiculos;
    int tamanho;
}ListaVeiculos;

// Iniciar lista de veículos
void inicializarListaVeiculos(ListaVeiculos *listaVeiculos){
    listaVeiculos->veiculos = NULL;
    listaVeiculos->tamanho = 0;
}

// Adicionar novo veiculo
void adicionarVeiculo(ListaVeiculos *listaVeiculos){
    Veiculo novoVeiculo;

    printf("Nome do proprietario:\n");
    scanf("%s", novoVeiculo.proprietario);

    printf("Qual o tipo de combustivel (alcool/diesel/gasolina):\n");
    scanf("%s", novoVeiculo.combustivel);

    printf("Modelo do veiculo:\n");
    scanf("%s", novoVeiculo.modelo);

    printf("Cor do veiculo:\n");
    scanf("%s", novoVeiculo.cor);

    printf("Numero do chassi:\n");
    scanf("%s", novoVeiculo.chassi);

    printf("Ano do veiculo:\n");
    scanf("%d", &novoVeiculo.ano);

    printf("Placa do veiculo:\n");
    scanf("%s", novoVeiculo.placa);

    listaVeiculos->tamanho++;
    listaVeiculos->veiculos = realloc(listaVeiculos->veiculos, listaVeiculos->tamanho * sizeof(Veiculo));
    listaVeiculos->veiculos[listaVeiculos->tamanho - 1] = novoVeiculo;

    printf("Veiculo cadastrado com sucesso!\n");
}

// Listar proprietários de carros do ano de 2010 ou posterior e movidos a diesel
void ProprietariosDiesel2010(ListaVeiculos *listaVeiculos){
    printf("Proprietarios de carros do ano de 2010 ou posterior e movidos a diesel:\n");
    for(int i = 0; i < listaVeiculos->tamanho; i++){
        if(listaVeiculos->veiculos[i].ano >= 2010 && strcmp(listaVeiculos->veiculos[i].combustivel, "diesel") == 0){
            printf("%s\n", listaVeiculos->veiculos[i].proprietario);
        }
    }
}

// Listar placas que começam com a letra J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietários
void PlacasJ(ListaVeiculos *listaVeiculos){
    printf("Placas que comecam com a letra J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietarios:\n");
    for(int i = 0; i < listaVeiculos->tamanho; i++) {
        if(listaVeiculos->veiculos[i].placa[0] == 'J' &&
            (listaVeiculos->veiculos[i].placa[7] == '0' || listaVeiculos->veiculos[i].placa[7] == '2' ||
            listaVeiculos->veiculos[i].placa[7] == '4' || listaVeiculos->veiculos[i].placa[7] == '7')){
            printf("Placa: %s, Proprietario: %s\n", listaVeiculos->veiculos[i].placa, listaVeiculos->veiculos[i].proprietario);
        }
    }
}

// Listar modelo e cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par
void ModeloCorVogalSomaPar(ListaVeiculos *listaVeiculos){
    printf("Modelo e cor dos veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par:\n");
    for(int i = 0; i < listaVeiculos->tamanho; i++) {
        char vogais[] = {'A', 'E', 'I', 'O', 'U','a', 'e', 'i', 'o', 'u'};
        if(strchr(vogais, listaVeiculos->veiculos[i].placa[1]) != NULL){
            int soma = 0;
            for(int j = 0; j < 7; j++){
                if/*(isdigit)*/(listaVeiculos->veiculos[i].placa[j]){
                    soma += listaVeiculos->veiculos[i].placa[j] - '0';
                }
            }
            if (soma % 2 == 0){
                printf("Modelo: %s, Cor: %s\n", listaVeiculos->veiculos[i].modelo, listaVeiculos->veiculos[i].cor);
            }
        }
    }
}

// Trocar o proprietario com base no numero do chassi apenas para carros com placas que nao possuam nenhum digito igual a zero
void trocarProprietarioSemZero(ListaVeiculos *listaVeiculos, char chassi[30], char novoProprietario[10]){
    for(int i = 0; i < listaVeiculos->tamanho; i++){
        if(strcmp(listaVeiculos->veiculos[i].chassi, chassi) == 0 &&
            strpbrk(listaVeiculos->veiculos[i].placa, "0") == NULL){
            strcpy(listaVeiculos->veiculos[i].proprietario, novoProprietario);
            printf("Proprietario atualizado com sucesso!\n");
            return;
        }
    }
    printf("Veiculo nao encontrado ou placa contem digito zero.\n");
}

// Liberar a memoria alocada para a lista de veículos
void liberarListaVeiculos(ListaVeiculos *listaVeiculos){
    free(listaVeiculos->veiculos);
    listaVeiculos->tamanho = 0;
}

int main(){
    ListaVeiculos listaVeiculos;
    inicializarListaVeiculos(&listaVeiculos);

    int opcao;

    do{
        printf("\nMenu:\n");
        printf("1. Adicionar Veiculo.\n");
        printf("2. Lista de Proprietarios de Carros do Ano de 2010 ou Posterior e Movidos a Diesel.\n");
        printf("3. Lista de Placas que Comecam com a Letra J e Terminam com 0, 2, 4 ou 7 e Seus Respectivos Proprietarios.\n");
        printf("4. Listar Modelo e Cor dos Veiculos cujas Placas Possuem Como Segunda Letra uma Vogal e cuja Soma dos Valores Numericos Fornece um Numero Par.\n");
        printf("5. Trocar Proprietario com Fornecimento do Numero do Chassi para Carros com Placas que Nao Possuam Nenhum Digito Igual a Zero.\n");
        printf("0. Sair.\n");

        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionarVeiculo(&listaVeiculos);
                break;
            case 2:
                ProprietariosDiesel2010(&listaVeiculos);
                break;
            case 3:
                PlacasJ(&listaVeiculos);
                break;
            case 4:
                ModeloCorVogalSomaPar(&listaVeiculos);
                break;
            case 5: 
                {
                char chassiTroca[30], novoProprietario[10];
                printf("Informe o numero do chassi:\n");
                scanf("%s", chassiTroca);
                printf("Informe o novo proprietario:\n");
                scanf("%s", novoProprietario);
                trocarProprietarioSemZero(&listaVeiculos, chassiTroca, novoProprietario);
                break;
            }
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }while(opcao != 0);

    liberarListaVeiculos(&listaVeiculos);
    return 0;
}
