#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

// ==================== CONSTANTES ====================

// Tipos de Celda
const int TIPO_VACIO = 0;
const int TIPO_PARED = 1;
const int TIPO_INICIO = 2;
const int TIPO_SALIDA = 3;

// Tipos de Objeto
const int OBJ_POCION_NORMAL = 0;
const int OBJ_POCION_MAESTRA = 1;
const int OBJ_LLAVE_GENERAL = 2;
const int OBJ_LLAVE_ESPECIFICA = 3;

// Tipos de Enemigo
const int ENEMIGO_VIDA = 0;
const int ENEMIGO_TIEMPO = 1;
const int ENEMIGO_AMBOS = 2;

// ==================== ESTRUCTURAS AUXILIARES ====================

struct Posicion {
    int x, y;
    Posicion(int px = 0, int py = 0) : x(px), y(py) {}

    bool operator==(const Posicion& otra) const {
        return x == otra.x && y == otra.y;
    }
};

// ==================== PILA DE POSICIONES ====================

struct NodoPosicion {
    Posicion dato;
    NodoPosicion* siguiente;
    NodoPosicion(Posicion d) : dato(d), siguiente(nullptr) {}
};

class PilaPosiciones {
private:
    NodoPosicion* tope;
    int tamanio;

public:
    PilaPosiciones() : tope(nullptr), tamanio(0) {}

    void push(Posicion dato) {
        NodoPosicion* nuevo = new NodoPosicion(dato);
        nuevo->siguiente = tope;
        tope = nuevo;
        tamanio++;
    }

    Posicion pop() {
        if (estaVacia()) throw "Pila vacia";
        NodoPosicion* temp = tope;
        Posicion dato = temp->dato;
        tope = tope->siguiente;
        delete temp;
        tamanio--;
        return dato;
    }

    Posicion verTope() {
        if (estaVacia()) throw "Pila vacia";
        return tope->dato;
    }

    bool estaVacia() { return tope == nullptr; }
    int getTamanio() { return tamanio; }

    ~PilaPosiciones() {
        while (!estaVacia()) pop();
    }
};

// ==================== COLA DE POSICIONES ====================

class ColaPosiciones {
private:
    NodoPosicion* frente;
    NodoPosicion* final;
    int tamanio;

public:
    ColaPosiciones() : frente(nullptr), final(nullptr), tamanio(0) {}

    void encolar(Posicion dato) {
        NodoPosicion* nuevo = new NodoPosicion(dato);
        if (estaVacia()) {
            frente = final = nuevo;
        }
        else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        tamanio++;
    }

    Posicion desencolar() {
        if (estaVacia()) throw "Cola vacia";
        NodoPosicion* temp = frente;
        Posicion dato = temp->dato;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete temp;
        tamanio--;
        return dato;
    }

    Posicion verFrente() {
        if (estaVacia()) throw "Cola vacia";
        return frente->dato;
    }

    bool estaVacia() { return frente == nullptr; }
    int getTamanio() { return tamanio; }

    ~ColaPosiciones() {
        while (!estaVacia()) desencolar();
    }
};

// ==================== COLA DE STRINGS ====================

struct NodoString {
    string dato;
    NodoString* siguiente;
    NodoString(string d) : dato(d), siguiente(nullptr) {}
};

class ColaStrings {
private:
    NodoString* frente;
    NodoString* final;
    int tamanio;

public:
    ColaStrings() : frente(nullptr), final(nullptr), tamanio(0) {}

    void encolar(string dato) {
        NodoString* nuevo = new NodoString(dato);
        if (estaVacia()) {
            frente = final = nuevo;
        }
        else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        tamanio++;
    }

    string desencolar() {
        if (estaVacia()) throw "Cola vacia";
        NodoString* temp = frente;
        string dato = temp->dato;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete temp;
        tamanio--;
        return dato;
    }

    bool estaVacia() { return frente == nullptr; }
    int getTamanio() { return tamanio; }

    ~ColaStrings() {
        while (!estaVacia()) desencolar();
    }
};

// ==================== LISTA DE STRINGS ====================

class ListaStrings {
private:
    NodoString* cabeza;
    int tamanio;

public:
    ListaStrings() : cabeza(nullptr), tamanio(0) {}

    void agregar(string dato) {
        NodoString* nuevo = new NodoString(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodoString* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamanio++;
    }

    bool eliminar(string dato) {
        if (cabeza == nullptr) return false;

        if (cabeza->dato == dato) {
            NodoString* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamanio--;
            return true;
        }

        NodoString* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != dato) {
            actual = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            NodoString* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            tamanio--;
            return true;
        }
        return false;
    }

    bool contiene(string dato) {
        NodoString* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == dato) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    int getTamanio() { return tamanio; }

    void mostrar() {
        NodoString* actual = cabeza;
        cout << "[";
        while (actual != nullptr) {
            cout << actual->dato;
            if (actual->siguiente != nullptr) cout << ", ";
            actual = actual->siguiente;
        }
        cout << "]";
    }

    ~ListaStrings() {
        while (cabeza != nullptr) {
            NodoString* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// ==================== CLASE CELDA ====================

class Celda {
private:
    int tipo;
    bool visitada;
    bool tieneObjeto;
    bool tieneEnemigo;
    bool tieneTrampa;
    bool tienePuerta;
    int idPuerta;
    int idObjetoEnCelda;
    int idEnemigoEnCelda;

public:
    Celda() : tipo(TIPO_VACIO), visitada(false), tieneObjeto(false),
        tieneEnemigo(false), tieneTrampa(false), tienePuerta(false),
        idPuerta(-1), idObjetoEnCelda(-1), idEnemigoEnCelda(-1) {
    }

    void setTipo(int t) { tipo = t; }
    int getTipo() const { return tipo; }
    void setVisitada(bool v) { visitada = v; }
    bool estaVisitada() const { return visitada; }
    void setTieneObjeto(bool o) { tieneObjeto = o; }
    bool getTieneObjeto() const { return tieneObjeto; }
    void setTieneEnemigo(bool e) { tieneEnemigo = e; }
    bool getTieneEnemigo() const { return tieneEnemigo; }
    void setTieneTrampa(bool t) { tieneTrampa = t; }
    bool getTieneTrampa() const { return tieneTrampa; }
    void setTienePuerta(bool p) { tienePuerta = p; }
    bool getTienePuerta() const { return tienePuerta; }
    void setIdPuerta(int id) { idPuerta = id; }
    int getIdPuerta() const { return idPuerta; }
    void setIdObjeto(int id) { idObjetoEnCelda = id; }
    int getIdObjeto() const { return idObjetoEnCelda; }
    void setIdEnemigo(int id) { idEnemigoEnCelda = id; }
    int getIdEnemigo() const { return idEnemigoEnCelda; }
};

// ==================== CLASE ENTIDAD ====================

class Entidad {
protected:
    Posicion posicion;
    bool activa;

public:
    Entidad(Posicion pos) : posicion(pos), activa(true) {}
    virtual ~Entidad() {}

    Posicion getPosicion() const { return posicion; }
    void setPosicion(Posicion pos) { posicion = pos; }
    bool estaActiva() const { return activa; }
    void desactivar() { activa = false; }

    virtual void aplicarEfecto() = 0;
    virtual int getDanoVida() const = 0;
    virtual int getDanoTiempo() const = 0;
};

// ==================== CLASE ENEMIGO ====================

class Enemigo : public Entidad {
private:
    int tipo;
    ColaPosiciones* rutaPatrulla;
    int danoVida;
    int danoTiempo;

public:
    Enemigo(Posicion pos, int t) : Entidad(pos), tipo(t) {
        rutaPatrulla = new ColaPosiciones();

        if (tipo == ENEMIGO_VIDA) {
            danoVida = 20;
            danoTiempo = 0;
        }
        else if (tipo == ENEMIGO_TIEMPO) {
            danoVida = 0;
            danoTiempo = 10;
        }
        else {
            danoVida = 15;
            danoTiempo = 5;
        }
    }

    ~Enemigo() {
        delete rutaPatrulla;
    }

    void aplicarEfecto() {
        cout << "\n*** ENEMIGO ENCONTRADO ***";
        if (danoVida > 0) cout << "\n- Dano a vida: " << danoVida << " puntos";
        if (danoTiempo > 0) cout << "\n- Dano a tiempo: " << danoTiempo << " segundos";
    }

    int getDanoVida() const { return danoVida; }
    int getDanoTiempo() const { return danoTiempo; }
    int getTipo() const { return tipo; }

    void agregarPosicionPatrulla(Posicion pos) {
        rutaPatrulla->encolar(pos);
    }

    void patrullar() {
        if (!rutaPatrulla->estaVacia()) {
            Posicion siguiente = rutaPatrulla->desencolar();
            rutaPatrulla->encolar(posicion);
            posicion = siguiente;
        }
    }
};

// ==================== NODO Y LISTA DE ENEMIGOS ====================

struct NodoEnemigo {
    Enemigo* dato;
    NodoEnemigo* siguiente;
    NodoEnemigo(Enemigo* d) : dato(d), siguiente(nullptr) {}
};

class ListaEnemigos {
private:
    NodoEnemigo* cabeza;
    int tamanio;

public:
    ListaEnemigos() : cabeza(nullptr), tamanio(0) {}

    void agregar(Enemigo* dato) {
        NodoEnemigo* nuevo = new NodoEnemigo(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodoEnemigo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamanio++;
    }

    Enemigo* obtenerEn(int indice) {
        if (indice < 0 || indice >= tamanio) return nullptr;
        NodoEnemigo* actual = cabeza;
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }
        return actual->dato;
    }

    int getTamanio() { return tamanio; }

    ~ListaEnemigos() {
        while (cabeza != nullptr) {
            NodoEnemigo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp->dato;
            delete temp;
        }
    }
};

// ==================== CLASE OBJETO ====================

class Objeto {
private:
    int tipo;
    int valor;
    int idLlave;

public:
    Objeto(int t, int v = 0, int id = -1)
        : tipo(t), valor(v), idLlave(id) {
    }

    int getTipo() const { return tipo; }
    int getValor() const { return valor; }
    int getIdLlave() const { return idLlave; }

    string getNombre() const {
        if (tipo == OBJ_POCION_NORMAL) return "pocion";
        if (tipo == OBJ_POCION_MAESTRA) return "pocion_maestra";
        if (tipo == OBJ_LLAVE_GENERAL) return "llave";
        if (tipo == OBJ_LLAVE_ESPECIFICA) {
            return "llave_esp_" + to_string(idLlave);
        }
        return "objeto";
    }
};

// ==================== NODO Y LISTA DE OBJETOS ====================

struct NodoObjeto {
    Objeto* dato;
    NodoObjeto* siguiente;
    NodoObjeto(Objeto* d) : dato(d), siguiente(nullptr) {}
};

class ListaObjetos {
private:
    NodoObjeto* cabeza;
    int tamanio;

public:
    ListaObjetos() : cabeza(nullptr), tamanio(0) {}

    void agregar(Objeto* dato) {
        NodoObjeto* nuevo = new NodoObjeto(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodoObjeto* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamanio++;
    }

    Objeto* obtenerEn(int indice) {
        if (indice < 0 || indice >= tamanio) return nullptr;
        NodoObjeto* actual = cabeza;
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }
        return actual->dato;
    }

    int getTamanio() { return tamanio; }

    ~ListaObjetos() {
        while (cabeza != nullptr) {
            NodoObjeto* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp->dato;
            delete temp;
        }
    }
};

// ==================== LISTA DE POSICIONES ====================

class ListaPosiciones {
private:
    NodoPosicion* cabeza;
    int tamanio;

public:
    ListaPosiciones() : cabeza(nullptr), tamanio(0) {}

    void agregar(Posicion dato) {
        NodoPosicion* nuevo = new NodoPosicion(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodoPosicion* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamanio++;
    }

    int getTamanio() { return tamanio; }

    ~ListaPosiciones() {
        while (cabeza != nullptr) {
            NodoPosicion* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// ==================== CLASE JUGADOR ====================

class Jugador {
private:
    Posicion posicion;
    int vida;
    int vidaMaxima;
    ListaStrings* inventario;
    int deshacerRestantes;

public:
    Jugador(Posicion pos) : posicion(pos), vida(100), vidaMaxima(100),
        deshacerRestantes(2) {
        inventario = new ListaStrings();
    }

    ~Jugador() {
        delete inventario;
    }

    Posicion getPosicion() const { return posicion; }
    void setPosicion(Posicion pos) { posicion = pos; }

    int getVida() const { return vida; }
    void recibirDano(int dano) {
        vida -= dano;
        if (vida < 0) vida = 0;
    }

    void curar(int cantidad) {
        vida += cantidad;
        if (vida > vidaMaxima) vida = vidaMaxima;
    }

    bool estaVivo() const { return vida > 0; }

    void agregarItem(string item) {
        inventario->agregar(item);
    }

    bool tieneItem(string item) {
        return inventario->contiene(item);
    }

    bool usarItem(string item) {
        return inventario->eliminar(item);
    }

    void mostrarInventario() {
        inventario->mostrar();
    }

    int getDeshacerRestantes() const { return deshacerRestantes; }
    void usarDeshacer() { if (deshacerRestantes > 0) deshacerRestantes--; }
};

// ==================== CLASE LABERINTO ====================

class Laberinto {
private:
    Celda** matriz;
    int filas, columnas;
    Posicion inicio, salida;
    int totalCeldas;

    ListaEnemigos* enemigos;
    ListaObjetos* objetos;
    ListaPosiciones* trampas;
    int numPuertas;

    bool existeCaminoRecursivo(int x, int y, int fx, int fy, bool** visitado) {
        if (x < 0 || x >= columnas || y < 0 || y >= filas) return false;
        if (visitado[y][x]) return false;
        if (matriz[y][x].getTipo() == TIPO_PARED) return false;

        if (x == fx && y == fy) return true;

        visitado[y][x] = true;

        if (existeCaminoRecursivo(x + 1, y, fx, fy, visitado)) return true;
        if (existeCaminoRecursivo(x - 1, y, fx, fy, visitado)) return true;
        if (existeCaminoRecursivo(x, y + 1, fx, fy, visitado)) return true;
        if (existeCaminoRecursivo(x, y - 1, fx, fy, visitado)) return true;

        return false;
    }

public:
    Laberinto() {
        enemigos = new ListaEnemigos();
        objetos = new ListaObjetos();
        trampas = new ListaPosiciones();
        numPuertas = 0;
        generar();
    }

    ~Laberinto() {
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
        delete enemigos;
        delete objetos;
        delete trampas;
    }


    void generar() {
        filas = 7 + rand() % 6;
        columnas = 7 + rand() % 6;
        totalCeldas = filas * columnas;

        matriz = new Celda * [filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new Celda[columnas];
        }

        // Inicializar todo como vacío
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j].setTipo(TIPO_VACIO);
            }
        }

        // Bordes como paredes
        for (int i = 0; i < filas; i++) {
            matriz[i][0].setTipo(TIPO_PARED);
            matriz[i][columnas - 1].setTipo(TIPO_PARED);
        }
        for (int j = 0; j < columnas; j++) {
            matriz[0][j].setTipo(TIPO_PARED);
            matriz[filas - 1][j].setTipo(TIPO_PARED);
        }

        // Inicio y salida
        inicio = Posicion(1, 1);
        salida = Posicion(columnas - 2, filas - 2);
        matriz[1][1].setTipo(TIPO_INICIO);
        matriz[filas - 2][columnas - 2].setTipo(TIPO_SALIDA);

        // SOLUCIÓN MÁS RÁPIDA Y CONSISTENTE:
        // Recorrer TODAS las celdas en orden y decidir aleatoriamente cuáles son paredes

        int numParedes = (int)(totalCeldas * 0.30f);
        int paredesColocadas = 0;

        // Primera pasada: colocar paredes sin verificar (80% de las paredes)
        int paredesIniciales = (int)(numParedes * 0.8f);

        for (int i = 1; i < filas - 1 && paredesColocadas < paredesIniciales; i++) {
            for (int j = 1; j < columnas - 1 && paredesColocadas < paredesIniciales; j++) {
                if (matriz[i][j].getTipo() == TIPO_VACIO &&
                    !(i == inicio.y && j == inicio.x) &&
                    !(i == salida.y && j == salida.x)) {

                    // 40% de probabilidad de ser pared
                    if (rand() % 100 < 40) {
                        matriz[i][j].setTipo(TIPO_PARED);
                        paredesColocadas++;
                    }
                }
            }
        }

        // Segunda pasada: colocar paredes restantes VERIFICANDO cada vez
        int verificaciones = 0;
        for (int i = 1; i < filas - 1 && paredesColocadas < numParedes; i++) {
            for (int j = 1; j < columnas - 1 && paredesColocadas < numParedes; j++) {
                if (matriz[i][j].getTipo() == TIPO_VACIO &&
                    !(i == inicio.y && j == inicio.x) &&
                    !(i == salida.y && j == salida.x)) {

                    // Intentar colocar pared
                    matriz[i][j].setTipo(TIPO_PARED);
                    verificaciones++;

                    // Verificar si aún hay camino
                    if (!existeCamino(inicio, salida)) {
                        // Si bloquea, quitar la pared
                        matriz[i][j].setTipo(TIPO_VACIO);
                    }
                    else {
                        paredesColocadas++;
                    }

                    // Limitar verificaciones para evitar lentitud extrema
                    if (verificaciones > 20) {
                        break;
                    }
                }
            }
            if (verificaciones > 20) {
                break;
            }
        }

        // Verificación final ÚNICA
        if (!existeCamino(inicio, salida)) {
            // Quitar paredes hasta que haya camino
            bool caminoEncontrado = false;

            for (int i = 1; i < filas - 1 && !caminoEncontrado; i++) {
                for (int j = 1; j < columnas - 1 && !caminoEncontrado; j++) {
                    if (matriz[i][j].getTipo() == TIPO_PARED) {
                        matriz[i][j].setTipo(TIPO_VACIO);

                        // Verificar si ya hay camino
                        if (existeCamino(inicio, salida)) {
                            caminoEncontrado = true;
                        }
                    }
                }
            }
        }

        // Resto de elementos
        numPuertas = 2 + rand() % 3;
        colocarPuertas();
        colocarObjetos((int)(totalCeldas * 0.15f));
        colocarEnemigos((int)(totalCeldas * 0.10f));
        colocarTrampas((int)(totalCeldas * 0.06f));
    }
    void colocarPuertas() {
        for (int i = 0; i < numPuertas; i++) {
            int x, y;
            do {
                x = 1 + rand() % (columnas - 2);
                y = 1 + rand() % (filas - 2);
            } while (!esCeldaLibre(x, y));

            matriz[y][x].setTienePuerta(true);
            matriz[y][x].setIdPuerta(i);
        }
    }

    void colocarObjetos(int cantidad) {
        for (int i = 0; i < numPuertas; i++) {
            int x, y;
            do {
                x = 1 + rand() % (columnas - 2);
                y = 1 + rand() % (filas - 2);
            } while (!esCeldaLibre(x, y));

            matriz[y][x].setTieneObjeto(true);
            matriz[y][x].setIdObjeto(objetos->getTamanio());

            if (i < numPuertas / 2) {
                objetos->agregar(new Objeto(OBJ_LLAVE_ESPECIFICA, 0, i));
            }
            else {
                objetos->agregar(new Objeto(OBJ_LLAVE_GENERAL, 0));
            }
        }

        for (int i = numPuertas; i < cantidad; i++) {
            int x, y;
            do {
                x = 1 + rand() % (columnas - 2);
                y = 1 + rand() % (filas - 2);
            } while (!esCeldaLibre(x, y));

            matriz[y][x].setTieneObjeto(true);
            matriz[y][x].setIdObjeto(objetos->getTamanio());

            if (rand() % 3 == 0) {
                objetos->agregar(new Objeto(OBJ_POCION_MAESTRA, 60));
            }
            else {
                objetos->agregar(new Objeto(OBJ_POCION_NORMAL, 20));
            }
        }
    }

    void colocarEnemigos(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
            int x, y;
            do {
                x = 1 + rand() % (columnas - 2);
                y = 1 + rand() % (filas - 2);
            } while (!esCeldaLibre(x, y));

            matriz[y][x].setTieneEnemigo(true);
            matriz[y][x].setIdEnemigo(enemigos->getTamanio());

            int tipo = rand() % 3;
            Enemigo* nuevoEnemigo = new Enemigo(Posicion(x, y), tipo);

            nuevoEnemigo->agregarPosicionPatrulla(Posicion(x + 1, y));
            nuevoEnemigo->agregarPosicionPatrulla(Posicion(x, y + 1));
            nuevoEnemigo->agregarPosicionPatrulla(Posicion(x - 1, y));
            nuevoEnemigo->agregarPosicionPatrulla(Posicion(x, y - 1));

            enemigos->agregar(nuevoEnemigo);
        }
    }

    void colocarTrampas(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
            int x, y;
            do {
                x = 1 + rand() % (columnas - 2);
                y = 1 + rand() % (filas - 2);
            } while (!esCeldaLibre(x, y));

            matriz[y][x].setTieneTrampa(true);
            trampas->agregar(Posicion(x, y));
        }
    }

    bool esCeldaLibre(int x, int y) {
        if (x < 1 || x >= columnas - 1 || y < 1 || y >= filas - 1) return false;
        if (matriz[y][x].getTipo() != TIPO_VACIO) return false;
        if (matriz[y][x].getTieneEnemigo()) return false;
        if (matriz[y][x].getTieneObjeto()) return false;
        if (matriz[y][x].getTieneTrampa()) return false;
        if (matriz[y][x].getTienePuerta()) return false;
        if (x == inicio.x && y == inicio.y) return false;
        if (x == salida.x && y == salida.y) return false;
        return true;
    }

    bool existeCamino(Posicion origen, Posicion destino) {
        bool** visitado = new bool* [filas];
        for (int i = 0; i < filas; i++) {
            visitado[i] = new bool[columnas];
            for (int j = 0; j < columnas; j++) {
                visitado[i][j] = false;
            }
        }

        bool resultado = existeCaminoRecursivo(origen.x, origen.y,
            destino.x, destino.y, visitado);

        for (int i = 0; i < filas; i++) {
            delete[] visitado[i];
        }
        delete[] visitado;

        return resultado;
    }

    void mostrar(Posicion jugador, bool esAdmin) {
        system("cls");
        cout << "\n===== LABERINTO MAGICO =====\n\n";

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (jugador.x == j && jugador.y == i) {
                    cout << "J ";
                }
                else if (esAdmin) {
                    if (matriz[i][j].getTipo() == TIPO_PARED)
                    {
                        char a = 219; cout << a << " ";
                    }
                    else if (matriz[i][j].getTipo() == TIPO_SALIDA)
                        cout << "S ";
                    else if (matriz[i][j].getTieneEnemigo())
                        cout << "E ";
                    else if (matriz[i][j].getTieneObjeto())
                        cout << "O ";
                    else if (matriz[i][j].getTieneTrampa())
                        cout << "T ";
                    else if (matriz[i][j].getTienePuerta())
                        cout << "P ";
                    else
                        cout << ". ";
                }
                else {
                    if (matriz[i][j].getTipo() == TIPO_PARED)
                    {
                        char a = 219; cout << a << " ";
                    }
                    else if (matriz[i][j].getTipo() == TIPO_SALIDA)
                        cout << "S ";
                    else
                        cout << ". ";
                }
            }
            cout << "\n";
        }

        if (esAdmin) {
            cout << "\nLeyenda: J=Jugador #=Pared S=Salida E=Enemigo O=Objeto T=Trampa P=Puerta\n";
        }
        else {
            cout << "\nLeyenda: J=Jugador #=Pared S=Salida\n";
        }
    }

    Celda& getCelda(int x, int y) {
        return matriz[y][x];
    }

    bool movimientoValido(int x, int y) {
        if (x < 0 || x >= columnas || y < 0 || y >= filas) return false;
        if (matriz[y][x].getTipo() == TIPO_PARED) return false;
        return true;
    }

    Objeto* getObjeto(int indice) {
        return objetos->obtenerEn(indice);
    }

    Enemigo* getEnemigo(int indice) {
        return enemigos->obtenerEn(indice);
    }

    void moverEnemigos() {
        for (int i = 0; i < enemigos->getTamanio(); i++) {
            Enemigo* enemigo = enemigos->obtenerEn(i);
            if (enemigo && enemigo->estaActiva()) {
                Posicion posAnterior = enemigo->getPosicion();
                enemigo->patrullar();
                Posicion posNueva = enemigo->getPosicion();

                if (movimientoValido(posNueva.x, posNueva.y)) {
                    matriz[posAnterior.y][posAnterior.x].setTieneEnemigo(false);
                    matriz[posNueva.y][posNueva.x].setTieneEnemigo(true);
                    matriz[posNueva.y][posNueva.x].setIdEnemigo(i);
                }
            }
        }
    }

    Posicion getInicio() const { return inicio; }
    Posicion getSalida() const { return salida; }
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
};

// ==================== CLASE JUEGO ====================

class Juego {
private:
    Laberinto* laberinto;
    Jugador* jugador;
    PilaPosiciones* historial;
    ColaStrings* colaEventos;
    int turno;
    int tiempoRestante;
    int tiempoTotal;
    bool juegoActivo;

public:
    Juego() : laberinto(nullptr), jugador(nullptr), historial(nullptr),
        colaEventos(nullptr), turno(0), tiempoRestante(60),
        tiempoTotal(60), juegoActivo(false) {
        srand((unsigned)time(NULL));
    }

    ~Juego() {
        if (laberinto) delete laberinto;
        if (jugador) delete jugador;
        if (historial) delete historial;
        if (colaEventos) delete colaEventos;
    }

    void iniciar() {
        mostrarBienvenida();

        cout << "\nTiempo entre cambios de laberinto (45-200 seg, default 60): ";
        int tiempo;
        cin >> tiempo;

        if (tiempo < 45 || tiempo > 200) {
            tiempoTotal = 60;
            cout << "Valor invalido. Usando 60 segundos.\n";
        }
        else {
            tiempoTotal = tiempo;
        }
        tiempoRestante = tiempoTotal;

        cout << "\nGenerando laberinto...\n";
        Sleep(1000);

        laberinto = new Laberinto();
        Posicion posInicial = laberinto->getInicio();
        jugador = new Jugador(posInicial);
        historial = new PilaPosiciones();
        colaEventos = new ColaStrings();

        juegoActivo = true;
        turno = 1;

        bucleJuego();
    }

    void mostrarBienvenida() {
        system("cls");
        cout << "\n========================================\n";
        cout << "            LABERINTO MAGICO \n";
        cout << "========================================\n";
        cout << "\nObjetivo: Encuentra la salida!\n\n";
        cout << "Controles:\n";
        cout << "  W/A/S/D - Moverse\n";
        cout << "  U - Deshacer (max 2)\n";
        cout << "  P - Usar pocion\n";
        cout << "  V - Vista admin\n";
        cout << "\nPresiona Enter...";
        cin.ignore();
        cin.get();
    }

    void bucleJuego() {
        while (juegoActivo) {
            mostrarEstado();

            if (!jugador->estaVivo()) {
                cout << "\n*** HAS SIDO DERROTADO! ***\n";
                juegoActivo = false;
                break;
            }

            Posicion posJugador = jugador->getPosicion();
            if (posJugador == laberinto->getSalida()) {
                cout << "\n*** VICTORIA! ***\n";
                cout << "Turnos: " << turno << "\n";
                cout << "Vida restante: " << jugador->getVida() << "/100\n";
                juegoActivo = false;
                break;
            }

            procesarTurno();
            laberinto->moverEnemigos();

            turno++;
            tiempoRestante -= 5;

            if (tiempoRestante <= 0) {
                cout << "\n*** EL LABERINTO ESTA CAMBIANDO! ***\n";
                Sleep(2000);
                regenerarLaberinto();
                tiempoRestante = tiempoTotal;
            }

            procesarEventos();
        }

        cout << "\n=== FIN DEL JUEGO ===\n";
        cout << "\nPresiona Enter...";
        cin.ignore();
        cin.get();
    }

    void mostrarEstado() {
        laberinto->mostrar(jugador->getPosicion(), false);

        cout << "\n--- Estado ---\n";
        cout << "Turno: " << turno << " | Tiempo: " << tiempoRestante << "s\n";
        cout << "Posicion: (" << jugador->getPosicion().x << "," << jugador->getPosicion().y << ")";
        cout << " | Vida: " << jugador->getVida() << "/100\n";
        cout << "Inventario: ";
        jugador->mostrarInventario();
        cout << " | Deshacer: " << jugador->getDeshacerRestantes() << "\n";

        mostrarDireccionesValidas();
    }

    void mostrarDireccionesValidas() {
        Posicion pos = jugador->getPosicion();
        cout << "\nPuedes moverte: ";

        bool primera = true;
        if (laberinto->movimientoValido(pos.x, pos.y - 1)) {
            cout << "arriba(W)";
            primera = false;
        }
        if (laberinto->movimientoValido(pos.x, pos.y + 1)) {
            if (!primera) cout << ", ";
            cout << "abajo(S)";
            primera = false;
        }
        if (laberinto->movimientoValido(pos.x - 1, pos.y)) {
            if (!primera) cout << ", ";
            cout << "izquierda(A)";
            primera = false;
        }
        if (laberinto->movimientoValido(pos.x + 1, pos.y)) {
            if (!primera) cout << ", ";
            cout << "derecha(D)";
        }
        cout << "\n";
    }

    void procesarTurno() {
        cout << "\nAccion (W/A/S/D/U/P/V): ";
        char accion;
        cin >> accion;
        accion = toupper(accion);

        if (accion == 'W' || accion == 'A' || accion == 'S' || accion == 'D') {
            moverJugador(accion);
        }
        else if (accion == 'U') {
            deshacerMovimiento();
        }
        else if (accion == 'P') {
            usarPocion();
        }
        else if (accion == 'V') {
            mostrarVistaAdmin();
        }
        else {
            cout << "Accion invalida.\n";
            Sleep(1000);
        }
    }

    void moverJugador(char direccion) {
        Posicion posActual = jugador->getPosicion();
        Posicion nuevaPos = posActual;

        if (direccion == 'W') {
            nuevaPos.y--;
        }
        else if (direccion == 'S') {
            nuevaPos.y++;
        }
        else if (direccion == 'A') {
            nuevaPos.x--;
        }
        else if (direccion == 'D') {
            nuevaPos.x++;
        }

        if (!laberinto->movimientoValido(nuevaPos.x, nuevaPos.y)) {
            cout << "\n*** No puedes moverte ahi! ***\n";
            Sleep(1500);
            return;
        }

        historial->push(posActual);
        jugador->setPosicion(nuevaPos);
        cout << "\nMovido a (" << nuevaPos.x << "," << nuevaPos.y << ")\n";

        verificarEventos(nuevaPos);
        Sleep(1500);
    }

    void verificarEventos(Posicion pos) {
        Celda& celda = laberinto->getCelda(pos.x, pos.y);

        if (celda.getTieneEnemigo()) {
            int idEnemigo = celda.getIdEnemigo();
            Enemigo* enemigo = laberinto->getEnemigo(idEnemigo);

            if (enemigo && enemigo->estaActiva()) {
                enemigo->aplicarEfecto();
                jugador->recibirDano(enemigo->getDanoVida());
                tiempoRestante -= enemigo->getDanoTiempo();

                cout << "\nVida actual: " << jugador->getVida() << "/100\n";
                if (enemigo->getDanoTiempo() > 0) {
                    cout << "Tiempo restante: " << tiempoRestante << "s\n";
                }

                enemigo->desactivar();
                celda.setTieneEnemigo(false);
                colaEventos->encolar("ENEMIGO_DERROTADO");
            }
        }

        if (celda.getTieneObjeto()) {
            int idObjeto = celda.getIdObjeto();
            Objeto* objeto = laberinto->getObjeto(idObjeto);

            if (objeto) {
                string nombreObj = objeto->getNombre();
                jugador->agregarItem(nombreObj);
                cout << "\n*** OBJETO ENCONTRADO: " << nombreObj << " ***\n";
                celda.setTieneObjeto(false);
                colaEventos->encolar("OBJETO_RECOLECTADO");
            }
        }

        if (celda.getTieneTrampa()) {
            int efectoTrampa = rand() % 2;
            cout << "\n*** TRAMPA ACTIVADA! ***\n";

            if (efectoTrampa == 0) {
                int dano = 10 + rand() % 11;
                jugador->recibirDano(dano);
                cout << "Pierdes " << dano << " puntos de vida!\n";
                cout << "Vida actual: " << jugador->getVida() << "/100\n";
            }
            else {
                int tiempoPerdido = 5 + rand() % 11;
                tiempoRestante -= tiempoPerdido;
                if (tiempoRestante < 0) tiempoRestante = 0;
                cout << "Pierdes " << tiempoPerdido << " segundos!\n";
                cout << "Tiempo restante: " << tiempoRestante << "s\n";
            }

            celda.setTieneTrampa(false);
            colaEventos->encolar("TRAMPA_ACTIVADA");
        }

        if (celda.getTienePuerta()) {
            int idPuerta = celda.getIdPuerta();
            string llaveEsp = "llave_esp_" + to_string(idPuerta);

            cout << "\n*** PUERTA ENCONTRADA! ***\n";

            if (jugador->tieneItem(llaveEsp)) {
                cout << "Usas llave especifica.\n";
                jugador->usarItem(llaveEsp);
                celda.setTienePuerta(false);
            }
            else if (jugador->tieneItem("llave")) {
                cout << "Usas llave general.\n";
                jugador->usarItem("llave");
                celda.setTienePuerta(false);
            }
            else {
                cout << "Necesitas una llave! Retrocediendo...\n";
                if (!historial->estaVacia()) {
                    Posicion anterior = historial->pop();
                    jugador->setPosicion(anterior);
                }
            }
        }
    }

    void deshacerMovimiento() {
        if (jugador->getDeshacerRestantes() <= 0) {
            cout << "\nNo quedan movimientos para deshacer.\n";
            Sleep(1500);
            return;
        }

        if (historial->estaVacia()) {
            cout << "\nNo hay movimientos para deshacer.\n";
            Sleep(1500);
            return;
        }

        Posicion anterior = historial->pop();
        jugador->setPosicion(anterior);
        jugador->usarDeshacer();

        cout << "\nMovimiento deshecho!\n";
        cout << "Posicion: (" << anterior.x << "," << anterior.y << ")\n";
        cout << "Deshacer restantes: " << jugador->getDeshacerRestantes() << "\n";
        Sleep(1500);
    }

    void usarPocion() {
        cout << "\n--- Usar Pocion ---\n";

        if (jugador->tieneItem("pocion_maestra")) {
            if (jugador->getVida() <= 40) {
                jugador->curar(60);
                jugador->usarItem("pocion_maestra");
                cout << "Usaste Pocion Maestra (+60 HP)\n";
                cout << "Vida: " << jugador->getVida() << "/100\n";
            }
            else {
                cout << "Vida muy alta para Pocion Maestra.\n";
                cout << "(Requiere 40 HP o menos)\n";
            }
        }
        else if (jugador->tieneItem("pocion")) {
            if (jugador->getVida() <= 80) {
                jugador->curar(20);
                jugador->usarItem("pocion");
                cout << "Usaste Pocion Normal (+20 HP)\n";
                cout << "Vida: " << jugador->getVida() << "/100\n";
            }
            else {
                cout << "Vida muy alta para Pocion Normal.\n";
                cout << "(Requiere 80 HP o menos)\n";
            }
        }
        else {
            cout << "No tienes pociones.\n";
        }

        Sleep(1500);
    }

    void mostrarVistaAdmin() {
        cout << "\nVer vista admin? (S/N): ";
        char resp;
        cin >> resp;
        resp = toupper(resp);

        if (resp == 'S') {
            laberinto->mostrar(jugador->getPosicion(), true);
            cout << "\nPresiona Enter...";
            cin.ignore();
            cin.get();
        }
    }

    void regenerarLaberinto() {
        Posicion posActual = jugador->getPosicion();

        delete laberinto;
        laberinto = new Laberinto();

        if (!laberinto->movimientoValido(posActual.x, posActual.y)) {
            posActual = laberinto->getInicio();
            cout << "Posicion invalida. Movido al inicio.\n";
        }

        jugador->setPosicion(posActual);

        delete historial;
        historial = new PilaPosiciones();

        cout << "Nuevo laberinto generado!\n";
        Sleep(1000);
    }

    void procesarEventos() {
        while (!colaEventos->estaVacia()) {
            colaEventos->desencolar();
        }
    }
};

// ==================== FUNCION PRINCIPAL ====================

int main() {
    try {
        Juego juego;
        juego.iniciar();
    }
    catch (const char* error) {
        cout << "\nError: " << error << endl;
        system("pause");
    }
    catch (...) {
        cout << "\nError desconocido.\n";
        system("pause");
    }

    return 0;
}