#include <iostream>
#include <fstream>
#include  <string.h>

using namespace std;

void eliminar_estudiantes()
{

    fstream stud;
    fstream temp;

    stud.open("estudiantes.txt",ios::in);
    temp.open("temp.txt",ios::out);

    char name [25];
    char age[25];
    char phone [25];
    char a[25];

    cin.ignore();

    cout <<" \n\t Pon el numero de telefono del estudiante para eliminar :: " ;

    cin.getline(a,25);

    while(!stud.eof()) {

        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);

        if(strcmp(phone,a)==0) {
            continue;
        } else {
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }


    }

    temp.close();
    stud.close();

    stud.open("estudiantes.txt",ios::out);
    temp.open("temp.txt",ios::in);

    while(!temp.eof()) {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(age,25);
        stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    }

    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n  hecho! \n";
}
void actualizar_estudiantes()
{
    fstream stud;
    fstream temp;

    stud.open("estudiantes.txt",ios::in);
    temp.open("temp.txt",ios::out);

    char name [25];
    char age[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout << " \n\t Pon el numero de telefono para actualizar un estudiante :: ";

    cin.getline(a,25);

    while (!stud.eof()) {

        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);

        if (strcmp(phone,a)==0) {

            cout<<" \n\tPon un nuevo valor  \n ";
            cout<<" \n Numbre :: ";
            cin.getline(name, 25);
            cout<<" \n telefono :: ";
            cin.getline(phone, 25);
            cout<<" \n años :: ";

            cin.getline(age,25);

            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        } else {
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }

    }

    temp.close();
    stud.close();

    stud.open("estudiantes.txt",ios::out);
    temp.open("temp.txt",ios::in);

    while (!temp.eof()) {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(age,25);
        stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    }

    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n  Hecho! \n";
}

void mirar_todo() {
    char name [25];
    char age[25];
    char phone [25];

    fstream stud;
    stud.open("estudiantes.txt",ios::in);

    cout<< " \n\t Nombre \t Numero \t Años \n";
    while (!stud.eof()) {

        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<age<<endl;
    }
}

void buscar_estudiantes(   ) {

    fstream stud;

    stud.open("estudiantes.txt",ios::in);
    char name [25];
    char age[25];
    char phone [25];
    char a[25];

    cout << " \n Pon un numero de telefono para buscar info :: ";
    cin.ignore();
    cin.getline(a,25);

    int x=0;
    cout<< " \n\t Nombre \t Numero \t años \n";

    while (!stud.eof()) {

        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);

        if (strcmp(phone, a)==0) {
            cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<age<<endl;
            x=1;
            break;
        }

    }

    if(x==0) {
        cout<<" \n  No se encontro!\n";
    }

    stud.close();
}

void insertar_estudiantes() {

    char name [25];
    char age[25];
    char phone [25];
    fstream stud;
    stud.open("estudiantes.txt", ios::app);
    cin.ignore();
    cout <<" \n Nombre :: ";
    cin.getline(name,25);

    cout <<" \n numero :: ";
    cin.getline(phone,25);

    cout <<" \n años :: ";
    cin.getline(age,25);
    stud << name<<'|'<<phone<<'|'<<age<<'\n';
    cout << "  Hecho!";
    stud.close();
}

int main() {
    bool flag = true;

    while (flag) {
        cout << " Insertar :: 1 \n buscar :: 2 \n Poner todo :: 3 \n actualizar :: 4 \n eliminar ::  5 \n escribe tu eleccion :: ";
        int c;
        cin>>c;

        switch (c) {
            case 1 :
                insertar_estudiantes();
                break;
            case 2:
                buscar_estudiantes();
                break;
            case 3:
                mirar_todo();
                break;
            case 4 :
                actualizar_estudiantes();

                break;
            case 5 :
                eliminar_estudiantes();
                break;
            default :
                cout << " \n Escoje un numero valido \n";
                // break;
        }

        cout << " Si quieres continuar dale a la ' y ' \n ";
        char f;
        cin >> f;

        if ( f != 'y' ) {
            return 0;
        }
    }

    return 0;
}

