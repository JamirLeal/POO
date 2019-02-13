// Jamir Leal Cota A00826275

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//  /Users/jamirleal/Desktop/dar.txt
//  /Users/jamirleal/Desktop/dar2.txt
using namespace std;

// despliega el contenido del archivo en terminal
void cat(string nombreArchivo){
    ifstream archivo;
    string texto;
    //cout << "Escriba el nombre del archivo" << endl;
    //getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in); // ABRIMOS EL ARCHIVO
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl; // MENSAJE DE QUE NO SE PUDO ABRIR
        exit(1); // SALIDA DEL PROGRAMA
    }
    while(!archivo.eof()){ // COPIAMOS Y MOSTRAMOS CASA UNA DE LAS LINEAS EN PANTALLA
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close(); // CERRAMOS EL ARCHIVO
}

//
void wc(string nombreArchivo){
    int longitud = 0;
    ifstream archivo;
    string texto; // STRING DONDE SE GUARDARA EL CONTENIDO
    //cout << "Escriba el nombre del archivo" << endl;
    //getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in); // ABRIMOS EL ARCHIVO
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl; // SI NO SE ABRE NOS MANDARA ERROR
        exit(1);
    }
    
    getline(archivo, texto, '\0');
    longitud = texto.length(); // OBTENEMOS LA LONGITUD DE CARACTERES
    cout << longitud << " caracteres" << endl; // MOSTRAMOS
    archivo.close(); // CERRAMOS EL ARCHIVO
}

void tail(string n, string nombreArchivo){
    ifstream archivo;
    string texto;
    //cout << "Escriba el nombre del archivo" << endl;
    //getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
        getline(archivo, texto, '\0'); // PASAMOS TODO EL CONTENIDO A UNA STRING
    
    int j = 0;
    int *arr;
    
    for(int i = 0; i < texto.length(); i++){ // OBTENEMOS CUANTOS RENGLONES TIENE ('\n')
        if(texto[i] == '\n'){
            j++;
        }
    }
    arr = new int [j]; // LE DAMOS ESE TAMAÑO AL ARREGLO DE LAS POSICIONES
    j=0;
    
    for(int i = 0; i < texto.length(); i++){
        if(texto[i] == '\n'){
            arr[j] = i;
            j++;
            }
    }
    int num = 0;
    for (int i = 0; i < n.length(); i++){
         num = n[i] - 48;}
    //cout << "Introduzca la linea n" << endl;
    cout << texto.substr(arr[j-num]) << endl;
    
}

void cp(string nombreArchivo, string nombreArchivo2){
    ifstream archivo;
    string texto;
    //cout << "Escriba el nombre del archivo" << endl;
    //getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    getline(archivo, texto, '\0');
    archivo.close(); // CIERRE ARCHIVO
    
    ofstream archivo2;
    //cout << "Escriba el nombre del archivo" << endl;
    //getline(cin, nombreArchivo2);
    archivo2.open(nombreArchivo2.c_str(), ios::in);
    if(archivo2.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
   
    archivo2 << texto; // COPIAMOS LA INFO DEL STRING AL ARCHIVO
    archivo2.close(); // CIERRE ARCHIVO 2
}

void grep(string nombreArchivo, string cadena){
    ifstream archivo; // DECLARACION DE ARCHIVO
    string texto;
    //cout << "Introduzca el nombre del archivo" << endl;
    //getline(cin, nombreArchivo); // NOMBRE DEL ARCHIVO
    archivo.open(nombreArchivo.c_str(), ios::in); // ABRIMOS EL ARCHIVO
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    getline(archivo, texto, '\0'); // LO COPIAMOS A UNA CADENA
    //cout << "Introduzca la cadena" << endl;
    //getline(cin, cadena); // INTRODUCIMOS LA CADENA
    int j = 0;
    int *arr;
    
    for(int i = 0; i <= texto.length(); i++){
        if((texto[i] == '\n')||(texto[i]== '\0')){
            j++;
        }
    }
    arr = new int [j]; // ARRAY DEL TAMAÑO CON LAS POSICIONES DE LOS RENGLONES ('\0')
    j=0;
    
    for(int i = 0; i <= texto.length(); i++){ // FOR QUE ASIGNA LAS POSICIONES DE CADA FINAL DEL RENGLON Y FINAL TOTAL
        if((texto[i] == '\n')||(texto[i]== '\0')){
            arr[j] = i;
            j++;
        }
    }
    string renglon; // PARA UN SOLO RENGLON
    int n = 0;
    
    for(int contR = 0; contR < j; contR++){    // FOR QUE VA CONTANDO CADA RENGLON
        renglon = texto.substr(n, arr[contR] - n);
        if (renglon.find(cadena) != std::string::npos) {  // SI SE REPITE LA PALABRA EN UN RENGLON
         cout << renglon << endl;
        }
        n = arr[contR] + 1; // ASIGNAMOS N AL SIGUIENTE INICIO DE RENGLON
        renglon = ""; // BORRAMOS EL CONTENIDO DE LA STRING
    }
    archivo.close();
}

void diff(string nombreArchivo, string nombreArchivo2){ // despliega las líneas en donde los archivos son diferentes
    
        ifstream archivo; // DECLARACION DE ARCHIVO
        string texto;
        //cout << "Introduzca el nombre del archivo" << endl;
        //getline(cin, nombreArchivo); // NOMBRE DEL ARCHIVO
        archivo.open(nombreArchivo.c_str(), ios::in); // ABRIMOS EL ARCHIVO
        if(archivo.fail()){
            cout << "No se pudo abrir el archivo" << endl;
            exit(1);
        }
        getline(archivo, texto, '\0'); // LO COPIAMOS A UNA CADENA
   
        ifstream archivo2; // DECLARACION DE ARCHIVO
        string texto2;
        //cout << "Introduzca el nombre del archivo 2" << endl;
        //getline(cin, nombreArchivo2); // NOMBRE DEL ARCHIVO
        archivo2.open(nombreArchivo2.c_str(), ios::in); // ABRIMOS EL ARCHIVO
        if(archivo2.fail()){
            cout << "No se pudo abrir el archivo 2" << endl;
            exit(1);
    }
        getline(archivo2, texto2, '\0'); // LO COPIAMOS A UNA CADENA
    
    int j = 0;
    int *arr;
    
    for(int i = 0; i <= texto.length(); i++){
        if((texto[i] == '\n')||(texto[i]== '\0')){
            j++;
        }
    }
    arr = new int [j]; // ARRAY DEL TAMAÑO CON LAS POSICIONES DE LOS RENGLONES ('\0')
    j=0;
    
    for(int i = 0; i <= texto.length(); i++){ // FOR QUE ASIGNA LAS POSICIONES DE CADA FINAL DEL RENGLON Y FINAL TOTAL
        if((texto[i] == '\n')||(texto[i]== '\0')){
            arr[j] = i;
            j++;
        }
    }
    
    int k = 0;
    int *arr2;
    
    for(int i = 0; i <= texto2.length(); i++){
        if((texto2[i] == '\n')||(texto2[i]== '\0')){
            k++;
        }
    }
    arr2 = new int [k]; // ARRAY DEL TAMAÑO CON LAS POSICIONES DE LOS RENGLONES ('\0')
    k=0;
    
    for(int i = 0; i <= texto2.length(); i++){ // FOR QUE ASIGNA LAS POSICIONES DE CADA FINAL DEL RENGLON Y FINAL TOTAL
        if((texto2[i] == '\n')||(texto2[i]== '\0')){
            arr2[k] = i;
            k++;
        }
    }
    string renglon, renglon2; // PARA UN SOLO RENGLON
    int n = 0, n2 = 0;
    for(int contR = 0; contR < j; contR++){    // FOR QUE VA CONTANDO CADA RENGLON
        renglon = texto.substr(n, arr[contR] - n);
        renglon2 = texto2.substr(n2, arr2[contR] - n2);
        
        if (renglon != renglon2) {  // SI SE REPITE LA PALABRA EN UN RENGLON
            cout << "linea " << contR << " archivo1 = " << renglon << "|" << " archivo2 = " << renglon2 << endl;
        }
        n = arr[contR] + 1;
        n2 = arr2[contR] + 1;// ASIGNAMOS N AL SIGUIENTE INICIO DE RENGLON
        renglon = "";
        renglon2 = "";// BORRAMOS EL CONTENIDO DE LA STRING
    }
    archivo.close(); // CERRAMOS LOS ARCHIVOS
    archivo2.close();
    
}

int main(int argc, const char* argv[])
{
    for(int i = 0; i < argc; i++) // EL NUMERO DE PARAMETROS QUE LEERA LA CONSOLA
    {
        cout << argv[i] << endl;
    }
    
    string utilidad = argv[1]; // LA FUNCION QUE QUEREMOS LLAMAR
    
    if(utilidad == "cat"){
             //cout << "Escriba el nombre del archivo" << endl;
             string nombreDelArchivo = argv[2];
        cat(nombreDelArchivo);
        
    }
    else if(utilidad == "wc"){
             //cout << "Escriba el nombre del archivo" << endl;
             string nombreDelArchivo = argv[2];
        wc(nombreDelArchivo);
        
    }
    else if(utilidad == "tail"){
             //cout << "Escriba las ultimas lineas a mostrar" << endl;
             string n = argv[2];
             //cout << "Escriba el nombre del archivo" << endl;
             string nombreDelArchivo = argv[3];
             tail(n, nombreDelArchivo);
        
    }
    else if(utilidad == "cp"){
            //cout << "Escriba el nombre del archivo" << endl;
            string nombreDelArchivo = argv[2];
            //cout << "Escriba el nombre del archivo 2" << endl;
            string nombreDelArchivo2 = argv[3];
            cp(nombreDelArchivo, nombreDelArchivo2);
        
    }
    else if(utilidad == "grep"){
            //cout << "Escriba el nombre del archivo" << endl;
            string nombreDelArchivo = argv[2];
            //cout << "Escriba la cadena" << endl;
            string cadena = argv[3];
        grep(nombreDelArchivo, cadena);
        
    }
    else if(utilidad == "diff"){
            //cout << "Escriba el nombre del archivo" << endl;
            string nombreDelArchivo = argv[2];
            //cout << "Escriba el nombre del archivo 2" << endl;
            string nombreDelArchivo2 = argv[3];
        diff(nombreDelArchivo, nombreDelArchivo2);
        
    }
    return 0;
}
