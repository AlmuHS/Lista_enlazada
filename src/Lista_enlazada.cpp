#include "../include/Lista_enlazada.h"

#include <cstddef>
#include <iostream>

Lista_enlazada::Lista_enlazada()
{
    this->lista_ptr = NULL;
    this->ultimo = NULL;
}

void Lista_enlazada::insertar_inicio(int valor){
    elemento* nuevo = new elemento;
    nuevo->dato = valor;

    //Por si acaso no se ha actualizado el puntero inicial
    if(!this->es_vacia())
        nuevo->siguiente = this->lista_ptr;
    else
        nuevo->siguiente = NULL;

    this->lista_ptr = nuevo;
}

void Lista_enlazada::insertar_final(int valor){
    elemento* nuevo = new elemento;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    //Si la lista está vacía, el elemento se asigna al puntero inicial
    if(this->es_vacia()){
        this->ultimo = nuevo;
        this->lista_ptr = this->ultimo;
    }
    //Si no, se asigna al puntero final
    else{
        this->ultimo->siguiente = nuevo;
        this->ultimo = nuevo;
    }
}

void Lista_enlazada::insertar_intermedio(int pos, int valor){
    if(pos == 0) this->insertar_inicio(valor);
    else{

        elemento* nuevo = new elemento;
        nuevo->dato = valor;

        //Navegamos hasta el elemento de la posicion anterior a donde queremos insertar
        int i = 0;
        elemento* aux = this->lista_ptr;

        //Debemos comprobar que no nos estemos saliendo de la lista
        while(i < pos-1 && aux->siguiente != NULL){
            aux = aux->siguiente;
            i++;
        }

        /* Reasignamos los punteros */

        if(aux->siguiente != NULL){
            //El siguiente del nuevo será el siguiente de su antiguo anterior
            nuevo->siguiente = aux->siguiente;

            //El nuevo siguiente del anterior será el nuevo
            aux->siguiente = nuevo;
        }
    }

}

void Lista_enlazada::eliminar_inicio(){
    if(!this->es_vacia()){
        elemento *aux = this->lista_ptr;
        if(this->lista_ptr->siguiente != NULL){
            this->lista_ptr = this->lista_ptr->siguiente;
        }
        else{
            this->lista_ptr = NULL;
        }
        delete aux;
    }
    //Por si accidentalmente se ha quedado sin anular
    else
        this->lista_ptr = NULL;
}

/*TODO*/
void Lista_enlazada::eliminar_final(){

    if(!this->es_vacia()){

        //Solo queda un elemento (el inicio)
        if(this->lista_ptr->siguiente == NULL){
            delete lista_ptr;
            this->lista_ptr = NULL;
            this->ultimo = NULL;

        }
        //En otro caso
        else{
            //Navegamos hasta la penultima posicion
            elemento* aux = this->lista_ptr; //ultima posicion
            while(aux->siguiente != this->ultimo){
                aux = aux->siguiente;
            }

            //Liberamos la memoria de la ultima posicion
            delete this->ultimo;

            //Actualizamos el ultimo con el antiguo penultimo
            this->ultimo = aux;
            this->ultimo->siguiente = NULL;
        }

    }
}

void Lista_enlazada::eliminar(int pos){
    if(pos >= 0 && !this->es_vacia()){
        int i = 0;
        elemento* aux = this->lista_ptr;
        while(i < pos-1 && aux->siguiente != NULL){
            aux = aux->siguiente;
            i++;
        }
        if(aux->siguiente != NULL){
            elemento *aux2 = aux->siguiente;
            aux->siguiente = aux2->siguiente;
            delete aux2;
        }
    }

}

void Lista_enlazada::mostrar(){
    elemento *aux = this->lista_ptr;
    while(aux != NULL){
        std::cout<<aux->dato<<" ";
        aux = aux->siguiente;
    }
    std::cout<<"\n";
}

int Lista_enlazada::buscar(int valor){
    elemento* aux = this->lista_ptr;
    int pos = 0;

    while(aux->dato != valor && aux->siguiente != NULL){
        aux = aux->siguiente;
        pos++;
    }
    if(aux->siguiente != NULL) return pos;
    else return -1;

}

int Lista_enlazada::obtener(int pos){
    elemento* aux = this->lista_ptr;
    int i = 0;
    int valor;

    while(i < pos && aux->siguiente != NULL){
        aux = aux->siguiente;
        i++;
    }

    if(aux != NULL){
        valor = aux->dato;
    }
    else valor = -1;

    return valor;
}

void Lista_enlazada::modificar(int pos, int valor){
    elemento* aux = this->lista_ptr;
    int i = 0;

    while(i < pos && aux != NULL){
        aux = aux->siguiente;
        i++;
    }

    if(aux != NULL){
        aux->dato = valor;
    }
}

int Lista_enlazada::longitud(){
    elemento* aux = this->lista_ptr;
    int longitud = 0;

    if(this->lista_ptr != NULL){
        while(aux != NULL){
            aux = aux->siguiente;
            longitud++;
        }
    }
    return longitud;

}

bool Lista_enlazada::es_vacia(){
    return (this->lista_ptr == NULL || this->ultimo == NULL);
}

Lista_enlazada::~Lista_enlazada()
{
    elemento* aux = this->lista_ptr;
    while(aux != NULL){
        elemento *aux2 = aux->siguiente;
        delete aux;
        aux = aux2;
    }
}


