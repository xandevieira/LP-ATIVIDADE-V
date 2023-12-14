#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ContaBancaria
{
    int numeroDaConta;
    char nomeDoTitular[200];
    float saldo;
    float salario;
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Depósito realizado com sucesso! Novo saldo: %.2f\n", conta->saldo);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("\nSaque realizado com sucesso! \nNovo saldo: %.2f\n", conta->saldo);
    }
    else
    {
        printf("\nSaldo insuficiente. Operação não realizada.\n");
    }
}

void imprimirSaldo(struct ContaBancaria *conta)
{
    printf("Saldo atual da conta: %.2f\n", conta->saldo);
}

void VerificarSePodeFazerEmprestimo(struct ContaBancaria *renda, float valor)
{
    if (renda->salario >= 3500)
    {
        printf("Empréstimo de R$ 10.000,00 aceito\n\n", renda->salario);
    }
    else
    {
        printf("Empréstimo negado!\n\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct ContaBancaria conta;
    int opcao;
    float valor;

    printf("Nome do titular da conta:");
    gets(conta.nomeDoTitular);
    
    fflush(stdin);

    printf("\nNúmero da conta: ");
    scanf("%d", &conta.numeroDaConta);

    fflush(stdin);

    printf("\nRenda mensal: ");
    scanf("%f", &conta.salario);

    fflush(stdin);

    printf("\nSaldo atual da conta: ");
    scanf("%f", &conta.saldo);

    system("CLS || CLEAR");

    do
    {
        printf("    Operações Bancárias \n");
        printf("1|     DEPOSITAR            |\n");
        printf("2|     SACAR                |\n");
        printf("3|     IMPRIMIR SALDO       |\n");
        printf("4|     EMPRÉSTIMO           |\n");
        printf("5|     SAIR                 |\n");
        printf("\nEscolha a opção desejada: ");
        scanf("%d", &opcao);

        system("CLS || CLEAR");

        switch (opcao)
        {
        case 1:
            printf("Valor do depósito: ");
            scanf("%f", &valor);
            depositar(&conta, valor);
            break;

        case 2:
            printf("Valor do saque: ");
            scanf("%f", &valor);
            sacar(&conta, valor);
            break;

        case 3:
            imprimirSaldo(&conta);
            break;
        case 4:
            printf ("Digite o valor do Empréstimo: ");
            scanf ("%f", &valor);
            VerificarSePodeFazerEmprestimo(&conta, valor);
            break;

        case 5:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (opcao != 5);

    return 0;
}
