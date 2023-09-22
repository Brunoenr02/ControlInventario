#include <iostream>
using namespace std;
int main()
{
    char cat;
    string pl,pap,pb;
    int cl,cap,cb;

    cout<<"----- BIENVENIDO AL SISTEMA DE CONTROL DE INVENTARIO -----"<<endl;
    cout<<""<<endl;
    cout<<"Categorias Disponibles"<<endl;
    cout<<"1. Productos de Limpieza"<<endl;
    cout<<"2. Productos de Aseo Personal"<<endl;
    cout<<"3. Bebidas"<<endl;
    cout<<""<<endl;
    cout<<"Ingrese Categoria: "<<endl;
    cin>>cat;

    switch(cat)
        {
        case '1':
            do
                {
                cout<<"Ingrese Producto de Aseo Personal (0 para salir)"<<endl;
                cin>>pl;
                if(pl!="0")
                    {
                    cout<<"Ingrese Cantidad"<<endl;
                    cin>>cl;
                    }
                }
            while(pl!="0");
            break;
        case '2':
            do
                {
                cout<<"Ingrese Producto de Aseo Personal (0 para salir)"<<endl;
                cin>>pap;
                if(pap!="0")
                    {
                    cout<<"Ingrese Cantidad"<<endl;
                    cin>>cap;
                    }
                }
            while(pap!="0");
            break;
        case '3':
            do
                {
                cout<<"Ingrese Bebidas (0 para salir)"<<endl;
                cin>>pb;
                if(pb!="0")
                    {
                    cout<<"Ingrese Cantidad"<<endl;
                    cin>>cb;
                    }
                }
            while(pb!="0");
            break;
        }
    
    cout<<"Gracias"<<endl;
    
    system("PAUSE");
    return 0;
}