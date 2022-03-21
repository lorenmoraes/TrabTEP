/* ------------------------- Alunas: --------------------------------
 * ------- Camila Castro Abreu - 2020102558 - Turma da Manhã --------
 * ---- Lorraynne Modolo de Moraes - 2020101444 - Turma da Manhã ----
 * ---------------- Engenharia da Computação UFES -------------------
 * --------- Tópicos Especiais em Programação I (2021/2) ----------*/

/* main.c */
/* teste do tipo de dados meuracional */
#include <stdio.h>
#include "meu_racional.h"

int main ()
{

/** ------ PARTE ORIGINAL DO PROGRAMA: MEU_RACIONAL ------*/
    MeuRacional_pt ptR1=NULL, ptR2=NULL, ptR3=NULL;

/* veja que aqui neste ponto faço chamadas de algumas funções
 * através dos ponteiros que estão na tabela vtbl (ponteiro "metodo")
 * da superclasse "Numero". Como as funções desta tabela esperam
 * receber "ponteiro para Numero_t", preciso converter o ptX1 para
 * Numero_pt e depois converter o resultado "de volta" para
 * MeuRacional_pt */

    ptR1 = Racional_constroi (ptR1, 10, 20);

    ptR2 = ptR1->Metodo->copia (ptR1);

    printf ("Os dois numeros sao Y1 = %s e Y2 = %s \n",
	    ptR1->Metodo->imprime (ptR1),
	    ptR2->Metodo->imprime (ptR2));

    ptR3 = Racional_constroi (ptR3, 0, 1);

    ptR3 = ptR2->Metodo->atribui (ptR2, ptR3);
    printf ("Y3 recebeu o valor de Y2 = %s \n",
	    ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->soma(ptR1, ptR2, ptR3);
    printf ("Y3 recebeu a soma de Y1 com Y2 = %s \n",
	    ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR3->Metodo->subt(ptR3, ptR2, ptR3);
    printf ("Y3 recebeu a subtracao de Y3 com Y2 = %s \n",
	    ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->mult(ptR1, ptR2, ptR3);
    printf ("Y3 recebeu a multiplicacao de Y1 com Y2 = %s \n",
            ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->divd(ptR1, ptR2, ptR3);
    printf ("Y3 recebeu a divisão de Y1 com Y2 = %s \n",
            ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_soma(ptR3, ptR2);
    printf ("Y3 foi somado com Y2 = %s \n",
	    ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR3->Metodo->ac_subt(ptR3, ptR2);
    printf ("Y3 subtraiu Y2 = %s \n",
	    ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_mult(ptR3, ptR2);
    printf ("Y3 foi multiplicado por Y2 = %s \n",
            ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_divd(ptR3, ptR2);
    printf ("Y3 foi dividido por Y2 = %s \n",
            ptR3->Metodo->imprime (ptR3));

    if (ptR1->Metodo->compara(ptR1,ptR2)==0)
    {
       printf ("Y1 eh igual a Y2 = %s\n", ptR1->Metodo->imprime(ptR1));
    }
    if (ptR1->Metodo->compara(ptR2,ptR3)>0)
    {
       printf ("Y2 eh maior que Y3 \n");
    }
    if (ptR1->Metodo->compara(ptR2,ptR3)<0)
    {
       printf ("Y2 eh menor que Y3 \n");
    }

    ptR1->Metodo->destroi (ptR1);
    ptR2->Metodo->destroi (ptR2);
    ptR3->Metodo->destroi (ptR3);

    return (0);
}