/**
 * Name: Ivan Loufer
 * Course: CIS-162 Computer Science (C++)
 * Instructor: Busch
 * Lab 4: Temperature Output
 * Description: Programa that reads a series of temperatures from a file,
 * validates that they are within the range of -30 to 120, and generates 
 * a bar chart where each star (*) represents a range of 3 degrees.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // Declaración de variables
    ifstream inputFile;
    string filename;
    double temperature;

    // Pedir el nombre del archivo de entrada al usuario
    cout << "Enter the temperature file name (e.g., temperatures.txt): ";
    cin >> filename;

    // Abrir el archivo
    inputFile.open(filename);

    // Verificar si el archivo se abrió correctamente
    if (!inputFile) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    // Imprimir el encabezado de la gráfica
    cout << "\n--- TEMPERATURE CHART (EACH * = 3 DEGREES) ---\n";
    cout << "Temp \t Bar\n";
    cout << "---------------------------------------------------\n";

    // Leer el archivo valor por valor hasta el final
    while (inputFile >> temperature) {
        // Validar los valores (rango de -30 a 120)[span_0](start_span)[span_0](end_span)
        if (temperature < -30 || temperature > 120) {
            cout << setw(5) << temperature << " : [Value out of range (-30 to 120), ignored]" << endl;
            continue;
        }

        // Imprimir la temperatura a la izquierda de la barra[span_1](start_span)[span_1](end_span)
        cout << setw(5) << temperature << " | ";

        // Calcular cuántos asteriscos pintar (cada estrella representa 3 grados)[span_2](start_span)[span_2](end_span)
        int numStars = static_cast<int>((temperature + 30) / 3);

        // Imprimir los asteriscos de la barra
        for (int i = 0; i < numStars; i++) {
            cout << "*";
        }
        cout << endl;
    }

    // Cerrar el archivo
    inputFile.close();
    cout << "\nProcess completed successfully." << endl;

    return 0;
}