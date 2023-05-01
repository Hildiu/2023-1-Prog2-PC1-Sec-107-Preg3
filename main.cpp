/*----------------------------------------------------------
 * Dato de Entrada: n1 y n2 (int) n1 y n2 >=5 y n1 y n2 <=20
 * Dato de Salida: a3 con la mezcla e a1 y a2
 -----------------------------------------------------------*/

#include <iostream>
#include <iomanip>

using namespace std;

int leer();
void   llenarArreglo(int *a, int n);
void imprimirArreglo(int *a, int n);
void   mezclar(int *a1, int n1, int *a2, int n2, int *a3, int &n3);

int main()
{
  int a1[20], a2[20], a3[40];
  int n1, n2,n3;

  srand(time(nullptr));
  cout << "Arreglo 1:\n";
  n1 = leer();
  cout << "Arreglo 2:\n";
  n2 = leer();
  llenarArreglo(a1, n1);
  llenarArreglo(a2,n2);
  imprimirArreglo(a1, n1);
  imprimirArreglo(a2, n2);
  mezclar(a1,n1,a2,n2,a3,n3);
  cout <<"\n";
  imprimirArreglo(a3, n3);
  return 0;
}

void   mezclar(int *a1, int n1, int *a2, int n2, int *a3, int &n3)
{
  n3 = n1 + n2;
  int ia1, ia2, ia3;

  ia1 = ia2 = ia3=0;
  while(ia1<n1 and ia2<n2)
  {
    a3[ia3++]= a1[ia1++];
    a3[ia3++]= a2[ia2++];
  }
  //--- averiaguamos cual termino para seguir
  //--- pasando los que quedan del otro arreglo
  if( n1!=n2) {
    if (ia1 < n1) //-- aun faltan pasar al arreglo n3
    {
      for (int i = ia1; i < n1; i++)
        a3[ia3++] = a1[i];
    }
    else
    {
      for (int i = ia2; i < n2; i++)
        a3[ia3++] = a2[i];
    }
  }
}


int leer()
{ int n;
  do{
    cout << "Numero de casilleros del arreglo : ";
    cin >> n;
  }while(n<5  || n>20);
  return n;
}

void   llenarArreglo(int *a, int n)
{
  for(int i=0; i<n; i++)
    a[i] = rand() % 50 + 1;
}

void imprimirArreglo(int *a, int n)
{
  cout << "\n";
  for(int i=0; i<n; i++)
    cout << setw(4) << a[i];
}

