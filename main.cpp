#include <iostream>
#include "include/Lista_enlazada.h"


int main()
{
    Lista_enlazada lista;

    if(lista.es_vacia()) std::cout<<"La lista está vacía\n";

    std::cout<<"\nInsertando 10 elementos\n";
    for(int i = 0; i < 10; i++){
        lista.insertar_final(i*4);
    }
    lista.mostrar();

    std::cout<<"El contenido de la posicion 3 es "<<lista.obtener(3)<<std::endl;

    std::cout<<"\nInsertando valor 256 en posicion 7\n";
    lista.insertar_intermedio(7, 256);
    lista.mostrar();
    std::cout<<"\nLa longitud de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nEliminando valor de la posicion 4\n";
    lista.eliminar(4);
    lista.mostrar();

    std::cout<<"\nLa longitud de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nCambiando el contenido de la posición 3 al valor 6\n";
    lista.modificar(3, 6);
    lista.mostrar();

    std::cout<<"\nInsertando el valor 48 al inicio de la lista\n";
    lista.insertar_inicio(48);
    lista.mostrar();

    std::cout<<"\nInsertando el valor 78 en la posicion 6\n";
    lista.insertar_intermedio(6, 78);
    lista.mostrar();

    std::cout<<"\nEliminando el último elemento de la lista\n";
    lista.eliminar_final();
    lista.mostrar();

    std::cout<<"\nInsertando el numero 56 al final de la lista\n";
    lista.insertar_final(56);
    lista.mostrar();

    std::cout<<"\nInsertando el numero 54 al final de la lista\n";
    lista.insertar_final(54);
    lista.mostrar();
    std::cout<<"\nLa capacidad de la lista es "<<lista.longitud()<<"\n";

    std::cout<<"\nEliminando el último elemento de la lista\n";
    lista.eliminar_final();
    lista.mostrar();


    while(!lista.es_vacia()){
        lista.eliminar_final();
        lista.mostrar();
        std::cout<<"La capacidad de la lista es "<<lista.longitud()<<"\n";
    }
    lista.mostrar();
    if(lista.es_vacia()) std::cout<<"La lista está vacía";

    std::cout<<"\nInsertando el valor 1 en la lista vacia\n";
    lista.insertar_final(1);
    lista.mostrar();

    std::cout<<"\nInsertando 7 nuevos elementos\n";
    for(int i = 0; i < 7; i++){
        lista.insertar_final(i*4);
    }
    lista.mostrar();

    std::cout<<"La longitud de la lista es "<<lista.longitud()<<"\n";

    return 0;
}
