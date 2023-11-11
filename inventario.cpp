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
void buscarTipo(Producto,int);

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
                cout<<"OPCION 2"<<endl;
                break;  
            case '3':
                cout<<"OPCION 3"<<endl;
                break;
            case '4':
                if(cant>0)
                {
                    cout<<"Ingrese tipo de producto a buscar: "<<endl;
                    cin>>ti;
                    for(i=0;i<cant;i++)
                    {
                        buscarTipo(lista[i], ti);
                    }
                break;
                }
                else
                {
                    cout<<"Aun no hay productos registrados"<<endl;
                }
                break;
            default:
            cout<<"Categoria no valida. Intente nuevamente"<<endl;
        }
        cout<<"  "<<endl;
        system("PAUSE");
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
        cout<<"\t|1. Limpieza|2. Aseo Personal|3. Bebidas|4. Snacks|"<<endl;
        cout<<"\nIngrese Tipo de Producto: ";
        cin>>p.tipo;
        cin.ignore();
        cout<<"Ingrese Producto: ";
        getline(cin, p.nombre);
        cout<<"Ingrese Cantidad: ";
        cin>>p.cantidad;
        cout<<"Se registro: "<<endl;
        cout<<"TIPO         |        NOMBRE      |      CANTIDAD(unidades)"<<endl;
        cout<<" "<<p.tipo<<"     "<<p.nombre<<"     "<<p.cantidad<<endl;
        cout<<"Es correcto? (S/N): ";
        cin>>op;
    }while(op!='s' && op!='S');
    cout<<"---- REGISTRO EXITOSO ----"<<endl;
}

int agregarProducto(Producto lista[], Producto p, int cant)//bien
{
    lista[cant]=p;
    cant=cant+1;
    return cant;
}

void buscarTipo(Producto p,int ti)//falta
{
    system("cls");
    if(p.tipo==ti)
    {
        cout<<p.tipo<<"     "<<p.nombre<<"     "<<p.cantidad<<endl;
    }
    else
    {
        cout<<"No se encontraro productos del tipo: "<<ti<<endl;
    }
}