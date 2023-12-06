//https://drive.google.com/drive/folders/1ZPjmxjUomEtev_RO5KCptVgomTzzrsRV?usp=drive_link//
#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    string tipo;
    int codigo;
    string nombre;
    int cantidad;
    bool abastecer;
};

void leerProducto(Producto &);
int agregarProducto(Producto[],Producto,int);
void mostrarProducto(Producto);
void buscarTipo(Producto[],int,string);
void modificarProducto(Producto[],int);
void ordenarCodigo(Producto[],int);
int busquedaCodigo(Producto[],int,int);

int main()
{
    Producto p;
    Producto lista[100];
    char cat,cen;
    int cant=0,i,dato,posi;
    string ti;

    do
    {
        system("cls");
        cout<<"------ BIENVENIDO AL SISTEMA DE CONTROL DE INVENTARIO ------"<<endl;
        cout<<"\n1. Agregar Producto"<<endl;
        cout<<"2. Modificar Producto"<<endl;
        cout<<"3. Mostrar todos los Productos (Se ordenara por codigo)"<<endl;
        cout<<"4. Buscar por tipo de Producto"<<endl;
        cout<<"5. Buscar por codigo de Producto"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"\nIngrese Categoria: ";
        cin>>cat;
        switch(cat)
        {
            case '0':
                cout<<"\nSe perderan todos datos. Seguro que desea salir? (S/N): ";
                cin>>cen;
                if(cen!='S' && cen!='s')
                {
                    cat=-1;
                }
                break;
            case '1':
                leerProducto(p);
                cant=agregarProducto(lista,p,cant);
                break;
            case '2':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ MODIFICAR PRODUCTOS ------"<<endl;
                    cout<<"\n LIMPIEZA |  ASEO  |  BEBIDA  |  SNACK"<<endl;
                    cout<<"\nID |\tTIPO         |         CODIGO         |        NOMBRE      |      CANTIDAD   "<<endl;
                    for(i=0;i<cant;i++)
                    {
                        cout<<i;
                        mostrarProducto(lista[i]);
                    }
                    modificarProducto(lista,cant);
                    break;
                }
                else
                {
                    cout<<"NO HAY PRODUCTOS INGRESADOS"<<endl;
                }               
                break;  
            case '3':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ LISTA DE PRODUCTOS INGRESADOS ------"<<endl;
                    cout<<"\n\tTIPO         |         CODIGO         |        NOMBRE      |      CANTIDAD   "<<endl;
                    for(i=0;i<cant;i++)
                    {
                        ordenarCodigo(lista,cant);
                    }
                    for(i=0;i<cant;i++)
                    {
                        mostrarProducto(lista[i]);
                    }
                    break;
                }
                else
                {
                    cout<<"NO HAY PRODUCTOS INGRESADOS"<<endl;
                }
                break;
            case '4':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ BUSQUEDA POR TIPO DE PRODUCTO ------"<<endl;
                    cout<<"\nLIMPIEZA | ASEO | BEBIDA | SNACK"<<endl;
                    cout<<"\nIngrese tipo de producto a buscar: ";
                    cin>>ti;
                    buscarTipo(lista,cant,ti);
                    break;
                }
                else
                {
                    cout<<"NO HAY PRODUCTOS INGRESADOS"<<endl;
                }
                break;
            case '5':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ BUSQUEDA POR CODIGO DE PRODUCTO ------"<<endl;
                    for(i=0;i<cant;i++)
                    {
                        ordenarCodigo(lista,cant);
                    }
                    cout<<"\nIngrese codigo del Producto que desea buscar: ";
                    cin>>dato;
                    posi=busquedaCodigo(lista,cant,dato);
                    if(posi>=0)
                    {
                        cout<<"\n\t"<<lista[posi].tipo<<"\t\t"<<lista[posi].codigo<<"\t\t\t"<<lista[posi].nombre<<"\t\t\t"<<lista[posi].cantidad<<endl;
                    }
                    else
                    {
                        cout<<"CODIGO DE PRODUCTO NO ENCONTRADO"<<endl;
                        break;
                    }   
                }
                else
                {
                    cout<<"NO HAY PRODUCTOS INGRESADOS"<<endl;
                }
                break;
            default:
            cout<<"Categoria no valida. Intente nuevamente"<<endl;
        }
        cout<<"  "<<endl;
        system("pause");
    }while(cat!='0');

    cout<<"FIN DEL PROGRAMA"<<endl;
    system("cls");
    return 0;
}

void leerProducto(Producto &p)//bien
{
    char op;
    do
    {
        system("cls");
        cout<<"\t------ INGRESE PRODUCTO ------"<<endl;
        cout<<"\n LIMPIEZA |  ASEO  |  BEBIDA  |  SNACK"<<endl;
        cout<<"\nIngrese Tipo de Producto: ";
        cin>>p.tipo;
        cout<<"Ingrese Codigo: ";
        cin>>p.codigo;
        cin.ignore();
        cout<<"Ingrese Producto: ";
        getline(cin, p.nombre);
        cout<<"Ingrese Cantidad: ";
        cin>>p.cantidad;
        cout<<"\nSe registro: "<<endl;
        cout<<"\tTIPO         |         CODIGO         |        NOMBRE      |      CANTIDAD   "<<endl;
        cout<<"\t"<<p.tipo<<"\t\t"<<p.codigo<<"\t\t\t"<<p.nombre<<"\t\t\t"<<p.cantidad<<endl;
        cout<<"\nEs correcto? (S/N): ";
        cin>>op;
    }while(op!='s' && op!='S');
    cout<<"\n-------- REGISTRO EXITOSO --------"<<endl;
}

int agregarProducto(Producto lista[], Producto p, int cant)//bien
{
    lista[cant]=p;
    cant=cant+1;
    return cant;
}

void mostrarProducto(Producto p)//bien
{
    cout<<"\t"<<p.tipo<<"\t\t"<<p.codigo<<"\t\t\t"<<p.nombre<<"\t\t\t"<<p.cantidad<<endl;
}

void buscarTipo(Producto lista[], int cant, string ti)//bien
{
    int i;
    cout<<"Lista de productos de tipo "<<ti<<" :"<<endl;
    cout<<"\n\tTIPO         |         CODIGO         |        NOMBRE      |      CANTIDAD   "<<endl;
    for(i=0;i<cant;i++)
    {
        if(lista[i].tipo==ti)
        {
            cout<<"\t"<<lista[i].tipo<<"\t\t"<<lista[i].codigo<<"\t\t\t"<<lista[i].nombre<<"\t\t\t"<<lista[i].cantidad<<endl;
        }
    }
}

void modificarProducto(Producto lista[], int cant)
{
    int id,i;
    char op;
    cout<<"\nIngrese ID de producto a modificar: ";
    cin>>id;

    for(i=0;i<cant;i++)
    {
        if (i==id)
        {
           cout<<"Modificar Tipo? (S/N): ";
           cin>>op;
           if(op=='S' || op=='s')
           {
                cout<<"\tIngrese Tipo: ";
                cin>>lista[i].tipo;
                cout<<"Modificar Nombre? (S/N): ";
                cin>>op;
                if(op=='S' || op=='s')
                {
                    cout<<"\tIngrese Nombre: ";
                    cin>>lista[i].nombre;
                    cout<<"Modificar Cantidad? (S/N): ";
                    cin>>op;
                    if(op=='S' || op=='s')
                    {
                        cout<<"\tIngrese Cantidad: ";
                        cin>>lista[i].cantidad;
                    }
                }
                else
                {
                    cout<<"Modificar Cantidad? (S/N): ";
                    cin>>op;
                    if(op=='S' || op=='s')
                    {
                        cout<<"\tIngrese Cantidad: ";
                        cin>>lista[i].cantidad;
                    }
                }
           }
           else
           {
                cout<<"Modificar Nombre? (S/N): ";
                cin>>op;
                if(op=='S' || op=='s')
                {
                    cout<<"\tIngrese Nombre: ";
                    cin>>lista[i].nombre;
                    cout<<"Modificar Cantidad? (S/N): ";
                    cin>>op;
                    if(op=='S' || op=='s')
                    {
                        cout<<"\tIngrese Cantidad: ";
                        cin>>lista[i].cantidad;
                    }
                }
                else
                {
                    cout<<"Modificar Cantidad? (S/N): ";
                    cin>>op;
                    if(op=='S' || op=='s')
                    {
                        cout<<"\tIngrese Cantidad: ";
                        cin>>lista[i].cantidad;
                    }
                }
            }
        }
    } 
}

void ordenarCodigo(Producto lista[], int cant) 
{
    int i,j;
    Producto aux;
    for(i=0;i<cant-1;i++) 
    {
        for(j=0;j<cant-i-1;j++) 
        {
            if(lista[j].codigo>lista[j+1].codigo) 
            {
                aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
}

int busquedaCodigo(Producto lista[],int cant,int dato)
{
    int i,pos;
    i=0;
    while(i<cant && lista[i].codigo!=dato)
    {
        i=i+1;
    }
    if(i==cant)
    {
        pos=-i;
    }
    else
    {
        pos=i;
    }
    return pos;
}