#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

struct elemento{
    int dato;
    elemento* siguiente;
};

class Lista_enlazada{
    elemento* lista_ptr;
    elemento* ultimo;

    public:
        Lista_enlazada();
        ~Lista_enlazada();
        void insertar_inicio(int valor);
        void insertar_final(int valor);
        void insertar_intermedio(int pos, int valor);
        void eliminar(int pos);
        void eliminar_inicio();
        void eliminar_final();
        int buscar(int valor);
        int obtener(int pos);
        void modificar(int pos, int valor);
        void mostrar();
        int longitud();
        bool es_vacia();

    protected:

    private:
};

#endif // LISTA_ENLAZADA_H
