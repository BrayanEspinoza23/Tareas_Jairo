#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string Reporta;

public:
    Empleado(int _ClaveEmpleado = 0, string _Nombre = "", string _Domicilio = "", float _Sueldo = 0.0, string _Reporta = "")
        : ClaveEmpleado(_ClaveEmpleado), Nombre(_Nombre), Domicilio(_Domicilio), Sueldo(_Sueldo), Reporta(_Reporta) {}

    void Imprimir() const{
        cout<< "Clave de Empleado: "<<ClaveEmpleado<<endl;
        cout<< "Nombre: " << Nombre<<endl;
        cout<< "Domicilio: " << Domicilio <<endl;
        cout<< "Sueldo: $" << Sueldo <<endl;
        cout<< "Reporta a: " << Reporta <<endl;
    }

    bool operator==(const Empleado& otro) const{
        return ClaveEmpleado == otro.ClaveEmpleado;
    }

    int ObtenerClave() const{
        return ClaveEmpleado;
    }

    friend ostream& operator<<(ostream& os, const Empleado& emp){
        os << "Clave de Empleado: " << emp.ClaveEmpleado << endl;
        os << "Nombre: " << emp.Nombre << endl;
        os << "Domicilio: " << emp.Domicilio << endl;
        os << "Sueldo: $" << emp.Sueldo << endl;
        os << "Reporta a: " << emp.Reporta << endl;
        return os;
    }
};

template<typename T>
class ListaEstatica{
private:
    T Datos[MAX];
    int Tam;

    int Agrega(T elemento){
        if (Llena()){
            cout << "La lista esta llena. No se puede agregar." << endl;
            return -1;
        }
        Datos[Tam++] = elemento;
        return 0;
    }

    int Elimina(int posicion){
        if (Vacia()){
            cout << "La lista esta vacia. No se puede eliminar." << endl;
            return -1;
        }
        if (posicion < 0 || posicion >= Tam){
            cout << "Posicion invalida." << endl;
            return -1;
        }
        for (int i = posicion; i < Tam - 1; ++i){
            Datos[i] = Datos[i + 1];
        }
        --Tam;
        return 0;
    }

    bool Vacia() const{
        return Tam == 0;
    }

    bool Llena() const{
        return Tam == MAX;
    }

public:
    ListaEstatica() : Tam(0) {}

    void push(T elemento){
        Agrega(elemento);
    }

    void pop(){
        if (Vacia()){
            cout << "La pila esta vacia. No se puede eliminar." << endl;
        }
        else{
        Elimina(Tam - 1);
            cout << "Ultimo elemento eliminado." << endl;
        }
    }

    T top() const{
        if (Vacia()){
            cout << "La pila esta vacia." << endl;
            exit(1);
        }
        return Datos[Tam - 1];
    }

    void Muestra() const{
        if (Vacia()){
            cout << "La pila esta vacia." << endl;
            return;
        }
        for (int i = 0; i < Tam; ++i){
            cout << "Empleado en posicion " << i + 1 << ":" << endl;
            cout << Datos[i] << endl;
        }
    }
};

void Menu(ListaEstatica<Empleado>& pila){
    int opcion;
    do{
        cout << "        ********** MENU **********\n" << endl;
        cout << " 1. Push (Agregar)" << endl;
        cout << " 2. Pop (Eliminar ultimo)" << endl;
        cout << " 3. Top (Mostrar ultimo)" << endl;
        cout << " 4. Muestra (Mostrar pila completa)" << endl;
        cout << " 5. Salir\n" << endl;
        cout << "-> Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion){
        case 1:{
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
            pila.push(nuevoEmpleado);
            break;
        }
        case 2:
            pila.pop();
            break;

        case 3:{
            Empleado ultimo = pila.top();
            cout << "Ultimo empleado en la pila:\n" << ultimo << endl;
            break;
        }

        case 4:
            pila.Muestra();
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 5);
}

int main()
{
    ListaEstatica<Empleado> pila;
    pila.push(Empleado(1, "Diego Dubis", "Vicente Guerrero 789", 10200.0, "Director General"));
    pila.push(Empleado(2, "Susana Oria", "San carlitos", 10000.0, "Director General"));
    pila.push(Empleado(3, "Alan Lucio", "Patria 1000", 35000.0, "Director General"));
    pila.push(Empleado(3, "Angel Marina", "tonala 123", 59000.0, "Director General Mayor"));

    Menu(pila);

    system("pause");
    return 0;
}
