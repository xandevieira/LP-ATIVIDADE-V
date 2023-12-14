// Dupla : Joabes Alves e Alexandre Vitoriano

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct SuaConta {
    float saldo;
    char nome[250];
    float salario;
    float rendaMensal;
    float divida;
    float investimento;
};

void cabecalho()
{
    printf("=====================================\n");
    printf("\tBem-vindo ao Senai-Bank\n");
    printf("\tSeu Banco\n");
    printf("=====================================\n\n");
}

void cabecalhoBoasVindas(struct SuaConta *conta) {
    printf("Olá, %s\n", conta->nome);
    printf("Conta\t>\nR$ %.2f\n", conta->saldo);
    printf("Dívida\t>\nR$ -%.2f\n", conta->divida);
    printf ("Investimento Rendendo 2%%a.m\t>\nR$ %.2f\n", conta->investimento);
    printf("\nEscolha a opção desejada:\n");
    printf("1|     TRANSFERIR POR PIX \n");
    printf("2|     DEPOSITAR\n");
    printf("3|     EMPRÉSTIMO\n");
    printf("4|     INVESTIMENTO \n");
    printf("5|     SAIR\n");
}


void transferirPorPix (struct SuaConta *conta, float valor) {
    if (valor <= conta->saldo) { 
    conta->saldo -= valor;
    printf ("Transferência realizada com sucesso!\n\n");
    printf ("Saldo atual: %.2f\n", conta->saldo);
    }
    else {
        printf ("\nSaldo Insuficiente.\n\n");
    }
    printf("\n\nVoltando a página inicial...");
    sleep(3);
    system("cls || clear");  
}

void depositar (struct SuaConta *conta, float valor) {
    conta->saldo += valor;
    printf ("Deposito realizado com sucesso!!\n\n");
    printf ("Saldo atual: %.2f\n", conta->saldo);
    printf("\n\nVoltando a página inicial...");
    sleep(3);
    system("cls || clear");  
}

void pegarEmprestimo(struct SuaConta *conta) {
    float limiteEmprestimo = 5 * conta->salario;
    float valorEmprestimo;

    printf("Digite o valor desejado do empréstimo (até R$ %.2f): ", limiteEmprestimo);
    scanf("%f", &valorEmprestimo);

    if (valorEmprestimo <= 0 || valorEmprestimo > limiteEmprestimo) {
        printf("Valor de empréstimo inválido. Certifique-se de que está dentro do limite permitido.\n");
    } else {
        conta->divida += valorEmprestimo;
        conta->saldo += valorEmprestimo;
        printf("Empréstimo de R$ %.2f realizado com sucesso!\n", valorEmprestimo);
        printf("Saldo atual: R$ %.2f\n", conta->saldo);
    }
    
    printf("\n\nVoltando a página inicial...");
    sleep(5);
    system("cls || clear");    
}

void investir(struct SuaConta *conta) {
    float valorInvestimento;

    printf("Digite o valor que deseja investir: ");
    scanf("%f", &valorInvestimento);

    if (valorInvestimento <= 0 || valorInvestimento > conta->saldo) {
        printf("Valor de investimento inválido. Certifique-se de que está dentro do limite permitido.\n");
    } else {
        conta->saldo -= valorInvestimento;
        conta->investimento += valorInvestimento;
        printf("Investimento de R$ %.2f realizado com sucesso!\n", valorInvestimento);
        printf("Saldo atual: R$ %.2f\n", conta->saldo);
    }
    printf("\n\nVoltando a página inicial...");
    sleep(5);
    system("cls || clear");  
}


void simularRendimento(struct SuaConta *conta) {
    float rendimentoMensal = conta->investimento * 0.02; 
    conta->investimento += rendimentoMensal;
    printf("Investimento rendendo: R$ %.2f\n", rendimentoMensal);
    printf("Novo valor do investimento: R$ %.2f\n", conta->investimento);
    printf("\n\nVoltando a página inicial...");
    sleep(5);
    system("cls || clear");  
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
        cabecalhoBoasVindas(&conta);
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
            pegarEmprestimo(&conta);
            break;
        case 4:
            investir(&conta);
            simularRendimento(&conta);
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
