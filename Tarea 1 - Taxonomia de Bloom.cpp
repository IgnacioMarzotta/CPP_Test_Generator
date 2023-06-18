//Tarea 1 - Paradigmas de Programacion
//Ignacio Marzotta - 23.601.779-6
//Cristobal Zapata - 19.962.025-8

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pregunta
{
    public:
        string enunciado;               //Atributo basico de enunciado
        string respuesta;               //Atributo basico de respuesta
        int tax;                        //Taxonomia asociada a la pregunta
        int tipo;                       //Tipo de pregunta (Alternativas, VoF, etc)
};

class Evaluacion
{
    public:
        vector<Pregunta> preguntas;     //Vector para almacenar las preguntas y asociarlas con una evaluacion.
        int ponderacion;                //Atributo adicional de ponderacion
};

string generarEnunciado(int tipo)     //Funcion encargada de generar el enunciado de cada pregunta basado en el tipo de pregunta
{
    switch (tipo)
    {
        case 1:                 //Preguntas de composicion y ensayo
            return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
        case 2:                 //Preguntas de respuesta corta
            return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
        case 3:                 //Preguntas de texto incompleto
            return "Duis aute irure _____ in reprehenderit in voluptate ______ esse cillum dolore eu fugiat nulla ________. Excepteur sint ________ cupidatat non proident, sunt in culpa qui ________ deserunt mollit anim id est laborum.";
        case 4:                 //Preguntas de correspondencia o emparejamiento
            return "1,2,3,4,5,6 | Duis, aute, irure, dolor, in, reprehenderit.";
        case 5:                 //Preguntas de opcion multiple
            return " 1) Duis \n 2) aute \n 3) irure \n 4) dolor \n 5) reprehenderit\n";
        case 6:                 //Preguntas de Verdadero-Falso
            return " V/F) Duis aute irure?\n V/F) dolor in reprehenderit? \n V/F) voluptate velit esse? \n V/F) cillum dolore eu? \n V/F) fugiat nulla pariatur?\n";
        case 7:                 //Preguntas de analogias/diferencias
            return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
        case 8:                 //Preguntas de interpretacion y/o elaboracion de graficos, mapas, estadisticas, etc.
            return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    }
};

string generarRespuesta(int tipo)    //Funcion encargada de generar la respuesta de cada pregunta basado en el tipo de pregunta
{
    switch (tipo)
    {
    case 1:                 //Preguntas de composicion y ensayo
        return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    case 2:                 //Preguntas de respuesta corta
        return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.";
    case 3:                 //Preguntas de texto incompleto
        return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    case 4:                 //Preguntas de correspondencia o emparejamiento
        return "1) Duis\n 2) aute \n 3) irure \n 4) dolor \n 5) in \n 6) reprehenderit \n";
    case 5:                 //Preguntas de opcion multiple
        return "2,4,5";
    case 6:                 //Preguntas de Verdadero-Falso
        return "V,V,F,F,V";
    case 7:                 //Preguntas de analogias/diferencias
        return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    case 8:                 //Preguntas de interpretacion y/o elaboracion de graficos, mapas, estadisticas, etc.
        return "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    }
};

Evaluacion llenarEvaluacion(Evaluacion evaluacion, int totalPreguntas)  //Funcion encargada de llenar el vector de preguntas utilizando el input del usuario
{
    cout << "(Recuerde que los niveles taxonomicos de Bloom van desde 1. Recordar hasta 6. Crear)\n";
    for (int i = 0; i < totalPreguntas; i++)                     //Ciclo de generacion de preguntas
    {
        Pregunta pregunta;                                      //Definir la instancia de la nueva pregunta
        cout << "Taxonomia de pregunta " << i+1 << ": ";        //Mostrar mensaje de solicitud de taxonomia
        cin >> pregunta.tax;                                    //Pedir taxonomia asociada a la pregunta
        while((int)pregunta.tax > 6 || (int)pregunta.tax < 1)   //Breve check de input para asegurarse que el usuario ingrese un nivel taxonomico valido (entre 1 y 6)
        {
            cout << "\n Seleccione un nivel taxonomico correcto. \n";  //Mostrar mensaje de taxonomia incorrecta
            cout << "Taxonomia de pregunta " << i+1 << ": ";           //Mostrar mensaje de solicitud de taxonomia
            cin >> pregunta.tax;                                       //Pedir taxonomia asociada a la pregunta
        }

        pregunta.tipo = rand() % 8 + 1;                         //Asignar un tipo de pregunta aleatorio. Luego afecta al enunciado y respuesta.
        pregunta.enunciado = generarEnunciado(pregunta.tipo);   //Generar el enunciado en base al tipo de pregunta.
        pregunta.respuesta = generarRespuesta(pregunta.tipo);   //Generar la respuesta en base al tipo de pregunta.
        evaluacion.preguntas.push_back(pregunta);               //Usa push_back para agregar el nuevo elemento al final del vector.
    }

    return evaluacion;
};

void mostrarEvaluacion(Evaluacion evaluacion)   //Funcion encargada de mostrar la evaluacion generada, utilizando arrays de strings para dar mas detalles al usuario.
{
    string nivelesTax[6] = {"1) Recordar.","2) Entender.","3) Aplicar.","4) Analizar.","5) Evaluar.","6) Crear."};
    string tiposPreg[8] = {"Composicion y ensayo","Respuesta corta","Texto incompleto","Corrrespondencia o emparejamiento","Seleccion multiple","Verdadero-Falso","Analogias/diferencias","interpretacion y/o elaboracion de graficos, mapas, estadisticas, etc."};
    cout << "\n ------ Nueva evaluacion ------ \n ----- Ponderacion de " << evaluacion.ponderacion << "% ------\n";
    for (int i = 0; i < evaluacion.preguntas.size(); i++) 
    {
        Pregunta pregunta = evaluacion.preguntas[i];
        cout << "================\nPregunta " << i+1 << ":" << endl;
        cout << "Nivel taxonomico: " << nivelesTax[pregunta.tax-1] << endl;
        cout << "Tipo de pregunta: " << tiposPreg[pregunta.tipo-1] << endl << endl;
        cout << "Enunciado:\n" << pregunta.enunciado << endl;              
        cout << "Respuesta:\n" << pregunta.respuesta << endl;              
    }
};

int main()
{
    Evaluacion evaluacion;                                          //Crear nueva evaluacion.
    int totalPreguntas;                                             //Definir variable para total de preguntas

    cout << "Ingrese la ponderacion de la evaluacion (%): ";        //Mostrar mensaje de ponderacion
    cin >> evaluacion.ponderacion;                                  //Pedir ponderacion de evaluacion
    while((int)evaluacion.ponderacion > 100 || (int)evaluacion.ponderacion < 1)     //Breve check de input para la ponderacion, de esta manera, el usuario solo puede ingresar un % entre 1% y 100%.
    {
        cout << "\n Introduzca una ponderacion correcta: ";
        cin >> evaluacion.ponderacion;
    }

    cout << "Ingrese la cantidad de preguntas de la evaluacion: ";  //Mostrar mensaje de preguntas
    cin >> totalPreguntas;                                          //Pedir cantidad de preguntas

    evaluacion = llenarEvaluacion(evaluacion, totalPreguntas);      //Llenar evaluacion
    mostrarEvaluacion(evaluacion);                                  //Mostrar evaluacion

    return 0;
}