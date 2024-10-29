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

    void Insercion(Empleado arr[], int ultind) {
        int i = 1;
        while (i <= ultind) {
            Empleado aux = arr[i];
            int j = i;
            while (j > 0 && aux.ObtenerClave() < arr[j - 1].ObtenerClave()) {
                arr[j] = arr[j - 1];
                j--;
            }
            if (i != j) {
                arr[j] = aux;
            }
            i++;
        }
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

    bool Vacia() const { return Tam == 0; }
    bool Llena() const { return Tam == MAX; }

    void enqueue(T elemento) {
        if (Llena()) {
            cout << "La cola está llena. No se puede agregar." << endl;
        } else {
            Final = (Final + 1) % MAX;
            Datos[Final] = elemento;
            Tam++;
        }
    }

    void dequeue() {
    if (Vacia()) {
        cout << "La cola está vacía. No se puede eliminar." << endl;
    } else {
        cout << "Eliminando del frente: " << Datos[Frente] << endl;
        Frente = (Frente + 1) % MAX;  // Avanzar de forma circular
        Tam--;  // Reducir el tamaño
    }
}



    T frente() const {
    if (Vacia()) {
        cout << "La cola está vacía." << endl;
        throw runtime_error("Cola vacía");  // Mejor manejo de errores
    }
    cout << "Empleado en el frente: " << Datos[Frente] << endl;  // Diagnóstico
    return Datos[Frente];
}


    void Muestra() const {
    cout << "\nEstado de la cola:" << endl;
    cout << "Frente: " << Frente << ", Final: " << Final << ", Tamaño: " << Tam << endl;

    if (Vacia()) {
        cout << "La cola está vacía." << endl;
        return;
    }

    cout << "\n*** Empleados en la cola ***\n" << endl;
    int i = Frente;
    for (int count = 0; count < Tam; ++count) {
        cout << "Empleado en posición " << count + 1 << ":\n";
        cout << Datos[i] << endl;
        i = (i + 1) % MAX;  // Avanzar circularmente al siguiente índice
    }
}



    int BusquedaLineal(const T& elem) const {
    int i = Frente;
    int count = 0;

    for (int j = 0; j < Tam; ++j) {
        if (Datos[i] == elem) {
            cout << "Empleado encontrado en posición: " << count << endl;
            return count;
        }
        i = (i + 1) % MAX;
        count++;
    }
    cout << "Empleado no encontrado." << endl;
    return -1;
}


    // Métodos get para acceder a atributos privados
    int getFrente() const { return Frente; }
    int getTam() const { return Tam; }
    T getDato(int indice) const { return Datos[indice]; }
};

void MenuCola(ColaEstatica<Empleado>& cola) {
    int opcion;
    do {
        cout << "********** MENU **********\n\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Frente\n4. Muestra\n";
        cout << "5. Buscar empleado\n6. Ordenar por clave\n7. Salir\n\n\n";
        cout << "-> Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int clave;
            string nombre, domicilio, reporta;
            float sueldo;
            cout << "Ingrese la clave: ";
            cin >> clave;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Domicilio: "; getline(cin, domicilio);
            cout << "Sueldo: "; cin >> sueldo;
            cin.ignore();
            cout << "Reporta a: "; getline(cin, reporta);
            cola.enqueue(Empleado(clave, nombre, domicilio, sueldo, reporta));
            break;
        }
        case 2:
            break;
        case 6: {
            Empleado empleados[MAX];
            int tam = 0;
            for (int i = cola.getFrente(), count = 0; count < cola.getTam(); ++count) {
                empleados[count] = cola.getDato(i);
                i = (i + 1) % MAX;
                tam++;
            }
            empleados[0].Insercion(empleados, tam - 1);
            cout << "Empleados ordenados:\n";
            for (int i = 0; i < tam; ++i) {
                cout << empleados[i] << endl;
            }
            break;
        }
        case 7:
            cout << "Saliendo...\n";
            break;
        }
    } while (opcion != 7);
}

int main() {
    ColaEstatica<Empleado> cola;
    cola.enqueue(Empleado(1, "Diego Dubis", "Guerrero", 10200.0, "Director"));
    cola.enqueue(Empleado(2, "Susana Oria", "San carlitos", 10000.0, "Director General"));
    cola.enqueue(Empleado(3, "Alan Lucio", "Patria 1000", 35000.0, "Director General"));
    cola.enqueue(Empleado(4, "Angel Marina", "Tonala 123", 59000.0, "Director General Mayor"));

    MenuCola(cola);
    return 0;
}
