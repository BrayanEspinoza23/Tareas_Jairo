#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

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

    void Imprimir() const
    {
        cout << "Clave de Empleado: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: $" << Sueldo << endl;
        cout << "Reporta a: " << Reporta << endl;
    }

    bool operator==(const Empleado& otro) const
    {
        return ClaveEmpleado == otro.ClaveEmpleado;
    }

    int ObtenerClave() const
    {
        return ClaveEmpleado;
    }

    friend ostream& operator<<(ostream& os, const Empleado& emp)
    {
        os << "Clave de Empleado: " << emp.ClaveEmpleado << endl;
        os << "Nombre: " << emp.Nombre << endl;
        os << "Domicilio: " << emp.Domicilio << endl;
        os << "Sueldo: $" << emp.Sueldo << endl;
        os << "Reporta a: " << emp.Reporta << endl;
        return os;
    }
};

template<typename T>
class ListaEstatica
{
private:
    T Datos[MAX];
    int Tam;

public:
    ListaEstatica() : Tam(0) {}

    T& operator[](int indice)
    {
        if (indice < 0 || indice >= Tam)
        {
            cout << "Indice fuera de rango." << endl;
            exit(1);
        }
        return Datos[indice];
    }

    const T& operator[](int indice) const
    {
        if (indice < 0 || indice >= Tam)
        {
            cout << "Indice fuera de rango." << endl;
            exit(1);
        }
        return Datos[indice];
    }

    int Inserta(T elemento, int posicion)
    {
        if (Llena())
        {
            cout << "La lista esta llena. No se puede insertar." << endl;
            return -1;
        }
        if (posicion < 0 || posicion > Tam)
        {
            cout << "Posicion invalida." << endl;
            return -1;
        }
        for (int i = Tam; i > posicion; --i)
        {
            Datos[i] = Datos[i - 1];
        }
        Datos[posicion] = elemento;
        ++Tam;
        return 0;
    }

    int Agrega(T elemento)
    {
        if (Llena())
        {
            cout << "La lista esta llena. No se puede agregar." << endl;
            return -1;
        }
        Datos[Tam++] = elemento;
        return 0;
    }

    int Busca(T elemento)
    {
        for (int i = 0; i < Tam; ++i)
        {
            if (Datos[i] == elemento)
            {
                return i;
            }
        }
        return -1;
    }

    int Elimina(int posicion)
    {
        if (Vacia())
        {
            cout << "La lista esta vacia. No se puede eliminar." << endl;
            return -1;
        }
        if (posicion < 0 || posicion >= Tam)
        {
            cout << "Posicion invalida." << endl;
            return -1;
        }
        for (int i = posicion; i < Tam - 1; ++i)
        {
            Datos[i] = Datos[i + 1];
        }
        --Tam;
        return 0;
    }

    int Vacia() const
    {
        return Tam == 0;
    }

    int Llena() const
    {
        return Tam == MAX;
    }

    void Muestra() const
    {
        if (Vacia())
        {
            cout << "La lista esta vacia." << endl;
            return;
        }
        for (int i = 0; i < Tam; ++i)
        {
            cout << "Empleado en posicion " << i + 1 << ":" << endl;
            cout << Datos[i] << endl;
        }
        system("pause");
        system("cls");
    }

};

void Menu(ListaEstatica<Empleado>& lista)
{
    int opcion;
    int pos;
    int clave;
    do
    {
        cout << "        ********** MENU **********\n" << endl;
        cout << " 1. Agrega" << endl;
        cout << " 2. Buscar" << endl;
        cout << " 3. Elimina" << endl;
        cout << " 4. Inserta" << endl;
        cout << " 5. Muestra" << endl;
        cout << " 6. Salir\n" << endl;
        cout << "-> Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
        {
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
            lista.Agrega(nuevoEmpleado);
            break;
        }
        case 2:
        {
            cout << "Ingrese la clave del empleado a buscar: ";
            cin >> clave;
            Empleado empleadoBuscar(clave, "", "", 0.0, "");
            int indice = lista.Busca(empleadoBuscar);
            if (indice != -1)
            {
                cout << "Empleado encontrado en la posicion: " << indice << endl;
                cout << lista[indice];  // Sobrecargar el operador [] para acceder al elemento
            }
            else if (lista.Vacia())
            {
                cout << "La lista está vacía." << endl;
            }
            else
            {
                cout << "Empleado no encontrado." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Ingrese la posicion del empleado a eliminar: ";
            cin >> pos;
            lista.Elimina(pos - 1);
            break;
        }
        case 4:
        {
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
            cout << "Ingrese la posicion donde insertar el empleado: ";
            cin >> pos;
            lista.Inserta(nuevoEmpleado, pos - 1);
            break;
        }
        case 5:
            lista.Muestra();
            break;

        case 6:
            cout << "Gracias por usar el programa:))..." << endl;
            break;

        default:
            cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 6);
}

int main()
{
    ListaEstatica<Empleado> lista;
    lista.Agrega(Empleado(1, "Diego Dubis", "Vicente Guerrero 789", 10200.0, "Director General"));
    lista.Agrega(Empleado(2, "Susana Oria", "San carlitos", 10000.0, "Director General"));
    lista.Agrega(Empleado(3, "Alan Lucio", "Patria 1000", 35000.0, "Director General"));
    lista.Agrega(Empleado(4, "Fabio Yeri", "Belenes 13", 30000.0, "Director General"));
    lista.Agrega(Empleado(5, "Angel Tona", "Tonaltecas 25", 26000.0, "Jefe de Planta"));

    Menu(lista);

    system("pause");
    return 0;
}
