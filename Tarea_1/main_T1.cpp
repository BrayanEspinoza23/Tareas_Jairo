#include <iostream>
using namespace std;

class Empleado {
private:
    int ClaveEmpleado;
    char Nombre[20];
    char Domicilio[20];
    float Sueldo;
    char ReportaA[20];

public:
    void Imprime() {
        cout << "----------------------------------------" << endl;
        cout << "Clave del Empleado: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: $" << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
        cout << "----------------------------------------" << endl;
    }

    void CambiaDomic(char nuevoDomicilio[20]) {
        for (int i = 0; i < 20; i++) {
            Domicilio[i] = nuevoDomicilio[i];
        }
        cout << "Domicilio actualizado correctamente." << endl;
    }

    void CambiaReportaA(char nuevoReportaA[20]) {
        for (int i = 0; i < 20; i++) {
            ReportaA[i] = nuevoReportaA[i];
        }
        cout << "El campo 'Reporta a' ha sido actualizado correctamente." << endl;
    }

    void ActualSueldo(float porcentajeIncremento) {
        Sueldo += Sueldo * (porcentajeIncremento / 100);
        cout << "Sueldo actualizado correctamente." << endl;
    }

    void setClaveEmpleado(int clave) {
        ClaveEmpleado = clave;
    }

    void setNombre(char nombre[20]) {
        for (int i = 0; i < 20; i++) {
            Nombre[i] = nombre[i];
        }
    }

    void setDomicilio(char domicilio[20]) {
        for (int i = 0; i < 20; i++) {
            Domicilio[i] = domicilio[i];
        }
    }

    void setSueldo(float sueldo) {
        Sueldo = sueldo;
    }

    void setReportaA(char reportaA[20]) {
        for (int i = 0; i < 20; i++) {
            ReportaA[i] = reportaA[i];
        }
    }

    int getClaveEmpleado() {
        return ClaveEmpleado;
    }
};

int main() {
    Empleado JefePlanta;
    Empleado JefePersonal;

    char nombrePlanta[20] = "Carlitos Perez";
    char domicilioPlanta[20] = "calle San Agus 100";
    char reportaAPlanta[20] = "Director General";

    JefePlanta.setClaveEmpleado(1);
    JefePlanta.setNombre(nombrePlanta);
    JefePlanta.setDomicilio(domicilioPlanta);
    JefePlanta.setSueldo(5000.0);
    JefePlanta.setReportaA(reportaAPlanta);

    char nombrePersonal[20] = "Susana Oria";
    char domicilioPersonal[20] = "Calle Porai 456";
    char reportaAPersonal[20] = "Gerente de RRHH";

    JefePersonal.setClaveEmpleado(2);
    JefePersonal.setNombre(nombrePersonal);
    JefePersonal.setDomicilio(domicilioPersonal);
    JefePersonal.setSueldo(4500.0);
    JefePersonal.setReportaA(reportaAPersonal);

    int opcion;
    do {
        cout << "\n====== Menu de Opciones ======" << endl;
        cout << "1. Cambiar domicilio de un empleado" << endl;
        cout << "2. Actualizar sueldo de un empleado" << endl;
        cout << "3. Imprimir datos de un empleado" << endl;
        cout << "4. Cambiar 'Reporta a' de un empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        int clave;
        char nuevoDomicilio[20];
        char nuevoReportaA[20];
        float porcentajeIncremento;

        switch (opcion) {
        case 1:
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el nuevo domicilio: ";
            cin >> nuevoDomicilio;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.CambiaDomic(nuevoDomicilio);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.CambiaDomic(nuevoDomicilio);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
            break;

        case 2:
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el porcentaje de incremento de sueldo: ";
            cin >> porcentajeIncremento;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.ActualSueldo(porcentajeIncremento);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.ActualSueldo(porcentajeIncremento);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
            break;

        case 3:
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.Imprime();
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.Imprime();
            } else {
                cout << "Empleado no encontrado." << endl;
            }
            break;

        case 4:
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el nuevo nombre de quien reporta: ";
            cin >> nuevoReportaA;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.CambiaReportaA(nuevoReportaA);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.CambiaReportaA(nuevoReportaA);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
            break;
        }
    } while (opcion != 5);
    return 0;
}
