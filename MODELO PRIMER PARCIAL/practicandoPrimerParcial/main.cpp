/*
a)Generar un archivo con el codigo de obra, la direccion, el importe total de las compeas para esa obra.
 Es decir por cada obra se debe registrar el codigo de obra, la direccion de obra y el importe total para esa obra
 b) La provincia con menos provedores(ignorando las provincias sun proveedores)

//c) crear un archivo con el numero de compra,numero de proveedor, provedor de las compras y cargar su nombre y telefono


*/



#include <string.h>
#include <iostream>
using namespace std;


#include "parcialm1.h"





class puntoA
{
private:
    char _codigoObra[5];
    char _direccion[30];
    int _importeTotal;
public:

    void mostrar()
    {
        cout <<_codigoObra<< endl;
        cout<<_direccion<< endl;
        cout <<_importeTotal << endl;
    }

    void cargar()
    {
        cout <<"ingrese codigo de obra"<< endl;
        cin>> _codigoObra;

        cout <<"ingrese direccion" << endl;
        cin>> _direccion;


    }

    const char* getCodigoObra()
    {
        return _codigoObra;

    }


    void setCodgioObra(const char *co)
    {
        strcpy(_codigoObra,co);
    }
    void setDireccion(const char *di)
    {
        strcpy(_direccion,di);
    }

    void setImportetotal(float it)
    {
        _importeTotal = it;
    }

    void grabarEnDisco()
    {

        FILE *p;
        p =fopen( "puntoa", " ab" ) ;
        if (p==NULL) exit(-1) ;

        fwrite (this, sizeof (puntoA), 1, p);

        fclose (p);


    }


};


int cantidadDeRegistrosObra()
{
    FILE *puntero;
    Obra obra;

    int cantidadRegistros;
    puntero = fopen("obras.dat","rb");
    if (puntero == NULL) cout<< "no se pudo abrir" << endl;


    fseek(puntero,sizeof(obra),SEEK_END);
    cantidadRegistros =ftell(puntero) / sizeof obra;

    fclose(puntero);
    return cantidadRegistros;










}
//c) crear un archivo con el numero de provedor de las compras y cargar su nombre y telefono

class puntoC
{
private:
    int _numeroDeCompra;
    int _numeroDeProveedor;
    char _nombreProv[30];
    char _telefonoProv[30];

public:
    void setNumeroDeProveedor(int numeroDeProveedor)
    {
        _numeroDeProveedor = numeroDeProveedor;
    }

    void setNumeroDeCompra(int numeroDeCompra)
    {
        _numeroDeCompra = numeroDeCompra;

    }

    int getNumeroDeProveedor()
    {
        return _numeroDeProveedor;
    }


    void mostrar()
    {
        cout << "numero de compra"<< endl;
        cout << _numeroDeCompra << endl;
        cout <<"numero de proveedor" << endl;
        cout <<_numeroDeProveedor << endl;
        cout <<"nombre del proveedor"<< endl;
        cout <<_nombreProv<< endl;
        cout <<"telefono del proveedor" <<endl;
        cout <<_telefonoProv << endl;
        cout <<"-------------------------------------------------"<< endl;


    }





    void setTelefono(const char *telefono)
    {
        strcpy(_telefonoProv,telefono);
    }


    void setNombreProveedor(const char *nombreProv)
    {
        strcpy(_nombreProv,nombreProv);

    }

    int leerDeDisco(int pos)
    {
        FILE *p;
        p=fopen("ejercicio3", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof(puntoC)*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }


};




//a)Generar un archivo con el codigo de obra, la direccion, el importe total de las compeas para esa obra.
void primerejercicio()
{
    puntoA puntoA;
    Obra obra;
    Compra compra;
    FILE *puntero;





    for(int i = 1; i < cantidadDeRegistrosObra(); i++ )
    {
        obra.leerDeDisco(i);
        int pos = 0;

        puntoA.setCodgioObra(obra.getCodigoObra());
        puntoA.setDireccion(obra.getDireccion());

        while (compra.leerDeDisco ( pos ) == 1)
        {
            if ( strcmp(compra.getCodigoObra(),puntoA.getCodigoObra()) == 0 )
            {
                puntoA.setImportetotal(compra.getImporte());
            }
            pos++;


        }
        puntoA.grabarEnDisco();


    }




//esta funcion lee todo mi archivo
    puntero = fopen("puntoa","rb");
    if (puntero == NULL) cout<< "no se pudo abrir" << endl;


    while ( fread(&puntoA,sizeof(puntoA),1,puntero) == 1 )
    {
        puntoA.mostrar();

    }

    fclose(puntero);




}

int  cantidadDeregistrosProveedor()
{
    Proveedor proveedor;
    int cant;

    FILE *p;
    p = fopen("proveedores.dat","rb");
    if (p == NULL)
    {
        cout <<"no se pudo abrir" << endl;
    }



    fseek(p,sizeof proveedor,SEEK_END);

    cant = ftell(p) / sizeof proveedor;
    cout <<"tiene "<< cant <<" registros" << endl;

    fclose(p);

    return cant;
}



int  cantidadDeregistrosCompras()
{
    Compra compras;
    int cant;

    FILE *p;
    p = fopen("compras.dat","rb");
    if (p == NULL)
    {
        cout <<"no se pudo abrir" << endl;
    }



    fseek(p,sizeof compras,SEEK_END);

    cant = ftell(p) / sizeof compras;
    cout <<"tiene "<< cant <<" registros" << endl;

    fclose(p);

    return cant;
}



// b) La provincia con menos provedores(ignorando las provincias sun proveedores)
void segundoEjercicio()
{
    Proveedor prov;

    int cant = cantidadDeregistrosProveedor();

    int  provedoresPorProvincia[24] = {};
    cout << "---------------------------------------"<< endl;

    int menorCantidadDePRovedores;
    int provinciaConMenos;
    for (int i = 1; i  < cant; i++)
    {
        prov.leerDeDisco(i);
        provedoresPorProvincia[prov.getProvincia()] = prov.getNumeroProveedor();

        if (i == 1)
        {

            menorCantidadDePRovedores = prov.getNumeroProveedor();
            provinciaConMenos = prov.getProvincia();
        }

        if ( ( prov.getNumeroProveedor() < menorCantidadDePRovedores     ))
        {
            provinciaConMenos = prov.getProvincia();
            menorCantidadDePRovedores = prov.getNumeroProveedor();
        }

        //  prov.Mostrar();
    }

    cout << menorCantidadDePRovedores << endl;
    cout << provinciaConMenos << endl;




}

void tercerEjercicio()
{
//c) crear un archivo con el numero de compra,numero de proveedor, y cargar su nombre y telefono
    Compra compras;
    Proveedor proveedor;
    puntoC puntoC;
    FILE *p;

    int cantidadDeCompras = cantidadDeregistrosCompras();

    for (int i = 0; i < cantidadDeCompras; i++)
    {

        compras.leerDeDisco(i);

        puntoC.setNumeroDeCompra(compras.getNumeroCompra());
        puntoC.setNumeroDeProveedor (compras.getNumeroproveedor());



        int y = 0;
        while( proveedor.leerDeDisco(y) == 1)
        {

            if ( proveedor.getNumeroProveedor() == puntoC.getNumeroDeProveedor())
            {

                puntoC.setNombreProveedor(proveedor.getNombre ());
                puntoC.setTelefono(proveedor.getTelefono());

            }
            y++;

        }

        p = fopen("ejercicio3","ab");
        if (p == NULL) cout << "no se pudo abrir el archivo" << endl;



        fwrite(&puntoC,sizeof(puntoC),1,p);


        fclose(p);

    }



}
// fin tercer ejercicio


int cantidadDeRegistrosPunto3(){
puntoC aux;
FILE *p;

int cantidadRegistros;
p = fopen("ejercicio3","rb");
if (p == NULL) cout<< "no se pudo abrir"<< endl;


fseek(p,0,2);


cantidadRegistros =   ftell(p) / sizeof (puntoC);
cout << cantidadRegistros;







fclose(p);

return cantidadRegistros;



}









void modificarNumeroProveedor()
{
    puntoC aux;
    char nuevoTelefono[30];
    int numeroProveedor;
    FILE *p;
    int x = 1;
    p=fopen("ejercicio3","rb+");
    if (p = NULL) cout <<"no se pudo abrir el archivo"<< endl;

    cout<<"ingrese el numero de proveedor para cambiar su numero"<< endl;
    cin >> numeroProveedor;
    cout <<"ingrese el nuevo numero de telefono"<< endl;
    cin>> nuevoTelefono;



    for( int y = 0; y < 7; y++ )          // el ciclo lo puedo hacer sabiendo la cantidad de registros o leyendo con un while mientras fread devuelva 1
    {
         aux.leerDeDisco(y);

if (  aux.getNumeroDeProveedor() == numeroProveedor ){

    aux.setNumeroDeCompra(99);
    aux.setTelefono(nuevoTelefono);

    fseek(p,sizeof aux * y,0);
    fwrite(&aux,sizeof (puntoC),1,p);

}



    }
    fclose(p);





}














int main()
{
cantidadDeRegistrosPunto3();

    int opcion;
    cout <<"1: primer ejercicio"<< endl <<"2: segundo ejercicio"<< endl << "3: tercer ejercicio" << endl<< "4: modificar numero de proveedor"<< endl;
    cin >> opcion;

    switch(opcion)
    {

    case 1:
        primerejercicio();
        break;

    case 2:
        cout << "ejercicio 2"<< endl;
        segundoEjercicio();

        break;



    case 4:
        cout <<"ejercicio 4"<< endl;
       modificarNumeroProveedor();
   break;




    case 3:
        cout << "ejercicio 3"<< endl;
        //c) crear un archivo con el numero de compra,numero de proveedor, provedor de las compras y cargar su nombre y telefono
// tercerEjercicio();

        FILE *p;
        puntoC puntoC;
        int i = 0;

        p = fopen("ejercicio3","rb");
        if (p == NULL) cout<< "no se pudo abrir" << endl;


        while ( fread(&puntoC,sizeof(puntoC),1,p) == 1 )
        {
            cout <<"registro " << i << endl;
            puntoC.mostrar();
            i++;
        }
        fclose(p);


        break;








    }

    return 9;


}



















//obra.Cargar();
//compra.Cargar();




