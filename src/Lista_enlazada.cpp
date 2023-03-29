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
    nuevo->siguiente = this->lista_ptr;

    this->lista_ptr = nuevo;
}

void Lista_enlazada::insertar_final(int valor){
    elemento* nuevo = new elemento;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(this->es_vacia()){
        this->ultimo = nuevo;
        this->lista_ptr = this->ultimo;
    }
    else{
        this->ultimo->siguiente = NULL;
        this->ultimo->siguiente = nuevo;
        this->ultimo = nuevo;
        this->ultimo->siguiente = NULL;
    }
}

void Lista_enlazada::insertar_intermedio(int pos, int valor){
    if(pos == 0) this->insertar_inicio(valor);
    else{

        elemento* nuevo = new elemento;
        nuevo->dato = valor;

        int i = 0;
        elemento* aux = this->lista_ptr;
        while(i < pos-1 && aux->siguiente != NULL){
            aux = aux->siguiente;
            i++;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }

}

void Lista_enlazada::eliminar_inicio(){
    if(!this->es_vacia()){
        this->lista_ptr = this->lista_ptr->siguiente;
    }
}

/*TODO*/
void Lista_enlazada::eliminar_final(){

    if(!this->es_vacia()){

        if(this->lista_ptr->siguiente == NULL){
            delete lista_ptr;
            this->lista_ptr = NULL;
            this->ultimo = NULL;

        }
        else{
            elemento* aux = this->lista_ptr;
            elemento* aux2 = aux;
            while(aux->siguiente != NULL){
                aux2 = aux;
                aux = aux->siguiente;
            }
            delete aux;
            this->ultimo = aux2;
            this->ultimo->siguiente = NULL;
        }

    }
}

void Lista_enlazada::eliminar(int pos){
    if(pos >= 0){
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

    while(i < pos && aux != NULL){
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
        while(aux->siguiente != NULL){
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


