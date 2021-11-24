#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
 
int main()
{
   const string linea_blanco_100 = "                                                                                                    ";
   const string linea_blanco_65 = "                                                                 ";
   string opcion_str;
   int opcion;
 
   //case 1
   string usuario = "x", respuesta;
   bool ingresa = 0;
   int clave = 000000, contador2 = 0;
 
   ofstream archivo;
   string mod_cantidad, clave_producto2;
   int mas_cantidad;
   double cantidad2[10];
   int contador3 = 0;
 
   //case 2
   fstream abrir;
   string clave_arch[24];
   int precio_arch[24], cantidad_arch[24], contador4 = 0;
 
   int total_pagar = 0, cantidad;
   string respuesta2 = "No", respuesta3;
   int contador1= 0, i = 0;
   string clave_producto = "Nada", producto[i];
 
   string respuesta4 = "No", respuesta5, producto_elm;
   int cantidad3;
 
   int contador5 = 0;
   ofstream info_cliente;
   string nombre, direccion;
 
   do
   {
       cout << "          "<<char(201);
       for (int i=1; i<=100;i++)
       {
       cout << char(205);
       }
       cout << char(187)<<endl;
       // Y ahora hacemos 3 lineas hacia abajo
       for (int i=1; i<=3;i++)
       {
           cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
       }
       // Ponemos el letrero principal
       cout << "          " << char(186) << "                                         MENU PRINCIPAL                                             "<< char(186) << endl;
       // Y ahora hacemos 3 lineas hacia abajo
       for (int i=1; i<=3;i++)
       {
           cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
       }
       // Ponemos las opciones
       cout << "          " << char(186) << "      01 Acceder como administrador" << linea_blanco_65 << char(186) << endl;
       cout << "          " << char(186) << "      02 Acceder como cliente      " << linea_blanco_65 << char(186) << endl;
       cout << "          " << char(186) << "      03 Salir del programa        " << linea_blanco_65 << char(186) << endl;
       cout << "          " << char(186) << "                                   " << linea_blanco_65 << char(186) << endl;
       // Y ahora hacemos 5 lineas hacia abajo
       for (int i=1; i<=5;i++)
       {
           cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
       }
       //Ponemos la linea de abajo
       cout << "          "<<char(200);
       for (int i=1; i<=100;i++)
       {
       cout << char(205);
       }
       cout << char(188)<<endl;
 
  
       //Se abre el archivo y se muestra para que el cliente vea los productos, precios y cantidad
       ifstream archivo1("joyeria.txt");
       if (archivo1.is_open())
       {
           char c;
           while (!archivo1.eof())
           {
               archivo1.read(&c, 1);
               cout << c;
           }
       }
       archivo1.close();
 
       cout << " " << endl;
 
       //Pedimos la opción al usuario, la capturamos como string para no tener problemas si el usurio se equivoca
       cout << "                                  Opcion ";
       cin >> opcion_str;
 
       // Cambiamos de string a entero
       opcion = atoi(opcion_str.c_str());
 
       // Y utilizamos un switch para ejecutar las diferentes opciones
       switch (opcion)
       {
       case 1:
 
           //Primero se deben de declarar todos los datos, como los productos y los precios
          
           //Hacer un ciclo hasta que el acceso sea permitido o se haya equivocado 3 veces
           do
           {
               cout << "Ingrese Usuario :\n";
               cin >> usuario;
 
               cout << "Ingrese Clave :\n";
               cin >> clave;
 
               if (usuario == "Admin" and clave == 123456)
               {
                   cout << "Acceso permitido " << endl;
                   ingresa = 1;
               }
               else
               {
                   cout << "Acceso denegado :\n";
                   contador2++;
               }
           }while (ingresa == 0 and contador2 < 3);
          
           if (usuario == "Admin" and clave == 123456)
           {
               // Aqui va lo que puede hacer el admin
               archivo.open("joyeria.txt", ios::out);
 
               if (archivo.fail())
               {
                   cout << "No se pudo abrir el archivo";
               }
 
               cout << char(168) << "Desea modificar la cantidad de productos en existencia? :\n";
               cin >> mod_cantidad;
               cout << "Recuerda tomar en cuenta que se va haciendo por un orden en especifico el cambio de existencias" << endl;
               cout << "donde se empieza con el AnilloDiamantes y acaba con AretesCamelliePlata" << endl;
               if (mod_cantidad == "Si")
               {
                   do
                   {
                       cout << char(168) << "Cuantos en existencia hay del producto? :\n";
                       cin >> cantidad2[contador3++];
 
                   } while (contador3 < 8);
                   archivo << "AnilloDimante 3000 " << cantidad2[0] << endl;
                   archivo << "AnilloOroRosa 4800 " << cantidad2[1] << endl;
                   archivo << "AnilloPlata 2700 " << cantidad2[2] << endl;
                   archivo << "CollarDije 1250 " << cantidad2[3] << endl;
                   archivo << "CollarPlateado 1300 " << cantidad2[4] << endl;
                   archivo << "AretesPeqPlata 8000 " << cantidad2[5] << endl;
                   archivo << "AretesHoldPlata 3600 " << cantidad2[6] << endl;
                   archivo << "AretesCamelliePlata 5200 " << cantidad2[7] << endl;
                   cout << "La información ha sido almacenada en el archivo" << endl;
               }
               archivo.close();
           }
           break;
       case 2:
           //Aquí van todas las cosas que haría el comprador
           //Volvemos a declarar variables y hacemos un ciclo donde compran el producto
 
           abrir.open("joyeria.txt");
           do
           {
               abrir >> clave_arch[contador4];
               abrir >> precio_arch[contador4];
               abrir >> cantidad_arch[contador4];
               contador4 = contador4 + 1;
           } while (abrir.eof() != true);
 
           abrir.close();
 
           cout << char(168) << "Desea agregar un producto a su carrito de compra? :\n";
           cin >> respuesta2;
           do
           {
               if (respuesta2 == "Si")
               {
                   cout << char(168) << "Cuál producto desea agregar? :\n";
                   cin >> clave_producto;
                   cout << char(168) << "Cuál es la cantidad que quiere de ese producto? :\n";
                   cin >> cantidad;
                   //producto[i] = clave_producto;
                   //i++;
                   if (clave_producto == "AnilloDiamante")
                   {
                       total_pagar = total_pagar + 3000 * cantidad;
                       cantidad_arch[0] = cantidad_arch[0] - cantidad;
                   }
                   if (clave_producto == "AnilloOroRosa")
                   {
                       total_pagar = total_pagar + 4800 * cantidad;
                       cantidad_arch[1] = cantidad_arch[1] - cantidad;
                   }
                   if (clave_producto == "AnilloPlata")
                   {
                       total_pagar = total_pagar + 2700 * cantidad;
                       cantidad_arch[2] = cantidad_arch[2] - cantidad;
                   }           
                   if (clave_producto == "CollarDije")
                   {
                       total_pagar = total_pagar + 1250 * cantidad;
                       cantidad_arch[3] = cantidad_arch[3] - cantidad;
                   }
                   if (clave_producto == "CollarPlateado")
                   {
                       total_pagar = total_pagar + 1300 * cantidad;
                       cantidad_arch[4] = cantidad_arch[4] - cantidad;
                   }                   
                   if (clave_producto == "AretesPeqPlata")
                   {
                       total_pagar = total_pagar + 8000 * cantidad;
                       cantidad_arch[5] = cantidad_arch[5] - cantidad;
                   }                       
                   if (clave_producto == "AretesHoldPlata")
                   {
                       total_pagar = total_pagar + 3600 * cantidad;
                       cantidad_arch[6] = cantidad_arch[6] - cantidad;
                   }
                   if (clave_producto == "AretesCamillePlata")
                   {
                       total_pagar = total_pagar + 5200 * cantidad;
                       cantidad_arch[7] = cantidad_arch[7] - cantidad;
                   }   
                   cout << char(168) << "Desea agregar otro producto al carrito? :\n";
                   cin >> respuesta3;
               }
           } while (respuesta3 == "Si");
 
           cout << "El total a pagar es " << total_pagar << endl;
 
           if (total_pagar != 0)
           {
               cout << char(168) << "Desea modificar el carrito de compra? :\n";
               cin >> respuesta4;
           }
           do
           {
               if (respuesta4 == "Si")
               {
                   cout << char(168) << "Cuál producto desea eliminar? :\n";
                   cin >> producto_elm;
                   cout << char(168) << "Cuantos deseas eliminar?";
                   cin >> cantidad3;
                   if (producto_elm == "AnilloDiamante")
                   {
                       total_pagar = total_pagar - 3000 * cantidad3;
                       cantidad_arch[0] = cantidad_arch[0] + cantidad;
                   }
                   if (producto_elm == "AnilloOroRosa")
                   {
                       total_pagar = total_pagar - 4800 * cantidad3;
                       cantidad_arch[1] = cantidad_arch[1] + cantidad;
                   }       
                   if (producto_elm == "AnilloPlata")
                   {
                       total_pagar = total_pagar - 2700 * cantidad3;
                       cantidad_arch[2] = cantidad_arch[2] + cantidad;
                   }           
                   if (producto_elm == "CollarDije")
                   {
                       total_pagar = total_pagar - 1250 * cantidad3;
                       cantidad_arch[3] = cantidad_arch[3] + cantidad;
                   }               
                   if (producto_elm == "CollarPlateado")
                   {
                       total_pagar = total_pagar - 1300 * cantidad3;
                       cantidad_arch[4] = cantidad_arch[4] + cantidad;
                   }                   
                   if (producto_elm == "AretesPeqPlata")
                   {
                       total_pagar = total_pagar - 8000 * cantidad3;
                       cantidad_arch[5] = cantidad_arch[5] + cantidad;
                   }                       
                   if (producto_elm == "AretesHoldPlata")
                   {
                       total_pagar = total_pagar - 3600 * cantidad3;
                       cantidad_arch[6] = cantidad_arch[6] + cantidad;
                   }                           
                   if (producto_elm == "AretesCamillePlata")
                   {
                       total_pagar = total_pagar - 5200 * cantidad3;
                       cantidad_arch[7] = cantidad_arch[7] + cantidad;
                   }
                   cout << char(168) << "Desea eliminar otro producto? :\n";
                   cin >> respuesta5;
               }
           } while (respuesta5 == "Si");
          
           if (respuesta2 == "Si")
           {
               cout << "El total a pagar es " << total_pagar << endl;
 
           abrir.open("joyeria.txt");
           do
           {
               abrir << clave_arch[contador5] << " " << precio_arch[contador5] << " " << cantidad_arch[contador5] << endl;
               contador5 = contador5 + 1;
           } while (contador5 == 7);
 
           abrir.close();
 
               cout << "Para que su pedido llegue a casa necesitamos su nombre y dirección" << endl;
               cout << "El pago lo podrá realizar por medio de nuestro PayPal";
               cout << "y cuando nos llegue enviaremos su pedido lo antes posible" << endl;
               cout << "Favor de escribir su nombre completo sin espacios. Ej. AnaPaulaTamez :\n";
               cin >> nombre;
 
               info_cliente.open(nombre.c_str(),ios::out);
 
               cout << "Favor de escribir tu dirección, pero en lugar de espacios favor de poner un guión bajo :\n";
               cin >> direccion;
               cout << "Gracias :) \n";
 
               info_cliente << nombre << endl;
               info_cliente << direccion << endl;
 
               info_cliente.close();
               cout << "Su información ha sido guardada correctamente"<< endl;
           }
           break;
       case 3:
           cout << "Vamos a salir"<<endl;
           system("pause");
           break;
       default:
           cout << "Por favor da una opcion valida (1, 2, 3 o 4)"<<endl;
           system("pause");
           break;
       }
   }while (opcion != 3);
   return 0;
}
