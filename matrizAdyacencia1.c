#include <stdio.h>
int main(int argc, char* argv[])
{
  int **adj_matrix;
  char d;
  int r, c, nodes;
  printf ("matriz de adyacencia\n");
  printf ("Numero de nodos: ");
  scanf ("%d", &nodes);

  /* Dynamic allocation of matrix array */
  adj_matrix = (int **) malloc (sizeof(int **)*nodes);
  if(!adj_matrix) 
  {
    printf ("Fatal error in memory allocation!");
    return -1;
  }
  for (r = 0; r < nodes; r++) 
  {
    adj_matrix[r] = (int *) malloc(sizeof(int)*nodes);
    if(!adj_matrix[r]) {
      printf ("Error en la asignacion de memoria**\n");
      return -1;
    }
  }
  for (r = 0; r < nodes; r++) 
  {
    for (c = 0; c < nodes; c++) 
	{
        adj_matrix[r][c] = 0;
    }

  }
  r = 0;
  c = 0;
  
  printf ("Tipo de nodo (U = no dirigido, D = dirigido) <U/D> <V1> <V2>\n");
  do 
  {
    printf ("Ingrese el par de nodos: ");
    fflush(stdin);
    scanf ("%c %d %d", &d, &r, &c);
    
    if (r > 0 && r <= nodes && c > 0 && c <= nodes)
	{
            adj_matrix[r - 1][c - 1] = 1;
      if(d == 'U' || d == 'u')
	  {
	      adj_matrix[c - 1][r - 1] = 1;
	      printf ("Conexion no dirigida entre %d y %d\n", r, c);
      } 
	  else 
	  {
            printf ("Conexion dirigida entre %d y %d\n", r, c);
      }
    }
  }while(r > 0 && c > 0);

  printf("\nMatriz adyacencia\n");
  printf(" ");
  for (c = 0; c < nodes; c++) 
  {
    printf("%.1d ", c + 1);
  }
  printf("\n");
  for (c = 0; c < nodes; c++) 
  {
    printf("---");
  }
  printf("\n");
  for (r = 0; r < nodes; r++) 
  {
    printf("%.1d| ", r+1);
    for (c = 0; c < nodes; c++) 
	{
        printf("%.1d ", adj_matrix[r][c]);
    }
    printf("\n");
  }
  return 0;
}
