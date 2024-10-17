#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string Reporta;

public:
    Empleado(int _ClaveEmpleado = 0, string _Nombre = "", string _Domicilio = "", float _Sueldo = 0.0, string _Reporta = "")
        : ClaveEmpleado(_ClaveEmpleado), Nombre(_Nombre), Domicilio(_Domicilio), Sueldo(_Sueldo), Reporta(_Reporta) {}

    void Imprimir() const {
        cout << "Clave de Empleado: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: $" << Sueldo << endl;
        cout << "Reporta a: " << Reporta << endl;
    }

    bool operator==(const Empleado& otro) const {
        return ClaveEmpleado == otro.ClaveEmpleado;
    }

    int ObtenerClave() const {
        return ClaveEmpleado;
    }

    friend ostream& operator<<(ostream& os, const Empleado& emp) {
        os << "Clave de Empleado: " << emp.ClaveEmpleado << endl;
        os << "Nombre: " << emp.Nombre << endl;
        os << "Domicilio: " << emp.Domicilio << endl;
        os << "Sueldo: $" << emp.Sueldo << endl;
        os << "Reporta a: " << emp.Reporta << endl;

        return os;

    }
};

template<typename T>
class ColaEstatica {
private:
    T Datos[MAX];
    int Frente;
    int Final;
    int Tam;

public:
    ColaEstatica() : Frente(0), Final(-1), Tam(0) {}

    bool Vacia() const {
        return Tam == 0;
    }

    bool Llena() const {
        return Tam == MAX;
    }

    void enqueue(T elemento) {
        if (Llena()) {
            cout << "La cola está llena. No se puede agregar." << endl;
        } else {
            Final = (Final + 1) % MAX;
            Datos[Final] = elemento;
        system("cls");
            Tam++;
        }
    }

    void dequeue() {
        if (Vacia()) {
            cout << "La cola está vacía. No se puede eliminar." << endl;
        } else {
            Frente = (Frente + 1) % MAX;
            Tam--;
        }
    }

    T frente() const {
        if (Vacia()) {
            cout << "La cola está vacía." << endl;
            exit(1);
        }
        return Datos[Frente];
        system("pause");
        system("cls");
    }

    void Muestra() const {
        if (Vacia()) {
            cout << "La cola está vacía." << endl;
            return;
        }
        int i = Frente;
        for (int count = 0; count < Tam; ++count) {
            cout << "Empleado en posición " << count + 1 << ":" << endl;
            cout << Datos[i] << endl;
            i = (i + 1) % MAX;
        }
        system("pause");
        system("cls");
    }

    int BusquedaLineal(const T& elem) const {
        int i = Frente;
        int count = 0;
        for(int j=0;j<Tam;++j) {
            if (Datos[i] == elem) {
                return count;}
            i = (i + 1) % MAX;
            count++;}
        return -1;}
};

void MenuCola(ColaEstatica<Empleado>& cola) {
    int opcion;
    do {
        cout << "        ********** MENU **********\n" << endl;
        cout << " 1. Enqueue (Agregar a la cola)" << endl;
        cout << " 2. Dequeue (Eliminar del frente)" << endl;
        cout << " 3. Frente (Mostrar frente)" << endl;
        cout << " 4. Muestra (Mostrar cola completa)" << endl;
        cout << " 5. Buscar empleado (Mostrar cuántos antes)" << endl;
        cout << " 6. Salir\n" << endl;
        cout << "-> Seleccione una opción: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1: {
            int clave;
            string nombre, domicilio, reporta;
            float sueldo;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el domicilio del empleado: ";
            getline(cin, domicilio);
            cout << "Ingrese el sueldo del empleado: ";
            cin >> sueldo;
            cout << "Ingrese el nombre de la persona a la que reporta: ";
            cin.ignore();
            getline(cin, reporta);
            Empleado nuevoEmpleado(clave, nombre, domicilio, sueldo, reporta);
            cola.enqueue(nuevoEmpleado);
            break;
        }
        case 2:
            cola.dequeue();
            break;

        case 3: {
            Empleado frente = cola.frente();
            cout << "Empleado en el frente de la cola:\n" << frente << endl;
            break;
        }

        case 4:
            cola.Muestra();
            break;
            case 5: {
    int clave;
    cout << "Ingrese la clave del empleado a buscar: ";
    cin >> clave;
    Empleado empBusqueda(clave);  // Solo la clave es necesaria para la búsqueda
    int resultado = cola.BusquedaLineal(empBusqueda);
    if (resultado != -1) {
        cout << "Hay " << resultado << " empleados antes de este en la cola." << endl;
    } else {
        cout << "Empleado no encontrado en la cola." << endl;
    }
    break;
}
        case 6:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion !=6);
}

int main() {
    ColaEstatica<Empleado> cola;
    cola.enqueue(Empleado(1, "Diego Dubis", "Vicente Guerrero 789", 10200.0, "Director General"));
    cola.enqueue(Empleado(2, "Susana Oria", "San carlitos", 10000.0, "Director General"));
    cola.enqueue(Empleado(3, "Alan Lucio", "Patria 1000", 35000.0, "Director General"));
    cola.enqueue(Empleado(4, "Angel Marina", "Tonala 123", 59000.0, "Director General Mayor"));

    MenuCola(cola);

    system("pause");
    return 0;
}
