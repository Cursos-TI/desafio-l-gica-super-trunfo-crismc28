#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];               // Ex: "SP"
    char codigoCarta[10];        // Código da carta
    char nomeCidade[50];         // Nome da cidade
    int populacao;               // População da cidade
    float area;                  // Área da cidade em km²
    float pib;                   // PIB da cidade
    int pontosTuristicos;        // Número de pontos turísticos

    float densidadePopulacional; // Calculado: população / área
    float pibPerCapita;          // Calculado: pib / população
} Carta;

// Função para calcular os atributos derivados de uma carta
void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para exibir os dados principais de uma carta
void exibirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("Pontos Turísticos: %d\n\n", c.pontosTuristicos);
}

int main() {
    // Cadastro das duas cartas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 750.5, 80};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6710000, 1182.3, 380.0, 60};

    // Cálculo dos indicadores para as duas cartas
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibir os dados das cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);
    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // ==============================================
    // Escolha do atributo para comparação:
    // Altere apenas UMA destas comparações para testar:
    // 1 = População, 2 = Área, 3 = PIB, 4 = Densidade, 5 = PIB per capita
    int atributoEscolhido = 5;
    // ==============================================

    printf("\n=== Comparação de Cartas ===\n");

    if (atributoEscolhido == 1) {
        printf("Atributo: População\n");
        printf("Carta 1 - %s: %d\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 - %s: %d\n", carta2.nomeCidade, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 2) {
        printf("Atributo: Área\n");
        printf("Carta 1 - %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("Carta 2 - %s: %.2f km²\n", carta2.nomeCidade, carta2.area);

        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 3) {
        printf("Atributo: PIB\n");
        printf("Carta 1 - %s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
        printf("Carta 2 - %s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);

        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 4) {
        printf("Atributo: Densidade Populacional (menor vence)\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
        printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);

        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 5) {
        printf("Atributo: PIB per capita\n");
        printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
        printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);

        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Atributo inválido para comparação.\n");
    }

    return 0;
}
