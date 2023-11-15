#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Producto{
    string nombre;
    string tipo;
    unsigned int cantidad_actual;
    unsigned int cantidad_minima;
    double precio_base;
    
   
};

double calcularPrecioFinal(const Producto& producto) {
    double impuestos = 0.0;

    if (producto.tipo == "Papeleria") {
        impuestos = 0.16;
    } else if (producto.tipo == "Supermercado") {
        impuestos = 0.04;
    } else if (producto.tipo == "Drogueria") {
        impuestos = 0.12;
    }

    return producto.precio_base * (1 + impuestos);
}

main()
{
    vector<Producto> inventario;
    double Dinero_en_caja;
    int i=0, j=0,opcion, opc2, opc3, a=0, cantidad_producto_vender, pregunta_descuento, descuento;
cout<<"Bienvenido\n";
  
 do 
 {
    cout<<"Menu de opciones: \n";
    cout<<" 1. Informacion de productos \n";
    cout<<" 2. Vender Producto\n";
    cout<<" 3. Abastecimiento de productos \n";
    cout<<" 4. Cambiar un producto \n";
    cout<<" 5. Calcular estadísticas de ventas \n";
    cout<<" 6. Salir \n";
  
 int opcion;
 cout<<"Ingrese la opcion deseada: ";
 cin>>opcion;
 
 switch(opcion)
 {
    case 1:
    {
       cout<<"Inventario de productos: \n";
       for(Producto:inventario)
       cout<< "Nombre: "<<Producto.nombre;
       cout<< "Tipo: "<< Producto.tipo;
       cout<<"cantidad actual"<< Producto.cantidad_actual;
       cout<<"Catidad Minima para abastecimiento"<<producto.cantidad_minima;
       cout<<"Precio base: $ "<<Producto.precio_base;
       cout<<"Precio Final: $"<<Producto.precio_final
    }break;
    
    case 2:
    {
        cout<<"\nIngrese el nombre del producto a vender: "<<endl;
	 cin>>Producto.nombre;	
	 cout<<"\nIngrese el precio del producto: "<<endl;
	 cin>>Producto.nombre;
	 cout<<"\nIngrese la cantidad del producto a vender: "<<endl;
	 cin>>cantidad_producto_vender;
	
	 total = calcularPrecioFinal*cantidad_producto_vender;
	 cout<<"El total es de : "<<total;
	
     
     
    }
    
    
    case 3: 
    {
      a++;	
	  cout<<"\nIngrese el nombre del producto: "; 
	  cin>>Producto.nombre[a];	
	  cout<<"Ingrese el precio del producto: "; 
	  cin>>Producto.precio_baseo[a];
	  cout<<"\nIngrese 1 para volver al menu y 0 para salir: ";
	  cin>>opc2;
        
    }break;
    
    case 4 :
    {
        
        
    }
 };
 }while(true);
 
 
 
 
 }
 




