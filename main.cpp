#include <iostream>
#include <fstream>
using namespace std;

void algoritmoInserccion(int a[], int n);

void algoritmoInterpolacion (int a[], int n);

void impirmirElementos(int a[], int n);


int main()
{
  int suma;
  ofstream archivo;
  ofstream interpolacion;
  archivo.open("ordenamiento.txt", ios::app);
  interpolacion.open("Interpolación.txt", ios::app);
  int a[7]= {1,5,8,9,2,3,7};
  
  archivo<<"La lista desordenada es :\n";
  interpolacion<<"ARREGLO DE ELEMENTOS: "<<endl;
  
  for (int i=0; i<7; i++)
  {
    archivo<<"|"<<a[i]<<"|";
  }
  archivo<<endl;
  impirmirElementos (a,7);
  cout<<"\n";
  algoritmoInserccion(a,7);
  
  archivo<<"La lista ordenada es :\n";
  for (int i=0; i<7; i++)
  {
    archivo<<"|"<<a[i]<<"|";
    interpolacion<<"|"<<a[i]<<"|";
  }
  archivo<<endl;
  interpolacion<<endl;
  archivo<<"El total de elementos en el arreglo es de: 7\n";
  for (int i=0; i<7; i++)
  {
    suma=suma+a[i];
  }
  archivo<<"La suma de los elementos en el arreglo es de : "<<suma<<endl;
  cout<<"\n";
  impirmirElementos (a,7);
  cout<<"\n";
  algoritmoInterpolacion(a,7);
  archivo.close();
  interpolacion.close();
}


void impirmirElementos(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"|"<<a[i]<<"|";
  }
}


void algoritmoInserccion(int a[], int n)
{
    int pos,aux;
    for(int i=0; i<n; i++)
    {
        pos=i;

        aux=a[i];

        while((pos>0)&&(a[pos-1]>aux))
        {
            a[pos] = a[pos-1];

            pos--;

        }

        a[pos]=aux;
    }


}


void algoritmoInterpolacion (int a[], int n)
{
  ofstream interpolacion;
  interpolacion.open("Interpolación.txt", ios::app);
    int primero = 0;

    int ultimo = n-1;

    int medio;

    int cont=0;

    int num=7;
    interpolacion<<"ELEMENTO A BUSCAR: "<<num;
    while(a[primero] != num && cont<=7 )
    {
        medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        {
            primero = medio +1;
        }
        else if(a[medio]>num)
        {
            ultimo = medio-1;
        }
        else
        {
            primero = medio;
        }
        cont++;
    }
    if(a[primero]==num)
    {
        cout<<"ELEMENTO ENCONTRADO, EN LA POSICIÓN: "<<a[primero];
        interpolacion<<endl;
        interpolacion<<"ELEMENTO ENCONTRADO, EN LA POSICIÓN: "<<a[primero]<<endl;

    }
    else
    {
        cout<<"ELEMENTO NO ENCONTRADO";
        interpolacion<<"ELEMENTO NO ENCONTRADO"<<endl;
    }
  interpolacion.close();
}
