#include <iostream>
#include <string>
using namespace std;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string Reporta;

public:
    Empleado(int, string, string, float, string);
    void Imprimir() const;
    void CambiarDomicilio();
    void CambiarSueldo();
    void CambiarReporta();
    int ObtenerClave() const
    {
        return ClaveEmpleado;
    }

    bool operator==(const Empleado& otro) const;
    friend ostream& operator<<(ostream& os, const Empleado& emp);
    Empleado& operator+(float aumento);
};

Empleado::Empleado(int _ClaveEmpleado, string _Nombre, string _Domicilio, float _Sueldo, string _Reporta)
{
    ClaveEmpleado = _ClaveEmpleado;
    Nombre = _Nombre;
    Domicilio = _Domicilio;
    Sueldo = _Sueldo;
    Reporta = _Reporta;
}

void Empleado::Imprimir() const
{
    cout << "Clave de Empleado: " << ClaveEmpleado << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Domicilio: " << Domicilio << endl;
    cout << "Sueldo: $" << Sueldo << endl;
    cout << "Reporta a: " << Reporta << endl;
    system("pause");
    system("cls");
}

void Empleado::CambiarDomicilio()
{
    cout << "Ingrese el nuevo domicilio: ";
    cin.ignore();
    getline(cin, Domicilio);
    cout << "Domicilio actualizado a: " << Domicilio << endl;
    system("pause");
    system("cls");
}

void Empleado::CambiarSueldo()
{
    float porcentaje;
    cout << "Ingrese el porcentaje de aumento de sueldo: ";
    cin >> porcentaje;
    Sueldo += Sueldo * (porcentaje / 100);
    cout << "Sueldo actualizado a: " << Sueldo << endl;
    system("pause");
    system("cls");
}

void Empleado::CambiarReporta()
{
    cout << "Ingrese el nombre de la nueva persona a la que reporta: ";
    cin.ignore();
    getline(cin, Reporta);
    cout << "Ahora reporta a: " << Reporta << endl;
    system("pause");
    system("cls");
}

bool Empleado::operator==(const Empleado& otro) const
{
    return ClaveEmpleado == otro.ClaveEmpleado;
}

ostream& operator<<(ostream& os, const Empleado& emp)
{
    os << "Clave de Empleado: " << emp.ClaveEmpleado << endl;
    os << "Nombre: " << emp.Nombre << endl;
    os << "Domicilio: " << emp.Domicilio << endl;
    os << "Sueldo: $" << emp.Sueldo << endl;
    os << "Reporta a: " << emp.Reporta << endl;
    return os;
}

Empleado& Empleado::operator+(float aumento)
{
    Sueldo += aumento;
    return *this;
}

void Menu(Empleado& JefePlanta, Empleado& JefePersonal, Empleado& Empleado1, Empleado& Empleado2, Empleado& Empleado3)
{
    int opcion;
    int clave;
    bool encontrado;

    do
    {
        cout << "        ********** MENU **********\n\n" << endl;
        cout << "1. Imprimir informacion de un empleado" << endl;
        cout << "2. Cambiar domicilio" << endl;
        cout << "3. Cambiar sueldo" << endl;
        cout << "4. Cambiar la persona a la que reporta" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cout << "Ingrese la clave del empleado para mostrar su informacion: ";
            cin >> clave;
            encontrado = false;
            if (JefePlanta.ObtenerClave() == clave)
            {
                cout << JefePlanta;
                encontrado = true;
            }
            else if (JefePersonal.ObtenerClave() == clave)
            {
                cout << JefePersonal;
                encontrado = true;
            }
            else if (Empleado1.ObtenerClave() == clave)
            {
                cout << Empleado1;
                encontrado = true;
            }
            else if (Empleado2.ObtenerClave() == clave)
            {
                cout << Empleado2;
                encontrado = true;
            }
            else if (Empleado3.ObtenerClave() == clave)
            {
                cout << Empleado3;
                encontrado = true;
            }
            if (!encontrado)
            {
                cout << "Clave incorrecta. No se puede mostrar la informacion." << endl;
            }
            break;

        case 2:
            cout << "Ingrese la clave del empleado para cambiar su domicilio: ";
            cin >> clave;
            encontrado = false;
            if (JefePlanta.ObtenerClave() == clave)
            {
                JefePlanta.CambiarDomicilio();
                encontrado = true;
            }
            else if (JefePersonal.ObtenerClave() == clave)
            {
                JefePersonal.CambiarDomicilio();
                encontrado = true;
            }
            else if (Empleado1.ObtenerClave() == clave)
            {
                Empleado1.CambiarDomicilio();
                encontrado = true;
            }
            else if (Empleado2.ObtenerClave() == clave)
            {
                Empleado2.CambiarDomicilio();
                encontrado = true;
            }
            else if (Empleado3.ObtenerClave() == clave)
            {
                Empleado3.CambiarDomicilio();
                encontrado = true;
            }
            if (!encontrado)
            {
                cout << "Clave incorrecta. No se puede cambiar el domicilio." << endl;
            }
            break;

        case 3:
            cout << "Ingrese la clave del empleado para cambiar su sueldo: ";
            cin >> clave;
            encontrado = false;
            if (JefePlanta.ObtenerClave() == clave)
            {
                JefePlanta.CambiarSueldo();
                encontrado = true;
            }
            else if (JefePersonal.ObtenerClave() == clave)
            {
                JefePersonal.CambiarSueldo();
                encontrado = true;
            }
            else if (Empleado1.ObtenerClave() == clave)
            {
                Empleado1.CambiarSueldo();
                encontrado = true;
            }
            else if (Empleado2.ObtenerClave() == clave)
            {
                Empleado2.CambiarSueldo();
                encontrado = true;
            }
            else if (Empleado3.ObtenerClave() == clave)
            {
                Empleado3.CambiarSueldo();
                encontrado = true;
            }
            if (!encontrado)
            {
                cout << "Clave incorrecta. No se puede cambiar el sueldo." << endl;
            }
            break;

        case 4:
            cout << "Ingrese la clave del empleado para cambiar la persona a la que reporta: ";
            cin >> clave;
            encontrado = false;
            if (JefePlanta.ObtenerClave() == clave)
            {
                JefePlanta.CambiarReporta();
                encontrado = true;
            }
            else if (JefePersonal.ObtenerClave() == clave)
            {
                JefePersonal.CambiarReporta();
                encontrado = true;
            }
            else if (Empleado1.ObtenerClave() == clave)
            {
                Empleado1.CambiarReporta();
                encontrado = true;
            }
            else if (Empleado2.ObtenerClave() == clave)
            {
                Empleado2.CambiarReporta();
                encontrado = true;
            }
            else if (Empleado3.ObtenerClave() == clave)
            {
                Empleado3.CambiarReporta();
                encontrado = true;
            }
            if (!encontrado)
            {
                cout << "Clave incorrecta. No se puede cambiar la persona a la que reporta." << endl;
            }
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 5);
}

int main()
{
    Empleado JefePlanta(1, "Diego Dubis", "Vicente Guerrero 789", 10200.0, "Director General");
    Empleado JefePersonal(2, "Susana Oria", "San carlitos", 10000.0, "Director General");
    Empleado Empleado1(3, "Alan Lucio", "Patria 1000", 35000.0, "Director General");
    Empleado Empleado2(4, "Fabio Yeri", "Belenes 13", 30000.0, "Director General");
    Empleado Empleado3(5, "Angel Tona", "Tonaltecas 25", 26000.0, "Jefe de Planta");

Menu(JefePlanta, JefePersonal, Empleado1, Empleado2, Empleado3);

    system("pause");
    return 0;
}
