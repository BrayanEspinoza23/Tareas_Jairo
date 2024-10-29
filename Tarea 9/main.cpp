#include <iostream>
#include <string>
using namespace std;

// Clase Solicitud para almacenar la información de cada alumno
class Solicitud
{
private:
    string nombre;
    string carrera;
    int materiasAprobadas;
    float promedio;

public:
    // Constructor por defecto
    Solicitud() : nombre(""), carrera(""), materiasAprobadas(0), promedio(0.0) {}

    // Constructor parametrizado
    Solicitud(string n, string c, int m, float p)
        : nombre(n), carrera(c), materiasAprobadas(m), promedio(p) {}

    // Sobrecarga del operador de inserción para imprimir la solicitud
    friend ostream& operator<<(ostream& os, const Solicitud& s)
    {
        os << "Nombre: " << s.nombre << "\n"
           << "Carrera: " << s.carrera << "\n"
           << "Materias Aprobadas: " << s.materiasAprobadas << "\n"
           << "Promedio: " << s.promedio << "\n";
        return os;
    }
};

// Nodo de la lista dinámica
struct Nodo
{
    Solicitud solicitud;
    Nodo* siguiente;

    Nodo(const Solicitud& s) : solicitud(s), siguiente(nullptr) {}
};

// Clase ColaDinamica para manejar las solicitudes con la estructura FIFO
class ColaDinamica
{
private:
    Nodo* frente;
    Nodo* final;

public:
    // Constructor
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    // Verifica si la cola está vacía
    bool estaVacia() const
    {
        return frente == nullptr;
    }

    // Agregar una solicitud
    void encolar(const Solicitud& nuevaSolicitud)
    {
        Nodo* nuevo = new Nodo(nuevaSolicitud);
        if (estaVacia())
        {
            frente = final = nuevo;
        }
        else
        {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cout << "Solicitud encolada con exito.\n";
    }

    // Atender una solicitud (Desencolar)
    void atenderSolicitud()
    {
        if (estaVacia())
        {
            cout << "No hay solicitudes por atender.\n";
            return;
        }

        Nodo* temp = frente;
        cout << "Atendiendo la siguiente solicitud:\n";
        cout << temp->solicitud << endl;

        frente = frente->siguiente;
        delete temp;

        if (!frente) final = nullptr;
    }

    // Mostrar todas las solicitudes en la cola
    void mostrarSolicitudes() const
    {
        if (estaVacia())
        {
            cout << "No hay solicitudes en la cola.\n";
            return;
        }

        Nodo* actual = frente;
        while (actual)
        {
            cout << actual->solicitud << endl;
            cout << "------------------------\n";
            actual = actual->siguiente;
        }
    }

    // Destructor para liberar la memory
    ~ColaDinamica()
    {
        while (!estaVacia())
        {
            atenderSolicitud();  // Vaciar la cola al destruir el objeto
        }
    }
};

int main()
{
    ColaDinamica cola;
    int opcion;

    do
    {
        cout << "    *** Menu Principal ***\n\n";
        cout << "1. Registrar Solicitud\n";
        cout << "2. Atender Solicitud\n";
        cout << "3. Mostrar Solicitudes\n";
        cout << "4. Salir\n\n";
        cout << "-> Seleccione una opcion: ";

        cin >> opcion;


        switch (opcion)
        {
        case 1:
        {
            string nombre, carrera;
            int materiasAprobadas;
            float promedio;

            cin.ignore();
            cout << "Nombre del Alumno: ";
            getline(cin, nombre);
            cout << "Carrera: ";
            getline(cin, carrera);
            cout << "Materias Aprobadas: ";
            cin >> materiasAprobadas;
            cout << "Promedio: ";
            cin >> promedio;

            Solicitud nueva(nombre, carrera, materiasAprobadas, promedio);
            cola.encolar(nueva);

            system("pause");
            system("cls");

            break;
        }
        case 2:
            cola.atenderSolicitud();
            break;
        case 3:
            cola.mostrarSolicitudes();
            break;
        case 4:
            cout << "Gracias por usar el programa\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    }
    while (opcion != 4);

    return 0;
}
