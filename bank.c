#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include <windows.h>
#define TAM 200

struct fila
{
    int f;
    int r;
    int conta[TAM];
};

typedef struct fila Fila;

void enqueue(Fila *q, int x);
void dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);

int main()
{
    system("color 3f");
    setlocale(LC_ALL,"");
    Fila caixa, caixapref, guiche, guichepref;
    caixa.f = caixa.r = -1;
    caixapref.f = caixapref.r = -1;
    guiche.f = guiche.r = -1;
    guichepref.f = guichepref.r = -1;
    int w = 0;
    int opc1,opc2,opc3,opc4,opc5,contaCr,idadeCr,atendimentoCr,caixa1=0,caixapref1=0,guiche1=0,guichepref1=0,nada;

    while(w!=1)
    {
        opc1 = 9;
        while(opc1 < 1 || opc1 > 3)
        {
            printf(" ---------------------------------------------------\n");
            printf(" |                  Quem é você ?                  |\n");
            printf(" |                                                 |\n");
            printf(" |                  (pressione)                    |\n");
            printf(" |                                                 |\n");
            printf(" |     1 - Funcionário (Atendimento ao caixa)      |\n");
            printf(" |                                                 |\n");
            printf(" |     2 - Funcionário (Atendimento no guichê)     |\n");
            printf(" |                                                 |\n");
            printf(" |               3 - Correntista                   |\n");
            printf(" |                                                 |\n");
            printf(" ---------------------------------------------------\n");
            scanf("%i",&opc1);
            system("cls");
        }




        if(opc1 == 1)
        {
            opc2 = 9;
            while(opc2 < 1 || opc2 > 4)
            {
                printf(" ---------------------------------------------------\n");
                printf(" |                 O que deseja ?                  |\n");
                printf(" |                                                 |\n");
                printf(" |                  (pressione)                    |\n");
                printf(" |                                                 |\n");
                printf(" |                1 - Chamar ficha                 |\n");
                printf(" |                                                 |\n");
                printf(" |               2 - Gerar relatório               |\n");
                printf(" |                                                 |\n");
                printf(" |              3 - Visualizar filas               |\n");
                printf(" |                                                 |\n");
                printf(" |                   4 -  Sair                     |\n");
                printf(" |                                                 |\n");
                printf(" ---------------------------------------------------\n");
                scanf("%i",&opc2);
                system("cls");
            }
            if(opc2==1)
            {
                if(isEmpty(caixapref)==0)
                {
                    Beep(330, 150);
                    Beep(264, 150);
                    Beep(330, 150);
                    printf(" ---------------------------------------------------\n");
                    printf("   Atendimento prioritário ao caixa: Conta %i       \n",caixapref.conta[caixapref.f]);
                    printf(" ---------------------------------------------------\n");
                    Sleep(5000);
                    system("cls");
                    dequeue(&caixapref);
                    caixapref1++;
                }
                else
                {
                    if(isEmpty(caixa)==0)
                    {
                        Beep(330, 150);
                        Beep(264, 150);
                        Beep(330, 150);
                        printf(" ---------------------------------------------------\n");
                        printf("           Atendimento ao caixa: Conta %i           \n",caixa.conta[caixa.f]);
                        printf(" ---------------------------------------------------\n");
                        Sleep(5000);
                        system("cls");
                        dequeue(&caixa);
                        caixa1++;
                    }
                    else
                    {
                        printf("As filas estão vazias !!!");
                        Sleep(5000);
                        system("cls");
                    }
                }

            }
            else if(opc2==2)
            {
                printf(" ---------------------------------------------------\n");
                printf("         Quantidade de atendimentos realizados      \n");
                printf("                                                    \n");
                printf("        Atendimentos ao caixa(Prioritário): %i      \n",caixapref1);
                printf("                                                    \n");
                printf("        Atendimentos no guichê(Prioritário): %i     \n",guichepref1);
                printf("                                                    \n");
                printf("       Atendimentos ao caixa(Convencional): %i      \n",caixa1);
                printf("                                                    \n");
                printf("       Atendimentos no guichê(Convencional): %i     \n",guiche1);
                printf("                                                    \n");
                printf(" ---------------------------------------------------\n");
                Sleep(5000);
                system("cls");
            }
            else if(opc2==3)
            {
                printf(" ---------------------------------------------------\n");
                printf("       Fila de atendimento prioritário ao caixa     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(caixapref);
                printf(" ---------------------------------------------------\n");
                printf("       Fila de atendimento convencional ao caixa     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(caixa);
                printf(" ---------------------------------------------------\n");
                printf("      Fila de atendimento prioritário ao guichê     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(guichepref);
                printf(" ---------------------------------------------------\n");
                printf("      Fila de atendimento prioritário ao guichê     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(guiche);
                printf(" ---------------------------------------------------\n");
                printf("pressione qualquer número+enter para continuar... ");
                scanf("%i",&nada);
                system("cls");
            }
            else if(opc2==4)
            {
                w = 1;
            }
        }
        else if(opc1 == 2)
        {
            opc3 = 9;
            while(opc3 < 1 || opc3 > 4)
            {
                printf(" ---------------------------------------------------\n");
                printf(" |                 O que deseja ?                  |\n");
                printf(" |                                                 |\n");
                printf(" |                  (pressione)                    |\n");
                printf(" |                                                 |\n");
                printf(" |                1 - Chamar ficha                 |\n");
                printf(" |                                                 |\n");
                printf(" |               2 - Gerar relatório               |\n");
                printf(" |                                                 |\n");
                printf(" |              3 - Visualizar filas               |\n");
                printf(" |                                                 |\n");
                printf(" |                   4 -  Sair                     |\n");
                printf(" |                                                 |\n");
                printf(" ---------------------------------------------------\n");
                scanf("%i",&opc3);
                system("cls");
            }
            if(opc3==1)
            {
                if(isEmpty(guichepref)==0)
                {
                    Beep(330, 150);
                    Beep(264, 150);
                    Beep(330, 150);
                    printf(" ---------------------------------------------------\n");
                    printf("   Atendimento prioritário ao caixa: Conta %i       \n",guichepref.conta[guichepref.f]);
                    printf(" ---------------------------------------------------\n");
                    Sleep(5000);
                    system("cls");
                    dequeue(&guichepref);
                    guichepref1++;
                }
                else
                {
                    if(isEmpty(guiche)==0)
                    {
                        Beep(330, 150);
                        Beep(264, 150);
                        Beep(330, 150);
                        printf(" ---------------------------------------------------\n");
                        printf("           Atendimento ao caixa: Conta %i           \n",guiche.conta[guiche.f]);
                        printf(" ---------------------------------------------------\n");
                        Sleep(5000);
                        system("cls");
                        dequeue(&guiche);
                        guiche1++;
                    }
                    else
                    {
                        printf("As filas estão vazias !!!");
                        Sleep(5000);
                        system("cls");
                    }
                }
            }
            else if(opc3==2)
            {
                printf(" ---------------------------------------------------\n");
                printf("         Quantidade de atendimentos realizados      \n");
                printf("                                                    \n");
                printf("        Atendimentos ao caixa(Prioritário): %i      \n",caixapref1);
                printf("                                                    \n");
                printf("        Atendimentos no guichê(Prioritário): %i     \n",guichepref1);
                printf("                                                    \n");
                printf("       Atendimentos ao caixa(Convencional): %i      \n",caixa1);
                printf("                                                    \n");
                printf("       Atendimentos no guichê(Convencional): %i     \n",guiche1);
                printf("                                                    \n");
                printf(" ---------------------------------------------------\n");
                Sleep(5000);
                system("cls");
            }
            else if(opc3==3)
            {
                printf(" ---------------------------------------------------\n");
                printf("       Fila de atendimento prioritário ao caixa     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(caixapref);
                printf(" ---------------------------------------------------\n");
                printf("       Fila de atendimento convencional ao caixa     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(caixa);
                printf(" ---------------------------------------------------\n");
                printf("      Fila de atendimento prioritário ao guichê     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(guichepref);
                printf(" ---------------------------------------------------\n");
                printf("      Fila de atendimento prioritário ao guichê     \n");
                printf(" ---------------------------------------------------\n");
                imprimir(guiche);
                printf(" ---------------------------------------------------\n");
                printf("pressione qualquer número+enter para continuar... ");
                scanf("%i",&nada);
                system("cls");
            }
            else if(opc3==4)
            {
                w = 1;
            }
        }
        else if(opc1 == 3)
        {
            printf(" ---------------------------------------------------\n");
            printf(" |                                                 |\n");
            printf(" |                                                 |\n");
            printf(" |          Qual é o número da sua conta ?         |\n");
            printf(" |                                                 |\n");
            printf(" |                                                 |\n");
            printf(" ---------------------------------------------------\n");
            scanf("%i",&contaCr);
            system("cls");
            printf(" ---------------------------------------------------\n");
            printf(" |                                                 |\n");
            printf(" |                                                 |\n");
            printf(" |                 Qual  sua idade ?               |\n");
            printf(" |                                                 |\n");
            printf(" |                                                 |\n");
            printf(" ---------------------------------------------------\n");
            scanf("%i",&idadeCr);
            system("cls");

            atendimentoCr = 9;
            while(atendimentoCr > 2 || atendimentoCr < 1)
            {
                printf(" ---------------------------------------------------\n");
                printf(" |          Que tipo de atendimento deseja ?       |\n");
                printf(" |                                                 |\n");
                printf(" |                  (pressione)                    |\n");
                printf(" |                                                 |\n");
                printf(" |            1 - Atendimento ao caixa             |\n");
                printf(" |                                                 |\n");
                printf(" |         2 - Outro (Atendimento no guichê)       |\n");
                printf(" |                                                 |\n");
                printf(" ---------------------------------------------------\n");
                scanf("%i",&atendimentoCr);
                system("cls");
            }
            if(atendimentoCr==1)
            {
                if(idadeCr>60)
                {
                    enqueue(&caixapref,contaCr);
                }
                else
                {
                    enqueue(&caixa,contaCr);
                }

            }
            else if(atendimentoCr==2)
            {
                if(idadeCr>60)
                {
                    enqueue(&guichepref,contaCr);
                }
                else
                {
                    enqueue(&guiche,contaCr);
                }
            }
        }

    }



    printf(" ---------------------------------------------------\n");
    printf(" |                                                 |\n");
    printf(" |                                                 |\n");
    printf(" |                Fim do expediente !              |\n");
    printf(" |                                                 |\n");
    printf(" |                                                 |\n");
    printf(" ---------------------------------------------------\n");
    Sleep(3000);
    system("cls");

}
void imprimir(Fila q)
{
    if(q.f <= q.r && q.f!=-1)
    {
        for(int i=q.f; i<=q.r; i++)
        {
            printf("                         %i \n", q.conta[i]);
        }
    }
    else if(q.f!=-1)
    {
        for(int i=q.f; i<TAM; i++)
        {
            printf("                         %i \n", q.conta[i]);
        }
        for(int i=0; i<=q.r; i++)
        {
            printf("                         %i \n", q.conta[i]);
        }
    }
    else
    {
        printf("                      Vazia !!!\n");
    }

}

void dequeue(Fila *q)
{
    if(q->r != -1)
    {
        if(q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = (q->f+1)%TAM;
        }
    }
    else
    {
        printf("Não consegui remover");
    }
}

void enqueue(Fila *q, int x)
{
    if(isFull(*q)==0)
    {
        q->r = (q->r + 1)%TAM;
        q->conta[q->r] = x;
        if(q->f==-1)
        {
            q->f++;
        }
    }
    else
    {
        printf("\nFila cheia - Não pode inserir\n");
    }
}
int isEmpty(Fila q)
{
    if(q.f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(Fila q)
{
    if(q.f < q.r && q.f==0 && q.r==TAM-1)
    {
        printf("Fila cheia");
        return 1;
    }
    else if(q.f > q.r && q.f-q.r==1)
    {
        printf("Fila cheia");
        return 1;
    }
    else
    {
        return 0;
    }
}
