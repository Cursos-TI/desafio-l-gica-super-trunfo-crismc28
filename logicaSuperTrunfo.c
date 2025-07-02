#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para calcular densidade demográfica
void calcularDensidade(Carta *c) {
    c->densidadeDemografica = c->populacao / c->area;
}

// Função para exibir as opções de atributos
void exibirMenuAtributos(int excluirOpcao) {
    printf("Escolha um atributo:\n");
    if (excluirOpcao != 1) printf("1 - População\n");
    if (excluirOpcao != 2) printf("2 - Área\n");
    if (excluirOpcao != 3) printf("3 - PIB\n");
    if (excluirOpcao != 4) printf("4 - Pontos Turísticos\n");
    if (excluirOpcao != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para obter o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return -1; // erro
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função que decide qual carta venceu no atributo
int compararAtributo(float valor1, float valor2, int atributo) {
    // Para densidade demográfica, menor vence
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    } else {
        return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 211000000, 8515767.0, 1847.0, 150};
    Carta carta2 = {"Argentina", 45376763, 2780400.0, 600.0, 90};

    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO FINAL ===\n\n");

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Atributo inválido! Encerrando o programa.\n");
        return 1;
    }

    // Escolha do segundo atributo (menu dinâmico)
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    exibirMenuAtributos(atributo1);
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Atributo inválido ou repetido! Encerrando o programa.\n");
        return 1;
    }

    // Obtenção dos valores
    float valor1_attr1 = obterValorAtributo(carta1, atributo1);
    float valor2_attr1 = obterValorAtributo(carta2, atributo1);
    float valor1_attr2 = obterValorAtributo(carta1, atributo2);
    float valor2_attr2 = obterValorAtributo(carta2, atributo2);

    // Soma dos valores (considerando regra especial para densidade)
    float soma1 = (atributo1 == 5 ? -valor1_attr1 : valor1_attr1) +
                  (atributo2 == 5 ? -valor1_attr2 : valor1_attr2);

    float soma2 = (atributo1 == 5 ? -valor2_attr1 : valor2_attr1) +
                  (atributo2 == 5 ? -valor2_attr2 : valor2_attr2);

    printf("\n=== COMPARAÇÃO FINAL ===\n\n");

    printf("Carta 1 - %s\n", carta1.nomePais);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor1_attr2);
    printf("  Soma dos atributos: %.2f\n\n", soma1);

    printf("Carta 2 - %s\n", carta2.nomePais);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor2_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_attr2);
    printf("  Soma dos atributos: %.2f\n\n", soma2);

    // Decisão final
    if (soma1 > soma2) {
        printf("Resultado: %s venceu!\n", carta1.nomePais);
    } else if (soma2 > soma1) {
        printf("Resultado: %s venceu!\n", carta2.nomePais);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
