#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de paises.
// O objetivo é utilizar estruturas de decisão, repetição e lógica complexa para criar o jogo.

// Declaração de Funções (Protótipos) para o Nível Mestre
void compararEAtribuirPontos(int atributo, long popA, long popB, double areaA, double areaB, double pibA, double pibB, int ptsA, int ptsB, int* pontosA, int* pontosB);
const char* getNomeAtributo(int atributo);

int main() {
    // Definição das variáveis para armazenar as propriedades das paises
    // Sugestão: Crie variáveis separadas para cada atributo de cada carta.
    char estadoA[3], codigoA[5], nomepaisA[50];
    long int populacaoA;
    double areaA, pibA;
    int pontosTuristicosA;

    char estadoB[3], codigoB[5], nomepaisB[50];
    long int populacaoB;
    double areaB, pibB;
    int pontosTuristicosB;

    printf("======================================\n");
    printf("  BEM-VINDO AO SUPER TRUNFO - paises \n");
    printf("======================================\n\n");

    // Cadastro das Cartas:
    // Sugestão: Implemente a lógica para solicitar ao usuário que insira os dados das paises
    // utilizando a função scanf para capturar as entradas.
    printf("--- CADASTRO DA CARTA 1 ---\n");
    printf("Digite a sigla do Estado (ex: SP): ");
    scanf("%s", estadoA);
    printf("Digite o codigo da carta (ex: A1): ");
    scanf("%s", codigoA);
    printf("Digite o nome da pais: ");
    scanf(" %[^\n]", nomepaisA);
    printf("Digite o numero de habitantes: ");
    scanf("%ld", &populacaoA);
    printf("Digite a area em km2: ");
    scanf("%lf", &areaA);
    printf("Digite o PIB em bilhoes de R$: ");
    scanf("%lf", &pibA);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicosA);
    printf("\n");

    printf("--- CADASTRO DA CARTA 2 ---\n");
    printf("Digite a sigla do Estado (ex: RJ): ");
    scanf("%s", estadoB);
    printf("Digite o codigo da carta (ex: B2): ");
    scanf("%s", codigoB);
    printf("Digite o nome da pais: ");
    scanf(" %[^\n]", nomepaisB);
    printf("Digite o numero de habitantes: ");
    scanf("%ld", &populacaoB);
    printf("Digite a area em km2: ");
    scanf("%lf", &areaB);
    printf("Digite o PIB em bilhoes de R$: ");
    scanf("%lf", &pibB);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicosB);
    printf("\n");

    system("cls || clear");

    // Exibição dos Resultados do Cadastro:
    // Sugestão: Mostre os dados de ambas as cartas de forma organizada para o usuário.
    printf("======================================\n");
    printf("           CARTAS NA MESA             \n");
    printf("======================================\n");
    printf("CARTA 1 (%s): %s-%s\n", codigoA, nomepaisA, estadoA);
    printf(" > Populacao: %ld habitantes\n\n", populacaoA);
    printf("CARTA 2 (%s): %s-%s\n", codigoB, nomepaisB, estadoB);
    printf(" > Populacao: %ld habitantes\n\n", populacaoB);

    // Nível Novato - Comparação de Cartas:
    // Sugestão: Desenvolva a lógica de comparação entre duas cartas utilizando if-else para um atributo fixo, como o PIB.
    printf("--------------------------------------\n");
    printf("          NIVEL NOVATO\n");
    printf("--------------------------------------\n");
    if (pibA > pibB) {
        printf("RESULTADO (PIB): A carta %s (%s) venceu!\n", codigoA, nomepaisA);
    } else if (pibB > pibA) {
        printf("RESULTADO (PIB): A carta %s (%s) venceu!\n", codigoB, nomepaisB);
    } else {
        printf("RESULTADO (PIB): Houve um empate!\n");
    }
    printf("\n");


    // Nível Aventureiro e Mestre - Menu Interativo e Lógica Complexa
    // Sugestão: Crie um loop para que o usuário possa fazer várias comparações sem reiniciar o programa (Menu Dinâmico).
    int escolha;
    char continuar;
    do {
        printf("======================================\n");
        printf("      Escolha o atributo para comparar\n");
        printf("======================================\n");
        printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Populacional\n");
        printf("6. [MESTRE] Comparar DOIS atributos\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        // Menu Interativo:
        // Sugestão: Utilize a estrutura switch para permitir que o usuário escolha qual atributo comparar.
        switch (escolha) {
            case 1:
                // Comparação Aninhada:
                // Sugestão: Em caso de empate, utilize um if-else aninhado para decidir com base em um segundo atributo.
                if (populacaoA == populacaoB) {
                    printf("EMPATE na Populacao! Desempatando pelo PIB...\n");
                    if (pibA > pibB) printf("VENCEDOR (desempate): %s\n", nomepaisA);
                    else printf("VENCEDOR (desempate): %s\n", nomepaisB);
                } else if (populacaoA > populacaoB) {
                    printf("VENCEDOR (Populacao): %s\n", nomepaisA);
                } else {
                    printf("VENCEDOR (Populacao): %s\n", nomepaisB);
                }
                break;
            case 2:
                // Lógica Avançada com Operador Ternário:
                // Sugestão: Utilize o operador ternário para decidir e exibir o vencedor de forma concisa.
                printf("VENCEDOR (Area): %s\n", (areaA > areaB) ? nomepaisA : nomepaisB);
                break;
            case 3:
                if (pibA > pibB) printf("VENCEDOR (PIB): %s\n", nomepaisA);
                else if (pibB > pibA) printf("VENCEDOR (PIB): %s\n", nomepaisB);
                else printf("RESULTADO: EMPATE no PIB!\n");
                break;
            case 4:
                if (pontosTuristicosA > pontosTuristicosB) printf("VENCEDOR (Pontos Turisticos): %s\n", nomepaisA);
                else if (pontosTuristicosB > pontosTuristicosA) printf("VENCEDOR (Pontos Turisticos): %s\n", nomepaisB);
                else printf("RESULTADO: EMPATE nos Pontos Turisticos!\n");
                break;
            case 5:
                // Lógica de Comparação Invertida:
                // Sugestão: Lembre-se que para a Densidade, o menor valor é o vencedor.
                if (areaA > 0 && areaB > 0) {
                    double densidadeA = populacaoA / areaA;
                    double densidadeB = populacaoB / areaB;
                    if (densidadeA < densidadeB) printf("VENCEDOR (Densidade): %s (menor densidade)\n", nomepaisA);
                    else if (densidadeB < densidadeA) printf("VENCEDOR (Densidade): %s (menor densidade)\n", nomepaisB);
                    else printf("RESULTADO: EMPATE na Densidade!\n");
                } else {
                    printf("Erro: Area de uma das paises e zero, nao e possivel calcular a densidade.\n");
                }
                break;
            case 6:
                // Nível Mestre - Comparação de Dois Atributos:
                // Sugestão: Peça ao usuário para escolher dois atributos e use um sistema de pontos para determinar o vencedor geral.
                { // Bloco para declaração de variáveis locais ao case
                    int atr1, atr2, pontosA = 0, pontosB = 0;
                    printf("Escolha o primeiro atributo (1-4): ");
                    scanf("%d", &atr1);
                    printf("Escolha o segundo atributo (1-4): ");
                    scanf("%d", &atr2);

                    compararEAtribuirPontos(atr1, populacaoA, populacaoB, areaA, areaB, pibA, pibB, pontosTuristicosA, pontosTuristicosB, &pontosA, &pontosB);
                    compararEAtribuirPontos(atr2, populacaoA, populacaoB, areaA, areaB, pibA, pibB, pontosTuristicosA, pontosTuristicosB, &pontosA, &pontosB);

                    printf("\nComparando '%s' e '%s'...\n", getNomeAtributo(atr1), getNomeAtributo(atr2));
                    printf("Placar: %s (%d) x (%d) %s\n", nomepaisA, pontosA, pontosB, nomepaisB);

                    if (pontosA > pontosB) printf("VENCEDOR GERAL: %s\n", nomepaisA);
                    else if (pontosB > pontosA) printf("VENCEDOR GERAL: %s\n", nomepaisB);
                    else printf("RESULTADO GERAL: EMPATE!\n");
                }
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        printf("\nDeseja comparar novamente? (S/N): ");
        scanf(" %c", &continuar);

    } while (toupper(continuar) == 'S');

    printf("\nObrigado por jogar!\n");

    return 0;
}


// Funções Auxiliares (Nível Mestre)
// Sugestão: Crie funções para organizar lógicas complexas e repetitivas.
const char* getNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        default: return "Desconhecido";
    }
}

void compararEAtribuirPontos(int atributo, long popA, long popB, double areaA, double areaB, double pibA, double pibB, int ptsA, int ptsB, int* pontosA, int* pontosB) {
    switch (atributo) {
        case 1: if (popA > popB) (*pontosA)++; else if (popB > popA) (*pontosB)++; break;
        case 2: if (areaA > areaB) (*pontosA)++; else if (areaB > areaA) (*pontosB)++; break;
        case 3: if (pibA > pibB) (*pontosA)++; else if (pibB > pibA) (*pontosB)++; break;
        case 4: if (ptsA > ptsB) (*pontosA)++; else if (ptsB > ptsA) (*pontosB)++; break;
    }
}