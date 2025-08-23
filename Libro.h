
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    double precio;
    int anoPublicacion;
    int numeroPaginas;
    bool disponibleTienda;
    string genero;

public:
    // Constructor por defecto
    Libro();

    // Constructor con parámetros
    Libro(string titulo, string autor, string isbn, double precio,
        int ano, int paginas, bool disponible, string genero);

    // Métodos set
    void setTitulo(string titulo);
    void setAutor(string autor);
    void setIsbn(string isbn);
    void setPrecio(double precio);
    void setAnoPublicacion(int ano);
    void setNumeroPaginas(int paginas);
    void setDisponibleTienda(bool disponible);
    void setGenero(string genero);

    // Métodos get
    string getTitulo() const;
    string getAutor() const;
    string getIsbn() const;
    double getPrecio() const;
    int getAnoPublicacion() const;
    int getNumeroPaginas() const;
    bool getDisponibleTienda() const;
    string getGenero() const;

    // Método para mostrar información
    void mostrarInfo() const;
};
