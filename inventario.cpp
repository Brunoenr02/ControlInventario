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
void mostrarProducto(Producto);

int main()
{
    Producto p;
    Producto lista[100];
    char cat,cen;

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
                cout<<"\nSe perderan todos datos. Seguro que desea salir? (S/N): "<<endl;
                cin>>cen;
                if(cen!='S' && cen!='s')
                {
                    cat=-1;
                }
                break;
            case '1':
                leerProducto(p);
                break;
            case '2':
                cout<<"OPCION 2"<<endl;
                break;  
            case '3':
                cout<<"OPCION 3"<<endl;
                break;
            case '4':
                cout<<"OPCION 4"<<endl;
                break;
            default:
            cout<<"Categoria no valida. Intente nuevamente"<<endl;
        }
        system("PAUSE");
    }while(cat!='0');

    cout<<"FIN DEL PROGRAMA"<<endl;
    system("cls");
    return 0;
}

void leerProducto(Producto &p)
{
    char op;
    do
    {
        system("cls");
        cout<<"\t|01. Limpieza|02. Aseo Personal|03. Bebidas|04. Snacks|"<<endl;
        cout<<"\nIngrese Tipo de Producto: ";
        cin>>p.tipo;
        cin.ignore();
        cout<<"Ingrese Producto: ";
        getline(cin, p.nombre);
        cout<<"Ingrese Cantidad: ";
        cin>>p.cantidad;
        cout<<"Se registro: ";
        cout<<p.tipo<<" "<<p.nombre<<" "<<p.cantidad<<endl;
        cout<<"Es correcto? (S/N): ";
        cin>>op;
    }while(op!='s' && op!='S');
    cout<<"REGISTRO EXITOSO"<<endl;
}