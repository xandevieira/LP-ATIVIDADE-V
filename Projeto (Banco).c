// Dupla : Joabes Alves e Alexandre Vitoriano

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void cabecalho()
{
    printf("=====================================\n");
    printf("\tBem-vindo ao Senai-Bank\n");
    printf("\tSeu Banco\n");
    printf("=====================================\n\n");
}

void cabecalhoBoasVindas() {
        printf("1|     TANSFERIR POR PIX \n");
        printf("2|     DEPOSITAR\n");
        printf("3|     EMPRÉSTIMO\n");
        printf("4|     INVESTIMENTO \n");
        printf("5|     SAIR\n");
        printf("\nEscolha a opção desejada: ");    
}

struct SuaConta {
    float saldo;
    char nome[250];
    float salario;
    float rendaMensal;
};

void transferirPorPix (struct SuaConta *conta, float valor) {
    if (valor <= conta->saldo) { 
    conta->saldo -= valor;
    printf ("Transferência realizada com sucesso!\n\n");
    printf ("Saldo atual: %.2f\n", conta->saldo);
    }
    else {
        printf ("\nSaldo Insuficiente.\n\n");
    }

}

void depositar (struct SuaConta *conta, float valor) {
    conta->saldo += valor;
    printf ("Deposito realizado com sucesso!!\n\n");
    printf ("Saldo atual: %.2f\n", conta->saldo);
}


int main () {
    setlocale(LC_ALL, "portuguese");
    struct SuaConta conta;
    int escolha;
    float valor;
    char chavePix[250];

    cabecalho();

    printf ("Digite seu Nome: \n");
    gets (conta.nome);

    fflush(stdin);

    printf ("Digite seu Saldo: \n");
    scanf ("%f", &conta.saldo);

    fflush(stdin);

    printf ("Renda mensal: \n");
    scanf ("%f", &conta.salario);

    system("CLS || CLEAR");

    do
    {
        cabecalho();
        printf("Olá,%s\n\n", conta.nome);
        printf ("Conta\t>\nR$ %.2f\n\n", conta.saldo);
        cabecalhoBoasVindas();
        scanf("%d", &escolha);

        system("CLS || CLEAR");

        switch (escolha)
        {
        case 1:
            printf("Valor do Pix: ");
            scanf("%f", &valor);
            fflush(stdin);
            printf ("Digite a Chave Pix: ");
            gets(chavePix);
            transferirPorPix(&conta, valor);
            break;

        case 2:
            printf("Valor do Deposito: ");
            scanf("%f", &valor);
            depositar(&conta, valor);
            break;

        case 3:
            //imprimirSaldo(&conta);
            break;
        case 4:
            //VerificarSePodeFazerEmprestimo(&conta);
            break;

        case 5:
            printf("Programa encerrado.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (escolha != 5);

    return 0;

}
