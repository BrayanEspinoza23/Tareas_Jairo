#include <iostream>
#include <string>
using namespace std;

// Clase SocioClub para almacenar la información de los socios
class SocioClub
{
private:
    int numeroSocio;
    string nombre;
    string domicilio;
    string telefono;

public:
    // Constructor por defecto
    SocioClub() : numeroSocio(0), nombre(""), domicilio(""), telefono("") {}

    // Constructor parametrizado
    SocioClub(int num, string nom, string dom, string tel)
        : numeroSocio(num), nombre(nom), domicilio(dom), telefono(tel) {}

    // Sobrecarga de operadores para comparar socios por número
    bool operator<(const SocioClub& otro) const
    {
        return numeroSocio < otro.numeroSocio;
    }

    bool operator>(const SocioClub& otro) const
    {
        return numeroSocio > otro.numeroSocio;
    }

    bool operator==(const SocioClub& otro) const
    {
        return numeroSocio == otro.numeroSocio;
    }

    // getters
    int getNumeroSocio() const
    {
        return numeroSocio;
    }
    string getNombre() const
    {
        return nombre;
    }
    string getDomicilio() const
    {
        return domicilio;
    }

    //imprimir los datos del socio
    void imprimir() const
    {
        cout << "Numero de Socio: " << numeroSocio << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Telefono: " << telefono << endl;
    }
};

// Nodo para la lista simplemente ligada
struct Nodo
{
    SocioClub socio;
    Nodo* siguiente;

    Nodo(const SocioClub& s) : socio(s), siguiente(nullptr) {}
};

// Clase ListaSocios para manejar la lista simplemente ligada
class ListaSocios
{
private:
    Nodo* cabeza;

public:
    ListaSocios() : cabeza(nullptr) {}

    // Registrar un nuevo socio en orden por número de socio
    void registrarSocio(const SocioClub& nuevoSocio)
    {
        if (buscarPorNumero(nuevoSocio.getNumeroSocio()))
        {
            cout << "Ya existe un socio con ese numero." << endl;
            return;
        }

        Nodo* nuevo = new Nodo(nuevoSocio);
        if (!cabeza || cabeza->socio > nuevoSocio)
        {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }
        else
        {
            Nodo* actual = cabeza;
            while (actual->siguiente && actual->siguiente->socio < nuevoSocio)
            {
                actual = actual->siguiente;
            }
            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
        }
        cout << "Socio registrado con exito." << endl;
    }

    // Dar de baja un socio por número de socio
    void darDeBaja(int numeroSocio)
    {
        if (!cabeza)
        {
            cout << "La lista esta vacia." << endl;
            return;
        }

        if (cabeza->socio.getNumeroSocio() == numeroSocio)
        {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            cout << "Socio eliminado." << endl;
            return;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->socio.getNumeroSocio() != numeroSocio)
        {
            actual = actual->siguiente;}

        if (actual->siguiente)
        {
            Nodo* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            cout << "Socio eliminado." << endl;}
        else
        {
            cout << "No se encontro al socio." << endl;}}

    // Buscar un socio por número
    bool buscarPorNumero(int numeroSocio) const
    {
        Nodo* actual = cabeza;
        while (actual)
        {
            if (actual->socio.getNumeroSocio() == numeroSocio)
            {
                return true;}
            actual = actual->siguiente;
        }
        return false;}

    // Buscar un socio por nombre y domicilio
    void buscarPorNombreYDom(string nombre, string domicilio) const
    {
        Nodo* actual = cabeza;
        while (actual)
        {
            if (actual->socio.getNombre() == nombre && actual->socio.getDomicilio() == domicilio)
            {
                cout << "Socio encontrado:" << endl;
                actual->socio.imprimir();
                return;}
            actual = actual->siguiente;}
        cout << "No se encontro al socio." << endl;}

    // Generar reporte con todos los socios
    void generarReporte() const
    {
        if (!cabeza)
        {
            cout << "No hay socios registrados." << endl;
            return;}

        Nodo* actual = cabeza;
        while (actual)
        {
            actual->socio.imprimir();
            cout << "-------------------------" << endl;
            actual = actual->siguiente;
        }
    }

    // Calcular el total de socios registrados
    int totalSocios() const
    {
        int contador = 0;
        Nodo* actual = cabeza;
        while (actual)
        {
            contador++;
            actual = actual->siguiente;
        }
        return contador;}
};

// Menú principal para interactuar con el usuario
int main()
{
    ListaSocios lista;
    int opcion;

    do
    {
        cout << "     *** Menu Principal ***\n\n" << endl;
        cout << "1. Registrar Socio" << endl;
        cout << "2. Dar de Baja Socio" << endl;
        cout << "3. Generar Reporte" << endl;
        cout << "4. Buscar Socio por Nombre y Domicilio" << endl;
        cout << "5. Calcular Total de Socios" << endl;
        cout << "6. Salir" << endl;
        cout << "\n\n->Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int numero;
            string nombre, domicilio, telefono;
            cout << "Numero de Socio: ";
            cin >> numero;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Domicilio: ";
            getline(cin, domicilio);
            cout << "Telefono: ";
            getline(cin, telefono);

            SocioClub nuevo(numero, nombre, domicilio, telefono);
            lista.registrarSocio(nuevo);
            break;
        }
        case 2:
        {
            int numero;
            cout << "Numero de Socio a eliminar: ";
            cin >> numero;
            lista.darDeBaja(numero);
            break;
        }
        case 3:
            lista.generarReporte();
            break;
        case 4:
        {
            string nombre, domicilio;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Domicilio: ";
            getline(cin, domicilio);
            lista.buscarPorNombreYDom(nombre, domicilio);
            break;
        }
        case 5:
            cout << "Total de Socios: " << lista.totalSocios() << endl;
            break;
        case 6:
            cout << "Gracias por usar el programa:)" << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    }
    while (opcion != 6);

    return 0;
}
