#include <stdio.h>

#define linha 10  // quantidade de linhas do mapa
#define coluna 10 // quantidade de colunas do mapa
#define conek 5 // valor adicionado ao mapa ao usar a habilidade cone
#define cruzk 6 // valor adicionado ao mapa ao usar a habilidade cruz
#define octak 7  // valor adicionado ao mapa ao usar a habilidade octaedro
#define navio 3 // valor adicionado ao mapa ao inserir um navio

int main() {
        int opcao;
        int sentido, habilidade;
        int lin, col;

/*####################################### */
        // campo inicial 0 = agua
/*####################################### */

        int campo[linha][coluna];
        for (int i = 0; i < linha; i++) {             // loop externo
            for (int j = 0; j < coluna; j++) {     // loop interno
                    campo[i][j] = 0;     }} // fecha for (2x)

/*####################################### */
        // menu principal do programa
/*####################################### */

                while (opcao != 5)
        {       // abre while opcao
                // entrando no menu principal e escolhendo uma opção
                printf("### Jogo de Batalha Naval ### \n");   // nome do app
                printf("1. Colocar um novo navio  \n");           // entra no menu para colocar um navio
                printf("2. Escolher uma matriz de habilidade  \n");           // Usar uma matriz de habilidade
                printf("3. Ver o mapa  \n");           // entra no menu para colocar um navio
                printf("4. Ver regras para inserir um navio \n"); //entende as regras de colocar navios
                printf("5. Sair do jogo \n");                     //finaliza o programa
                printf("Digite um número de 1 a 4 \n"); //informa ao usuario que deve escolher uma opcao
                // o usuário fará a sua escolha
                scanf("%d", &opcao);

/*####################################### */
        // submenu de formato da inserção de navios
/*####################################### */

                switch (opcao)
                { // abre switch opcao
                        case 1: // o usuario vai inserir um navio
                                printf("Deseja colocar o navio de 3 Pontos Vitais na horizontal, na vertical ou na diagonal? \n");
                                printf("1. Colocar na horizontal \n");
                                printf("2. Colocar na vertical \n");
                                printf("3. Colocar na diagonal positiva / \n");
                                printf("4. Colocar na diagonal negativa \\ \n");
                                scanf("%d", &sentido);

/*####################################### */
        // submenu de inserção de navios
/*####################################### */

                                switch (sentido)
                                { //abre switch sentido
                                        case 1: // colocando um navio na horizontal
                                                printf("Digite um número de 0 a %d para a linha \n", linha - 1); // linha que será inserido o navio
                                                scanf("%d", &lin);
                                                printf("Digite um número de 0 a %d para a coluna \n", coluna - navio); // coluna que será inserido o navio
                                                scanf("%d", &col);
                                                if (    (0 <= lin) && (lin <= linha - 1) && (0 <= col) && (col <= coluna - navio)    ) // verificando se o navio cabe no mapa
                                                {
                                                if (    (campo[lin][col] == 0) && (campo[lin][col+1] == 0) && (campo[lin][col+2] == 0)    )  // verifica se nao tem navio no local selecionado
                                                {            printf("O navio será colocado nos pontos (%d, %d), (%d, %d), (%d, %d) \n. \n. \n. \n. \n", lin, col, lin, col + 1, lin, col + 2);
                                                              campo[lin][col] = navio, campo[lin][col+1] = navio, campo[lin][col+2] = navio; // coordenadas do navio sendo colocado
                                                } else { printf("Nesse local já tem um navio \n.\n.\n.\n.\n");}
                                                } else { printf("O navio ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                        case 2:   // colocando um navio na vertical
                                                printf("Digite um número de 0 a %d para a linha \n", linha-navio); // linha que será inserido o navio
                                                scanf("%d", &lin);
                                                printf("Digite um número de 0 a %d para a coluna \n", coluna - 1); // coluna que será inserido o navio
                                                scanf("%d", &col);
                                                if (    (0 <= lin) && (lin <= linha - navio) && (0 <= col) && (col <= coluna - 1)    )  // verificando se o navio cabe no mapa
                                                {
                                                if (    (campo[lin][col] == 0) && (campo[lin+1][col] == 0) && (campo[lin+2][col] == 0)    )    // verifica se nao tem navio no local selecionado
                                                {            printf("O navio será colocado nos pontos (%d, %d), (%d, %d), (%d, %d) \n.\n.\n.\n.\n", lin, col, lin + 1, col, lin + 2, col);
                                                campo[lin][col] = navio, campo[lin+1][col] = navio, campo[lin+2][col] = navio; // coordenadas do navio sendo colocado
                                                } else { printf("Nesse local já tem um navio \n.\n.\n.\n.\n");}
                                                } else { printf("O navio ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                         case 3:  // colocando um navio na diagonal positiva /
                                                printf("Digite um número de %d a %d para a linha \n", navio - 1, linha - 1); // linha que será inserido o navio
                                                scanf("%d", &lin);
                                                printf("Digite um número de 0 a %d para a coluna \n", coluna - navio); // coluna que será inserido o navio
                                                scanf("%d", &col);
                                                if (    (navio - 1 <= lin) && (lin <= linha - 1) && (0 <= col) && (col <= coluna - navio)    ) // verificando se o navio cabe no mapa
                                                {
                                                if (    (campo[lin][col] == 0) && (campo[lin-1][col+1] == 0) && (campo[lin-2][col+2] == 0)    )
                                                {            printf("O navio será colocado nos pontos (%d, %d), (%d, %d), (%d, %d) \n.\n.\n.\n.\n", lin, col, lin - 1, col + 1, lin - 2, col + 2);
                                                campo[lin][col] = navio, campo[lin-1][col+1] = navio, campo[lin-2][col+2] = navio; // coordenadas do navio sendo colocado
                                                } else { printf("Nesse local já tem um navio \n.\n.\n.\n.\n");}
                                                } else { printf("O navio ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                         case 4:  // colocando um navio na diagonal negativa /
                                                printf("Digite um número de %d a %d para a linha \n", navio - 1, linha - 1); // linha que será inserido o navio
                                                scanf("%d", &lin);
                                                printf("Digite um número de 0 a %d para a coluna \n", coluna - navio); // coluna que será inserido o navio
                                                scanf("%d", &col);
                                                if (    (navio -1 <= lin) && (lin <= linha - 1) && (0 <= col) && (col <= coluna - navio)    ) // verificando se o navio cabe no mapa
                                                {
                                                if (    (campo[lin][col] == 0) && (campo[lin+1][col+1] == 0) && (campo[lin+2][col+2] == 0)    )
                                                {            printf("O navio será colocado nos pontos (%d, %d), (%d, %d), (%d, %d) \n.\n.\n.\n.\n", lin, col, lin + 1, col + 1, lin + 2, col + 2);
                                                campo[lin][col] = navio, campo[lin+1][col+1] = navio, campo[lin+2][col+2] = navio; // coordenadas do navio sendo colocado
                                                } else { printf("Nesse local já tem um navio \n.\n.\n.\n.\n");}
                                                } else { printf("O navio ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                        default:
                                                printf("Opção inválida. Tente novamente \n.\n.\n.\n.\n");
                                                break;
                                 } // fecha switch sentido
                                break;

/*####################################### */
        // submenu do tipo de habilidades
/*####################################### */

                    case 2: // o usuario vai usar as habilidades
                                printf("Deseja usar qual habilidade: cone, cruz e octaedro \n");
                                printf("1. Usar a habilidade de Cone \n");
                                printf("2. Usar a habilidade de Cruz \n");
                                printf("3. Usar a habilidade de Octaedro / \n");
                                scanf("%d", &habilidade);
                                
/*####################################### */
        // submenu de uso de habilidades
/*####################################### */
                                
                                switch (habilidade)
                                { //abre switch habilidade
                                        case 1: // usar a habilidade cone
                                                printf("Digite um número de 0 a %d para a linha \n", linha - 2); // linha que será inserido a habilidade cone
                                                scanf("%d", &lin);
                                                printf("Digite um número de 2 a %d para a coluna \n", coluna - 2); // coluna que será inserido a habilidade cone
                                                scanf("%d", &col);
                                                if (    (0 <= lin) && (lin <= linha - 2) && (2 <= col) && (col <= linha - 2)    ) // verificando se o navio cabe no mapa
                                                        {        campo[lin][col] += conek; campo[lin+1][col-1] +=conek; campo[lin+1][col] +=conek;
                                                                 campo[lin+1][col+1] +=conek; campo[lin+2][col-2] +=conek; campo[lin+2][col-1] +=conek;
                                                                 campo[lin+2][col] +=conek; campo[lin+2][col+1] +=conek; campo[lin+2][col+2] +=conek;       // add conek
                                                                  printf("A habilidade cone será colocada nos pontos: \n");
                                                                  printf("(%d, %d), (%d, %d), (%d, %d)  \n", lin, col, lin + 1, col - 1, lin + 1, col);
                                                                  printf(" (%d, %d), (%d, %d), (%d, %d)  \n", lin + 1, col + 1, lin + 2, col - 2, lin + 2, col - 1);
                                                                  printf(" (%d, %d), (%d, %d), (%d, %d) \n. \n. \n. \n. \n", lin + 2, col, lin + 2, col + 1, lin + 2, col + 2);
                                                          } else { printf("A matriz da habilidade ficará fora do mapa \n.\n.\n.\n.\n");}
                                                          
                                                break;
                                        case 2:   // usar a habilidade cruz
                                                printf("Digite um número de 1 a %d para a linha \n", linha - 1); // linha que será inserido a habilidade cone
                                                scanf("%d", &lin);
                                                printf("Digite um número de 2 a %d para a coluna \n", coluna - 2); // coluna que será inserido a habilidade cone
                                                scanf("%d", &col);
                                                if (    (1 <= lin) && (lin <= linha - 1) && (2 <= col) && (col <= linha - 2)    ) // verificando se o navio cabe no mapa
                                                        {        campo[lin][col] += cruzk; campo[lin-1][col] +=cruzk; campo[lin+1][col] +=cruzk;
                                                                  campo[lin][col-2] +=cruzk; campo[lin][col-1] +=cruzk;
                                                                  campo[lin][col+1] +=cruzk; campo[lin][col+2] +=cruzk;       // add cruzk
                                                                  printf("A habilidade cruz será colocada nos pontos: \n");
                                                                  {printf("(%d, %d), (%d, %d), (%d, %d)  \n", lin, col, lin - 1, col, lin + 1, col);
                                                                  printf("(%d, %d), (%d, %d)  \n", lin, col - 2, lin, col - 1);
                                                                  printf("(%d, %d), (%d, %d) \n. \n. \n. \n. \n", lin, col + 1, lin, col + 2);
                                                           }} else { printf("A matriz da habilidade ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                         case 3:  // usar a habilidade octaedro
                                                printf("Digite um número de 1 a %d para a linha \n", linha - 1); // linha que será inserido a habilidade cone
                                                scanf("%d", &lin);
                                                printf("Digite um número de 1 a %d para a coluna \n", coluna - 1); // coluna que será inserido a habilidade cone
                                                scanf("%d", &col);
                                                if (    (1 <= lin) && (lin <= linha - 1) && (1 <= col) && (col <= linha - 1)    ) // verificando se o navio cabe no mapa
                                                        {        campo[lin][col] += octak; campo[lin+1][col] +=octak; campo[lin-1][col] +=octak;
                                                                  campo[lin][col-1] +=octak; campo[lin][col+1] +=octak;        // add octak
                                                                  printf("A habilidade cruz será colocada nos pontos: \n");
                                                                  printf("(%d, %d), (%d, %d), (%d, %d)  \n", lin, col, lin + 1, col, lin - 1, col);
                                                                  printf("(%d, %d), (%d, %d), (%d, %d)  \n. \n. \n. \n. \n", lin, col - 1, lin, col + 1);
                                                          } else { printf("A matriz da habilidade ficará fora do mapa \n.\n.\n.\n.\n");}
                                                break;
                                        default:
                                                printf("Opção inválida. Tente novamente \n.\n.\n.\n.\n");
                                                break;
                                 } // fecha switch habilidade
                                break; 

/*####################################### */
        // menu do mapa
/*####################################### */

                        case 3: // ver o mapa
                printf("colunas  0  1  2  3  4  5  6  7  8  9 \n");
                for (int i = 0; i < linha; i++)    {             // loop externo
                printf("linha %d  ", i); 
                for (int j = 0; j < coluna; j++) {     // loop interno
                if (campo[i][j] >= 8)                {
                campo[i][j] = 9;       }  // fecha if
                printf("%d  ", campo[i][j]);    } // fecha for
                    printf("\n");                            } // fecha for
                    printf("\n \n \n \n");
                                break;

/*####################################### */
        // Regras do jogo
/*####################################### */

                        case 4:
                                printf("Regras do jogo:\n");
                                printf("Regra 1: Os navios podem ser inseridos na horizontal, vertical ou na diagonal. \n. \n");
                                printf("Regra 2: (Navio na horizontal) Você vai digitar o primeiro ponto vital. \n         Os outros pontos vitais serão colocados a direita dele. \n. \n");
                                printf("Regra 3: (Navio na vertical) Você vai digitar o primeiro ponto vital. \n         Os outros pontos vitais serão colocados abaixo dele. \n. \n");
                                printf("Regra 4: (Navio na diagonal positiva /) Você vai digitar o primeiro ponto vital. \n         Os outros pontos vitais serão colocados na direita para cima. \n. \n");
                                printf("Regra 5: (Navio na diagonal negativa \\) Você vai digitar o primeiro ponto vital. \n         Os outros pontos vitais serão colocados na direita para baixo. \n. \n");
                                printf("Regra 6: (Ao inserir uma habilidade aparecerá um número 5, 6 ou 7 para sinalizar o local usado. \n         O número 9 simboliza o local que a habilidade coincidiu com a posiçao de um navio \n. \n");
                                break;
                        case 5:
                                printf("Saindo ...\n.\n.\n.\n.\n");
                                break;
                        default:
                        printf("Opção inválida. Tente novamente \n.\n.\n.\n.\n");
                        break;
                } // fecha switch opcao
        } // fecha while opcao

/*####################################### */
        // Navios atingidos pela habilidade
/*####################################### */
/*
        switch(destroy)
        {case 1:
                for (int i = 0; i < linha; i++) {             // loop externo
                for (int j = 0; j < coluna; j++) {     // loop interno
                if (campo[i][j] >= 8)            {
                campo[i][j] = printf("#");   }  // fecha if
                                                                    } // fecha for - loop interno
                                                                  } // fecha for - loop externo
          break;
          } // fecha switch destroy */
    return 0;
} // fecha main