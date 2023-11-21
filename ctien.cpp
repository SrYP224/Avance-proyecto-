#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Producto {
    string nombre;
    string tipo;
    unsigned int cantidad_actual;
    unsigned int cantidad_minima;
    double precio_base;
    
   
};

struct Impuesto {
    string tipo;
    double porcentaje;
    
};



main()
{
    int Max_productos = 100;
    Producto productos[Max_productos];
    Impuesto impuestos[] = {{"papeleria", 0.16}, {"supermercado", 0.04}, {"drogueria", 0.12}};
    
    double Dinero_en_caja= 0.0;
    int total_productos= 0;
    
    
cout<<"Bienvenido\n";
  
 do 
 {
    cout<<"\n=== Menu de opciones ===\n";
    cout<<" 1. Agregar producto\n";
    cout<<" 2. Vender Producto\n";
    cout<<" 3. Abastecimiento de productos \n";
    cout<<" 4. Cambiar un producto \n";
    cout<<" 5. Ver informacion de productos \n";
    cout<<" 6. Estadisticas de Ventas\n";
    cout<<" 7. Salir\n";
 int opcion;
 cout<<"Ingrese la opcion deseada: ";
 cin>>opcion;
 
 switch(opcion)
 {
    case 1:
    {
       if(total_productos < Max_productos)
       {
        cout<< "Nombre del producto: ";
        string nuevoNombre;
        cin>>nuevoNombre;
        bool nombreExistente = false;
        for(int i=0; i< total_productos; ++i)
        { 
          if(productos[i].nombre== nuevoNombre)
          {
          	nombreExistente=true;
          	break;
		  }
		}
		
		if (!nombreExistente)
		{
			productos[total_productos].nombre =nuevoNombre;
        cout<< "Tipo de Producto (papeleria, supermercado, drogueria):";
        cin>> productos[total_productos].tipo;
        
        cout<< "Cantidad Actual: ";
        cin>> productos[total_productos].cantidad_actual;
        
        cout<< "Cantidad Minima para Abastecimiento: ";
        cin>>productos[total_productos].cantidad_minima;
        
        cout<<"Precio base: ";
        cin>> productos[total_productos].precio_base;
        
        total_productos++;
        cout<< "Producto Agregado Correctamente.\n";
       }
        else
		{
		  cout<<"Ya existe un producto con el mismo nombre. No es posible agregarlo.\n";
		}
	 }
        else 
		{
           cout<<"No es posible agregar mas productos porque el limite ha sido alcanzado.\n";
        }
        break;
    } 
    
    case 2:
    {
        string nombre;
        int cantidad;
        
        cout<<" Ingrese el nombre del producto a vender: ";
	 cin>> nombre;	
	 
	 bool producto_encontrado = false;
	 for (int i= 0; i < total_productos; ++i)
	 {
	     if (productos[i].nombre == nombre) 
	        {
	            cout<< "cantidad a vender: ";
	            cin>> cantidad;
	            
	            if(productos[i].cantidad_actual >= cantidad)
	            {
	             double precio_venta = cantidad * productos[i].precio_base * (1 + impuestos[0].porcentaje);
	             productos[i].cantidad_actual -= cantidad;
	             Dinero_en_caja += precio_venta;
	             
	             cout<< "Venta realizada Exitosamente. Total a pagar: "<< precio_venta<< "\n";
	             
	            }else {
	                cout<<"No hay unidades sufucientes para vender.\n";
	            }
	            
	            producto_encontrado= true;
	            break;
	            
	        } 
	     
	 }
	 
	   if(!producto_encontrado)
	   {
         cout<<"Producto no enconmtrado.\n";
        }
        break;
    }
    
    case 3: 
    {
      string nombre;
      int cantidad;
      
      cout<< "Nombre del producto a abastecer: ";
      cin>> nombre;
      bool producto_encontrado = false;
      for (int i = 0; i < total_productos; ++i) 
      {
        if (productos[i].nombre == nombre) 
        {
         cout << "Cantidad a abastecer: ";
         cin >> cantidad;
         productos[i].cantidad_actual += cantidad;
         cout << "Abastecimiento realizado correctamente.\n";
         producto_encontrado = true;
         break;
       }
       
      }
      
      if (!producto_encontrado) 
      {
      cout << "Producto no encontrado.\n";
      
      }break;
      
    }
    
    case 4 :
    {
       string nombre;
       int indice;
       
       cout<<" Nombre del producto a cambiar: ";
       cin>> nombre;
       bool producto_encontrado = false;
       for(int i = 0; i < total_productos; ++i)
       {
           if(productos[i].nombre == nombre)
           {
               cout<<"Nuevo Nombre del producto";
               cin>>productos[i].nombre;
               
               cout<<"Nuevo tipo del producto (papeleria, supermercado, drogueria): ";
               cin>> productos[i].tipo;
               
               cout<<"Nueva Cantidad Actual: ";
               cin>> productos[i].cantidad_actual;
               
               cout<<"Nueva Cantidad minima para Abastecimiento: ";
               cin>> productos[i].cantidad_minima;
               
               cout<<"Nuevo Precio Base: ";
               cin >> productos[i].precio_base;
               
               cout << "Producto cambiado correctamente.\n";
               
               producto_encontrado = true;
             break;
           }
           
       }
       
      if (!producto_encontrado) 
      {
        cout << "Producto no encontrado.\n";
      }
      break;
        
    }
    
    case 5: 
    {
        
     for (int i = 0; i < total_productos; ++i)
     {
      cout << "Nombre: " << productos[i].nombre << ", Tipo: " << productos[i].tipo << ", Cantidad: " << productos[i].cantidad_actual << ", Precio: " << productos[i].precio_base;
     }
     break;
     
    }
    
    case 6: 
    {
      if (total_productos > 0) 
      {
        Producto mas_vendido = productos[0];
        Producto menos_vendido = productos[0];
        double total_ventas = 0.0;
        int total_unidades = 0;

        for (int i = 0; i < total_productos; ++i) 
        {
            total_ventas += productos[i].cantidad_actual * productos[i].precio_base * (1 + impuestos[0].porcentaje);
            total_unidades += productos[i].cantidad_actual;

            if ((productos[i].cantidad_minima - productos[i].cantidad_actual) > (mas_vendido.cantidad_minima - mas_vendido.cantidad_actual)) 
            {
               mas_vendido = productos[i];
            }

            if ((productos[i].cantidad_minima - productos[i].cantidad_actual) < (menos_vendido.cantidad_minima - menos_vendido.cantidad_actual)) 
            {
               menos_vendido = productos[i];
            }
        }

        cout << "Producto más vendido: " << mas_vendido.nombre << std::endl;
        cout << "Producto menos vendido: " << menos_vendido.nombre << std::endl;
        cout << "Cantidad total de dinero obtenido por las ventas: $" << total_ventas << std::endl;
        cout << "Cantidad de dinero promedio obtenido por unidad de producto vendida: $" << (total_unidades > 0 ? total_ventas / total_unidades : 0.0);
      }else 
      
      {
        cout << "No hay productos para calcular estadísticas.\n";
      }
      break;
    }
    
    case 7:
    {
     cout << "Saliendo del programa.\n";
     return 0;
	}
    default:
    {
    	cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
	}
        
    
    
 }
 
 }while(true);
 
 
 
 
 }
 
