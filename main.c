#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//Estructuras
struct Gerente{
    char nombre[30];
    char id[20];
    char psssword[20];
}gerente;
struct Empleados{
    char nombre[20];
    char app[20];
    char apm[20];
    char area[20];
    char usuario[20];
    char id[20];
    char password[20];
    int ventasRealisadas;
    float totalVendido;
}empleados[50];
struct Productos{
    char id[20];
    char nombre[20];
    char provedor[20];
    float precio;
    int existencia;
}productos[50];
struct DetalleDeVenta{
    char idVenta[20];
    char idProducto[20];
    int cantidad;
    float total;
};
struct Ventas{
    char idVentas[20];
    char idEmpleado[20];
    int dia;
    int mes;
    int anio;
    struct DetalleDeVenta detalleDeVenta;
}ventas[100];
//Variables Globales
size_t contadorEmpleados=0,contadorProductos=0,contadorSalir=0,contadorVentas=0,empleado,consecutivoProductos=0;
size_t consecutivoEmp=0;
//Prototipos de funciones
int Login();
void menuGerente();
void menuEmpleados();
//Funciones Memu Gerente
void nuevoEmpleado();
void mostrarEmpleados();
void buscarEmpleadoCodigo();
void buscarEmpleadoApp();
void modificarInformacionEmpleado();
void eliminarEmpleado();
void reportesVentas();
void totalDeTodo();
//Reportes de venta
void cantidadVentasEmpleados();
void totalVendidoEmpleados();
void totalVendidoDia();
void surtirProductos();
//Funciones Gerente con parametros y retorno
int validarID(char[]);
int validarUsuario(char[]);
//Funciones Empleados
void productosEmpleados();
void ventaProductos();
void capturarProductos();
void mostrarProductos();
void buscarProductoProvedor();
void buscarProductoID();
void modificarProducto();
void eliminarProducto();
//funciones con parametros y retorno
int validarIDproducto(char[]);
//Funcion principal
int main(){
    system("color 0D");
    strcpy(gerente.nombre,"Zoila Liliana");
    strcpy(gerente.id, "GERENTE");
    strcpy(gerente.psssword,"1212");
    int login;
    char opc;
    do{
        do{
            fflush(stdin);
            printf("\t\t\tMenu\n");
            printf("1.Iniciar\n2.Salir\nElige una opcion : ");
            scanf("%c",&opc);
            if(opc=='2'){
                printf("Adios Vaquero\n");
                return 0;
            }
            if(opc!='2'&&opc!='1')
                contadorSalir++;
            if(contadorSalir==3)
                return 0;
        }while(opc!='1');
        switch (login=Login()) {
            case 1:
                menuGerente();
                login=-1;
                break;
            case 2:
                menuEmpleados();
                login=-1;
                break;
            default:
                if(contadorSalir==2){
                    return 0;
                }
                printf("Usuario no corecto\n");
                contadorSalir++;
                break;
        }
    }while(login==-1);
    return 0;
}
int Login(){
    char aux[20];
    int i;
    fflush(stdin);
    system("cls");
    printf("\t\t\tLOGIN\n");
    printf("________________________\n");
    printf("|  Usuario :            |\n");
    printf("|_______________________|\n");
    scanf("%s",aux);
    fflush(stdin);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    //printf("%s",aux);
    if(strcmp(aux,gerente.id)==0){
        system("cls");
        printf("\t\t\tLOGIN\n");
        printf("________________________\n");
        printf("|  Gerente Password :   |\n");
        printf("|_______________________|\n");
        scanf("%s",aux);
        for (i=0;aux[i];i++)
            aux[i]=toupper(aux[i]);
        fflush(stdin);
        if(strcmp(aux,gerente.psssword)==0){
            return 1;
        }
    }
    else{
        for (i=0;i<contadorEmpleados;i++)
            if(strcmp(aux,empleados[i].usuario)==0){
                system("cls");
                printf("LOGIN\n");
                printf("________________________\n");
                printf("| Empleados Password :  |\n");
                printf("|_______________________|\n");
                scanf("%s",aux);
                for (i=0;aux[i];i++)
                    aux[i]=toupper(aux[i]);
                for(i=0;i<contadorEmpleados;i++)
                    if(strcmp(aux,empleados[i].password)==0){
                        empleado=i;
                        return 2;
                    }

            }
    }
    return -1;
}
void menuGerente(){
    char opc;
    system("cls");
    do{
        fflush(stdin);
        printf("\t\tMenu  Gerente\n");
        printf("1.Nuevo\n2.Mostrar todos\n3.Buscar por codigo\n4.Buscar por apellido Paterno\n");
        printf("5.Modificar\n6.Eliminar por ID de empleado\n7.Reportes\n8.Cambiar de Usuario\n");
        printf("\tElige una opcion : ");
        scanf("%c",&opc);
        if(opc=='1'){
            nuevoEmpleado();
        }
        else if(opc=='2'){
            mostrarEmpleados();
        }
        else if(opc=='3'){
            buscarEmpleadoCodigo();
        }
        else if(opc=='4'){
            buscarEmpleadoApp();
        }
        else if(opc=='5'){
            modificarInformacionEmpleado();
        }
        else if(opc=='6'){
            eliminarEmpleado();
        }
        else if(opc=='7'){
            reportesVentas();
        }
        else if(opc=='8'){
            contadorSalir=0;
        }
        else{
            printf("Opcion no valida\n");
        }
    }while(opc!='8');
}
void nuevoEmpleado(){
    if(contadorEmpleados==50){
        printf("Base de datos llena///Error 404\n");
        return;
    }
    system("cls");
    fflush(stdin);
    int i;
    char aux[3];
    char string[20];
    printf("\t\t\t///Registrar Nuevo Empleado///\n\n");
    printf("Nombre del Empleado : ");
    scanf("%[^\n]",empleados[contadorEmpleados].nombre);
    for (i=0;empleados[contadorEmpleados].nombre[i];i++)
        empleados[contadorEmpleados].nombre[i]=toupper(empleados[contadorEmpleados].nombre[i]);
    fflush(stdin);
    printf("Apellido Paterno : ");
    scanf("%s",empleados[contadorEmpleados].app);
    for (i=0;empleados[contadorEmpleados].app[i];i++)
        empleados[contadorEmpleados].app[i]=toupper(empleados[contadorEmpleados].app[i]);
    fflush(stdin);
    printf("Apellido Materno : ");
    scanf("%s",empleados[contadorEmpleados].apm);
    for (i=0;empleados[contadorEmpleados].apm[i];i++)
        empleados[contadorEmpleados].apm[i]=toupper(empleados[contadorEmpleados].apm[i]);
    fflush(stdin);
    printf("Area : ");
    scanf("%[^\n]",empleados[contadorEmpleados].area);
    for (i=0;empleados[contadorEmpleados].area[i];i++)
        empleados[contadorEmpleados].area[i]=toupper(empleados[contadorEmpleados].area[i]);
    fflush(stdin);
    do{
        fflush(stdin);
        printf("Usuario : ");
        scanf("%[^\n]",string);
        for (i=0;string[i];i++)
            string[i]=toupper(string[i]);
        i=validarUsuario(string);
        if(i==1)
            strcpy(empleados[contadorEmpleados].usuario,string);
        else
            printf("Ya existe un Empleado registrado con este usuario\n");
        fflush(stdin);
    }while(i==0);
    do{
        fflush(stdin);
        sprintf(string,"EMPLEADO%d",consecutivoEmp+1);
        i=validarID(string);
        if(i==1){
            strcpy(empleados[contadorEmpleados].id,string);
            printf("ID : %s\n",empleados[contadorEmpleados].id);
        }
        else
            printf("Ya existe un Empleado registrado con este ID\n");
        fflush(stdin);
    }while(i==0);
    strncat(empleados[contadorEmpleados].password,empleados[contadorEmpleados].app,2);
    strncat(empleados[contadorEmpleados].password,empleados[contadorEmpleados].nombre,1);
    sprintf(aux,"%u",contadorEmpleados);
    strncat(empleados[contadorEmpleados].password,aux,2);
    printf("Password : ");
    printf("%s\n",empleados[contadorEmpleados].password);
    empleados[contadorEmpleados].ventasRealisadas=0;
    fflush(stdin);
    contadorEmpleados++;
    consecutivoEmp++;
}
int validarID(char cadena[]){
    if(contadorEmpleados==0)
        return 1;
    size_t i;
    for(i=0;i<contadorEmpleados;i++)
        if(strcmp(cadena,empleados[i].id)==0)
            return 0;
    return 1;
}
int validarUsuario(char cadena[]){
    if(contadorEmpleados==0)
        return 1;
    size_t i;
    for(i=0;i<contadorEmpleados;i++)
        if(strcmp(cadena,empleados[i].usuario)==0)
            return 0;
    return 1;
}
void mostrarEmpleados(){
    if(contadorEmpleados==0){
        printf("No hay empleados registrados");
        return;
    }
    int i;
    system("cls");
    printf("\t\t\tEmpleados Registrados\n\n");
    for(i=0;i<contadorEmpleados;i++){
        printf("Empleado %d\n\n",i+1);
        printf(")Nombre : %s\n",empleados[i].nombre);
        printf(")Apellido Paterno : %s\n",empleados[i].app);
        printf(")Apellido Materno : %s\n",empleados[i].apm);
        printf(")Area : %s\n",empleados[i].area);
        printf(")Usuario  :  %s\n",empleados[i].usuario);
        printf(")  ID   : %s\n",empleados[i].id);
        printf(") Password : %s\n\n",empleados[i].password);
    }
}
void buscarEmpleadoCodigo(){
    if(contadorEmpleados==0){
        printf("No hay empleados registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    int i;
    int band=0;
    fflush(stdin);
    printf("\t\t\tBuscar por codigo : \n\n");
    printf("Codigo : ");
    scanf("%s",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    for(i=0;i<contadorEmpleados;i++){
        if(strcmp(aux,empleados[i].id)==0){
            if(band==0){
                printf("Usuario encontrado\n\n");
                band++;
                printf("Empleado %d\n\n",i+1);
                printf(")Nombre : %s\n",empleados[i].nombre);
                printf(")Apellido Paterno : %s\n",empleados[i].app);
                printf(")Apellido Materno : %s\n",empleados[i].apm);
                printf(")Usuario  :  %s\n",empleados[i].usuario);
                printf(")  ID   : %s\n",empleados[i].id);
                printf(") Password : %s\n",empleados[i].password);
            }
        }
    }
    if(band==0)
        printf("Empleado no encontrado en la base de datos\n");
}
void buscarEmpleadoApp(){
    if(contadorEmpleados==0){
        printf("No hay empleados registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    int i;
    int band=0;
    fflush(stdin);
    printf("\t\t\tBuscar por Apellido Paterno : \n\n");
    printf("Apellido Paterno : ");
    scanf("%s",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    for(i=0;i<contadorEmpleados;i++){
        if(strcmp(aux,empleados[i].app)==0){
                printf("Usuario encontrado\n\n");
                band++;
                printf("Empleado %d\n\n",i+1);
                printf(")Nombre : %s\n",empleados[i].nombre);
                printf(")Apellido Paterno : %s\n",empleados[i].app);
                printf(")Apellido Materno : %s\n",empleados[i].apm);
                printf(")Usuario  :  %s\n",empleados[i].usuario);
                printf(")  ID   : %s\n",empleados[i].id);
                printf(") Password : %s\n",empleados[i].password);

        }
    }
    if(band==0)
        printf("Empleado no encontrado en la base de datos\n\n");
}
void modificarInformacionEmpleado(){
    if(contadorEmpleados==0){
        printf("No hay empleados registrados\n");
        return;
    }
    system("cls");
    char opc,modificar[20];
    size_t band,repetir,i,aux;
    do{
        fflush(stdin);
        printf("\t\t\tModificar Empleado \n\n");
        printf("1.Area\n2.Password\n3.Regresar\nElige una opcion : ");
        scanf("%c",&opc);
        switch(opc){
        case '1':
            repetir=0;
            printf("\t\t\tModificar Area\n\n");
            mostrarEmpleados();
            fflush(stdin);
            printf("IDE de Empleado que desea Modificar?\n");
            scanf("%[^\n]",modificar);
            for(i=0;modificar[i];i++)
                modificar[i]=toupper(modificar[i]);
            i=0;
            band=0;
            while(i<contadorEmpleados&&band==0){
                if(strcmp(modificar,empleados[i].id)==0){
                    band=1;
                    aux=i;
                }
                i++;
            }
            if(band==0){
                printf("El Empleado no se encuentra en la base de datos\n");
                return;
            }
            printf("\n\t\t\tNombre del Empleado :  %s\n",empleados[aux].nombre);
            printf("\t\tArea actual : %s\n",empleados[aux].area);
            printf("Nueva Area : ");
            fflush(stdin);
            scanf("%[^\n]",empleados[aux].area);
             for (i=0;empleados[aux].area[i];aux++)
                empleados[aux].area[i]=toupper(empleados[aux].area[i]);
            printf("\tRegistro Actualizado con Exito\n");
            break;
        case '2':
            repetir=0;
            printf("\t\t\tModificar Password\n\n");
            mostrarEmpleados();
            fflush(stdin);
            printf("IDE de Empleado que desea Modificar?\n");
            scanf("%[^\n]",modificar);
            for(i=0;modificar[i];i++)
                modificar[i]=toupper(modificar[i]);
            i=0;
            band=0;
            while(i<contadorEmpleados&&band==0){
                if(strcmp(modificar,empleados[i].id)==0){
                    band=1;
                    aux=i;
                }
                i++;
            }
            if(band==0){
                printf("El Empleado no se encuentra en la base de datos\n");
                return;
            }
            printf("\n\t\t\tNombre del Empleado :  %s \n",empleados[aux].nombre);
            printf("\t\tPassword actual : %s \n",empleados[aux].password);
            printf("Nueva Password : ");
            fflush(stdin);
            scanf("%[^\n]",empleados[aux].password);
             for (i=0;empleados[aux].password[i];i++)
                empleados[aux].password[i]=toupper(empleados[aux].password[i]);
            printf("\tRegistro Actualizado con Exito\n");
            break;
        case '3':
            repetir=0;
            break;
        default :
            printf("Opcion no valida\n");
            repetir=1;
            break;
        }
    }while(repetir==1);
}
void eliminarEmpleado(){
    if(contadorEmpleados==0){
        printf("No hay empleados registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    char opc;
    int i=0;
    int band=0;
    fflush(stdin);
    printf("\t\t\t///Despedir a Empleado///\n\n");
    printf("ID del Empleado : ");
    scanf("%s",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    i=0;
    while(i<contadorEmpleados&&band==0){
        if(strcmp(aux,empleados[i].id)==0)
            band++;
        i++;
    }
    if(band==0){
        printf("ID incorrecto, no existe ningun empleado con ese ID\n\n");
        return;
    }
    i--;
    printf("Empleado %d\n\n",i+1);
    printf(")Nombre : %s\n",empleados[i].nombre);
    printf(")Apellido Paterno : %s\n",empleados[i].app);
    printf(")Apellido Materno : %s\n",empleados[i].apm);
    printf(")Usuario  :  %s\n",empleados[i].usuario);
    printf("¿Desea a Eliminarlo?\t1.Si\2.Cancelar\n");
    fflush(stdin);
    scanf("%c",&opc);
    if(opc=='2')
        return;
    for(i=i;i<contadorEmpleados;i++)
        empleados[i]=empleados[i+1];
    contadorEmpleados--;

    printf("\tEmpleado Eliminado///\n");
}
void reportesVentas(){
    size_t i=0;
    char opc;
    int repetir;
    system("cls");
    do{
        fflush(stdin);
        printf("\t\tMenu Reportes De Ventas\n\n");
        printf("1.Cantidad de ventas realizadas por empleado\n");
        printf("2.Total vendido por empleado\n");
        printf("3.Total vendido por dia\n");
        printf("4.Productos a Surtir\n");
        printf("5.Existencia de todo\n");
        printf("6.Regresar\n");
        printf("Elige una opcion : ");
        scanf("%c",&opc);
        if(opc=='1'){
            repetir=1;
            cantidadVentasEmpleados();
        }
        else if(opc=='2'){
            repetir=1;
            totalVendidoEmpleados();
        }
        else if(opc=='3'){
            totalVendidoDia();
            repetir=1;
        }
        else if(opc=='4'){
            repetir=1;
            surtirProductos();
        }
        else if(opc=='5'){
            totalDeTodo();
            repetir=1;

        }
        else if(opc=='6'){
            repetir=0;
        }
        else{
            printf("Opcion no valida\n");
            repetir=1;
        }
    }while(repetir==1);
}
void totalDeTodo(){
    if(contadorProductos==0){
        printf("No hay productos registrados\n");
        return;
    }
    int i=0;
    int contenedor;
    contenedor=0;
    for(i=0;i<contadorProductos;i++){
        contenedor+=productos[i].existencia;
    }
    printf("En total estos son  todos los productos que hay %d\n",contenedor);
}
void surtirProductos(){
    if(contadorProductos==0||contadorEmpleados==0){
        printf("No hay productos registrados\n");
        return;
    }
    int i,band;
    system("cls");
    printf("\tProductos agotados : \n ");
    for(i=0;i<contadorProductos;i++){
        if(productos[i].existencia==0){
            printf("\n\tProducto %d\n\n",i+1);
            printf("Nombre : %s\n",productos[i].nombre);
            printf("Provedor : %s\n",productos[i].provedor);
            printf("Precio : %.2f\n",productos[i].precio);
            printf("Existencia : %d\n",productos[i].existencia);
            printf("ID : %s\n",productos[i].id);
        }
    }
    band=0;
    printf("Productos que estan proximos a agotarse : \n");
    for(i=0;i<contadorProductos;i++){
        if(productos[i].existencia!=0 && productos[i].existencia<9){
            printf("\n\tProducto %d\n\n",i+1);
            printf("Nombre : %s\n",productos[i].nombre);
            printf("Provedor : %s\n",productos[i].provedor);
            printf("Precio : %.2f\n",productos[i].precio);
            printf("Existencia : %d\n",productos[i].existencia);
            printf("ID : %s\n",productos[i].id);
            band=1;
        }
    }
    if(band==0){
        printf("Parece que no hay productos proximos a agotarse, todos tienen por lo menos un stock de 10\n");
    }
}
void totalVendidoDia(){
    if(contadorEmpleados==0||contadorVentas==0){
        printf("No se han realizado ventas\n");
        return;
    }
    int i,j;
    float contenedor;
    char aux[20];
    system("cls");
    for(i=0;i<contadorVentas;i++){
    printf("Fecha %d/%d/%d  | Total vendido : %.2f $$\n",ventas[i].dia,ventas[i].mes,ventas[i].anio,ventas[i].detalleDeVenta.total);
    }
}
void totalVendidoEmpleados(){
    if(contadorEmpleados==0||contadorVentas==0){
        printf("No se han realizado ventas\n");
        return;
    }
    int i,j;
    float contenedor;
    system("cls");
    printf("\t\t\tTotal Vendido Por Empleado\n\n");
    for(i=0;i<contadorEmpleados;i++){
        contenedor=0.0;
        if(empleados[i].ventasRealisadas>0){
            j=0;
            while(j<contadorVentas){
                if(strcmp(empleados[i].id,ventas[j].idEmpleado)==0)
                    contenedor+=ventas[j].detalleDeVenta.total;
                j++;
            }
        }
        printf("\n");
        printf("Empleado : %s %s %s\n",empleados[i].nombre,empleados[i].app,empleados[i].apm);
        printf("ID : %s\t\tArea : %s\n",empleados[i].id,empleados[i].area);
        printf("Total  vendido : %.2f $$\n",contenedor);
    }
}
void cantidadVentasEmpleados(){
    if(contadorEmpleados==0||contadorVentas==0){
        printf("No se han realizado ventas\n");
        return;
    }
    int i;
    system("cls");
    printf("\t\t\tTotal de ventas realizadas por Empleado\n\n");
    i=0;
    while(i<contadorEmpleados){
        printf("\n");
        printf("Empleado : %s %s %s\n",empleados[i].nombre,empleados[i].app,empleados[i].apm);
        printf("ID : %s\t\tArea : %s\n",empleados[i].id,empleados[i].area);
        printf("Ventas realizadas : %d\n",empleados[i].ventasRealisadas);
        i++;
    }
}
void menuEmpleados(){
    char opc;
    system("cls");
    do{
        fflush(stdin);
        printf("\t\t\tMenu Empleados\n\n");
        printf("1)Productos\n2)Venta\n3)Cambiar de usuario\nElige una opcion : ");
        scanf("%c",&opc);
        switch(opc){
            case '1':
                productosEmpleados();
                break;
            case '2':
                ventaProductos();
                break;
            case '3':
                printf("Adios Vaquero\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
    }
    }while(opc!='3');
}
void productosEmpleados(){
    char opc;
    int repetir=0;
    system("cls");
    do{
        fflush(stdin);
        repetir=1;
        printf("\t\t\tProductos\n\n");
        printf("1)Capturar\n2)Mostrar\n3)Buscar\n4)Modificar\n5)Eliminar por ID de Producto\n6)Regresar\n");
        printf("Elige una opcion : ");
        scanf("%c",&opc);
        if(opc=='1'){
            capturarProductos();
        }
        else if(opc=='2'){
            system("cls");
            printf("\t\t\tMostrar productos\n\n");
            mostrarProductos();
        }
        else if(opc=='3'){
            do{
                fflush(stdin);
                printf("\t\t\t/////Buscar/////\n");
                printf("1)Por provedor\n2)Por ID producto\n3.Regresar\nElige una opcion : ");
                scanf("%c",&opc);
                if(opc=='1')
                    buscarProductoProvedor();
                else if(opc=='2')
                    buscarProductoID();
                else if(opc=='3')
                    printf("Regresando a menu de productos\n");

                else
                    printf("Opcion no valida\n");
            }while(opc!='3');
            repetir=0;
        }
        else if(opc=='4'){
            modificarProducto();
        }
        else if(opc=='5'){
            eliminarProducto();
        }
        else if(opc=='6'){
            printf("Regresando al menu de empleados\n");
            repetir=0;
        }
        else{
            system("cls");
            printf("Opcion no valida\n");
        }
    }while(repetir==1);
}
void capturarProductos(){
    if(contadorProductos==50){
        printf("Base de Datos llena\n");
        return;
    }
    char aux[20];
    int i;
    fflush(stdin);
    system("cls");
    printf("\t\t\tCapturar Productos\n\n");
    printf("Nombre del producto : ");
    scanf("%[^\n]",productos[contadorProductos].nombre);
    for(i=0;productos[contadorProductos].nombre[i];i++)
        productos[contadorProductos].nombre[i]=toupper(productos[contadorProductos].nombre[i]);
    fflush(stdin);
    printf("Provedor : ");
    scanf("%[^\n]",productos[contadorProductos].provedor);
    for(i=0;productos[contadorProductos].provedor[i];i++)
        productos[contadorProductos].provedor[i]=toupper(productos[contadorProductos].provedor[i]);
    fflush(stdin);
    do{
        printf("Precio : ");
        scanf("%f",&productos[contadorProductos].precio);
        fflush(stdin);
    }while(productos[contadorProductos].precio<=0);
    do{
        fflush(stdin);
        printf("Existencia : ");
        scanf("%i",&productos[contadorProductos].existencia);
        if(productos[contadorProductos].existencia<=0)
            printf("Error 404, verifique existencia\n");
    }while(productos[contadorProductos].existencia<=0);
    fflush(stdin);
    sprintf(aux,"PRODUCTO%d",consecutivoProductos+1);
    strcpy(productos[contadorProductos].id,aux);
    printf("ID : %s",productos[contadorProductos].id);
    consecutivoProductos++;
    contadorProductos++;
}
int validarIDproducto(char id[20]){
    if(contadorProductos==0)
        return 1;
    int i;
    for(i=0;i<contadorProductos;i++)
        if(strcmp(id,productos[i].id)==0)
            return 0;
    return 1;
}
void mostrarProductos(){
    if(contadorProductos==0){
        printf("No hay productos registrados\n");
        return;
    }
    int i;
    for(i=0;i<contadorProductos;i++){
        printf("\n\tProducto %d\n\n",i+1);
        printf("Nombre : %s\n",productos[i].nombre);
        printf("Provedor : %s\n",productos[i].provedor);
        printf("Precio : %.2f\n",productos[i].precio);
        printf("Existencia : %d\n",productos[i].existencia);
        printf("ID : %s\n",productos[i].id);
    }
}
void buscarProductoProvedor(){
    if(contadorProductos==0){
        printf("No hay Productos registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    int i;
    int band=0;
    fflush(stdin);
    printf("\t\t\tBuscar productos por  Provedor : \n\n");
    printf("Provedor : ");
    scanf("%[^\n]",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    for(i=0;i<contadorProductos;i++){
        if(strcmp(aux,productos[i].provedor)==0){
                printf("Producto encontrado\n\n");
                band++;
                printf("\n\tProducto %d\n\n",i+1);
                printf("Nombre : %s\n",productos[i].nombre);
                printf("Provedor : %s\n",productos[i].provedor);
                printf("Precio : %.2f\n",productos[i].precio);
                printf("Existencia : %d\n",productos[i].existencia);
                printf("ID : %s\n",productos[i].id);

        }
    }
    if(band==0)
        printf("Provedor no encontrado en la base de datos\n");
}
void buscarProductoID(){
     if(contadorProductos==0){
        printf("No hay Productos registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    int i;
    int band=0;
    fflush(stdin);
    printf("\t\t\tBuscar productos por  codigo : \n\n");
    printf("Codigo : ");
    scanf("%[^\n]",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    for(i=0;i<contadorProductos;i++){
        if(strcmp(aux,productos[i].id)==0){
            if(band==0){
                printf("Producto encontrado\n\n");
                band++;
                printf("\n\tProducto %d\n\n",i+1);
                printf("Nombre : %s\n",productos[i].nombre);
                printf("Provedor : %s\n",productos[i].provedor);
                printf("Precio : %.2f\n",productos[i].precio);
                printf("Existencia : %d\n",productos[i].existencia);
                printf("ID : %s\n",productos[i].id);
            }
        }
    }
    if(band==0)
        printf("Producto no encontrado en la base de datos\n");
}
void modificarProducto(){
   if(contadorProductos==0){
        printf("No hay productos registrados\n");
        return;
    }
    char opc;
    float precio;
    char modificar[20];
    int aux;
    int band,repetir,i,existencia;
    system("cls");
    do{
        band=0;
        fflush(stdin);
        printf("\t\t\tModificar Productos \n\n");
        printf("1.Modificar Existencia\n2.Cambiar Precio\n3.Regresar\nElige una opcion : ");
        scanf("%c",&opc);
        switch(opc){
        case '1':
            repetir=0;
            fflush(stdin);
            printf("\t\t\tModificar Existencia\n\n");
            mostrarProductos();
            printf("IDE de producto que desea Modificar?\n");
            scanf("%[^\n]",modificar);
            for(i=0;modificar[i];i++)
                modificar[i]=toupper(modificar[i]);
            i=0;
            band=0;
            while(i<contadorProductos&&band==0){
                if(strcmp(modificar,productos[i].id)==0){
                    band=1;
                    aux=i;
                }
                i++;
            }
            if(band==0){
                printf("El producto no se encuentra en la base de datos\n");
                return;
            }
            i--;
            printf("\n\t\t\tNombre del producto %s\n",productos[i].nombre);
            printf("\t\tExistencia actual : %d\n",productos[i].existencia);
            printf("Nueva existencia : ");
            fflush(stdin);
            scanf("%d",&existencia);
            if(existencia<0){
                printf("No es posible realizar esta modificacion\n");
                return;
            }
            productos[i].existencia=existencia;
            printf("\tRegistro Actualizado con Exito\n");
            break;
        case '2':
            repetir=0;
            printf("\t\t\tModificar Precio\n\n");
            mostrarProductos();
            fflush(stdin);
            printf("IDE de producto que desea Modificar?\n");
            scanf("%[^\n]",modificar);
            for(i=0;modificar[i];i++)
                modificar[i]=toupper(modificar[i]);
            i=0;
            band=0;
            while(i<contadorProductos&&band==0){
                if(strcmp(modificar,productos[i].id)==0){
                    band=1;
                }
                i++;
            }
            i--;
            if(band==0){
                printf("El producto no se encuentra en la base de datos\n");
                return;
            }
            printf("\n\t\t\tNombre del producto %s\n",productos[i].nombre);
            printf("\t\tPrecio actual : %.2f\n",productos[i].precio);
            printf("Nuevo Precio : ");
            fflush(stdin);
            scanf("%f",&precio);
            if(precio<=0.00){
                printf("Precio no valido\nNo es posible cambiar esta informacion\n");
                return;
            }
            productos[i].precio=precio;
            printf("\tRegistro Actualizado con Exito\n");
        case '3':
            repetir=0;
            break;
        default :
            printf("Opcion no valida\n");
            repetir=1;
            break;
        }
    }while(repetir==1);
}
void eliminarProducto(){
    if(contadorProductos==0){
        printf("No hay Productos registrados\n");
        return;
    }
    system("cls");
    char aux[20];
    char opc;
    int i=0,j;
    int band=0;
    fflush(stdin);
    printf("\t\t\t///Eliminar Producto///\n\n");
    printf("ID del Producto : \n");
    scanf("%s",aux);
    for (i=0;aux[i];i++)
        aux[i]=toupper(aux[i]);
    i=0;
    while(i<contadorProductos&&band==0){
        if(strcmp(aux,productos[i].id)==0)
            band++;
        i++;
    }
    if(band==0){
        printf("ID incorrecto, no existe ningun producto con ese ID\n\n");
        return;
    }
    i--;
    printf("\n\tProducto %d\n\n",i+1);
    printf("Nombre : %s\n",productos[i].nombre);
    printf("Provedor : %s\n",productos[i].provedor);
    printf("Precio : %.2f\n",productos[i].precio);
    printf("Existencia : %d\n",productos[i].existencia);
    printf("ID : %s\n",productos[i].id);
    fflush(stdin);
    printf("¿Desea a Eliminarlo?\t1.Si\t2.Cancelar\n");
    scanf("%c",&opc);
    if(opc=='2')
        return;
    for(i=i;i<contadorProductos;i++)
        productos[i]=productos[i+1];
    contadorProductos--;
    printf("\tProducto Eliminado///\n");
}
void ventaProductos(){
    if(contadorProductos==0){
        printf("No tienes productos registrados actualmente\n");
        return;
    }
    system("cls");
    float total,pago,cambio;
    int opc,i,j;
    int aux;
    int repetir;
    char venta[20];
    do{
        do{
            repetir=0;
            do{
                printf("\t\t\tVender producto\n\n");
                mostrarProductos();
                fflush(stdin);
                printf("\n\n\n%d)Regresar\n\n\tIndice del producto que quieres vender : \n",contadorProductos+1);
                scanf("%d",&opc);
                fflush(stdin);
                if(opc==contadorProductos+1)
                    return;
                if(opc>contadorProductos||opc<=0)
                    printf("\tOpcion no valida\n");
            }while(opc>contadorProductos||opc<=0);
            opc--;
            if(productos[opc].existencia==0){
                printf("Articulo Agotado por el momento :,( \n");
                return;
            }
            system("cls");
            do{
                printf("\t\t\tVender Articulo : \n\n");
                printf("\n\tProducto %d\n\n",opc+1);
                printf("Nombre : %s\n",productos[opc].nombre);
                printf("Provedor : %s\n",productos[opc].provedor);
                printf("Precio : %.2f\n",productos[opc].precio);
                printf("Existencia : %d\n",productos[opc].existencia);
                printf("ID : %s\n",productos[opc].id);
                fflush(stdin);
                printf("Cuantos %s vas a vender : \n",productos[opc].nombre);
                scanf("%d",&aux);
                fflush(stdin);
                if(aux<=0)
                    printf("Error, eres tonto?\n");
            }while(aux<=0);
            if(aux>productos[opc].existencia){
                printf("No contamos con suficientes articulos por el momento");
                printf("Tenemos un stock de %d  %s\n",productos[opc].existencia,productos[opc].nombre);
                repetir=1;
            }
        }while(repetir==1);
        total=productos[opc].precio*aux;
        printf("\t\t\tTotal de la venta\n\n");
        printf("Total a pagar %.2f\n",total);
        printf("Con cuanto pago el cliente : \n");
        fflush(stdin);
        scanf("%f",&pago);
        if(pago<total){
            printf("\t\tError 4sa4\n Intentalo de nuevo\n pago insuficiente\n");
            repetir=1;
        }
    }while(repetir==1);
    cambio=pago-total;
    system("cls");
    printf("Su cambio es : %.2f",cambio);
    productos[opc].existencia-=aux;
    ventas[contadorVentas].detalleDeVenta.total=total;
    sprintf(venta,"VENTA%d",contadorVentas+1);
    strcpy(ventas[contadorVentas].idVentas,venta);
    strcpy(ventas[contadorVentas].detalleDeVenta.idVenta,venta);
    strcpy(ventas[contadorVentas].idEmpleado,empleados[empleado].id);
    strcpy(ventas[contadorVentas].detalleDeVenta.idProducto,productos[opc].id);
    ventas[contadorVentas].detalleDeVenta.cantidad=aux;
    printf("\nID EMPLEADO : %s",empleados[empleado].id);
    printf("\t\t\tID VENTA : %s\n",ventas[contadorVentas].idVentas);
    do{
        printf("\t\t\tDetalle de venta\n\n");
        printf("Dia  : ");
        scanf("%d",&ventas[contadorVentas].dia);
        if(ventas[contadorVentas].dia<=0||ventas[contadorVentas].dia>31){
            printf("Fecha no permitida\n");
        }
    }while(ventas[contadorVentas].dia<=0||ventas[contadorVentas].dia>31);
    do{
        repetir=0;
        printf("Mes  : ");
        scanf("%d",&ventas[contadorVentas].mes);
        if(ventas[contadorVentas].dia>28&&ventas[contadorVentas].mes==2){
            repetir=1;
            printf("Fecha no valida\n");
        }
        if(ventas[contadorVentas].mes>12){
            repetir=1;
            printf("Error\n");
        }
    }while(repetir==1);
    do{
        printf("A%co  : ",164);
        scanf("%d",&ventas[contadorVentas].anio);
    }while(ventas[contadorVentas].anio<=2017||ventas[contadorVentas].mes>2019);
    empleados[empleado].ventasRealisadas++;
    contadorVentas++;
    printf("Venta Realizada con super exito\n");
}
