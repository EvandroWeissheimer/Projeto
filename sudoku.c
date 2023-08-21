#include <stdio.h>
#define tamanho 9

 void resolucao(int matriz[][tamanho], int linhas,int colunas);
    
 void impresao(int matriz[][tamanho]);
    
 int VerificadordeViolacao(int matriz[][tamanho], int n, int linha, int coluna);

int main()
{
    int tabuleiro[][tamanho] = {
  {7, 0, 2, 0, 5, 0, 6, 0, 0},
  {0, 0, 0, 0, 0, 3, 0, 0, 0},
  {1, 0, 0, 0, 0, 9, 5, 0, 0},
  {8, 0, 0, 0, 0, 0, 0, 9, 0},
  {0, 4, 3, 0, 0, 0, 7, 5, 0},
  {0, 9, 0, 0, 0, 0, 0, 0, 8},
  {0, 0, 9, 7, 0, 0, 0, 0, 5},
  {0, 0, 0, 2, 0, 0, 0, 0, 0},
  {0, 0, 7, 0, 4, 0, 2, 0, 3}
  };
  
  /*int tabuleiro[][tamanho] = {
  {8, 3, 0, 0, 0, 5, 6, 9, 0},
  {0, 0, 6, 0, 8, 0, 0, 0, 2},
  {0, 0, 0, 6, 0, 0, 0, 0, 5},
  {6, 0, 0, 0, 0, 3, 0, 0, 0},
  {3, 0, 5, 0, 0, 0, 9, 0, 6},
  {0, 0, 0, 9, 0, 0, 0, 0, 7},
  {4, 0, 0, 0, 0, 2, 0, 0, 0},
  {5, 0, 0, 0, 4, 0, 1, 0, 0},
  {0, 8, 7, 1, 0, 0, 0, 4, 9}};*/
  
  /*int tabuleiro[][tamanho] = {
  {0, 0, 6, 2, 0, 0, 0, 8, 0},
  {0, 0, 8, 9, 7, 0, 0, 0, 0},
  {0, 0, 4, 8, 1, 0, 5, 0, 0},
  {0, 0, 0, 0, 6, 0, 0, 0, 2},
  {0, 7, 0, 0, 0, 0, 0, 3, 0},
  {6, 0, 0, 0, 5, 0, 0, 0, 0},
  {0, 0, 2, 0, 4, 7, 1, 0, 0},
  {0, 0, 3, 0, 2, 8, 4, 0, 0},
  {0, 5, 0, 0, 0, 1, 2, 0, 0}};*/
  
  printf("****** Sudoku inicial ******\n\n");
  
  impresao(tabuleiro);
  
  resolucao(tabuleiro, 0, 0);
  
    return 0;
}

 void impresao(int matriz[][tamanho]) // imprime a matriz
  {
      int i, j;
      
      for(i=0; i<tamanho; i++)
      {
          if(i != 0 && i % 3 == 0) // se i for divisivel por 3 com resto 0, sendo i != de 0
          {
              printf("----------------------------\n");
          }
          for(j=0; j<tamanho; j++)
          {
              if(j != 0 && j % 3 == 0)// se j for divisivel por 3 com resto 0, sendo j != de 0
              {
                  printf("|");
              }
              printf(" %d ", matriz[i][j]);
              
          }
          printf("\n");
          
      }
      
      printf("\n");
  }
  
 void resolucao(int matriz[][tamanho], int linha, int coluna) // resolucao da matriz
  {
    int tentativa, numero;

  if (linha == 9) // verifica se ja terminou o Sudoku
    {
       printf("******* Sudoku final *******\n\n");
       impresao(matriz);
    }
    
  else
  {
    for (numero = 1; numero <= 9; numero++) // aumentando um ao numero
    {
      if (VerificadordeViolacao(matriz, numero, linha, coluna)) // se a funco retornar verdadeiro
       {
         tentativa = matriz[linha][coluna]; // faz uma copia do numero na matriz
         matriz[linha][coluna] = numero;  // posicao na matriz recebe o numero 
         
         if (coluna == 8) // se  chegar na ultima coluna zerar a coluna e pular para a proxima linha
            {
              resolucao(matriz, linha + 1, 0);// pula uma linha na matriz
            }
         
         resolucao(matriz, linha, coluna + 1); // ele chama a funcao colocando mais uma coluna
         
         matriz[linha][coluna] = tentativa; // em caso da linha nao fechar o algoritmo volta a funcao anterior e retorna o valor salvo na tentativa
         
        }
    }
     
   }
    
  }
  
 int VerificadordeViolacao (int matriz[][tamanho], int n, int linha, int coluna) // verifica violacao de linha coluna e bloco
  {
       int lb, cb, i, j;
      
       if (matriz[linha][coluna] == n) // se ja tiver o numero no local
        {
          return 1; // retorna verdadeiro
        }
  
       else if (matriz[linha][coluna] != 0)  // se ja tiver um numero no local
       {
          return 0; // retorna falso 
       }
  
     // verificacao das linhas
      
      for(j=0; j<tamanho; j++)
      {
          if(matriz[linha][j] == n) // mantem a linha e percorre a coluna verificando o numero
          {
             return 0; // retorna falso 
          }
          
      }
  
  //  verificacao das colunas
      
      for(i=0; i<tamanho; i++)  
      {
          if (matriz[i][coluna] == n) // mantem a coluna e percorre a linha verificando o numero
           {
             return 0; // // retorna falso 
           }
          lb = linha / 3; // dividindo a linha por 3
          cb = coluna / 3; // dividindo a coluna por 3
      }
      
  // verificador de bloco
      
     for (i = lb * 3; i < (lb + 1) * 3; i++) // testando o na posicao  0 0; i = 0; i < 3; i + 1
       {
         for (j = cb * 3; j < (cb + 1) * 3; j++) // j= 0; j < 3; j + 1
            {
              if (matriz[i][j] == n) // se encontrar o numero no bloco
               {
                 return 0; // // retorna falso 
               }
            }
       }
      return 1; // retorna verdadeiro
  }
