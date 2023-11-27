#include <stdio.h>

// Função para ordenar os dígitos de um número em ordem crescente
int ascendingOrder(int num) {
    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    // Ordenar os dígitos em ordem crescente
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] > digits[j]) {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}

// Função para ordenar os dígitos de um número em ordem decrescente
int descendingOrder(int num) {
    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    // Ordenar os dígitos em ordem decrescente
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] < digits[j]) {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}

int main() {
    int num, steps = 0;

    printf("Digite um número de 4 dígitos: ");
    scanf("%d", &num);

    if (num < 1000 || num >= 10000) {
        printf("O número deve ter exatamente 4 dígitos.\n");
        return 1;
    }

    printf("Número inicial: %04d\n", num);

    while (num != 6174) {
        int ascending = ascendingOrder(num);
        int descending = descendingOrder(num);
        num = descending - ascending;
        steps++;
        printf("Passo %d: %04d - %04d = %04d\n", steps, descending, ascending, num);
    }

    printf("Atingiu a constante de Kaprekar 6174 em %d passos.\n", steps);

    return 0;
}

