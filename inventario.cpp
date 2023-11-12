//https://drive.google.com/drive/folders/1ZPjmxjUomEtev_RO5KCptVgomTzzrsRV?usp=drive_link//
#include <iostream>
#include <string>
using namespace std;

struct Producto
{
    int tipo;
    string nombre;
    int cantidad;
    bool abastecer;
};

void leerProducto(Producto &);
int agregarProducto(Producto[],Producto,int);
void mostrarProducto(Producto);
void buscarTipo(Producto[],int,int);
void modificarProducto(Producto[], int);

int main()
{
    Producto p;
    Producto lista[100];
    char cat,cen;
    int cant=0,i,ti;

    do
    {
        system("cls");
        cout<<"------ BIENVENIDO AL SISTEMA DE CONTROL DE INVENTARIO ------"<<endl;
        cout<<"\n1. Agregar Producto"<<endl;
        cout<<"2. Modificar Producto"<<endl;
        cout<<"3. Mostrar todos los Productos"<<endl;
        cout<<"4. Buscar por tipo de producto"<<endl;
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
                    cout<<"\n1. Limpieza | 2. Aseo Personal | 3. Bebidas | 4. Snacks"<<endl;
                    cout<<"\nID |\tTIPO         |        NOMBRE      |      CANTIDAD(unidades)"<<endl;
                    for(i=0;i<cant;i++)
                    {
                        cout<<i;
                        mostrarProducto(lista[i]);
                    }
                    modificarProducto(lista, cant);
                    break;
                }
                else
                {
                    cout<<"No hay productos ingresados"<<endl;
                }               
                break;  
            case '3':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ LISTA DE PRODUCTOS INGRESADOS ------"<<endl;
                    cout<<"\n1. Limpieza | 2. Aseo Personal | 3. Bebidas | 4. Snacks"<<endl;
                    cout<<"\n\tTIPO         |        NOMBRE      |      CANTIDAD(unidades)"<<endl;
                    for(i=0;i<cant;i++)
                    {
                        mostrarProducto(lista[i]);
                    }
                    break;
                }
                else
                {
                    cout<<"No hay productos ingresados"<<endl;
                }
                break;
            case '4':
                if(cant>0)
                {
                    system("cls");
                    cout<<"\t------ BUSQUEDA POR TIPO DE PRODUCTO ------"<<endl;
                    cout<<"\n1. Limpieza | 2. Aseo Personal | 3. Bebidas | 4. Snacks"<<endl;
                    cout<<"\nIngrese tipo de producto a buscar: ";
                    cin>>ti;
                    buscarTipo(lista,cant,ti);
                    break;
                }
                else
                {
                    cout<<"No hay productos ingresados"<<endl;
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
        cout<<"\n1. Limpieza | 2. Aseo Personal | 3. Bebidas | 4. Snacks"<<endl;
        cout<<"\nIngrese Tipo de Producto: ";
        cin>>p.tipo;
        cin.ignore();
        cout<<"Ingrese Producto: ";
        getline(cin, p.nombre);
        cout<<"Ingrese Cantidad: ";
        cin>>p.cantidad;
        cout<<"\nSe registro: "<<endl;
        cout<<"\tTIPO         |        NOMBRE      |      CANTIDAD(unidades)"<<endl;
        cout<<"\t"<<p.tipo<<"\t\t"<<p.nombre<<"\t\t\t"<<p.cantidad<<endl;
        cout<<"\nEs correcto? (S/N): ";
        cin>>op;
    }while(op!='s' && op!='S');
    cout<<"\n\t----- REGISTRO EXITOSO -----"<<endl;
}

int agregarProducto(Producto lista[], Producto p, int cant)//bien
{
    lista[cant]=p;
    cant=cant+1;
    return cant;
}

void mostrarProducto(Producto p)//bien
{
    cout<<"\t"<<p.tipo<<"\t\t"<<p.nombre<<"\t\t\t"<<p.cantidad<<endl;
}

void buscarTipo(Producto lista[], int cant, int ti)//bien
{
    int i;
    cout<<"Lista de productos de tipo "<<ti<<" :"<<endl;
    cout<<"\n\tTIPO         |        NOMBRE      |      CANTIDAD(unidades)"<<endl;
    for(i=0;i<cant;i++)
    {
        if(lista[i].tipo==ti)
        {
            cout<<"\t"<<lista[i].tipo<<"\t\t"<<lista[i].nombre<<"\t\t\t"<<lista[i].cantidad<<endl;
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