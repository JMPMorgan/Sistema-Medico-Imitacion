#include <windows.h>
#include  <iostream>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include <fstream>
#include <vector>
#include "resource.h"
//Proyecto de estructura de datos para la carrera de LMAD//
//Elaborado por Jonathan Manuel Morgan Pérez 
//Para cualquier duda y aclaracion puedes contactarme 
//Instagram: lordmorgan07
//Este proyecto es solo para uso Educativo

#define TM_RELOJ 3000
//Estos Char se utilizan para a entrar por primerar vez para dar de alta los usuarios//
char admi[6] = "Admi";
char pass[6] = "Pass";
//Estos Char se utilizan para a entrar por primerar vez para dar de alta los usuarios//
char passUserCheck[20];
char ListBoxEspecialidades[100];
char ListBoxDeCitas[300];
char ListBoxCitasWnd[150];
char ListBoxPacientes[150];
char ListBoxMedicos[150];
char ConseguirNumeroEspecialidades[100];
char direccionFotoMedicoTemporal[150];
char numeroespecialidad[2];
char TextoMesDeCita[20];
char TextoDoctor[20];
char TextoPaciente[20];
char TextoEspecialidad[20];
char TextoSemana[4];
int EspecialidadDeListBox=0, SeleccionDeListBoxPacientes = 0;
int SeleccionListBox = 0;
int PacientesDeListBox = 0;
int MedicosDeListBox = 0;
int CitasListBox =0;
int posicionQS = 0;
bool checkPrimeraVezDoc = false;
bool checkPrimeraVezDocCargar = false;
bool checkInsertarNuevoMedico = false;
int posicionCargarMedico = 0;
int contadorParaBuscarDoctor = 0;
int controladorNumeroDeCitas = 0;
char comparacionDoctorCita[100];
char comparacionEspecialidad[30];
char comparacionPaciente[50];
time_t segundosIniciales;
struct tm *actualTime;
using namespace std;
vector<int> numeros;
HINSTANCE hInst;
HWND hPrincipal;
HWND hEdit1, hEdit2,hEdit3,hEdit4,hEdit5,hEdit6,hEdit7,hEdit8,hEdit9,hEdit10,hEdit11,hEdit12,hEdit13,hEdit14,hEdit15,hEdit16, hPcLatern;
HBITMAP hBmpLatern;
struct NumeroDeCedulasComp {
	char ListaQS[150];
	int cedulaInt;
	NumeroDeCedulasComp *sig;
}*origenint,*auxint;
struct ListaDePacientesHeapShor{
	char ListaHP[100];
	ListaDePacientesHeapShor *sig;
}*origenHP, *auxHP;
struct reporteMedico {
	char listaMedico[250];
	reporteMedico *sig;
}*origenM,*auxM;
struct especialidades
{
	char especialidad[20];
	char descripcion[50];
	int numero;
	especialidades *sig;
	especialidades *ant;
}*origenespecialidad,*auxespecialidad,temporalespecialidad;
struct admi
{
	char verificacionadmi[5];
	char verificacionpass[5];
}check;
struct Users {
	char Usuario[10];
	char Pass[20];
	char Nombre[50];
	Users *sig;
	Users *ant;
}*origenusers,*auxusers,temporalusers;
struct pacientes
{
	char Nombre[50];
	char ApellidoPaterno[15];
	char ApellidoMaterno[15];
	char genero[10];
	char TelefonoChar[15];
	double Telefono;
	char EdadChar[10];
	int Edad;
	char referencia[150];
	char DiaChar[10];
	int Dia;
	char MesChar[10];
	int Mes;
	char anoChar[10];
	int ano;
	char fechacompleta[20];
	char primermedico[50];
	pacientes *sig;
	pacientes *ant; 
}*origenpacientes,*auxpacientes,temporalpacientes;
struct Medicos
{
	int Cedula;
	char CedulaChar[16];
	char NombreDoctor[50];
	char ApellidoPaterno[15];
	char ApellidoMaterno[15];
	int numerodeconsultorio;
	char numerodeconsultorioChar[4];
	char numeroTelefonicoChar[20];
	char especialidadM[20];
	char HoraInicioChar[5];
	int HoraInicio;
	int HoraSalida;
	char HoraSalidaChar[5];
	double NumeroTelefonico;
	char DireccionFoto[150];
	char diasactivos[90];
	bool Lunes;
	bool Martes;
	bool Miercoles;
	bool Jueves;
	bool Viernes;
	bool Sabado;
	bool Domingo;
	Medicos *izq;
	Medicos *der;
	Medicos *padre;
}*medico,temporalmedico,*raiz;
struct radioboton
{
	bool RadioButton1=true;
	bool RadioButton2 = true;
	bool RadioButton3 = true;
	bool RadioButton4 = true;
	bool RadioButton5 = true;
	bool RadioButton6 = true;
	bool RadioButton7 = true;
}radioCheck,radioCheckPacientes;
struct Citas
{
	double numeroTelefonicoPaciente;
	char numeroTelefonicoPacienteChar[15];
	char nombrePaciente[20];
	char nombreDoctor[20];
	int CedulaDoctor;
	int numeroespecialidadCita;
	int mesCita;
	char mesCitaChar[15];
	char FechaDeCita[51];
	char horacompleta[20];
	char DireccionFotoDoctor[150];
	int HoraInicio;
	char HoraInicioChar[5];
	int HoraFinal;
	char HoraFinalChar[5];
	int MinutosInicio;
	char MinutosInicioChar[5];
	int MinutosFinal;
	char MinutosFinalChar[5];
	int numeroDeCita;
	char numeroDeCitaChar[4];
	char atendidaChar[3];
	bool atendida = false;
	bool cancelada = false;
	char motivodeCancelacion[20];
	Citas *sig;
	Citas *ant;
}*origencitas,*auxcitas,temporalcitas;
struct CitasSemana {
	char Lista[100];
	CitasSemana *sig;
}*origencitasemana,*auxcitasemana;
struct Fechas
{
	char fechas[3];
	int fecha;
	Fechas *sig;
}*origenfechas, *auxfechas;

BOOL CALLBACK ventanaLogin(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaMenu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AltaUsuario(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaAltaEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaEdicionEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK veentanaRegistroMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaRegistroPacientes(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaRegistroDeCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaMostrarCita(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaVerCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaCancelacionCita(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaBuscadorMedicoCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaConsultaMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaBuscadorSemanaCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaBuscadorEspecialidadCita(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaMostrarPacientes(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaEdicionPaciente(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaMostrarMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaEdicionMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ventanaEdicionCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool CheckLogin();
bool verificarPass();
bool verificarUsuarios();
bool accesoUsuario();
bool verificarEspecialidad();
bool CheckEdicion();
bool checkNumeroConsultorio();
bool verificarNombreDoctor();
bool longitudTelefonoDoctor();
bool verificacionCitasSemanas();
bool verificacionEspecialidadBuscador();
bool verificarHorarioEntradaSalidaDoctor();
bool checkHoraMedico();
bool especialidadesIgual();
void agregarUsuario();
void guardarUsuarioEnArchivo();
void cargarUsuariosDeArchivo();
void agregarEspecialidad();
void guardarEspecialidadesArchivo();
void cargarEspecialidadesArchivo();
void borrarEspecialidad();
void EditarEspecialidad();
void RegresarAPunterosEdicion();
void AgregarRBDias();
void cambiarHorarioDoctoresAInt();
void guardarMedicosEnArchivo();
void limpiarTemporalMedicoPorError();
void insertarNuevoMedico(Medicos *&medico, Medicos m, Medicos *padre);
bool verificarCedula(Medicos *medico, Medicos m);
bool verificarHorarioDoctor(Medicos *medico, Medicos m);
void recorrerMedicoPreOrden(Medicos *medico);
void buscareliminar(Medicos *medico, Medicos m);
void eliminarNodo(Medicos *medico);
void destruirNodo(Medicos *paraeliminar);
void reemplazarNodo(Medicos *arbol, Medicos *nuevomedico);
void cargarMedicosEnArchivo(Medicos *padre);
Medicos *minimo(Medicos *medico);
void cargarMedicosArchivoBinario(Medicos *&medico, Medicos *temp, Medicos *&padre, fstream *&archivo, int i);
Medicos *CargarSuperNodoMedico(fstream *&archivo, Medicos *temp, Medicos *&padre);
void mostrarTodoMedicos(Medicos *medico, Medicos *&temp, Medicos m, fstream *archivo);
void mostrarArbolenComboBox(Medicos *medico);
void AgregarRBSexo();
bool verificarNombrePaciente(char verificar[150]);
bool longitudTelefonoPaciente();
bool verificarFechaPaciente();
bool verificarEdad();
void agregarPacientes();
void guardarPacientesArchivo();
void cargarPacientesArchivo();
void EncontrarDoctorParaCita(Medicos *medico);
bool verificacionDiaDeFecha();
void cambiarIntAConsulta();
void agregarCitas();
void guardarCitasArchivo();
void cargarCitasArchivo();
bool verificarCita();
void ObtenerNombreDoctorCita();
void encontrarEspecialidad(char contenedor[50]);
void ObtenerNumeroEspecialidadCita();
void ObtenerTelefonoCita();
void EncontrarNombreDoctor(Medicos *medico);
void EncontrarPacienteCita();
void EncontrarEspecialidadCita();
void CompletarCita();
void CancelarCita();
void transformarMesAIntCitas();
void encontrarMesCitas();
void encontrarMedicoCitas(Medicos *medico);
void BuscarSemanaCita();
void conseguirDiaDeCita();
void mandarReporte();
void rellenarespacionBlanco(CitasSemana *&a);
bool buscarEspcialidadCita();
void mandarReporteespecialidad();
void verificarSemanaEspecialidad();
void AgregarNumeroEnQuickSort();
void pasarMedicoAInt(Medicos *medico);
void OrdenamientoMedicoQuickSort(Medicos *medico);
void OrdenamientoQuickSortAux(vector<int>&numeros, int limite_izq, int limite_der);
void agregarInt(Medicos *medico);
void pasarMedicoArchivoQuickSort();
void ordenarPacientesHP();
void hacerListaHP();
void reporteHP();
void editarPacientesSel();
void seleccionEdicionPaciente();
void eliminarPacientes();
void hacerEdicion(Medicos *medico);
void mostrarArbolEnListBox(Medicos *medico);
void mostrarMedicoAEditar(Medicos *medico);
void escogerMedicoEdicion();
void guardarEdicionCitas();
void EncontrarDoctorParaCitaEdicion(Medicos *medico);
bool verificarFechaPaciente();
bool CharAIntEdadPaciente();
bool verificacionCedulaBuscadorMedico();
bool verificacionMesBuscadorMedico();
void mandarReporteMedico();
void limpiarTemporalPacientesPorError();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevhInstance, PSTR cmdLine, int ShowCmd) {
	origenpacientes = auxpacientes = NULL;
	origenusers = auxusers = NULL;
	origenespecialidad = auxespecialidad = NULL;
	origencitas = auxcitas = NULL;
	auxM = origenM = NULL;
	medico = raiz = NULL;
	raiz = NULL;
	medico = NULL;
	hInst = hInstance;
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Login), 0, ventanaLogin);
	ShowWindow(hPrincipal, SW_SHOW);

	while (GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
BOOL CALLBACK ventanaLogin(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, ED_User);
		hEdit2 = GetDlgItem(hWnd, ED_Pass);
		cargarUsuariosDeArchivo();
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == IDB_Login && HIWORD(wParam) == BN_CLICKED) {
			GetWindowTextA(hEdit1, check.verificacionadmi, 10);
			GetWindowTextA(hEdit2, check.verificacionpass, 10);
			if (CheckLogin() == true) {
				MessageBox(hWnd, "Usuario Correcto", 0, MB_ICONINFORMATION);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Alta), 0, AltaUsuario);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else if (CheckLogin() == false) {
				//MessageBox(hWnd, "Usuario Incorrecto", "Verifique su informacion e intentelo de nuevo", MB_ICONERROR);
				//hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Login), 0, ventanaLogin);
				//DestroyWindow(hWnd);
				//ShowWindow(hPrincipal, SW_SHOW);
				GetWindowTextA(hEdit1, temporalusers.Usuario, 10);
				GetWindowTextA(hEdit2, temporalusers.Pass, 20);
				if (accesoUsuario() == true)
				{
					MessageBox(hWnd, "Usuario Correcto", 0, MB_ICONINFORMATION);
					hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
					DestroyWindow(hWnd);
					ShowWindow(hPrincipal, SW_SHOW);
				}
				else if (accesoUsuario() == false)
				{
					MessageBox(hWnd, "Usuario Incorrecto", "Verifique su informacion e intentelo de nuevo", MB_ICONERROR);
					hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Login), 0, ventanaLogin);
					DestroyWindow(hWnd);
					ShowWindow(hPrincipal, SW_SHOW);
				}
	
			}
		}
		else if (LOWORD(wParam) == IDB_Salir&& HIWORD(wParam) == BN_CLICKED) {
			DestroyWindow(hWnd);
			PostQuitMessage(0);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;

}
BOOL CALLBACK AltaUsuario(HWND hWnd, UINT msg,WPARAM wParam,LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd,EDT_User);
		hEdit2 = GetDlgItem(hWnd,EDT_NombreUser);
		hEdit3 = GetDlgItem(hWnd,EDT_ContraUser);
		hEdit4 = GetDlgItem(hWnd,EDT_VeriContraUser);
		cargarUsuariosDeArchivo();
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == IDB_GuardarUser&& HIWORD(wParam) == BN_CLICKED) {
			GetWindowTextA(hEdit1, temporalusers.Usuario, 10);
			GetWindowTextA(hEdit2, temporalusers.Nombre, 50);
			GetWindowTextA(hEdit3, temporalusers.Pass, 20);
			GetWindowTextA(hEdit4, passUserCheck, 20);
			//Verifica si la contraseña es correcta con la que inserto//
			if (verificarPass()==true) {
				if (verificarUsuarios()==true)
				{
					agregarUsuario();
					guardarUsuarioEnArchivo();
					MessageBox(hWnd, "Usuario Correcto", "Usuario Añadido correcto", MB_ICONINFORMATION);
					hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Alta), 0, AltaUsuario);
					DestroyWindow(hWnd);
					ShowWindow(hPrincipal, SW_SHOW);
				}
				else
				{
					MessageBox(hWnd, "Usuario Existente", "Este Usuario ya existe", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Contraseña", "Contraseña no coincide", MB_ICONINFORMATION);
			}
			//Verifica si no hay mas usuarios con ese nombre//
		}
		else if (LOWORD(wParam) == IDB_RegresarUser && HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Login), 0, ventanaLogin);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}

	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;


}
BOOL CALLBACK ventanaMenu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, IDB_Especialidades);
		hEdit2 = GetDlgItem(hWnd, IDB_RegistroMedico);
		hEdit3 = GetDlgItem(hWnd, IDB_RegistroCitas);
		hEdit4 = GetDlgItem(hWnd, IDB_Pacientes);
		hEdit5 = GetDlgItem(hWnd, IDB_ConsultaCitas);

	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == IDB_Especialidades&&HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Especialidades), 0, ventanaEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam) == IDB_RegistroMedico && HIWORD(wParam) == BN_CLICKED) {
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			if (origenespecialidad != NULL) {//Verifica que si no es vacio para poder acceder a la ventana
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_RegistroMedico), 0, veentanaRegistroMedico);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}
		}

		else if (LOWORD(wParam) == IDB_Pacientes&&HIWORD(wParam) == BN_CLICKED) {
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			if (origenespecialidad != NULL) {//Verifica que si no es vacio para poder acceder a la ventana
				hPrincipal = CreateDialog(hInst,MAKEINTRESOURCE(IDD_Pacientes), 0, ventanaRegistroPacientes);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}
		}
		else if (LOWORD(wParam) == IDB_RegistroCitas&&HIWORD(wParam) == BN_CLICKED) {
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			if (origenespecialidad!= NULL) {//Verifica que si no es vacio para poder acceder a la ventana
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_RegistroCitas), 0, ventanaRegistroDeCitas);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}
		}
		else if (LOWORD(wParam) == IDB_ConsultaCitas&&HIWORD(wParam) == BN_CLICKED) {
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			if (origenespecialidad != NULL) {//Verifica que si no es vacio para poder acceder a la ventana
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}

		}
		else if (LOWORD(wParam) == BTN_MostrarPacientes&&HIWORD(wParam) == BN_CLICKED) {
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			if (origenespecialidad!=NULL)
			{
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MostrarPacientes), 0, ventanaMostrarPacientes);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}
		}
		else if (LOWORD(wParam)==BTN_MostrarMedicos&&HIWORD(wParam)==BN_CLICKED)
		{
			cargarEspecialidadesArchivo();
			auxespecialidad = origenespecialidad;
			medico = raiz;
			if (origenespecialidad != NULL)
			{
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_mostrarMedicos), 0, ventanaMostrarMedico);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Debe Rellenar las especialidades primero", "Error", MB_ICONERROR);

			}
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;
}
bool CheckLogin() {
	if (strcmp(check.verificacionadmi, admi) == 0) {
		if (strcmp(check.verificacionpass, pass) == 0) {
			return true;
		}
	}
	return false;

}
BOOL CALLBACK ventanaEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, IDB_AltaEspecialidad);
		hEdit2 = GetDlgItem(hWnd, IDB_BajaEspecialidad);
		hEdit3 = GetDlgItem(hWnd, IDB_CambiarEspecialidad);
		hEdit1 = GetDlgItem(hWnd, LB_Especialidades);
		cargarEspecialidadesArchivo();
		auxespecialidad = origenespecialidad;
		while (auxespecialidad !=NULL)
		{
			memset(ListBoxEspecialidades, NULL, 100);
			strcpy_s(ListBoxEspecialidades, auxespecialidad->especialidad);
			strcat(ListBoxEspecialidades, " | ");
			strcat(ListBoxEspecialidades, auxespecialidad->descripcion);
			strcat(ListBoxEspecialidades, " | ");
			_itoa_s(auxespecialidad->numero,numeroespecialidad,10);
			strcat(ListBoxEspecialidades, numeroespecialidad);
			SendMessage(hEdit1,LB_ADDSTRING,0,(LPARAM)ListBoxEspecialidades);
			auxespecialidad = auxespecialidad->sig;
		}
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == IDB_AltaEspecialidad&&HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_AltaEspecialidades), 0, ventanaAltaEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam) == IDB_BajaEspecialidad&&HIWORD(wParam) == BN_CLICKED) {
			borrarEspecialidad();
			guardarEspecialidadesArchivo();
			MessageBox(hWnd, "Especialidad Borrada Con exito", "Informacion", MB_ICONINFORMATION);
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Especialidades), 0, ventanaEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal,SW_SHOW);
		}
		else if(LOWORD(wParam)==IDB_CambiarEspecialidad && HIWORD(wParam)==BN_CLICKED)
		{
			/*EspecialidadDeListBox = (int)SendMessage(hEdit4, LB_GETCURSEL, 0, 0);*/
			EditarEspecialidad();
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_EditarEspecialidades), 0, ventanaEdicionEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam) == IDB_RegresarEspecialidades && HIWORD(wParam) == BN_CLICKED)
		{
			hPrincipal=CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);

		}
		else if (LOWORD(wParam) == LB_Especialidades && HIWORD(wParam) == LBN_SELCHANGE)
		{
 			EspecialidadDeListBox = (int)SendMessage(hEdit1, LB_GETCURSEL,0,0);
			SeleccionListBox = EspecialidadDeListBox;
			/*SendMessage(hEdit1, LB_GETTEXT, 0, 0);*/
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaAltaEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_NombreEspecialidad);
		hEdit2 = GetDlgItem(hWnd, EDT_DescripcionDeEspecialidad);
		cargarEspecialidadesArchivo();
		SetWindowText(hEdit1, temporalespecialidad.especialidad);
		SetWindowText(hEdit2, temporalespecialidad.descripcion);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == IDB_GuardarEspecialidad&&HIWORD(wParam) == BN_CLICKED) {
			GetWindowTextA(hEdit1, temporalespecialidad.especialidad, 19);
			GetWindowTextA(hEdit2, temporalespecialidad.descripcion, 49);
			if (temporalespecialidad.especialidad[0]!=NULL)
			{
				if (temporalespecialidad.descripcion[0]!=NULL)
				{
					if (verificarEspecialidad() == true) {
						agregarEspecialidad();
						guardarEspecialidadesArchivo();
						MessageBox(hWnd, "Especialidad Registrada con exito", "Informacion", MB_ICONINFORMATION);
						hPrincipal = CreateDialog(hInst, MAKEINTRESOURCEA(IDD_AltaEspecialidades), 0, ventanaAltaEspecialidades);
						DestroyWindow(hWnd);
						ShowWindow(hPrincipal, SW_SHOW);
					}
					else
					{
						MessageBox(hWnd, "Esta especialidad ya esta registrada", "Error", MB_ICONERROR);
					}
				}
				else
				{
					MessageBox(hWnd, "Debe ingresar texto en texto en la descripcion", "Error", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Debe ingresar texto en texto en la especialidad", "Error", MB_ICONERROR);
			}
		}
		else if (LOWORD(wParam) == IDB_RegresarEspecialidad && HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Especialidades), 0, ventanaEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaEdicionEspecialidades(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_EspecialidadEdicion);
		hEdit2 = GetDlgItem(hWnd, EDT_DescripcionEdiconEspecialidad);
		SetWindowText(hEdit1, temporalespecialidad.especialidad);
		SetWindowText(hEdit2, temporalespecialidad.descripcion);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==IDB_GuardarEdicionEspecialidad&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, temporalespecialidad.especialidad, 19);
			GetWindowTextA(hEdit2, temporalespecialidad.descripcion, 49);
			if (CheckEdicion() == true)//Verifica si esxiste una especialidad igual con el mismo nombre
			{
				cargarEspecialidadesArchivo();
				RegresarAPunterosEdicion();
				guardarEspecialidadesArchivo();
				MessageBox(hWnd, "Guardado la edicion con exito", "Informacion", MB_ICONINFORMATION);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Especialidades), 0, ventanaEspecialidades);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Ya existe una especialidad con este nombre", "Error", MB_ICONERROR);

			}
		}
		else if (LOWORD(wParam) == IDB_RegresarEdicionEspecialidad&&HIWORD(wParam) == BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Especialidades), 0, ventanaEspecialidades);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);

	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK veentanaRegistroMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		cargarMedicosEnArchivo(medico);
		hEdit1 = GetDlgItem(hWnd, EDT_NombreDoctor);
		hEdit2 = GetDlgItem(hWnd, EDT_ApellidoPDoctor);
		hEdit3 = GetDlgItem(hWnd, EDT_ApellidoMDoctor);
		hEdit4 = GetDlgItem(hWnd, EDT_CedulaRegistro);
		hEdit5 = GetDlgItem(hWnd, EDT_NumeroDoctorRegistro);
		hEdit6 = GetDlgItem(hWnd, EDT_NumeroConsultorioRegistro);
		hEdit7 = GetDlgItem(hWnd, EDT_HoraEntradaMedico);
		hEdit8 = GetDlgItem(hWnd, EDT_HoraSalidaMedico);
		hEdit9 = GetDlgItem(hWnd, RB_Lunes);
		hEdit10 = GetDlgItem(hWnd, RB_Martes);
		hEdit11 = GetDlgItem(hWnd, RB_Miercoles);
		hEdit12 = GetDlgItem(hWnd, RB_Jueves);
		hEdit13 = GetDlgItem(hWnd, RB_Viernes);
		hEdit14 = GetDlgItem(hWnd, RB_Sabado);
		hEdit15 = GetDlgItem(hWnd, RB_Domingo);
		hEdit16 = GetDlgItem(hWnd, CB_especialidadMdico);
		medico = raiz;
		cargarEspecialidadesArchivo();
		auxespecialidad = origenespecialidad;
		limpiarTemporalMedicoPorError();
		while (auxespecialidad!=NULL)
		{
			strcpy_s(ListBoxEspecialidades, auxespecialidad->especialidad);
			auxespecialidad->sig;
			SendMessage(hEdit16, CB_ADDSTRING, 0, (LPARAM)ListBoxEspecialidades);
			auxespecialidad = auxespecialidad->sig;
		}
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == RB_Lunes&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton1 == false) {
				CheckDlgButton(hWnd, RB_Lunes, BST_UNCHECKED);
				radioCheck.RadioButton1 = true;
			}
			else if (radioCheck.RadioButton1==true)
			{
				CheckDlgButton(hWnd, RB_Lunes, BST_CHECKED);
				radioCheck.RadioButton1 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Martes&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton2 == false) {
				CheckDlgButton(hWnd, RB_Martes, BST_UNCHECKED);
				radioCheck.RadioButton2 = true;
			}
			else if (radioCheck.RadioButton2 == true)
			{
				CheckDlgButton(hWnd, RB_Martes, BST_CHECKED);
				radioCheck.RadioButton2 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Miercoles&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton3 == false) {
				CheckDlgButton(hWnd, RB_Miercoles, BST_UNCHECKED);
				radioCheck.RadioButton3 = true;
			}
			else if (radioCheck.RadioButton3 == true)
			{
				CheckDlgButton(hWnd, RB_Miercoles, BST_CHECKED);
				radioCheck.RadioButton3 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Jueves&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton4 == false) {
				CheckDlgButton(hWnd, RB_Jueves, BST_UNCHECKED);
				radioCheck.RadioButton4 = true;
			}
			else if (radioCheck.RadioButton4 == true)
			{
				CheckDlgButton(hWnd, RB_Jueves, BST_CHECKED);
				radioCheck.RadioButton4 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Viernes&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton5 == false) {
				CheckDlgButton(hWnd, RB_Viernes, BST_UNCHECKED);
				radioCheck.RadioButton5 = true;
			}
			else if (radioCheck.RadioButton5 == true)
			{
				CheckDlgButton(hWnd, RB_Viernes, BST_CHECKED);
				radioCheck.RadioButton5 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Sabado&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton6 == false) {
				CheckDlgButton(hWnd, RB_Sabado, BST_UNCHECKED);
				radioCheck.RadioButton6 = true;
			}
			else if (radioCheck.RadioButton6 == true)
			{
				CheckDlgButton(hWnd, RB_Sabado, BST_CHECKED);
				radioCheck.RadioButton6 = false;
			}
		}
		else if (LOWORD(wParam) == RB_Domingo&&HIWORD(wParam) == BN_CLICKED) {
			if (radioCheck.RadioButton7 == false) {
				CheckDlgButton(hWnd, RB_Domingo, BST_UNCHECKED);
				radioCheck.RadioButton7 = true;
			}
			else if (radioCheck.RadioButton7 == true)
			{
				CheckDlgButton(hWnd, RB_Domingo, BST_CHECKED);
				radioCheck.RadioButton7 = false;
			}
		}
		else if (LOWORD(wParam) == BTN_CargarFoto&&HIWORD(wParam) == BN_CLICKED) {
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(ofn));
			char chDirFile[MAX_PATH] = "";
			ofn.hwndOwner = hWnd;
			ofn.lStructSize = sizeof(ofn);
			ofn.lpstrFile = chDirFile;
			ofn.nMaxFile = MAX_PATH;
			ofn.lpstrDefExt = "bmp";
			ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
			ofn.lpstrFilter = "Text Files\0*.bmp\0Users\onaz\source\repos\Proyecto PrograAvanzada\Proyecto PrograAvanzada\0*.*\0";
			if (GetOpenFileName(&ofn))
			{
				hPcLatern = GetDlgItem(hWnd, PC_FotoDoctor);
				strcpy_s(direccionFotoMedicoTemporal, chDirFile);
				hBmpLatern = (HBITMAP)LoadImage(NULL, chDirFile, IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
				SendMessage(hPcLatern, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmpLatern);
			}
		}
		else if (LOWORD(wParam) == BTN_GuardarInfoDoctor&&HIWORD(wParam) == BN_CLICKED) {
			GetWindowTextA(hEdit1, temporalmedico.NombreDoctor, 48);
			GetWindowTextA(hEdit2, temporalmedico.ApellidoPaterno, 12);
			GetWindowTextA(hEdit3, temporalmedico.ApellidoMaterno, 12);
			GetWindowTextA(hEdit4, temporalmedico.CedulaChar, 15);
			temporalmedico.Cedula = atoi(temporalmedico.CedulaChar);
			GetWindowTextA(hEdit5, temporalmedico.numeroTelefonicoChar, 18);
			GetWindowTextA(hEdit6, temporalmedico.numerodeconsultorioChar, 3);
			GetWindowTextA(hEdit7, temporalmedico.HoraInicioChar, 3);
			GetWindowTextA(hEdit8, temporalmedico.HoraSalidaChar, 3);
			GetWindowTextA(hEdit16, temporalmedico.especialidadM, 19);
			strcpy_s(temporalmedico.DireccionFoto, direccionFotoMedicoTemporal);
			AgregarRBDias();
			/*cambiarHorarioDoctoresAInt();*/
			cargarMedicosEnArchivo(medico);
			medico = raiz;
			if (checkNumeroConsultorio() == true) {
				if (temporalmedico.Cedula>0)
				{
					if (verificarCedula(medico, temporalmedico) == false)
					{
						if (verificarNombreDoctor() == true)
						{
							if (verificarNombrePaciente(temporalmedico.ApellidoPaterno) == true)
							{
								if (verificarNombrePaciente(temporalmedico.ApellidoMaterno) == true) {
									if (longitudTelefonoDoctor() == true)
									{
										if (checkHoraMedico() == true)
										{
											if (temporalmedico.HoraInicio>0&&temporalmedico.HoraSalida>0)
											{
												if (strlen(temporalmedico.DireccionFoto)>5)
												{
													if (temporalmedico.especialidadM[0] != NULL)
													{
														if (verificarHorarioDoctor(medico, temporalmedico) == false)
														{
															if (verificarHorarioEntradaSalidaDoctor() == true)
															{
																if (medico == NULL)
																{
																	//	/*insertarNuevoMedico(, temporalmedico, 0);*/
																	medico = new Medicos;
																}
																insertarNuevoMedico(medico, temporalmedico, medico->padre);
																numeros.clear();
																guardarMedicosEnArchivo();
																AgregarNumeroEnQuickSort();
																MessageBox(hWnd, "Se guardo Correctamente", "Informacion", MB_ICONINFORMATION);
																DestroyWindow(hWnd);
																hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
																ShowWindow(hPrincipal, SW_SHOW);
															}
															else {
																MessageBox(hWnd, "El horario no es valido debe haber una diferencia de 20 minutos entre el horario de salida y de entrada", "Error", MB_ICONERROR);
																limpiarTemporalMedicoPorError();
															}
														}
														else
														{
															MessageBox(hWnd, "El horario del trabajo no es valido en este numero de consultorio ", "Error", MB_ICONERROR);
															limpiarTemporalMedicoPorError();
														}
													}
													else
													{
														MessageBox(hWnd, "Debe escoger una especialidad", "Error", MB_ICONERROR);
														limpiarTemporalMedicoPorError();
													}
												}
												else
												{
													MessageBox(hWnd, "Debe haber una foto del doctor", "Error", MB_ICONERROR);
													limpiarTemporalMedicoPorError();
												}
											}
											else
											{
												MessageBox(hWnd, "Ingrese numero de trabajo", "Error", MB_ICONERROR);
												limpiarTemporalMedicoPorError();
											}
										}
										else
										{
											MessageBox(hWnd, "Solo debe Ingresar numeros en las horas de trabajo", "Error", MB_ICONERROR);
											limpiarTemporalMedicoPorError();
										}
									}
									else
									{
										MessageBox(hWnd, "Longitud del Telefono Incorrecta debe ser de 11 digitos", "Error", MB_ICONERROR);
										limpiarTemporalMedicoPorError();
									}
								}
								else
								{
									MessageBox(hWnd, "Debe rellenar apellido materno", "Error", MB_ICONERROR);
									limpiarTemporalMedicoPorError();
								}
							}
							else
							{
								MessageBox(hWnd, "Debe rellenar apelldido paterno", "Error", MB_ICONERROR);
								limpiarTemporalMedicoPorError();
							}
						}
						else
						{
							MessageBox(hWnd, "Solo puede ingresar letras en el nombre del Doctor", "Error", MB_ICONERROR);
							limpiarTemporalMedicoPorError();
						}
					}
					else
					{
						MessageBox(hWnd, "Cedula profesional ya registrada", "Error", MB_ICONERROR);
						limpiarTemporalMedicoPorError();
					}
				}
				else
				{
					MessageBox(hWnd, "Ingrese una cedula", "Error", MB_ICONERROR);
					limpiarTemporalMedicoPorError();
				}
			}
			else
			{
				MessageBox(hWnd, "Solo puede ingresar Numeros en la cedula ", "Error", MB_ICONERROR);
				limpiarTemporalMedicoPorError();
			}
		}
		else if (LOWORD(wParam)==BTN_RegresarRegistro&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaRegistroPacientes(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_NombrePaciente);
		hEdit2 = GetDlgItem(hWnd, EDT_ApellidoPaternoPaciente);
		hEdit3 = GetDlgItem(hWnd, EDT_ApellidoMaternoPaciente);
		hEdit4 = GetDlgItem(hWnd, EDT_NumeroPaciente);
		hEdit5 = GetDlgItem(hWnd, EDT_Refencia);
		hEdit6 = GetDlgItem(hWnd, EDT_PrimerDoctorPacientes);
		hEdit7 = GetDlgItem(hWnd, RB_HombreRegistro);
		hEdit8 = GetDlgItem(hWnd, RB_MujerRegistro);
		hEdit9 = GetDlgItem(hWnd, DTP_NacimientoPaciente);
		hEdit10 = GetDlgItem(hWnd, EDT_EdadPacientes);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_GuardarPacientes&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, temporalpacientes.Nombre, 49);
			GetWindowTextA(hEdit2, temporalpacientes.ApellidoPaterno, 14);
			GetWindowTextA(hEdit3, temporalpacientes.ApellidoMaterno, 14);
			GetWindowTextA(hEdit4, temporalpacientes.TelefonoChar, 14);
			GetWindowTextA(hEdit5, temporalpacientes.referencia, 149);
			GetWindowTextA(hEdit6, temporalpacientes.primermedico, 49);
			GetWindowTextA(hEdit9, temporalpacientes.fechacompleta, 19);
			GetWindowTextA(hEdit10, temporalpacientes.EdadChar, 3);
			CharAIntEdadPaciente();
			time(&segundosIniciales);
			actualTime = localtime(&segundosIniciales);
			cargarPacientesArchivo();

			if (verificarNombrePaciente(temporalpacientes.Nombre)==true)
			{
				if (verificarNombrePaciente(temporalpacientes.ApellidoPaterno)==true)
				{
					if (verificarNombrePaciente(temporalpacientes.ApellidoMaterno)==true)
					{
						if (longitudTelefonoPaciente()==true)
						{
							if (temporalpacientes.referencia[0]!=NULL)
							{
								if (temporalpacientes.primermedico[0]!=NULL)
								{
									if (verificarFechaPaciente()==true)
									{
										if (radioCheckPacientes.RadioButton1==false||radioCheckPacientes.RadioButton2==false)
										{
											if (CharAIntEdadPaciente()==true)
											{
												if (temporalpacientes.Edad<100&&temporalpacientes.Edad>=0)
												{
													AgregarRBSexo();
													temporalpacientes.Telefono = atof(temporalpacientes.TelefonoChar);
													agregarPacientes();
													ordenarPacientesHP();
													guardarPacientesArchivo();
													hacerListaHP();
													reporteHP();
													MessageBox(hWnd, "Paciente guardado correctamente", "Informacion", MB_ICONINFORMATION);
													hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
													DestroyWindow(hWnd);
													ShowWindow(hPrincipal, SW_SHOW);
												}
												else
												{
													MessageBox(hWnd, "La edad debe ser menor a 100 años o mayor a 0", "Error", MB_ICONERROR);
												}
											}
											else
											{
												MessageBox(hWnd, "Error en la edad verifique la informacion", "Error", MB_ICONERROR);
											}
										}
										else
										{
											MessageBox(hWnd, "Eliga Sexo", "Error", MB_ICONERROR);
										}
									}
									else
									{
										MessageBox(hWnd, "Fecha del paciente incorrecto", "Error", MB_ICONERROR);
									}
								}
								else
								{
									MessageBox(hWnd, "Debe ingresar un medico, si es la primera vez solo ingrese un espacio ", "ERROR", MB_ICONERROR);
								}
							}
							else
							{
								MessageBox(hWnd, "Debe llenar la referencia ", "ERROR", MB_ICONERROR);
							}
						}
						else
						{
							MessageBox(hWnd, "Longitud del telefono incorrecta, debe ser 11 digitos ", "ERROR", MB_ICONERROR);
						}
					}
					else
					{
						MessageBox(hWnd, "Error en el apellido materno del paciente,solo puede ingresar letras ", "ERROR", MB_ICONERROR);
					}
				}
				else
				{
					MessageBox(hWnd, "Error en el apellido paterno de paciente, solo puede ingresar letras  ", "ERROR", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Error en el nombre del paciente,solo puede ingresar letras ", "ERROR", MB_ICONERROR);
			}
			
		}
		else if (LOWORD(wParam)==RB_HombreRegistro &&HIWORD(wParam)==BN_CLICKED)
		{
			if (radioCheckPacientes.RadioButton1==false) {
				CheckDlgButton(hWnd, RB_HombreRegistro, BST_UNCHECKED);
				radioCheckPacientes.RadioButton1 = true;
			}
			else if (radioCheckPacientes.RadioButton1==true)
			{
				CheckDlgButton(hWnd, RB_HombreRegistro, BST_CHECKED);
				radioCheckPacientes.RadioButton1 = false;
			}
		}
		else if (LOWORD(wParam)==RB_MujerRegistro&&HIWORD(wParam)==BN_CLICKED)
		{
			if (radioCheckPacientes.RadioButton2 == false) {
				CheckDlgButton(hWnd, RB_MujerRegistro, BST_UNCHECKED);
				radioCheckPacientes.RadioButton2 = true;
			}
			else if (radioCheckPacientes.RadioButton2==true)
			{
				CheckDlgButton(hWnd, RB_MujerRegistro, BST_CHECKED);
				radioCheckPacientes.RadioButton1 = false;
			}
		}
		else if (LOWORD(wParam)==BTN_RegresarPacientes &&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaRegistroDeCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, CB_Pacientes);
		hEdit2 = GetDlgItem(hWnd, CB_Especialidad);
		hEdit3 = GetDlgItem(hWnd, CB_Medicos);
		hEdit4 = GetDlgItem(hWnd, DTP_DiaDeCita);
		hEdit5 = GetDlgItem(hWnd, DTP_HoraDeCita);
		cargarEspecialidadesArchivo();
		auxespecialidad = origenespecialidad;
		while (auxespecialidad!=NULL)
		{
			memset(ListBoxDeCitas, NULL, 300);
			strcpy_s(ListBoxDeCitas, auxespecialidad->especialidad);
			strcat(ListBoxDeCitas, " ");
			SendMessage(hEdit2, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
			auxespecialidad = auxespecialidad->sig;
		}
		cargarPacientesArchivo();
		auxpacientes = origenpacientes;
		while (auxpacientes!=NULL)
		{
			memset(ListBoxDeCitas, NULL, 300);
			strcpy_s(ListBoxDeCitas, auxpacientes->Nombre);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->ApellidoPaterno);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->ApellidoMaterno);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->TelefonoChar);

			SendMessage(hEdit1, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
			auxpacientes = auxpacientes->sig;
		}
		cargarMedicosEnArchivo(medico);
		medico = raiz;
		mostrarArbolenComboBox(medico);
		cargarCitasArchivo();

	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == BTN_GuardarCita&&HIWORD(wParam) == BN_CLICKED) {

			GetWindowTextA(hEdit4, temporalcitas.FechaDeCita, 50);
			GetWindowTextA(hEdit5, temporalcitas.horacompleta, 19);
			GetWindowTextA(hEdit3, comparacionDoctorCita, 99); 
			GetWindowTextA(hEdit1, comparacionPaciente,49);
			GetWindowTextA(hEdit2, comparacionEspecialidad, 29);
			
			if (comparacionDoctorCita[0]!=NULL)
			{

				if (comparacionPaciente[0]!=NULL)
				{
					if (comparacionEspecialidad[0]!=NULL)
					{
						cambiarIntAConsulta();
						transformarMesAIntCitas();
						ObtenerNombreDoctorCita();
						ObtenerNumeroEspecialidadCita();
						ObtenerTelefonoCita();
						cargarMedicosEnArchivo(medico);
						EncontrarDoctorParaCita(medico);
						if (temporalcitas.FechaDeCita[0] != NULL)
						{
							if (temporalcitas.horacompleta[0] != NULL)
							{
								if (especialidadesIgual() == true)
								{
									if (verificacionDiaDeFecha() == true)
									{
										if (verificarCita() == true)
										{
											cargarCitasArchivo();
											agregarCitas();
											guardarCitasArchivo();
											hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MostrarCita), 0, ventanaMostrarCita);
											DestroyWindow(hWnd);
											ShowWindow(hPrincipal, SW_SHOW);
										}
										else
										{
											MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
										}
									}
									else
									{
										MessageBox(hWnd, "El dia que selecciono al Medico no es en ese Horario o Su dia de trabajo por favor escoge a otro", "Error", MB_ICONERROR);
									}
								}
								else
								{
									MessageBox(hWnd, "La especialidad escogida el doctor que seleciono no esta disponible", "Error", MB_ICONERROR);
								}

							}
							else
							{
								MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
							}
						}
						else
						{
							MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
						}
					}
					else
					{
						MessageBox(hWnd, "Rellene la informacion", "Error", MB_ICONERROR);
					}
				}
				else
				{
					MessageBox(hWnd, "Rellene la informacion", "Error", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Rellene la informacion", "Error", MB_ICONERROR);
			}
		}
		else if (LOWORD(wParam) == CB_Pacientes&&HIWORD(wParam) == CBN_SELCHANGE) {
			PacientesDeListBox = (int)SendMessage(hEdit1, CB_GETCURSEL, 0, 0);
			SeleccionDeListBoxPacientes = PacientesDeListBox;
		}
		else if (LOWORD(wParam)==CB_Especialidad&&HIWORD(wParam)== CBN_SELCHANGE)
		{
			EspecialidadDeListBox = (int)SendMessage(hEdit2, CB_GETCURSEL, 0, 0);
		}
		else if (LOWORD(wParam)==CB_Medicos&&HIWORD(wParam)== CBN_SELCHANGE)
		{
			/*MedicosDeListBox = (int)SendMessage(hEdit3, CB_GETCURSEL, 0, 0);*/

		}
		else if (LOWORD(wParam)==BTN_RegresarGuardar&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaMostrarCita(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		cargarMedicosEnArchivo(medico);
		cargarEspecialidadesArchivo();
		cargarPacientesArchivo();
		auxespecialidad = origenespecialidad;
		auxpacientes = origenpacientes;
		medico = raiz;
		char Texto[20];
		memset(Texto, NULL, 20); 
		memset(TextoDoctor, NULL, 20);
		EncontrarNombreDoctor(medico);
		EncontrarPacienteCita();
		EncontrarEspecialidadCita();
		strcpy_s(TextoPaciente, temporalcitas.nombrePaciente);
		hEdit1 = GetDlgItem(hWnd, ST_PacienteCita);
		hEdit2 = GetDlgItem(hWnd, ST_DoctorCita);
		hEdit3 = GetDlgItem(hWnd, ST_EspecialidadCita);
		hEdit4 = GetDlgItem(hWnd, ST_NumeroTelefonicoCita);
		hEdit5 = GetDlgItem(hWnd, ST_HoraInicio);
		hEdit6 = GetDlgItem(hWnd, ST_HoraFinal);
		hEdit7 = GetDlgItem(hWnd, PC_DoctorConsulta);
		hEdit8 = GetDlgItem(hWnd, ST_FechaCompletaCita);
		SetWindowText(hEdit4, temporalcitas.numeroTelefonicoPacienteChar);
		SetWindowText(hEdit2, TextoDoctor);
		SetWindowText(hEdit1, TextoPaciente);
		SetWindowText(hEdit3, TextoEspecialidad);
		strcpy_s(Texto, temporalcitas.HoraInicioChar);
		strcat(Texto, temporalcitas.MinutosInicioChar);
		SetWindowText(hEdit5, Texto);
		strcpy_s(Texto, temporalcitas.HoraFinalChar);
		strcat(Texto, temporalcitas.MinutosFinalChar);
		SetWindowText(hEdit6, Texto);
		hPcLatern = GetDlgItem(hWnd, PC_DoctorConsulta);
		hBmpLatern = (HBITMAP)LoadImage(NULL, temporalcitas.DireccionFotoDoctor, IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
		SendMessage(hPcLatern, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmpLatern);
		SetWindowText(hEdit8, temporalcitas.FechaDeCita);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_OkCita&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaVerCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, LB_Citas);
		cargarCitasArchivo();
		auxcitas = origencitas;
		while (auxcitas!=NULL)
		{ 
			if (auxcitas->cancelada==false)
			{
				memset(ListBoxCitasWnd, NULL, 150);
				strcpy_s(ListBoxCitasWnd, auxcitas->nombrePaciente);
				strcat(ListBoxCitasWnd, " ");
				strcat(ListBoxCitasWnd, auxcitas->nombreDoctor);
				strcat(ListBoxCitasWnd, " ");
				strcat(ListBoxCitasWnd, auxcitas->FechaDeCita);
				strcat(ListBoxCitasWnd, " ");
				strcat(ListBoxCitasWnd, auxcitas->horacompleta);
				SendMessage(hEdit1, LB_ADDSTRING, 0, (LPARAM)ListBoxCitasWnd);
			}
			auxcitas = auxcitas->sig;
		}
		CitasListBox = -1;
	}return FALSE;
	case WM_COMMAND : {
		if (LOWORD(wParam) == LB_Citas&&HIWORD(wParam) == LBN_SELCHANGE)
		{
			CitasListBox = (int)SendMessage(hEdit1, LB_GETCURSEL, 0, 0);
		}
		else if (LOWORD(wParam) == BTN_CompletadoCita && HIWORD(wParam) == BN_CLICKED) {
			CompletarCita();
			guardarCitasArchivo();
			cargarCitasArchivo();
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita),0,ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam)==BTN_CancelarCita && HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Cancelacion), 0, ventanaCancelacionCita);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if(LOWORD(wParam)==BTN_EditarCita&&HIWORD(wParam)==BN_CLICKED)
		{
			escogerMedicoEdicion();
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_RegistroCitas), 0, ventanaEdicionCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam)==BTN_MedicoCitas&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_BuscardorCitasMedico), 0, ventanaBuscadorMedicoCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam)==BTN_SemanaCitas&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_BuscardorCitasSemana), 0, ventanaBuscadorSemanaCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam) == BTN_EspecialidadCitas&&HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_BuscadorEspecialidad), 0, ventanaBuscadorEspecialidadCita);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam)==BTN_RegresarCitas&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {

	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaCancelacionCita(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_Cancelacion);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_ConfirmarCancelacion&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, temporalcitas.motivodeCancelacion, 19);
			CancelarCita();
			guardarCitasArchivo();
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam) == BTN_RegresarCancelacion&&HIWORD(wParam) == BN_CLICKED) {
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaBuscadorMedicoCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_BuscadorMedicosCitas);
		hEdit2 = GetDlgItem(hWnd, EDT_NumeroDeMesCita);
		auxcitasemana = origencitasemana = NULL;
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_ContinuarMedicoCitas&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, TextoDoctor, 15);
			GetWindowTextA(hEdit2, TextoMesDeCita, 15);
			if (verificacionCedulaBuscadorMedico()==true)
			{
				if(verificacionMesBuscadorMedico()==true){
					medico = raiz;
					cargarMedicosEnArchivo(medico);
					cargarCitasArchivo();
					encontrarMedicoCitas(medico);
					encontrarMesCitas();
					mandarReporteMedico();
					MessageBox(hWnd, "Reeporte registrado correctamente","Informacion",MB_ICONINFORMATION);
						hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
					DestroyWindow(hWnd);
					ShowWindow(hPrincipal, SW_SHOW);
				}
			}
		}
		else if (LOWORD(wParam)==BTN_regresarconsultacitasmedico&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaConsultaMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, LB_CitasMedico);
		medico = raiz;
		cargarMedicosEnArchivo(medico);
		cargarCitasArchivo();
		encontrarMedicoCitas(medico);
		encontrarMesCitas();
		SendMessage(hEdit1, LB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_OkMedico&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaBuscadorSemanaCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		memset(TextoMesDeCita, NULL, 20);
		hEdit1 = GetDlgItem(hWnd, EDT_NumeroDeSemanaCita);
		hEdit2 = GetDlgItem(hWnd, EDT_NumeroDeMesCita);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_BuscarSemanaCita&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, TextoSemana, 4);
			GetWindowTextA(hEdit2, TextoMesDeCita, 4);
			if (verificacionCitasSemanas()==true)
			{
				BuscarSemanaCita();
				mandarReporte();
				MessageBox(hWnd, "Reporte generado con exito", "Informacion", MB_ICONINFORMATION);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Error", "Informacion", MB_ICONINFORMATION);
			}
		}
		else if (LOWORD(wParam)==BTN_RegresarSemanaCita&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaBuscadorEspecialidadCita(HWND hWnd ,UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_buscadorEspecialidad);
		hEdit2 = GetDlgItem(hWnd, EDT_buscadorSemanaEspecialidad);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == BTN_BuscadorEspecialidad&&HIWORD(wParam) == BN_CLICKED) {
			GetWindowTextA(hEdit1, TextoEspecialidad, 19);
			GetWindowTextA(hEdit2, TextoSemana, 2);
			if (verificacionCitasSemanas() == true)
			{
				if (verificacionEspecialidadBuscador() == true)
				{
					if (buscarEspcialidadCita() == true) {
						mandarReporteespecialidad();
						MessageBox(hWnd, "Reporte generado con exito en archivo de texto", "Informacion", MB_ICONINFORMATION);
						hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
						DestroyWindow(hWnd);
						ShowWindow(hPrincipal, SW_SHOW);
					}
					else
					{
						MessageBox(hWnd, "No se encontro una especialidad con ese nombre", "Error", MB_ICONERROR);
						hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
						DestroyWindow(hWnd);
						ShowWindow(hPrincipal, SW_SHOW);
					}
				}
				else
				{
					MessageBox(hWnd, "Error al ingresar el numero de la semana debe ser 1 a 4", "Error", MB_ICONERROR);
				}
			}
		}
		else if(LOWORD(wParam)==BTN_regresarbuscadorespecialidad &&HIWORD(wParam)==BN_CLICKED)
		{
								hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
					DestroyWindow(hWnd);
					ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaMostrarPacientes(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		limpiarTemporalMedicoPorError();
		limpiarTemporalPacientesPorError();
		hEdit1 = GetDlgItem(hWnd, LB_AllPacientes);
		cargarPacientesArchivo();
		auxpacientes = origenpacientes;
		PacientesDeListBox = -1;
		while (auxpacientes!=NULL)
		{
			memset(ListBoxPacientes, NULL, 150);
			strcpy_s(ListBoxPacientes, auxpacientes->Nombre);
			strcat(ListBoxPacientes, " ");
			strcat(ListBoxPacientes, auxpacientes->ApellidoPaterno);
			strcat(ListBoxPacientes, " ");
			strcat(ListBoxPacientes, auxpacientes->ApellidoMaterno);
			strcat(ListBoxPacientes, " ");
			strcat(ListBoxPacientes, auxpacientes->TelefonoChar);
			SendMessage(hEdit1, LB_ADDSTRING, 0, (LPARAM)ListBoxPacientes);
			auxpacientes = auxpacientes->sig;
		}
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==LB_AllPacientes&&HIWORD(wParam)==LBN_SELCHANGE)
		{
			PacientesDeListBox = (int)SendMessage(hEdit1, LB_GETCURSEL, 0, 0);
		}
		else if (LOWORD(wParam)==BTN_CambiarPaciente&&HIWORD(wParam)==BN_CLICKED)
		{
			seleccionEdicionPaciente();
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_editarPacientes), 0, ventanaEdicionPaciente);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
		else if (LOWORD(wParam)==BTN_EliminarPaciente&&HIWORD(wParam)==BN_CLICKED)
		{
			if (PacientesDeListBox!=-1)
			{
				eliminarPacientes();
				guardarPacientesArchivo();
				MessageBox(hWnd, "Paciente eliminado con exito", "Informacion", MB_ICONINFORMATION);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MostrarPacientes), 0, ventanaMostrarPacientes);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Eliga un paciente", "Informacion", MB_ICONINFORMATION);
			}
		}
		else if (LOWORD(wParam)==BTN_regresarTPacientes)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {

	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaEdicionPaciente(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd,EDT_NombreEdicionPacieente);
		hEdit2 = GetDlgItem(hWnd, EDT_ApellidoPEP);
		hEdit3 = GetDlgItem(hWnd, EDT_ApellidoMEP);
		hEdit4 = GetDlgItem(hWnd, EDT_NumeroTelefoniocoEP);
		SetWindowText(hEdit1, temporalpacientes.Nombre);
		SetWindowText(hEdit2, temporalpacientes.ApellidoPaterno);
		SetWindowText(hEdit3, temporalpacientes.ApellidoMaterno);
		SetWindowText(hEdit4, temporalpacientes.TelefonoChar);

	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_GuardarEdicion&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, temporalpacientes.Nombre, 49);
			GetWindowTextA(hEdit2, temporalpacientes.ApellidoPaterno, 14);
			GetWindowTextA(hEdit3, temporalpacientes.ApellidoMaterno, 14);
			GetWindowTextA(hEdit4, temporalpacientes.TelefonoChar, 14);
			if (verificarNombrePaciente(temporalpacientes.Nombre)==true)
			{
				if (verificarNombrePaciente(temporalpacientes.ApellidoPaterno)==true) {
					if (verificarNombrePaciente(temporalpacientes.ApellidoMaterno)==true)
					{
						if (longitudTelefonoPaciente()==true) {
							temporalpacientes.Telefono=atof(temporalpacientes.TelefonoChar);
							cargarPacientesArchivo();
							editarPacientesSel();
							ordenarPacientesHP();
							guardarPacientesArchivo();
							MessageBox(hWnd, "Modificado Correctamente", "Informacion", MB_ICONINFORMATION);
							hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MostrarPacientes), 0, ventanaMostrarPacientes);
							DestroyWindow(hWnd);
							ShowWindow(hPrincipal, SW_SHOW);
						}
						else
						{
							MessageBox(hWnd, "La longitud del telefono debe ser de 11 digitos", "Error", MB_ICONERROR);
						}
					}
					else
					{
						MessageBox(hWnd, "Error en el apellido materno del paciente, favor de modificarlo", "Error", MB_ICONERROR);
					}
				}
				else
				{
					MessageBox(hWnd, "Error en el apellido paterno del paciente, favor de modificarlo", "Error", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Error en el nombre del paciente, favor de modificarlo", "Error", MB_ICONERROR);
			}
		}
		else if (LOWORD(wParam)==BTN_RegresarEdicionP&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MostrarPacientes), 0, ventanaMostrarPacientes);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {

	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaMostrarMedico(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		cargarMedicosEnArchivo(medico);
		medico = raiz;
		hEdit1 = GetDlgItem(hWnd, LB_allMedicos);
		hEdit2 = GetDlgItem(hWnd, EDT_cedulabuscarmedico);
		mostrarArbolEnListBox(medico);
		medico = raiz;
		limpiarTemporalMedicoPorError();
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_EliminarMedico&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit2, temporalmedico.CedulaChar, 15);
			temporalmedico.Cedula = atoi(temporalmedico.CedulaChar);
			if (temporalmedico.CedulaChar[0]!=NULL)
			{
				buscareliminar(medico, temporalmedico);
				guardarMedicosEnArchivo();
				MessageBox(hWnd, "Eliminado correctamente", "Informacion", MB_ICONINFORMATION);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_mostrarMedicos), 0, ventanaMostrarMedico);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);
			}
			else
			{
				MessageBox(hWnd, "Digite la cedula del doctor", "Error", MB_ICONINFORMATION);
			}

			
		}
		else if (LOWORD(wParam)==BTN_editarMedico&&HIWORD(wParam)==BN_CLICKED)
		{

			GetWindowTextA(hEdit2, temporalmedico.CedulaChar, 15);
			temporalmedico.Cedula = atoi(temporalmedico.CedulaChar);
			if (temporalmedico.CedulaChar[0]!=NULL)
			{
				mostrarMedicoAEditar(medico);
				hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_edicionMedicos), 0, ventanaEdicionMedico);
				DestroyWindow(hWnd);
				ShowWindow(hPrincipal, SW_SHOW);

			}
		}
		else if (LOWORD(wParam)==BTN_regresarmostrarMedico&&HIWORD(wParam)==BN_CLICKED )
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Menu), 0, ventanaMenu);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	case WM_CLOSE: {

	}
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaEdicionMedico(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, EDT_EditarNombreMedico);
		hEdit2 = GetDlgItem(hWnd, EDT_EditarApellidoPMedico);
		hEdit3 = GetDlgItem(hWnd, EDT_ApellidoMMedico);
		hEdit4 = GetDlgItem(hWnd, EDT_numeroTEdicionMedico);
		SetWindowText(hEdit1, temporalmedico.NombreDoctor);
		SetWindowText(hEdit2, temporalmedico.ApellidoPaterno);
		SetWindowText(hEdit3, temporalmedico.ApellidoMaterno);
		SetWindowText(hEdit4, temporalmedico.numeroTelefonicoChar);
		medico = raiz;
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam)==BTN_guardarEdiconMedico&&HIWORD(wParam)==BN_CLICKED)
		{
			GetWindowTextA(hEdit1, temporalmedico.NombreDoctor, 49);
			GetWindowTextA(hEdit2, temporalmedico.ApellidoPaterno, 14);
			GetWindowTextA(hEdit3, temporalmedico.ApellidoMaterno, 14);
			GetWindowTextA(hEdit4, temporalmedico.numeroTelefonicoChar, 19);
			if (verificarNombrePaciente(temporalmedico.NombreDoctor)==true)
			{
				if (verificarNombrePaciente(temporalmedico.ApellidoMaterno)==true) {
					if (verificarNombrePaciente(temporalmedico.ApellidoPaterno)==true)
					{
						if (longitudTelefonoDoctor()==true)
						{
							hacerEdicion(medico);
							guardarMedicosEnArchivo(); 
							MessageBox(hWnd, "Medico Editado correctamente", "Informacion", MB_ICONINFORMATION);
							hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_mostrarMedicos), 0, ventanaMostrarMedico);
							DestroyWindow(hWnd);
							ShowWindow(hPrincipal, SW_SHOW);
						}
					}
				}
			}
		}
		else if (LOWORD(wParam)==BTN_regresarEdicionMedico&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_mostrarMedicos), 0, ventanaMostrarMedico);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
BOOL CALLBACK ventanaEdicionCitas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {
		hEdit1 = GetDlgItem(hWnd, CB_Pacientes);
		hEdit2 = GetDlgItem(hWnd, CB_Especialidad);
		hEdit3 = GetDlgItem(hWnd, CB_Medicos);
		hEdit4 = GetDlgItem(hWnd, DTP_DiaDeCita);
		hEdit5 = GetDlgItem(hWnd, DTP_HoraDeCita);
		cargarEspecialidadesArchivo();
		auxespecialidad = origenespecialidad;
		while (auxespecialidad != NULL)
		{
			memset(ListBoxDeCitas, NULL, 300);
			strcpy_s(ListBoxDeCitas, auxespecialidad->especialidad);
			strcat(ListBoxDeCitas, " ");
			SendMessage(hEdit2, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
			auxespecialidad = auxespecialidad->sig;
		}
		cargarPacientesArchivo();
		auxpacientes = origenpacientes;
		while (auxpacientes != NULL)
		{
			memset(ListBoxDeCitas, NULL, 300);
			strcpy_s(ListBoxDeCitas, auxpacientes->Nombre);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->ApellidoPaterno);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->ApellidoMaterno);
			strcat(ListBoxDeCitas, " ");
			strcat(ListBoxDeCitas, auxpacientes->TelefonoChar);

			SendMessage(hEdit1, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
			auxpacientes = auxpacientes->sig;
		}
		cargarMedicosEnArchivo(medico);
		medico = raiz;
		mostrarArbolenComboBox(medico);
		cargarCitasArchivo();
		SetWindowText(hEdit4, temporalcitas.FechaDeCita);
		SetWindowText(hEdit5, temporalcitas.horacompleta);
		SetWindowText(hEdit1, temporalcitas.nombrePaciente);
		SetWindowText(hEdit3, temporalcitas.nombreDoctor);
	}return FALSE;
	case WM_COMMAND: {
		if (LOWORD(wParam) == BTN_GuardarCita&&HIWORD(wParam) == BN_CLICKED) {

			GetWindowTextA(hEdit4, temporalcitas.FechaDeCita, 50);
			GetWindowTextA(hEdit5, temporalcitas.horacompleta, 19);
			GetWindowTextA(hEdit3, comparacionDoctorCita, 99);
			GetWindowTextA(hEdit1, comparacionPaciente, 49);
			GetWindowTextA(hEdit2, comparacionEspecialidad, 29);
			cambiarIntAConsulta();
			transformarMesAIntCitas();
			ObtenerNombreDoctorCita();
			ObtenerNumeroEspecialidadCita();
			ObtenerTelefonoCita();
			cargarMedicosEnArchivo(medico);
			EncontrarDoctorParaCitaEdicion(medico);

			if (temporalcitas.FechaDeCita[0] != NULL)
			{
				if (temporalcitas.horacompleta[0] != NULL)
				{
					if (especialidadesIgual() == true)
					{
						if (verificacionDiaDeFecha() == true)
						{
							if (verificarCita() == true)
							{
								guardarEdicionCitas();
								guardarCitasArchivo();
								hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
								DestroyWindow(hWnd);
								ShowWindow(hPrincipal, SW_SHOW);
							}
							else
							{
								MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
							}
						}
						else
						{
							MessageBox(hWnd, "El dia que selecciono al Medico no es en ese Horario o Su dia de trabajo por favor escoge a otro", "Error", MB_ICONERROR);
						}
					}
					else
					{
						MessageBox(hWnd, "La especialidad escogida el doctor que seleciono no esta disponible", "Error", MB_ICONERROR);
					}

				}
				else
				{
					MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(hWnd, "Debe escoger para su cita", "Error", MB_ICONERROR);
			}
		}
		else if (LOWORD(wParam)==BTN_RegresarGuardar&&HIWORD(wParam)==BN_CLICKED)
		{
			hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_ConsultaCita), 0, ventanaVerCitas);
			DestroyWindow(hWnd);
			ShowWindow(hPrincipal, SW_SHOW);
		}
	}return FALSE;
	default:
		break;
	}return FALSE;
}
void agregarUsuario()
{
	auxusers = origenusers;
	if (origenusers == NULL)//SI NO HAY NINGUN USUARIO CAE AQUI
	{
		origenusers = new Users;
		origenusers->Nombre;
		strcpy_s(origenusers->Nombre, temporalusers.Nombre);
		strcpy_s(origenusers->Pass, temporalusers.Pass);
		strcpy_s(origenusers->Usuario, temporalusers.Usuario);
		origenusers->sig = NULL;
		origenusers->ant = NULL;
	}
	else
	{
		while (auxusers->sig != NULL)
			auxusers = auxusers->sig;
		auxusers->sig = new Users;
		auxusers->sig->ant = auxusers;
		auxusers = auxusers->sig;
		strcpy_s(auxusers->Nombre, temporalusers.Nombre);
		strcpy_s(auxusers->Usuario, temporalusers.Usuario);
		strcpy_s(auxusers->Pass, temporalusers.Pass);
		auxusers->sig = NULL;
	}
	auxusers = origenusers;
 }
void guardarUsuarioEnArchivo()
{
	auxusers = origenusers;
	fstream archivo;
	archivo.open("usuarios.txt", ios::out);
	if (archivo.is_open())
	{
		Users *temp = origenusers;
		while (temp!=NULL)
		{
			archivo.write(reinterpret_cast<char*>(temp), sizeof(Users));
			temp = temp->sig;
		}
		archivo.close();
		return;
	}
}
void cargarUsuariosDeArchivo()
{
	auxusers = origenusers = NULL;
	fstream archivo;
	archivo.open("usuarios.txt", ios::in | ios::ate);
	if (archivo.is_open())
	{
		int size = archivo.tellg();
		if (size == 0) {
			return;
		}
		for (int i = 0; i < (size / sizeof(Users)); i++) {
			if (origenusers == NULL) {
				origenusers = new Users;
				Users *temp = new Users;
				archivo.seekg(0);
				archivo.read(reinterpret_cast<char*>(temp), sizeof(Users));
				strcpy_s(origenusers->Nombre, temp->Nombre);
				strcpy_s(origenusers->Pass, temp->Pass);
				strcpy_s(origenusers->Usuario, temp->Usuario);
				origenusers->ant = NULL;
				origenusers->sig = NULL;
				delete reinterpret_cast<char*>(temp);
				continue;
			}
			auxusers = origenusers;
			while (auxusers->sig != NULL)
				auxusers = auxusers->sig;
			auxusers->sig = new Users;
			Users*temp = new Users;
			archivo.seekg(i * sizeof(Users));
			archivo.read(reinterpret_cast<char*>(temp), sizeof(Users));
			auxusers->sig->ant = auxusers;
			auxusers->sig->sig = NULL;
			auxusers = auxusers->sig;
			auxespecialidad = auxespecialidad->sig;
			strcpy_s(auxusers->Nombre, temp->Nombre);
			strcpy_s(auxusers->Pass, temp->Pass);
			strcpy_s(auxusers->Usuario, temp->Usuario);
			delete reinterpret_cast<char*>(temp);
		}
		archivo.close();
		return;
	}
}
void agregarEspecialidad() //agrega Especialidades a la lista
{
	auxespecialidad = origenespecialidad;
	if (origenespecialidad == NULL)
	{
		origenespecialidad = new especialidades;
		strcpy_s(origenespecialidad->especialidad, temporalespecialidad.especialidad);
		strcpy_s(origenespecialidad->descripcion, temporalespecialidad.especialidad);
		origenespecialidad->numero =  1;
		origenespecialidad->sig = NULL;
		origenespecialidad->ant = NULL;


	}
	else
	{
		while (auxespecialidad->sig != NULL) 
			auxespecialidad = auxespecialidad->sig;
		auxespecialidad->sig = new especialidades;
		auxespecialidad->sig->ant = auxespecialidad;
		auxespecialidad = auxespecialidad->sig;
		strcpy_s(auxespecialidad->especialidad, temporalespecialidad.especialidad);
		strcpy_s(auxespecialidad->descripcion, temporalespecialidad.descripcion);
		auxespecialidad->numero =auxespecialidad->ant->numero+1;
		auxespecialidad->sig = NULL;
	}
	auxespecialidad = origenespecialidad;
}
bool verificarUsuarios() //verifica si hay usuarios con ese nombre
{
	auxusers = origenusers;
	while (auxusers!=NULL)
	{
		if (strcmp(auxusers->Usuario, temporalusers.Usuario) == 0)
		{
			return false;
		}
		auxusers = auxusers->sig;
	}
	return true;//No hay ningun usuario con ese usuario antes
	auxusers = origenusers;
}
bool accesoUsuario() //Les da acceso a los usuarios registrados
{
	auxusers = origenusers;
	while (auxusers!=NULL)
	{
		if (strcmp(auxusers->Usuario, temporalusers.Usuario) == 0) {
			if (strcmp(auxusers->Pass, temporalusers.Pass) == 0) {
				return true;
			}
		}
		auxusers = auxusers->sig;
	}
	return false;
	auxusers = origenusers;
}
bool verificarPass()//Verifica si la contra que puso es correcta
{
	if (strcmp(temporalusers.Pass,passUserCheck)==0)
	{
		return true;
	}
	return false;
}
bool verificarEspecialidad() //Verifica si la especialidad recibida existe o no 
{
	auxespecialidad = origenespecialidad;
	while (auxespecialidad!=NULL)
	{
		if (strcmp(auxespecialidad->especialidad,temporalespecialidad.especialidad)==0)
		{
			return false; //Esto quiere decir que si existe otra especialidad con este nombre
		}
		auxespecialidad = auxespecialidad->sig;
	}
	return true; //No existe otra especialidad
	auxespecialidad = origenespecialidad;
}
void guardarEspecialidadesArchivo() {
	auxespecialidad = origenespecialidad;
	fstream archivo;
	archivo.open("especialidades.bin", ios::binary | ios::trunc | ios::out);
	if (archivo.is_open()) {
		especialidades *temp = origenespecialidad;
		while (temp !=NULL)
		{
			archivo.write(reinterpret_cast<char*>(temp), sizeof(especialidades));
			temp=temp->sig;
		}
		archivo.close();
		return;
	}

}
void cargarEspecialidadesArchivo() {
	auxespecialidad = origenespecialidad = NULL;
	fstream archivo;
	archivo.open("especialidades.bin", ios::binary | ios::in | ios::ate);
	if (archivo.is_open())
	{
		int size = archivo.tellg();
		if (size == 0) {
			return;
		}
		for (int i = 0; i < (size / sizeof(especialidades)); i++) {
			if (origenespecialidad == NULL) {
				origenespecialidad = new especialidades;
				especialidades *temp = new especialidades;
				archivo.seekg(0);
				archivo.read(reinterpret_cast<char*>(temp), sizeof(especialidades));
				strcpy_s(origenespecialidad->especialidad, temp->especialidad);
				strcpy_s(origenespecialidad->descripcion, temp->descripcion);
				origenespecialidad->numero = temp->numero;
				origenespecialidad->ant = NULL;
				origenespecialidad->sig = NULL;
				delete reinterpret_cast<char*>(temp);
				continue;
			}
			auxespecialidad = origenespecialidad;
			while (auxespecialidad->sig != NULL)
				auxespecialidad = auxespecialidad->sig;
			auxespecialidad->sig = new especialidades;
			especialidades *temp = new especialidades;
			archivo.seekg(i * sizeof(especialidades));
			archivo.read(reinterpret_cast<char*>(temp), sizeof(especialidades));
			auxespecialidad->sig->ant = auxespecialidad;
			auxespecialidad->sig->sig = NULL;
			auxespecialidad = auxespecialidad->sig;
			strcpy_s(auxespecialidad->especialidad, temp->especialidad);
			strcpy_s(auxespecialidad->descripcion, temp->descripcion);
			auxespecialidad->numero = temp->numero;
			delete reinterpret_cast<char*>(temp);

		}
		archivo.close();
		return;
	}
	return;
}
void borrarEspecialidad() {
	auxespecialidad = origenespecialidad;
	int contador = 0;
	char Comparable[20];
	while (auxespecialidad!=NULL)//Cuenta con la variable especialidaddelistbox y contador hasta que sea igual para ver cual se va a borrar
	{
		if (EspecialidadDeListBox==contador)
		{
			strcpy_s(Comparable, auxespecialidad->especialidad);
			break;
		}	
	auxespecialidad = auxespecialidad->sig;
	contador++;
	}

	if (auxespecialidad != NULL)
	{
		while (strcmp(Comparable,auxespecialidad->especialidad)!=0)
		{
			if (auxespecialidad->sig==NULL)
			{
				return;
			}
			auxespecialidad = auxespecialidad->sig;
		}
		if (auxespecialidad->ant==NULL&& auxespecialidad->sig==NULL)//UNICO NODO
		{
			delete auxespecialidad;
			auxespecialidad = origenespecialidad = NULL;
		}
		else if (auxespecialidad->ant==NULL)//PRIMER NODO
		{
			origenespecialidad = auxespecialidad->sig;
			delete auxespecialidad;
			origenespecialidad->ant = NULL;
			auxespecialidad = origenespecialidad;
		}
		else if (auxespecialidad->sig==NULL)
		{
			auxespecialidad->ant->sig = NULL;
			delete auxespecialidad;
			auxespecialidad = origenespecialidad;
		}
		else
		{
			auxespecialidad->ant->sig = auxespecialidad->sig;
			auxespecialidad->sig->ant = auxespecialidad->ant;
			delete auxespecialidad;
			auxespecialidad = origenespecialidad;
		}
	}
	auxespecialidad = origenespecialidad;
	return;
}
void EditarEspecialidad() {
	auxespecialidad = origenespecialidad;
	int contador = 0;
	while (auxespecialidad!=NULL)//Recorre hasta que los numeros concidan y copia a temporal para que se pueda editar en la pagina.
	{
		if (SeleccionListBox==contador)
		{
			strcpy_s(temporalespecialidad.especialidad, auxespecialidad->especialidad);
			strcpy_s(temporalespecialidad.descripcion, auxespecialidad->descripcion);
			temporalespecialidad.numero = auxespecialidad->numero;
				break;
		}
		auxespecialidad = auxespecialidad->sig;
		contador++;
	}
}
bool CheckEdicion() {//Verifica si al momento de editar no hay uno igual

	auxespecialidad = origenespecialidad;
	while (auxespecialidad!=NULL)
	{

		if (temporalespecialidad.numero!=auxespecialidad->numero)
		{
			if (strcmp(temporalespecialidad.especialidad, auxespecialidad->especialidad) == 0) {
				return false;
			}
		}
		auxespecialidad = auxespecialidad->sig;
	}
	return true;
	auxespecialidad = origenespecialidad;
}
void RegresarAPunterosEdicion()//Regresa a punteros la informacion que se modifico en la edicion
{
	auxespecialidad = origenespecialidad;
	while (auxespecialidad!=NULL)
	{
		if (auxespecialidad->numero==temporalespecialidad.numero) {
			strcpy_s(auxespecialidad->especialidad, temporalespecialidad.especialidad);
			strcpy_s(auxespecialidad->descripcion, temporalespecialidad.descripcion);
		}
		auxespecialidad = auxespecialidad->sig;
	}
}
void checkAllVerificacionDoctor() {

}
bool verificarNombreDoctor()//verifica que solo entre letras en el nombre
{
	int sizeDoctor = 0;
	int sizeComparacion = strlen(temporalmedico.NombreDoctor);
	for (int i = 0; temporalmedico.NombreDoctor[i] != NULL; i++) {
		if ((temporalmedico.NombreDoctor[i] >= 'A'&& temporalmedico.NombreDoctor[i] <= 'Z') || (temporalmedico.NombreDoctor[i] >= 'a'&&temporalmedico.NombreDoctor[i] <= 'z')) {
			sizeDoctor++;
		}
		else if (temporalmedico.NombreDoctor[i] == ' ') {
			sizeDoctor++;
		}
	}
	if (sizeComparacion==0)
	{
		return false;
	}
	if (sizeComparacion == sizeDoctor) {
		return true;
	}
	else
	{
		return false;
	}
}
bool longitudTelefonoDoctor() {//Verifica la longitud de la hora del doctor
	int sizeComparassion = 0;
	int sizeNumero = strlen(temporalmedico.numeroTelefonicoChar);
	for (int i = 0; temporalmedico.numeroTelefonicoChar[i] != NULL; i++) {
		if (temporalmedico.numeroTelefonicoChar[i] >= '0'&&temporalmedico.numeroTelefonicoChar[i] <= '9') {
			sizeComparassion++;
		}	
	}
	if (sizeComparassion==11)
	{
		temporalmedico.NumeroTelefonico = atof(temporalmedico.numeroTelefonicoChar);
		return true;
	}
	else
	{
		return false;
	}

}
bool checkNumeroConsultorio() {//verifica que solo sea numero en el consultorio
	int sizeComparassion = 0;
	int sizeConsultorio = strlen(temporalmedico.numerodeconsultorioChar);
	for  (int i=0;temporalmedico.numerodeconsultorioChar[i]!=NULL;i++)
	{
		if (temporalmedico.numerodeconsultorioChar[i] >= '0'&& temporalmedico.numerodeconsultorioChar[i] <= '9') {
			sizeComparassion++;
		}
	}
	if (sizeConsultorio==0)
	{
		return false;
	}
	else if (sizeComparassion == sizeConsultorio) {
			temporalmedico.numerodeconsultorio = atoi(temporalmedico.numerodeconsultorioChar);
			return true;
	
	}
	else
	{
		return false;
	}
}

void AgregarRBDias() {
	if (radioCheck.RadioButton1==false)
	{
		if (temporalmedico.diasactivos[0]==NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Lunes |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Lunes |");
		}
	}
	if (radioCheck.RadioButton2 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Martes |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Martes |");
		}
	}
	if (radioCheck.RadioButton3 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Miercoles |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Miercoles |");
		}
	}
	if (radioCheck.RadioButton4 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Jueves |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Jueves |");
		}
	}
	if (radioCheck.RadioButton5 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Viernes |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Viernes |");
		}
	}
	if (radioCheck.RadioButton6 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Sabado |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Sabado |");
		}
	}
	if (radioCheck.RadioButton7 == false)
	{
		if (temporalmedico.diasactivos[0] == NULL)
		{
			strcpy_s(temporalmedico.diasactivos, "Domingo |");
		}
		else
		{
			strcat(temporalmedico.diasactivos, " Domingo |");
		}
	}
}
void AgregarRBSexo() {
	if (radioCheckPacientes.RadioButton1==false)
	{
		strcpy_s(temporalpacientes.genero, "Hombre");
	}
	else if(radioCheckPacientes.RadioButton2==false)
	{
		strcpy_s(temporalpacientes.genero, "Mujer");
		
	}
}
bool CharAIntEdadPaciente() {
	int contador = 0;
	int size = strlen(temporalpacientes.EdadChar);
	for (int i = 0; temporalpacientes.EdadChar[i]!=NULL; i++)
	{
		if (temporalpacientes.EdadChar[i] >= '0'&&temporalpacientes.EdadChar[i]<='9')
		{
			contador++;
		}
	}
	if (size==0)
	{
		return false;
	}
	else if (contador==size)
	{
		temporalpacientes.Edad = atoi(temporalpacientes.EdadChar);
		return true;
	}
	else
	{
		return false;
	}
}
Medicos *crearNodo(Medicos m,Medicos *padre) {
	Medicos *nuevo_medico = new Medicos;
	strcpy_s(nuevo_medico->ApellidoMaterno, m.ApellidoMaterno);
	strcpy_s(nuevo_medico->ApellidoPaterno, m.ApellidoPaterno);
	nuevo_medico->Cedula = m.Cedula;
	strcpy_s(nuevo_medico->CedulaChar, m.CedulaChar);
	strcpy_s(nuevo_medico->diasactivos, m.diasactivos);
	strcpy_s(nuevo_medico->DireccionFoto, m.DireccionFoto);
	strcpy_s(nuevo_medico->HoraInicioChar, m.HoraInicioChar);
	strcpy_s(nuevo_medico->HoraSalidaChar, m.HoraSalidaChar);
	nuevo_medico->HoraInicio = m.HoraInicio;
	nuevo_medico->HoraSalida = m.HoraSalida;
	strcpy_s(nuevo_medico->NombreDoctor, m.NombreDoctor);
	nuevo_medico->numerodeconsultorio = m.numerodeconsultorio;
	strcpy_s(nuevo_medico->numerodeconsultorioChar, m.numerodeconsultorioChar);
	nuevo_medico->NumeroTelefonico = m.NumeroTelefonico;
	strcpy_s(nuevo_medico->numeroTelefonicoChar, m.numeroTelefonicoChar);
	nuevo_medico->Lunes = radioCheck.RadioButton1;
	nuevo_medico->Martes = radioCheck.RadioButton2;
	nuevo_medico->Miercoles = radioCheck.RadioButton3;
	nuevo_medico->Jueves = radioCheck.RadioButton4;
	nuevo_medico->Viernes = radioCheck.RadioButton5;
	nuevo_medico->Sabado = radioCheck.RadioButton6;
	nuevo_medico->Domingo = radioCheck.RadioButton7;
	strcpy_s(nuevo_medico->especialidadM, m.especialidadM);
	nuevo_medico->der = NULL;
	nuevo_medico->izq = NULL;
	nuevo_medico->padre = padre;
	return nuevo_medico;
}
void insertarNuevoMedico(Medicos *&medico, Medicos m,Medicos *padre) {//Busca donde guardar el nuevo medico por la izq o por la der
	if (checkInsertarNuevoMedico==false)
	{
		medico = raiz;
		checkInsertarNuevoMedico = true;
	}
	/*medico = raiz;*/
	if (checkPrimeraVezDoc ==false)//Solo verifica la primera vez que crea el nodo o sea la raiz
	{
			medico = NULL;
			padre = raiz;
	}
	if (medico==NULL)
	{
		Medicos *nuevo_nodo = crearNodo(temporalmedico,padre);
		medico = nuevo_nodo;
		if (checkPrimeraVezDoc==false)
		{
			raiz = medico;
			checkPrimeraVezDoc = true;
		}
	}
	else
	{
		int valorCedula = medico->Cedula;//M.cedula ==temporalmedico.cedula
		if (m.Cedula < valorCedula) {
			insertarNuevoMedico(medico->izq, temporalmedico,medico);
		}
		else
		{
			insertarNuevoMedico(medico->der, temporalmedico,medico);
		}
	}
}
void guardarMedicosEnArchivo() {
		medico = raiz;
	fstream *archivo=NULL;
	archivo = new fstream;
	bool primeracarga = false;
	archivo->open("medicos.bin", ios::out | ios::trunc |ios::binary);
	if (archivo->is_open())
	{
		/*medico=raiz;*/
		Medicos *temp=raiz;
		char aux[100];
		int lugar = 0;
		archivo->seekg(0, ios::end);
		int final = archivo->tellg();
		archivo->seekg(0, ios::beg);
			/*archivo.write(reinterpret_cast<char*>(temp), sizeof(Medicos))*/;//EL PROBLEMA ES QUE SE VA UNO POR UNO Y TENGO QUE ENCONTRAR LA FOMRMA QUE RECORRA TODO EL ARBOL POR QUE SOLO RECCORE UN LADO.
			//if (primeracarga ==false)
			//{
			//	archivo->write(reinterpret_cast<char*>(temp), sizeof(Medicos));
			//	primeracarga = true;
			//}
			mostrarTodoMedicos(raiz, temp, temporalmedico, archivo);
		archivo->close();
		return;
	}
}
void mostrarTodoMedicos(Medicos *medico,Medicos *&temp,Medicos m,fstream *archivo) {
	if (medico==NULL)
	{

	}
	else
	{
		archivo->write(reinterpret_cast<char*>(temp), sizeof(Medicos));
		mostrarTodoMedicos(medico->izq, temp->izq,m, archivo);
		mostrarTodoMedicos(medico->der, temp->der, m, archivo);
		//archivo->write(reinterpret_cast<char*>(temp), sizeof(Medicos));
	}
}
void cargarMedicosEnArchivo(Medicos *padre) {
	medico = NULL;
	raiz = NULL;
	raiz = medico;
	Medicos *temporalNodo=new Medicos;
	//temporalNodo = NULL;
	/*Medicos *raiz = NULL;*/
	fstream *archivo=new fstream;
	archivo->open("medicos.bin", ios::binary |  ios::in|ios::ate);
	if (archivo->is_open())
	{
		int size = archivo->tellg();
		int sizeMedicos = sizeof(Medicos);
		for (int i = 0; i < (size/sizeof(Medicos)); i++)
		{
			posicionCargarMedico = i;
			cargarMedicosArchivoBinario(medico,temporalNodo,medico,archivo,sizeMedicos);
		}
	}
	checkPrimeraVezDocCargar = false;
	return;
	
}
void cargarMedicosArchivoBinario(Medicos *&medico,Medicos *temp,Medicos *&padre,fstream *&archivo,int i) {
	if (medico==NULL)
	{
		if (checkPrimeraVezDocCargar==false)
		{
			archivo->seekg(0);
			archivo->read(reinterpret_cast<char*>(temp), sizeof(Medicos));
		}
		Medicos *cargar = CargarSuperNodoMedico(archivo,temp,medico);
		medico = cargar;
		if (checkPrimeraVezDocCargar ==false)
		{
			raiz = medico;
			checkPrimeraVezDocCargar = true;
			checkPrimeraVezDoc = true;
		}
	}
	else
	{
		archivo->seekg(posicionCargarMedico * sizeof(Medicos));
		archivo->read(reinterpret_cast<char*>(temp), sizeof(Medicos));
		if (medico->Cedula>temp->Cedula)
		{
			cargarMedicosArchivoBinario(medico->izq, temp, medico, archivo,i);
		}
		else
		{
			cargarMedicosArchivoBinario(medico->der, temp, medico, archivo,i);
		}
	}
}
Medicos *CargarSuperNodoMedico(fstream *&archivo,Medicos *temp,Medicos *&padre) {
	Medicos*nuevo_medico = new Medicos;
	strcpy_s(nuevo_medico->ApellidoMaterno, temp->ApellidoMaterno);
	strcpy_s(nuevo_medico->ApellidoPaterno, temp->ApellidoPaterno);
	nuevo_medico->Cedula = temp->Cedula;
	strcpy_s(nuevo_medico->CedulaChar, temp->CedulaChar);
	strcpy_s(nuevo_medico->diasactivos, temp->diasactivos);
	strcpy_s(nuevo_medico->DireccionFoto, temp->DireccionFoto);
	strcpy_s(nuevo_medico->HoraInicioChar, temp->HoraInicioChar);
	strcpy_s(nuevo_medico->HoraSalidaChar, temp->HoraSalidaChar);
	nuevo_medico->HoraInicio = temp->HoraInicio;
	nuevo_medico->HoraSalida = temp->HoraSalida;
	strcpy_s(nuevo_medico->NombreDoctor, temp->NombreDoctor);
	nuevo_medico->numerodeconsultorio = temp->numerodeconsultorio;
	strcpy_s(nuevo_medico->numerodeconsultorioChar, temp->numerodeconsultorioChar);
	nuevo_medico->NumeroTelefonico = temp->NumeroTelefonico;
	strcpy_s(nuevo_medico->numeroTelefonicoChar, temp->numeroTelefonicoChar);
	nuevo_medico->Lunes = temp->Lunes;
	nuevo_medico->Martes = temp->Martes;
	nuevo_medico->Miercoles = temp->Miercoles;
	nuevo_medico->Miercoles = temp->Miercoles;
	nuevo_medico->Jueves = temp->Jueves;
	nuevo_medico->Viernes = temp->Viernes;
	nuevo_medico->Sabado = temp->Sabado;
	nuevo_medico->Domingo = temp->Domingo;
	strcpy_s(nuevo_medico->especialidadM, temp->especialidadM);
	nuevo_medico->der = NULL;
	nuevo_medico->izq = NULL;
	nuevo_medico->padre = medico;
	/*posicionCargarMedico++;*/
	return nuevo_medico;
}
bool verificarCedula(Medicos *medico, Medicos m) {//verifica si la cedula que se ingreso ya existe
	if (medico == NULL) {
		return false;//Esto quiere decir que no hay una cedula con ese numero
	}
	else if (medico->Cedula == m.Cedula) {
		return true; //Si existe una cedula con ese numero
	}
	else if (m.Cedula<medico->Cedula)
	{
		return verificarCedula(medico->izq, m);
	}
	else	{
		return verificarCedula(medico->der, m);
	}
}
bool verificarHorarioDoctor(Medicos *medico, Medicos m) {//Verifica si el horario ingresado del doctor no se junta con otro
	if (medico==NULL)
	{
		return false;
	}
	else if (m.numerodeconsultorio == medico->numerodeconsultorio)
	{
		if (medico->Lunes==radioCheck.RadioButton1)
		{
			if (m.HoraInicio==medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida<=medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Martes==radioCheck.RadioButton2)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Miercoles==radioCheck.RadioButton3)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Jueves==radioCheck.RadioButton4)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Viernes==radioCheck.RadioButton5)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Sabado==radioCheck.RadioButton6)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (medico->Domingo==radioCheck.RadioButton7)
		{
			if (m.HoraInicio == medico->HoraInicio)
			{
				return true;
			}
			else if (m.HoraInicio<medico->HoraInicio)
			{
				if (m.HoraSalida>medico->HoraInicio)
				{
					return true;
				}
				else if (m.HoraSalida <= medico->HoraInicio)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (m.HoraInicio>medico->HoraInicio)
			{
				if (m.HoraInicio<medico->HoraSalida) {
					return true;
				}
				else if (m.HoraInicio >= medico->HoraSalida) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else
		{
			return true;
		}

	}
	else if(m.numerodeconsultorio<medico->numerodeconsultorio)
	{
		return verificarHorarioDoctor(medico->izq, m);
	}
	else if(m.numerodeconsultorio>medico->numerodeconsultorio) {
		return verificarHorarioDoctor(medico->der, m);
	}
	else
	{
		return false;
	}

}
bool verificarHorarioEntradaSalidaDoctor() {//verifica si el horario ingresado es correcto comparando horario entrada y salida
	if (temporalmedico.HoraInicio<=temporalmedico.HoraSalida)
	{
		if (temporalmedico.HoraInicio<=24 && temporalmedico.HoraInicio>=1)
		{
			if (temporalmedico.HoraSalida <= 24 && temporalmedico.HoraSalida>=1) {
				return true;
			}
			else
			{
				return false;
			}
		}
		else {
			return false;
		}
	}
	else if (temporalmedico.HoraInicio > temporalmedico.HoraSalida) {
		return false;
	}
	
}
bool checkHoraMedico() {
	int comprobacion = 0;
	int size = strlen(temporalmedico.HoraInicioChar);
	int check = 0;
	for (int i = 0; temporalmedico.HoraInicioChar[i]!=NULL; i++)
	{
		if (temporalmedico.HoraInicioChar[i] >= '0'&&temporalmedico.HoraInicioChar[i] <= '9') {
			comprobacion++;
		}
	}
	if (comprobacion==size)
	{
		check++;
	}
	comprobacion = 0;
	size = strlen(temporalmedico.HoraSalidaChar);
	for (int i = 0; temporalmedico.HoraSalidaChar[i] != NULL; i++)
	{
		if (temporalmedico.HoraSalidaChar[i] >= '0'&&temporalmedico.HoraSalidaChar[i] <= '9') {
			comprobacion++;
		}
	}
	if (comprobacion == size)
	{
		check++;
	}
	if (check==2)
	{
		temporalmedico.HoraInicio = atoi(temporalmedico.HoraInicioChar);
		temporalmedico.HoraSalida = atoi(temporalmedico.HoraSalidaChar);
		return true;
	}
	else
	{
		return false;
	}
}
void limpiarTemporalMedicoPorError() {//Va limpiar los espacios cuando haya salido un error en la ventana
	memset(temporalmedico.ApellidoMaterno, NULL, 15);
	memset(temporalmedico.ApellidoPaterno, NULL, 15);
	memset(temporalmedico.CedulaChar, NULL, 16);
	memset(temporalmedico.diasactivos, NULL, 60);
	memset(temporalmedico.DireccionFoto, NULL, 150);
	memset(temporalmedico.HoraSalidaChar, NULL, 80);
	memset(temporalmedico.HoraInicioChar, NULL, 80);
	memset(temporalmedico.NombreDoctor, NULL, 50);
	memset(temporalmedico.numerodeconsultorioChar, NULL, 4);
	memset(temporalmedico.numeroTelefonicoChar, NULL, 20);
	memset(temporalmedico.especialidadM, NULL, 20);
	memset(temporalmedico.DireccionFoto, NULL, 150);
	temporalmedico.Cedula = 0;
	temporalmedico.HoraInicio = 0;
	temporalmedico.HoraSalida = 0;
	temporalmedico.numerodeconsultorio = 0;
	temporalmedico.NumeroTelefonico = 0;
}
void limpiarTemporalPacientesPorError() {
	memset(temporalpacientes.anoChar, NULL, 10);
	memset(temporalpacientes.ApellidoMaterno, NULL, 15);
	memset(temporalpacientes.ApellidoPaterno, NULL,15 );
	memset(temporalpacientes.DiaChar, NULL,10 );
	memset(temporalpacientes.EdadChar, NULL, 10);
	memset(temporalpacientes.fechacompleta, NULL,20 );
	memset(temporalpacientes.genero, NULL,10 );
	memset(temporalpacientes.MesChar, NULL,10 );
	memset(temporalpacientes.Nombre, NULL,50 );
	memset(temporalpacientes.primermedico, NULL,50 );
	memset(temporalpacientes.referencia, NULL,150 );
	memset(temporalpacientes.TelefonoChar, NULL,15 );
	temporalpacientes.ano = 0;
	temporalpacientes.Dia = 0;
	temporalpacientes.Edad = 0;
	temporalpacientes.Mes = 0;
	temporalpacientes.Telefono = 0;
}
void guardarEnArchivoMedicos() {

}
void recorrerMedicoPreOrden(Medicos *medico)
{
	if (medico == NULL) {//El Arbol esta vacio
		return;
	}
	else
	{
		recorrerMedicoPreOrden(medico->izq);
		recorrerMedicoPreOrden(medico->der);
	}
}
void buscareliminar(Medicos *medico, Medicos m) {
	if (medico==NULL)
	{
		return;
	}
	else if(temporalmedico.Cedula<medico->Cedula)
	{
		buscareliminar(medico->izq, temporalmedico);
	}
	else if (temporalmedico.Cedula>medico->Cedula)
	{
		buscareliminar(medico->der, temporalmedico);
	}
	else
	{
		eliminarNodo(medico);
	}
}
void eliminarNodo (Medicos *medico) {
	if (medico->izq&&medico->der)
	{
		Medicos *menor = minimo(medico->der);
		medico->Cedula = menor->Cedula;
		medico->HoraInicio = menor->HoraInicio;
		eliminarNodo(menor);
	}
	else if (medico->izq) {
		reemplazarNodo(medico, medico->izq);
		destruirNodo(medico);
	}
	else if (medico->der) {
		reemplazarNodo(medico, medico->der);
		destruirNodo(medico);
	}
	else
	{
		reemplazarNodo(medico, NULL);
		destruirNodo(medico);
	}
}
void destruirNodo(Medicos *paraeliminar) {
	paraeliminar->izq = NULL;
	paraeliminar->der = NULL;
	if (paraeliminar==raiz)
	{
		raiz = NULL;
	}
	delete paraeliminar;
}
void reemplazarNodo(Medicos *arbol, Medicos *nuevomedico) {
	if (arbol->padre)
	{
		if (arbol->Cedula==arbol->padre->izq->Cedula)
		{
			arbol->padre->izq = nuevomedico;
		}
		else if(arbol->Cedula==arbol->padre->der->Cedula)
		{
			arbol->padre->der = nuevomedico;
		}
	}
	if (nuevomedico)
	{
		if (arbol->padre==NULL)
		{
			nuevomedico->padre = arbol->padre;
			raiz = nuevomedico;
		}
		else
		{
			nuevomedico->padre = arbol->padre;
		}
	}
}
Medicos *minimo(Medicos *medico) {
	if (medico==NULL)
	{
		return NULL;
	}
	if (medico->izq)
	{
		return minimo(medico->izq);
	}
	else
	{
		return medico;
	}
}
bool verificarNombrePaciente(char verificar[150])
{
	int SizePaciente = 0;
	int sizeComparacion = strlen(verificar);
	for (int i=0;verificar[i]!=NULL;i++)
	{
		if ((verificar[i] >= 'A'&&verificar[i] <= 'Z') || (verificar[i] >= 'a'&&verificar[i] <= 'z')) {
			SizePaciente++;
		}
		else if (verificar[i]==' ')
		{
			SizePaciente++;
		}
	}
	if (sizeComparacion==0)
	{
		return false;
	}
	else if (sizeComparacion==SizePaciente)
	{

		return true;
	}
	else
	{
		return false;
	}
}
bool longitudTelefonoPaciente() {
	int SizePaciente = 0;
	int sizeComparacion = strlen(temporalpacientes.TelefonoChar);
	for (int i=0;temporalpacientes.TelefonoChar[i]!=NULL;i++)
	{
		if (temporalpacientes.TelefonoChar[i]>='0'&&temporalpacientes.TelefonoChar[i]<='9')
		{
			SizePaciente++;
		}
	}
	if (SizePaciente==sizeComparacion)
	{
		if (sizeComparacion==11)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool verificarFechaPaciente() {
	char Dia[3],Mes[3],Ano[5];
	memset(Dia, NULL, 3);
	memset(Mes, NULL, 3);
	memset(Ano, NULL, 5);
	int opcion = 1;
	for (int i=0;temporalpacientes.fechacompleta[i]!=NULL;i++)
	{
		if (temporalpacientes.fechacompleta[i] == '/') {
			if (opcion==1)
			{
				Dia[0] = temporalpacientes.fechacompleta[i - 2];
				Dia[1] = temporalpacientes.fechacompleta[i - 1];
				Mes[0] = temporalpacientes.fechacompleta[i + 1];
				Mes[1] = temporalpacientes.fechacompleta[i + 2];

				opcion++;
			}
			else if (opcion == 2) {
				Ano[0] = temporalpacientes.fechacompleta[i + 1];
				Ano[1] = temporalpacientes.fechacompleta[i + 2];
				Ano[2] = temporalpacientes.fechacompleta[i + 3];
				Ano[3] = temporalpacientes.fechacompleta[i + 4];
				opcion = 1;
			}
		}
	}
	temporalpacientes.Dia = atoi(Dia);
	strcpy_s(temporalpacientes.DiaChar, Dia);
	temporalpacientes.Mes = atoi(Mes);
	strcpy_s(temporalpacientes.MesChar, Mes);
	temporalpacientes.ano = atoi(Ano);
	strcpy_s(temporalpacientes.anoChar, Ano);
	memset(Dia, NULL, 3);
	memset(Mes, NULL, 3);
	memset(Ano, NULL, 5);
	actualTime->tm_mon = actualTime->tm_mon+1 ;
	actualTime->tm_year = actualTime->tm_year+1900;
	if (actualTime->tm_year>=temporalpacientes.ano)
	{
		if (temporalpacientes.ano==2020)
		{
			if (temporalpacientes.Mes <= actualTime->tm_mon)
			{
				if (temporalpacientes.Dia<=actualTime->tm_mday)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (temporalpacientes.ano<actualTime->tm_year)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
bool verificarEdad() {
	int SizePaciente = 0;
	int sizeComparasion = strlen(temporalpacientes.EdadChar);
	for (int i = 0; temporalpacientes.EdadChar[i]!=NULL; i++)
	{
		if (temporalpacientes.EdadChar[i] >= '0'&&temporalpacientes.EdadChar[i] <= '9') {
			SizePaciente++;
		}
	}
	if (SizePaciente==sizeComparasion)
	{
		temporalpacientes.Edad = atoi(temporalpacientes.EdadChar);
		return true;
	}
	else
	{
		return false;
	}
}
void agregarPacientes() {
	auxpacientes = origenpacientes;
	if (origenpacientes==NULL)
	{
		origenpacientes = new pacientes;
		origenpacientes->ano = temporalpacientes.ano;
		strcpy_s(origenpacientes->anoChar, temporalpacientes.anoChar);
		strcpy_s(origenpacientes->ApellidoMaterno, temporalpacientes.ApellidoMaterno);
		origenpacientes->Dia = temporalpacientes.Dia;
		strcpy_s(origenpacientes->DiaChar, temporalpacientes.DiaChar);
		origenpacientes->Edad = temporalpacientes.Edad;
		strcpy_s(origenpacientes->EdadChar, temporalpacientes.EdadChar);
		strcpy_s(origenpacientes->fechacompleta, temporalpacientes.fechacompleta);
		strcpy_s(origenpacientes->genero, temporalpacientes.genero);
		origenpacientes->Mes = temporalpacientes.Mes;
		strcpy_s(origenpacientes->MesChar, temporalpacientes.MesChar);
		strcpy_s(origenpacientes->Nombre, temporalpacientes.Nombre);
		strcpy_s(origenpacientes->primermedico, temporalpacientes.primermedico);
		strcpy_s(origenpacientes->referencia, temporalpacientes.referencia);
		origenpacientes->Telefono = temporalpacientes.Telefono;
		strcpy_s(origenpacientes->TelefonoChar, temporalpacientes.TelefonoChar);
		strcpy_s(origenpacientes->ApellidoPaterno, temporalpacientes.ApellidoPaterno);
		origenpacientes->sig = NULL;
		origenpacientes->ant = NULL;
	}
	else
	{
		while (auxpacientes->sig != NULL)
			auxpacientes = auxpacientes->sig;
		auxpacientes->sig = new pacientes;
		auxpacientes->sig->ant = auxpacientes;
		auxpacientes = auxpacientes->sig;
		auxpacientes->ano = temporalpacientes.ano;
		strcpy_s(auxpacientes->anoChar, temporalpacientes.anoChar);
		strcpy_s(auxpacientes->ApellidoMaterno, temporalpacientes.ApellidoMaterno);
		auxpacientes->Dia = temporalpacientes.Dia;
		strcpy_s(auxpacientes->DiaChar, temporalpacientes.DiaChar);
		auxpacientes->Edad = temporalpacientes.Edad;
		strcpy_s(auxpacientes->EdadChar, temporalpacientes.EdadChar);
		strcpy_s(auxpacientes->fechacompleta, temporalpacientes.fechacompleta);
		strcpy_s(auxpacientes->genero, temporalpacientes.genero);
		auxpacientes->Mes = temporalpacientes.Mes;
		strcpy_s(auxpacientes->MesChar, temporalpacientes.MesChar);
		strcpy_s(auxpacientes->Nombre, temporalpacientes.Nombre);
		strcpy_s(auxpacientes->primermedico, temporalpacientes.primermedico);
		strcpy_s(auxpacientes->referencia, temporalpacientes.referencia);
		auxpacientes->Telefono = temporalpacientes.Telefono;
		strcpy_s(auxpacientes->TelefonoChar, temporalpacientes.TelefonoChar);
		strcpy_s(auxpacientes->ApellidoPaterno, temporalpacientes.ApellidoPaterno);
		auxpacientes->sig = NULL;
	}
	auxpacientes = origenpacientes;
}
void guardarPacientesArchivo() {
	auxpacientes = origenpacientes;
	fstream archivo;
	archivo.open("pacientes.bin", ios::binary | ios::trunc | ios::out);
	if (archivo.is_open())
	{
		pacientes *temp = origenpacientes;
		while (temp!=NULL)
		{
			archivo.write(reinterpret_cast<char*>(temp), sizeof(pacientes));
			temp = temp->sig;
		}
		archivo.close();
		return;
	}
}
void cargarPacientesArchivo() {
	auxpacientes = origenpacientes = NULL;
	fstream archivo;
	archivo.open("pacientes.bin", ios::binary | ios::in | ios::ate);
	if (archivo.is_open())
	{
		int size = archivo.tellg();
		if (size==0)
		{
			return;
		}
		for (int i = 0; i < (size / sizeof(pacientes)); i++) {
			if (origenpacientes==NULL)
			{
				origenpacientes = new pacientes;
				pacientes *temp = new pacientes;
				archivo.seekg(0);
				archivo.read(reinterpret_cast<char*>(temp), sizeof(pacientes));
				origenpacientes->ano = temp->ano;
				strcpy(origenpacientes->anoChar, temp->anoChar);
				strcpy_s(origenpacientes->ApellidoMaterno, temp->ApellidoMaterno);
				strcpy_s(origenpacientes->ApellidoPaterno, temp->ApellidoPaterno);
				origenpacientes->Dia = temp->Dia;
				strcpy_s(origenpacientes->DiaChar, temp->DiaChar);
				origenpacientes->Edad = temp->Edad;
				strcpy_s(origenpacientes->EdadChar, temp->EdadChar);
				strcpy_s(origenpacientes->fechacompleta, temp->fechacompleta);
				strcpy_s(origenpacientes->genero, temp->genero);
				origenpacientes->Mes = temp->Mes;
				strcpy_s(origenpacientes->MesChar, temp->MesChar);
				strcpy_s(origenpacientes->Nombre, temp->Nombre);
				strcpy_s(origenpacientes->primermedico, temp->primermedico);
				strcpy_s(origenpacientes->referencia, temp->referencia);
				origenpacientes->Telefono = temp->Telefono;
				strcpy_s(origenpacientes->TelefonoChar, temp->TelefonoChar);
				origenpacientes->ant = NULL;
				origenpacientes->sig = NULL;
				delete reinterpret_cast<char*>(temp);
				continue;
			}
			auxpacientes = origenpacientes;
			while (auxpacientes->sig != NULL)
				auxpacientes = auxpacientes->sig;
			auxpacientes->sig = new pacientes;
			pacientes *temp = new pacientes;
			archivo.seekg(i * sizeof(pacientes));
			archivo.read(reinterpret_cast<char*>(temp), sizeof(pacientes));
			auxpacientes->sig->ant = auxpacientes;
			auxpacientes->sig->sig = NULL;
			auxpacientes = auxpacientes->sig;
			auxpacientes->ano = temp->ano;
			strcpy(auxpacientes->anoChar, temp->anoChar);
			strcpy_s(auxpacientes->ApellidoMaterno, temp->ApellidoMaterno);
			strcpy_s(auxpacientes->ApellidoPaterno, temp->ApellidoPaterno);
			auxpacientes->Dia = temp->Dia;
			strcpy_s(auxpacientes->DiaChar, temp->DiaChar);
			auxpacientes->Edad = temp->Edad;
			strcpy_s(auxpacientes->EdadChar, temp->EdadChar);
			strcpy_s(auxpacientes->fechacompleta, temp->fechacompleta);
			strcpy_s(auxpacientes->genero, temp->genero);
			auxpacientes->Mes = temp->Mes;
			strcpy_s(auxpacientes->MesChar, temp->MesChar);
			strcpy_s(auxpacientes->Nombre, temp->Nombre);
			strcpy_s(auxpacientes->primermedico, temp->primermedico);
			strcpy_s(auxpacientes->referencia, temp->referencia);
			auxpacientes->Telefono = temp->Telefono;
			strcpy_s(auxpacientes->TelefonoChar, temp->TelefonoChar);
			delete reinterpret_cast<char*>(temp);
		}
		archivo.close();
		return;
	}
	return;
}
void seleccionEdicionPaciente() {
	auxpacientes = origenpacientes;
	int contador = 0;
	while (auxpacientes!=NULL)
	{
		if (contador==PacientesDeListBox)
		{
			strcpy_s(temporalpacientes.Nombre, auxpacientes->Nombre);
			strcpy_s(temporalpacientes.ApellidoPaterno, auxpacientes->ApellidoPaterno);
			strcpy_s(temporalpacientes.ApellidoMaterno, auxpacientes->ApellidoMaterno);
			strcpy_s(temporalpacientes.anoChar, auxpacientes->anoChar);
			strcpy_s(temporalpacientes.DiaChar, auxpacientes->DiaChar);
			strcpy_s(temporalpacientes.EdadChar, auxpacientes->EdadChar);
			strcpy_s(temporalpacientes.fechacompleta, auxpacientes->fechacompleta);
			strcpy_s(temporalpacientes.genero, auxpacientes->genero);
			strcpy_s(temporalpacientes.MesChar, auxpacientes->MesChar);
			strcpy_s(temporalpacientes.primermedico, auxpacientes->primermedico);
			strcpy_s(temporalpacientes.referencia, auxpacientes->referencia);
			strcpy_s(temporalpacientes.TelefonoChar, auxpacientes->TelefonoChar);
			temporalpacientes.ano = auxpacientes->ano;
			temporalpacientes.Dia = auxpacientes->Dia;
			temporalpacientes.Edad = auxpacientes->Edad;
			temporalpacientes.Mes = auxpacientes->Mes;
			temporalpacientes.Telefono = auxpacientes->Telefono;
		}
		contador++;
		auxpacientes = auxpacientes->sig;
	}
	auxpacientes = origenpacientes;
}
void editarPacientesSel() {
	auxpacientes = origenpacientes;
	while (auxpacientes!=NULL)
	{
		if (strcmp(temporalpacientes.fechacompleta,auxpacientes->fechacompleta) == 0) {
			if (strcmp(temporalpacientes.primermedico,auxpacientes->primermedico)==0)
			{
				if (temporalpacientes.Edad==auxpacientes->Edad) {
					strcpy_s(auxpacientes->Nombre, temporalpacientes.Nombre);
					strcpy_s(auxpacientes->ApellidoPaterno, temporalpacientes.ApellidoPaterno);
					strcpy_s(auxpacientes->ApellidoMaterno, temporalpacientes.ApellidoMaterno);
					strcpy_s(auxpacientes->anoChar, temporalpacientes.anoChar);
					strcpy_s(auxpacientes->DiaChar, temporalpacientes.DiaChar);
					strcpy_s(auxpacientes->EdadChar, temporalpacientes.EdadChar);
					strcpy_s(auxpacientes->fechacompleta, temporalpacientes.fechacompleta);
					strcpy_s(auxpacientes->genero, temporalpacientes.genero);
					strcpy_s(auxpacientes->MesChar, temporalpacientes.MesChar);
					strcpy_s(auxpacientes->primermedico, temporalpacientes.primermedico);
					strcpy_s(auxpacientes->referencia, temporalpacientes.referencia);
					strcpy_s(auxpacientes->TelefonoChar, temporalpacientes.TelefonoChar);
					auxpacientes->ano = temporalpacientes.ano;
					auxpacientes->Dia = temporalpacientes.Dia;
					auxpacientes->Edad = temporalpacientes.Edad;
					auxpacientes->Mes = temporalpacientes.Mes;
					auxpacientes->Telefono = temporalpacientes.Telefono;
				}
			}
		}
		auxpacientes = auxpacientes->sig;
	}
}
void eliminarPacientes() {
	auxpacientes = origenpacientes;
	int contador = 0;
	while (contador!=PacientesDeListBox)
	{
		auxpacientes = auxpacientes->sig;
		contador++;
	}
	if (auxpacientes->ant==NULL&&auxpacientes->sig==NULL)//UNICO NODO
	{
		delete auxpacientes;
		auxpacientes = origenpacientes = NULL;
	}
	else if (auxpacientes->ant==NULL)//PRIMER NODO
	{
		origenpacientes = auxpacientes->sig;
		delete auxpacientes;
		origenpacientes->ant = NULL;
		auxpacientes = origenpacientes;
	}
	else if (auxpacientes->sig==NULL)//ULTIMO NODO
	{
		auxpacientes->ant->sig = NULL;
		delete auxpacientes;
		auxpacientes = origenpacientes;
	}
	else
	{
		auxpacientes->ant->sig = auxpacientes->sig;
		auxpacientes->sig->ant = auxpacientes->ant;
		delete auxpacientes;
		auxpacientes = origenpacientes;
	}
	auxpacientes = origenpacientes;
	return;
}
void mostrarArbolenComboBox(Medicos *medico) {
	if (medico==NULL)
	{
		return;
	}
	else
	{
		memset(ListBoxDeCitas, NULL, 300);
		strcpy_s(ListBoxDeCitas, medico->NombreDoctor);
		strcat(ListBoxDeCitas, " ");
		strcat(ListBoxDeCitas, medico->ApellidoPaterno);
		strcat(ListBoxDeCitas, " ");
		strcat(ListBoxDeCitas, medico->ApellidoMaterno);
		strcat(ListBoxDeCitas, " ");
		strcat(ListBoxDeCitas, medico->CedulaChar);
		SendMessage(hEdit3, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
		mostrarArbolenComboBox(medico->der);
		//memset(ListBoxDeCitas, NULL, 300);
		//strcpy_s(ListBoxDeCitas, medico->NombreDoctor);
		//strcat(ListBoxDeCitas, " ");
		//strcat(ListBoxDeCitas, medico->ApellidoPaterno);
		//strcat(ListBoxDeCitas, " ");
		//strcat(ListBoxDeCitas, medico->ApellidoMaterno);
		//SendMessage(hEdit3, CB_ADDSTRING, 0, (LPARAM)ListBoxDeCitas);
		mostrarArbolenComboBox(medico->izq);
	}
}
void mostrarArbolEnListBox(Medicos *medico) {
	if (medico==NULL)
	{
		return;
	}
	else
	{
		memset(ListBoxMedicos, NULL, 150);
		strcpy_s(ListBoxMedicos, medico->NombreDoctor);
		strcat(ListBoxMedicos, " ");
		strcat(ListBoxMedicos, medico->ApellidoPaterno);
		strcat(ListBoxMedicos, " ");
		strcat(ListBoxMedicos, medico->ApellidoMaterno);
		strcat(ListBoxMedicos, " ");
		strcat(ListBoxMedicos, medico->especialidadM);
		strcat(ListBoxMedicos, " ");
		strcat(ListBoxMedicos, "Cedula:");
		strcat(ListBoxMedicos, medico->CedulaChar);
		SendMessage(hEdit1, LB_ADDSTRING, 0, (LPARAM)ListBoxMedicos);
		mostrarArbolEnListBox(medico->izq);
		mostrarArbolEnListBox(medico->der);
	}
}
void mostrarMedicoAEditar(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else
	{
		if (temporalmedico.Cedula==medico->Cedula)
		{
			strcpy_s(temporalmedico.ApellidoMaterno, medico->ApellidoMaterno);
			strcpy_s(temporalmedico.ApellidoPaterno, medico->ApellidoPaterno);
			strcpy_s(temporalmedico.CedulaChar, medico->CedulaChar);
			strcpy_s(temporalmedico.diasactivos, medico->diasactivos);
			strcpy_s(temporalmedico.DireccionFoto, medico->DireccionFoto);
			strcpy_s(temporalmedico.especialidadM, medico->especialidadM);
			strcpy_s(temporalmedico.HoraInicioChar, medico->HoraInicioChar);
			strcpy_s(temporalmedico.HoraSalidaChar, medico->HoraSalidaChar);
			strcpy_s(temporalmedico.NombreDoctor, medico->NombreDoctor);
			strcpy_s(temporalmedico.numerodeconsultorioChar, medico->numerodeconsultorioChar);
			strcpy_s(temporalmedico.numeroTelefonicoChar, medico->numeroTelefonicoChar);
			temporalmedico.Cedula = medico->Cedula;
			temporalmedico.Domingo = medico->Domingo;
			temporalmedico.HoraInicio = medico->HoraInicio;
			temporalmedico.HoraSalida = medico->HoraSalida;
			temporalmedico.Jueves = medico->Jueves;
			temporalmedico.Lunes = medico->Lunes;
			temporalmedico.Martes = medico->Martes;
			temporalmedico.Miercoles = medico->Miercoles;
			temporalmedico.numerodeconsultorio = medico->numerodeconsultorio;
			temporalmedico.NumeroTelefonico = medico->NumeroTelefonico;
			temporalmedico.Sabado = temporalmedico.Sabado;
			temporalmedico.Viernes = medico->Viernes;
		}
		else
		{
			mostrarMedicoAEditar(medico->izq);
			mostrarMedicoAEditar(medico->der);
		}
	}
}
void EncontrarDoctorParaCita(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else
	{
		if (medico->Cedula==MedicosDeListBox)
		{
			strcpy_s(temporalmedico.ApellidoMaterno, medico->ApellidoMaterno);
			strcpy_s(temporalmedico.ApellidoPaterno, medico->ApellidoPaterno);
			strcpy_s(temporalmedico.NombreDoctor, medico->NombreDoctor);
			temporalmedico.Lunes = medico->Lunes;
			temporalmedico.Martes = medico->Martes;
			temporalmedico.Miercoles = medico->Miercoles;
			temporalmedico.Jueves = medico->Jueves;
			temporalmedico.Viernes = medico->Viernes;
			temporalmedico.Sabado = medico->Sabado;
			temporalmedico.Domingo = medico->Domingo;
			temporalmedico.HoraInicio = medico->HoraInicio;
			temporalmedico.HoraSalida = medico->HoraSalida;
			temporalmedico.Cedula = medico->Cedula;
			strcpy_s(temporalmedico.DireccionFoto,medico->DireccionFoto);
			strcpy_s(temporalcitas.DireccionFotoDoctor, temporalmedico.DireccionFoto);

			strcpy_s(temporalmedico.CedulaChar, medico->CedulaChar);
			strcpy_s(temporalmedico.especialidadM, medico->especialidadM);
			contadorParaBuscarDoctor = 0;
			return;
		}
		else
		{
			EncontrarDoctorParaCita(medico->izq);
			/*contadorParaBuscarDoctor++;*/
			EncontrarDoctorParaCita(medico->der);
			/*contadorParaBuscarDoctor++;*/
		}
	}

}
void EncontrarDoctorParaCitaEdicion(Medicos *medico) {
	if (medico == NULL)
	{

	}
	else
	{
		if (medico->Cedula == temporalcitas.CedulaDoctor)
		{
			strcpy_s(temporalmedico.ApellidoMaterno, medico->ApellidoMaterno);
			strcpy_s(temporalmedico.ApellidoPaterno, medico->ApellidoPaterno);
			strcpy_s(temporalmedico.NombreDoctor, medico->NombreDoctor);
			temporalmedico.Lunes = medico->Lunes;
			temporalmedico.Martes = medico->Martes;
			temporalmedico.Miercoles = medico->Miercoles;
			temporalmedico.Jueves = medico->Jueves;
			temporalmedico.Viernes = medico->Viernes;
			temporalmedico.Sabado = medico->Sabado;
			temporalmedico.Domingo = medico->Domingo;
			temporalmedico.HoraInicio = medico->HoraInicio;
			temporalmedico.HoraSalida = medico->HoraSalida;
			temporalmedico.Cedula = medico->Cedula;
			strcpy_s(temporalmedico.DireccionFoto, medico->DireccionFoto);
			strcpy_s(temporalcitas.DireccionFotoDoctor, temporalmedico.DireccionFoto);

			strcpy_s(temporalmedico.CedulaChar, medico->CedulaChar);
			strcpy_s(temporalmedico.especialidadM, medico->especialidadM);
			contadorParaBuscarDoctor = 0;
			return;
		}
		else
		{
			EncontrarDoctorParaCita(medico->izq);
			/*contadorParaBuscarDoctor++;*/
			EncontrarDoctorParaCita(medico->der);
			/*contadorParaBuscarDoctor++;*/
		}
	}

}
bool verificacionDiaDeFecha() {//Verifica si el dia y la hora coincide con el doctor
	if (temporalcitas.FechaDeCita[0] == 'l')
	{
		if (temporalmedico.Lunes == false) {
			if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (temporalcitas.FechaDeCita[0] == 'm')
	{
		if (temporalcitas.FechaDeCita[1] == 'a')
		{
			if (temporalmedico.Martes == false) {
				if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (temporalcitas.FechaDeCita[1] == 'i')
		{
			if (temporalmedico.Miercoles == false) {
				if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else if (temporalcitas.FechaDeCita[0] == 'j')
	{
		if (temporalmedico.Jueves == false) {
			if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (temporalcitas.FechaDeCita[0] == 'v')
	{
		if (temporalmedico.Viernes == false) {
			if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (temporalcitas.FechaDeCita[0] == 's')
	{
		if (temporalmedico.Sabado == false) {
			if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (temporalcitas.FechaDeCita[0] == 'd')
	{
		if (temporalmedico.Domingo == false) {
			if (temporalcitas.HoraInicio >= temporalmedico.HoraInicio&&temporalcitas.HoraInicio <= temporalmedico.HoraSalida)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
bool especialidadesIgual() {//Verifica que si la especialidad que selecciono es igual al la del doctor
	int comp = strlen(temporalmedico.especialidadM);
	int res = 0;
	int ans = 0;
	bool checkEspacio = false;
	for (int i = 0; comparacionEspecialidad[i]!=NULL; i++)
	{
		if (temporalmedico.especialidadM[i] == comparacionEspecialidad[i]) {
			res++;
		}
		else if (checkEspacio == false) {
			if (comparacionEspecialidad[i] == ' ')
			{
				checkEspacio = true;
			}
		}
		else
		{
			res++;
		}
	}
	if(comp==res){
		return true;
	}
	else
	{
		return false;
	}
}
void cambiarIntAConsulta() {
	char Hora[3];
	char Minutos[3];
	memset(Hora, NULL, 3);
	memset(Minutos, NULL, 3);
	int opcion = 1;
	for (int i = 0; temporalcitas.horacompleta[i] != NULL; i++)
	{
		if (temporalcitas.horacompleta[i] == ':') {
			if (opcion == 1)
			{
				Hora[0] = temporalcitas.horacompleta[i - 2];
				Hora[1] = temporalcitas.horacompleta[i - 1];
				Minutos[0] = temporalcitas.horacompleta[i + 1];
				Minutos[1] = temporalcitas.horacompleta[i + 2];
				opcion++;
			}
		}
	}
	strcpy_s(temporalcitas.HoraInicioChar, Hora);
	temporalcitas.HoraInicio = atoi(Hora);
	strcpy_s(temporalcitas.MinutosInicioChar, Minutos);
	temporalcitas.MinutosInicio = atoi(Minutos);
	if (temporalcitas.MinutosInicio+20>59)
	{
		int suma = temporalcitas.MinutosInicio + 20;
		suma = suma - 60;
		temporalcitas.MinutosFinal = suma;
		_itoa_s(temporalcitas.MinutosFinal, temporalcitas.MinutosFinalChar, 10);
		temporalcitas.HoraFinal = temporalcitas.HoraInicio + 1;
		_itoa_s(temporalcitas.HoraFinal, temporalcitas.HoraFinalChar, 10);

	}
	else
	{
		temporalcitas.MinutosFinal = temporalcitas.MinutosInicio+20;
		_itoa_s(temporalcitas.MinutosFinal, temporalcitas.MinutosFinalChar, 10);
		temporalcitas.HoraFinal = temporalcitas.HoraInicio ;
		_itoa_s(temporalcitas.HoraFinal, temporalcitas.HoraFinalChar, 10);
	}
	memset(Hora, NULL, 3);
	memset(Minutos, NULL, 3);
	opcion = 1;
}
void agregarCitas() {
	auxcitas = origencitas;
	if (origencitas==NULL)
	{
		origencitas = new Citas;
		origencitas->MinutosFinal = temporalcitas.MinutosFinal;
		strcpy_s(origencitas->MinutosFinalChar,temporalcitas.MinutosFinalChar);
		origencitas->MinutosInicio=temporalcitas.MinutosInicio;
		strcpy_s(origencitas->MinutosInicioChar,temporalcitas.MinutosInicioChar);
		origencitas->CedulaDoctor = temporalcitas.CedulaDoctor;
		origencitas->numeroTelefonicoPaciente= temporalcitas.numeroTelefonicoPaciente;
		strcpy_s(origencitas->numeroTelefonicoPacienteChar, temporalcitas.numeroTelefonicoPacienteChar);
		origencitas->numeroespecialidadCita = temporalcitas.numeroespecialidadCita;
		strcpy_s(origencitas->FechaDeCita, temporalcitas.FechaDeCita);
		strcpy_s(origencitas->horacompleta, temporalcitas.horacompleta);
		origencitas->HoraFinal = temporalcitas.HoraFinal;
		strcpy_s(origencitas->HoraFinalChar, temporalcitas.HoraFinalChar);
		origencitas->HoraInicio = temporalcitas.HoraInicio;
		strcpy_s(origencitas->HoraInicioChar, temporalcitas.HoraInicioChar);
		origencitas->numeroDeCita = 1;
		controladorNumeroDeCitas = origencitas->numeroDeCita;
		_itoa_s(controladorNumeroDeCitas, origencitas->numeroDeCitaChar, 10);
		strcpy_s(origencitas->DireccionFotoDoctor, temporalcitas.DireccionFotoDoctor);
		strcpy_s(origencitas->nombreDoctor, temporalcitas.nombreDoctor);
		strcpy_s(origencitas->nombrePaciente, temporalcitas.nombrePaciente);
		origencitas->atendida = temporalcitas.atendida;
		strcpy_s(origencitas->atendidaChar, temporalcitas.atendidaChar);
		origencitas->cancelada = temporalcitas.cancelada;
		strcpy_s(origencitas->motivodeCancelacion, temporalcitas.motivodeCancelacion);
		origencitas->mesCita = temporalcitas.mesCita;
		strcpy_s(origencitas->mesCitaChar, temporalcitas.mesCitaChar);
		origencitas->sig = NULL;
		origencitas->ant = NULL;
	}
	else
	{
		while (auxcitas->sig != NULL)
			auxcitas = auxcitas->sig;
		auxcitas->sig = new Citas;
		auxcitas->sig->ant = auxcitas;
		auxcitas = auxcitas->sig;
		auxcitas->MinutosFinal = temporalcitas.MinutosFinal;
		strcpy_s(auxcitas->MinutosFinalChar, temporalcitas.MinutosFinalChar);
		auxcitas->MinutosInicio = temporalcitas.MinutosInicio;
		strcpy_s(auxcitas->MinutosInicioChar, temporalcitas.MinutosInicioChar);
		auxcitas->CedulaDoctor = temporalcitas.CedulaDoctor;
		auxcitas->numeroTelefonicoPaciente= temporalcitas.numeroTelefonicoPaciente;
		strcpy_s(auxcitas->numeroTelefonicoPacienteChar, temporalcitas.numeroTelefonicoPacienteChar);
		auxcitas->numeroespecialidadCita = temporalcitas.numeroespecialidadCita;
		strcpy_s(auxcitas->FechaDeCita, temporalcitas.FechaDeCita);
		strcpy_s(auxcitas->horacompleta, temporalcitas.horacompleta);
		auxcitas->HoraFinal = temporalcitas.HoraFinal;
		strcpy_s(auxcitas->HoraFinalChar, temporalcitas.HoraFinalChar);
		auxcitas->HoraInicio = temporalcitas.HoraInicio;
		strcpy_s(auxcitas->HoraInicioChar, temporalcitas.HoraInicioChar);
		auxcitas->numeroDeCita = auxcitas->ant->numeroDeCita+1;
		controladorNumeroDeCitas = auxcitas->numeroDeCita;
		_itoa_s(controladorNumeroDeCitas, auxcitas->numeroDeCitaChar, 10);
		strcpy_s(auxcitas->DireccionFotoDoctor, temporalcitas.DireccionFotoDoctor);
		strcpy_s(auxcitas->nombreDoctor, temporalcitas.nombreDoctor);
		strcpy_s(auxcitas->nombrePaciente, temporalcitas.nombrePaciente);
		auxcitas->atendida = temporalcitas.atendida;
		strcpy_s(auxcitas->atendidaChar, temporalcitas.atendidaChar);
		auxcitas->cancelada = temporalcitas.cancelada;
		strcpy_s(auxcitas->motivodeCancelacion, temporalcitas.motivodeCancelacion);
		auxcitas->mesCita = temporalcitas.mesCita;
		strcpy_s(auxcitas->mesCitaChar, temporalcitas.mesCitaChar);
		auxcitas->sig = NULL;
	}
	auxcitas = origencitas;
}
void guardarCitasArchivo() {
	auxcitas = origencitas;
	fstream archivo;
	archivo.open("Citas.bin", ios::binary | ios::trunc | ios::out);
	if (archivo.is_open())
	{
		Citas *temp = origencitas;
		while (temp!=NULL)
		{
			archivo.write(reinterpret_cast<char*>(temp), sizeof(Citas));
			temp = temp->sig;
		}
		archivo.close();
		return;
	}
}
void cargarCitasArchivo() {
	auxcitas = origencitas = NULL;
	controladorNumeroDeCitas = 0;
	fstream archivo;
	archivo.open("Citas.bin", ios::binary | ios::in | ios::ate);
	if (archivo.is_open())
	{
		int size = archivo.tellg();
		if (size==0)
		{
			return;
		}
		for (int i=0;i <(size/sizeof(Citas)); i++)
		{
			if (origencitas==NULL)
			{
				origencitas = new Citas;
				Citas *temp = new Citas;
				archivo.seekg(0);
				archivo.read(reinterpret_cast<char*>(temp), sizeof(Citas));
				origencitas->CedulaDoctor = temp->CedulaDoctor;
				origencitas->numeroTelefonicoPaciente=temp->numeroTelefonicoPaciente;
				strcpy_s(origencitas->numeroTelefonicoPacienteChar, temp->numeroTelefonicoPacienteChar);
				origencitas->numeroespecialidadCita = temp->numeroespecialidadCita;
				strcpy_s(origencitas->FechaDeCita, temp->FechaDeCita);
				strcpy_s(origencitas->horacompleta, temp->horacompleta);
				origencitas->HoraFinal = temp->HoraFinal;
				strcpy_s(origencitas->HoraFinalChar, temp->HoraFinalChar);
				origencitas->HoraInicio = temp->HoraInicio;
				strcpy_s(origencitas->HoraInicioChar, temp->HoraInicioChar);
				origencitas->numeroDeCita = temp->numeroDeCita;
				controladorNumeroDeCitas = temp->numeroDeCita;
				strcpy_s(origencitas->numeroDeCitaChar, temp->numeroDeCitaChar);
				strcpy_s(origencitas->DireccionFotoDoctor, temp->DireccionFotoDoctor);
				strcpy_s(origencitas->nombreDoctor, temp->nombreDoctor);
				strcpy_s(origencitas->nombrePaciente, temp->nombrePaciente);
				origencitas->atendida = temp->atendida;
				strcpy_s(origencitas->atendidaChar, temp->atendidaChar);
				origencitas->cancelada = temp->cancelada;
				strcpy_s(origencitas->motivodeCancelacion, temp->motivodeCancelacion);
				origencitas->mesCita = temp->mesCita;
				strcpy_s(origencitas->mesCitaChar, temp->mesCitaChar);
				origencitas->MinutosFinal = temp->MinutosFinal;
				strcpy_s(origencitas->MinutosFinalChar, temp->MinutosFinalChar);
				origencitas->MinutosInicio = temp->MinutosInicio;
				strcpy_s(origencitas->MinutosInicioChar, temp->MinutosInicioChar);
				origencitas->ant = NULL;
				origencitas->sig = NULL;
				delete reinterpret_cast<char*>(temp);
				continue;
			}
			auxcitas = origencitas;
			while (auxcitas->sig != NULL)
				auxcitas = auxcitas->sig;
			auxcitas->sig = new Citas;
			Citas *temp = new Citas;
			archivo.seekg(i * sizeof(Citas));
			archivo.read(reinterpret_cast<char*>(temp), sizeof(Citas));
			auxcitas->sig->ant = auxcitas;
			auxcitas->sig->sig = NULL;
			auxcitas = auxcitas->sig;
			auxcitas->CedulaDoctor = temp->CedulaDoctor;
			auxcitas->numeroTelefonicoPaciente= temp->numeroTelefonicoPaciente;
			strcpy_s(auxcitas->numeroTelefonicoPacienteChar, temp->numeroTelefonicoPacienteChar);
			auxcitas->numeroespecialidadCita = temp->numeroespecialidadCita;
			strcpy_s(auxcitas->FechaDeCita, temp->FechaDeCita);
			strcpy_s(auxcitas->horacompleta, temp->horacompleta);
			auxcitas->HoraFinal = temp->HoraFinal;
			strcpy_s(auxcitas->HoraFinalChar, temp->HoraFinalChar);
			auxcitas->HoraInicio = temp->HoraInicio;
			strcpy_s(auxcitas->HoraInicioChar, temp->HoraInicioChar);
			auxcitas->numeroDeCita = temp->numeroDeCita;
			controladorNumeroDeCitas = temp->numeroDeCita;
			strcpy_s(auxcitas->numeroDeCitaChar, temp->numeroDeCitaChar);
			strcpy_s(auxcitas->DireccionFotoDoctor, temp->DireccionFotoDoctor);
			strcpy_s(auxcitas->nombreDoctor, temp->nombreDoctor);
			strcpy_s(auxcitas->nombrePaciente, temp->nombrePaciente);
			auxcitas->atendida = temp->atendida;
			strcpy_s(auxcitas->atendidaChar, temp->atendidaChar);
			auxcitas->cancelada = temp->cancelada;
			strcpy_s(auxcitas->motivodeCancelacion, temp->motivodeCancelacion);
			auxcitas->mesCita = temp->mesCita;
			strcpy_s(auxcitas->mesCitaChar, temp->mesCitaChar);
			auxcitas->MinutosFinal = temp->MinutosFinal;
			strcpy_s(auxcitas->MinutosFinalChar, temp->MinutosFinalChar);
			auxcitas->MinutosInicio = temp->MinutosInicio;
			strcpy_s(auxcitas->MinutosInicioChar, temp->MinutosInicioChar);
			delete reinterpret_cast<char*>(temp);
		}
		archivo.close();
		return;
	}
	return;
}
bool verificarCita() {
	auxcitas = origencitas;
	while (auxcitas!=NULL)
	{
		if (auxcitas->CedulaDoctor==temporalcitas.CedulaDoctor) {
			if (auxcitas->numeroDeCita==temporalcitas.numeroDeCita)
			{
				auxcitas = origencitas;
				return true;
			}
			else if (strcmp(auxcitas->FechaDeCita,temporalcitas.FechaDeCita)==0)
			{
				if (auxcitas->HoraInicio>=temporalcitas.HoraInicio && auxcitas->HoraFinal<=temporalcitas.HoraFinal) {

						auxcitas = origencitas;
						return true;
						

				}
				else
				{
					auxcitas = origencitas;
					return true;
				}
			}
			else
			{
				auxcitas = origencitas;
				return true;
			}
		}
		else
		{
			auxcitas = origencitas;
			return true;
		}
		auxcitas = auxcitas->sig;
	}
	return true;
}
void ObtenerNombreDoctorCita() {
	int size = strlen(comparacionDoctorCita);
	int comparador = 0;
	int controlador = 0;
	char a[3];
	for (int i = 0; comparacionDoctorCita[i] != NULL; i++) {
		if (comparacionDoctorCita[i]==' ')
		{
			controlador++;
		}
		if (controlador==0)
		{
			temporalcitas.nombreDoctor[i] = comparacionDoctorCita[i];
		}
	}
	if (comparacionDoctorCita[size - 2]==' ')
	{
		a[0] = comparacionDoctorCita[size - 1];
		MedicosDeListBox = atoi(a);
		temporalcitas.CedulaDoctor = MedicosDeListBox;
	}
	else
	{
		a[0] = comparacionDoctorCita[size - 2];
		a[1] = comparacionDoctorCita[size - 1];
		MedicosDeListBox = atoi(a);
		temporalcitas.CedulaDoctor = MedicosDeListBox;
	}
}
void ObtenerNumeroEspecialidadCita() {
	int size = 0;
	int  contador=0;
	char contenedor[50];
	memset(contenedor, NULL, 50);
	while(comparacionEspecialidad[contador]!=' ')
	{
		contenedor[size] = comparacionEspecialidad[contador];
		contador++;
		size++;
		
	}
	encontrarEspecialidad(contenedor);
	memset(contenedor, NULL, 50);
}
void encontrarEspecialidad(char contenedor[50]) {
	auxespecialidad = origenespecialidad;
	while (auxespecialidad!=NULL)
	{
		if (strcmp(auxespecialidad->especialidad, contenedor) == 0) {
			temporalcitas.numeroespecialidadCita=auxespecialidad->numero;
			break;
		}
		auxespecialidad = auxespecialidad->sig;
	}
	auxespecialidad = origenespecialidad;
}
void ObtenerTelefonoCita() {
	int size = 0;
	int size2 = 0;
	int contador = 0;
	memset(temporalcitas.nombrePaciente, NULL, 2); 
	int longitud = strlen(comparacionPaciente);
	char contenedor[50];
	memset(contenedor, NULL, 50);
	for (int i = 0; comparacionPaciente[i] !=NULL; i++) {
		if (comparacionPaciente[i]==' ')
		{
			contador++;
		}
		if (contador==0)
		{
			temporalcitas.nombrePaciente[size2] = comparacionPaciente[i];
			size2++;
		}
		else if (contador==3)
		{
			temporalcitas.numeroTelefonicoPacienteChar[size] = comparacionPaciente[i];
			size++;
		}
	}
	temporalcitas.numeroTelefonicoPaciente=atof(temporalcitas.numeroTelefonicoPacienteChar);
	for (int j = 0; temporalcitas.nombrePaciente[j] != NULL; j++)
	{
		if (temporalcitas.nombrePaciente[j] < 65 || temporalcitas.nombrePaciente[j]>122) {
			temporalcitas.nombrePaciente[j] = NULL;
		}
	}
	memset(contenedor, NULL, 50);
}
void EncontrarNombreDoctor(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else
	{
		if (temporalcitas.CedulaDoctor == medico->Cedula)
		{
			strcpy_s(TextoDoctor, medico->NombreDoctor);
			strcpy_s(temporalcitas.nombreDoctor, medico->NombreDoctor);
			return;
		}
		else
		{
			EncontrarNombreDoctor(medico->izq);
			EncontrarNombreDoctor(medico->der);
		}
	}
}
void EncontrarPacienteCita() {
	auxpacientes = origenpacientes;
	while (auxcitas!=NULL)
	{
		if (strcmp(temporalcitas.numeroTelefonicoPacienteChar,auxpacientes->TelefonoChar)==0) {
			strcpy_s(TextoPaciente,auxpacientes->Nombre);
			
			return;
		}
		auxcitas = auxcitas->sig;
	}
	auxcitas = origencitas;
}
void EncontrarEspecialidadCita() {
	auxespecialidad = origenespecialidad;
	while (auxespecialidad != NULL) {
		if (temporalcitas.numeroespecialidadCita==auxespecialidad->numero)
		{
			strcpy_s(TextoEspecialidad, auxespecialidad->especialidad);
			return;
		}
		auxespecialidad = auxespecialidad->sig;
	}
	auxespecialidad = origenespecialidad;
}
void CompletarCita() {//Borrar Cita Sin texto de Cancelacion
	auxcitas = origencitas;
	cargarCitasArchivo();
	auxcitas = origencitas;
	int contador = 0;
	while (CitasListBox!=contador)
	{
		contador++;
		auxcitas = auxcitas->sig;
	}
	if (auxcitas->ant==NULL&&auxcitas->sig==NULL)
	{
		delete auxcitas;
		auxcitas = origencitas = NULL;
	}
	else if (auxcitas->ant==NULL)
	{
		origencitas = auxcitas->sig;
		delete auxcitas;
		origencitas->ant = NULL;
		auxcitas = origencitas;
	}
	else if (auxcitas->sig==NULL)
	{
		auxcitas->ant->sig = NULL;
		delete auxcitas;
		auxcitas = origencitas;
	}
	else
	{
		auxcitas->ant->sig = auxcitas->sig;
		auxcitas->sig->ant = auxcitas->ant;
		delete auxcitas;
		auxcitas = origencitas;
	}
	auxcitas = origencitas;
	return;
}
void CancelarCita() {
	auxcitas = origencitas;
	cargarCitasArchivo();
	auxcitas = origencitas;
	int contador = 0;
	while (CitasListBox != contador)
	{
		contador++;
		auxcitas = auxcitas->sig;
		auxcitas->atendida = false;
		auxcitas->cancelada = true;
		strcpy_s(auxcitas->motivodeCancelacion, temporalcitas.motivodeCancelacion);
	}
	if (auxcitas->ant == NULL&&auxcitas->sig == NULL)
	{
		delete auxcitas;
		auxcitas = origencitas = NULL;
	}
	else if (auxcitas->ant == NULL)
	{
		origencitas = auxcitas->sig;
		delete auxcitas;
		origencitas->ant = NULL;
		auxcitas = origencitas;
	}
	else if (auxcitas->sig == NULL)
	{
		auxcitas->ant->sig = NULL;
		delete auxcitas;
		auxcitas = origencitas;
	}
	else
	{
		auxcitas->ant->sig = auxcitas->sig;
		auxcitas->sig->ant = auxcitas->ant;
		delete auxcitas;
		auxcitas = origencitas;
	}
	auxcitas = origencitas;
	return;
}
void encontrarMedicoCitas(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else
	{
		if (strcmp(TextoDoctor,medico->CedulaChar)==0)
		{
			strcpy_s(temporalmedico.NombreDoctor,medico->NombreDoctor);
			temporalmedico.Cedula=medico->Cedula;
			strcpy_s(temporalmedico.CedulaChar, medico->CedulaChar);
		}
		else
		{
			encontrarMedicoCitas(medico->izq);
			encontrarMedicoCitas(medico->der);
		}
	}
}
void encontrarMesCitas() {
	auxcitas = origencitas;
	origenM = NULL;
	auxM = origenM;
	while (auxcitas != NULL) {
		if (strcmp(temporalmedico.NombreDoctor,auxcitas->nombreDoctor)==0)
		{	
			if (strcmp(TextoMesDeCita,auxcitas->mesCitaChar) ==0)
			{
				if (origenM==NULL)
				{
					origenM = new reporteMedico;
					strcpy_s(origenM->listaMedico, auxcitas->nombrePaciente);
					strcat(origenM->listaMedico, " "); 
					strcat(origenM->listaMedico, auxcitas->nombreDoctor);
					strcat(origenM->listaMedico, " ");
					strcat(origenM->listaMedico, auxcitas->FechaDeCita);
					strcat(origenM->listaMedico, " ");
					strcat(origenM->listaMedico, auxcitas->horacompleta);
					origenM->sig = NULL;
				}
				else
				{
					while (auxM->sig != NULL)
						auxM = auxM->sig;
					auxM->sig = new reporteMedico;
					auxM = auxM->sig;
					strcpy_s(auxM->listaMedico, auxcitas->nombrePaciente);
					strcat(auxM->listaMedico, " ");
					strcat(auxM->listaMedico, auxcitas->nombreDoctor);
					strcat(auxM->listaMedico, " ");
					strcat(auxM->listaMedico, auxcitas->FechaDeCita);
					strcat(auxM->listaMedico, " ");
					strcat(auxM->listaMedico, auxcitas->horacompleta);
					auxM->sig = NULL;
				}
			}
		}
		auxcitas = auxcitas->sig;
	}
	auxM = origenM;
}
void mandarReporteMedico() {
	auxM = origenM;
	fstream archivo;
	archivo.open("Reporte por medico.txt", ios::out);
	if (archivo.is_open())
	{
		reporteMedico *temp = origenM;
		while (temp!=NULL)
		{
			int longitud = strlen(temp->listaMedico);
			for (int i = 0; temp->listaMedico[longitud+i]<250; i++)
			{
				if (longitud+i<250) {
					temp->listaMedico[longitud + i] = ' ';

				}
				else
				{
					break;
				}
			}
			archivo.write(reinterpret_cast<char*>(temp), sizeof(reporteMedico));
			temp = temp->sig;
		}
		archivo.close();
		return;
	}
}
void transformarMesAIntCitas() {
	for (int i=0;temporalcitas.FechaDeCita[i]!=NULL;i++)
	{
		if (temporalcitas.FechaDeCita[i] == 'e') {
			if (temporalcitas.FechaDeCita[i+1]=='n')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'e') {
					temporalcitas.mesCita = 1;
					strcpy_s(temporalcitas.mesCitaChar, "1");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'f') {
			if (temporalcitas.FechaDeCita[i + 1] == 'e')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'b') {
					temporalcitas.mesCita = 2;
					strcpy_s(temporalcitas.mesCitaChar, "2");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'm') {
			if (temporalcitas.FechaDeCita[i + 1] == 'a')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'r'){
					temporalcitas.mesCita = 3;
					strcpy_s(temporalcitas.mesCitaChar, "3");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'a') {
			if (temporalcitas.FechaDeCita[i + 1] == 'b')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'r') {
					temporalcitas.mesCita = 4;
					strcpy_s(temporalcitas.mesCitaChar, "4");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'm') {
			if (temporalcitas.FechaDeCita[i + 1] == 'a')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'y') {
					temporalcitas.mesCita = 5;
					strcpy_s(temporalcitas.mesCitaChar, "5");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'j') {
			if (temporalcitas.FechaDeCita[i + 1] == 'u')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'n') {
					temporalcitas.mesCita = 6;
					strcpy_s(temporalcitas.mesCitaChar, "6");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'j') {
			if (temporalcitas.FechaDeCita[i + 1] == 'u')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'l') {
					temporalcitas.mesCita = 7;
					strcpy_s(temporalcitas.mesCitaChar, "7");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'a') {
			if (temporalcitas.FechaDeCita[i + 1] == 'g')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'o') {
					temporalcitas.mesCita = 8;
					strcpy_s(temporalcitas.mesCitaChar, "8");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 's') {
			if (temporalcitas.FechaDeCita[i + 1] == 'e')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'p') {
					temporalcitas.mesCita = 9;
					strcpy_s(temporalcitas.mesCitaChar, "9");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'o') {
			if (temporalcitas.FechaDeCita[i + 1] == 'c')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 't') {
					temporalcitas.mesCita = 10;
					strcpy_s(temporalcitas.mesCitaChar, "10");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'n') {
			if (temporalcitas.FechaDeCita[i + 1] == 'o')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'v') {
					temporalcitas.mesCita = 11;
					strcpy_s(temporalcitas.mesCitaChar, "11");
				}
			}
		}
		else if (temporalcitas.FechaDeCita[i] == 'd') {
			if (temporalcitas.FechaDeCita[i + 1] == 'i')
			{
				if (temporalcitas.FechaDeCita[i + 2] == 'c') {
					temporalcitas.mesCita = 12;
					strcpy_s(temporalcitas.mesCitaChar, "12");
				}
			}
		}
	}
}
bool verificacionCitasSemanas() {
	int comprobacion = 0;
	int size = strlen(TextoSemana);
	for (int i = 0; TextoSemana[i]!=NULL; i++)
	{
		if (TextoSemana[i]>='1'&&TextoSemana[i]<='4')
		{
			comprobacion++;
		}
	}
	if (comprobacion==size)
	{
		return true;
	}
	else {
		return false;
	}
}
bool verificacionEspecialidadBuscador() {
	int comprobacion = 0;
	int size = strlen(TextoEspecialidad);
	for (int i = 0; TextoEspecialidad[i] != NULL; i++) {
		if (TextoEspecialidad[i]>='a'&& TextoEspecialidad[i]<='z')
		{
			comprobacion++;
		}
		else if (TextoEspecialidad[i] >= 'A'&& TextoEspecialidad[i] <= 'Z')
		{
			comprobacion++;
		}
	}
	if (comprobacion==size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void BuscarSemanaCita() {
	origencitasemana = NULL;
	auxcitasemana = origencitasemana;
	int semana = atoi(TextoSemana);
	int mes = atoi(TextoMesDeCita);
	cargarCitasArchivo();
	auxfechas = origenfechas = NULL;
	auxcitas = origencitas;
	while (auxcitas!=NULL)
	{
			conseguirDiaDeCita();
			auxcitas=auxcitas->sig;

	}
	auxfechas = origenfechas;
	auxcitas = origencitas;
	while (auxfechas != NULL) {
		if (semana==1)
		{
			if ((auxcitas->mesCita == mes))
			{
				if (auxfechas->fecha<=7)
				{
					if (origencitasemana==NULL)
					{
						origencitasemana = new CitasSemana;
						strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->horacompleta);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						origencitasemana->sig = NULL;
					}
					else
					{
						while (auxcitasemana->sig != NULL)
							auxcitasemana = auxcitasemana->sig;
						auxcitasemana->sig = new CitasSemana;
						auxcitasemana = auxcitasemana->sig;
						strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->horacompleta);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						auxcitasemana->sig = NULL;
					}
				}
			}
		}
		else if (semana == 2) {
			if ((auxcitas->mesCita == mes))
			{
				if (auxfechas->fecha > 7 && auxfechas->fecha<=14)
				{
					if (origencitasemana == NULL)
					{
						origencitasemana = new CitasSemana;
						strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->horacompleta);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						origencitasemana->sig = NULL;
					}
					else
					{
						while (auxcitasemana->sig != NULL)
							auxcitasemana = auxcitasemana->sig;
						auxcitasemana->sig = new CitasSemana;
						auxcitasemana = auxcitasemana->sig;
						strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->horacompleta);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						auxcitasemana->sig = NULL;
					}
				}
			}
		}
		else if (semana == 3) {
			if ((auxcitas->mesCita == mes))
			{
				if (auxfechas->fecha >14&& auxfechas->fecha<=21)
				{
					if (origencitasemana == NULL)
					{
						origencitasemana = new CitasSemana;
						strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->horacompleta);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						origencitasemana->sig = NULL;
					}
					else
					{
						while (auxcitasemana->sig != NULL)
							auxcitasemana = auxcitasemana->sig;
						auxcitasemana->sig = new CitasSemana;
						auxcitasemana = auxcitasemana->sig;
						strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->horacompleta);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						auxcitasemana->sig = NULL;
					}
				}
			}
		}
		else if (semana == 4)
		{
			if ((auxcitas->mesCita == mes))
			{
				if (auxfechas->fecha > 21 )
				{
					if (origencitasemana == NULL)
					{
						origencitasemana = new CitasSemana;
						strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->horacompleta);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(origencitasemana->Lista, " ");
						strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						origencitasemana->sig = NULL;
					}
					else
					{
						while (auxcitasemana->sig != NULL)
							auxcitasemana = auxcitasemana->sig;
						auxcitasemana->sig = new CitasSemana;
						auxcitasemana = auxcitasemana->sig;
						strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->horacompleta);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
						strcat(auxcitasemana->Lista, " ");
						strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
						auxcitasemana->sig = NULL;
					}
				}
			}
		}
		auxfechas = auxfechas->sig;
		auxcitas = auxcitas->sig;
	}
	auxcitas = origencitas;
	auxcitasemana = origencitasemana;
}
void conseguirDiaDeCita() {
	for (int i = 0;auxcitas->FechaDeCita[i]!=NULL ; i++)
	{
		if (auxcitas->FechaDeCita[i] == ' ') {
			if (auxcitas->FechaDeCita[i-1]==',')
			{
				if (auxcitas->FechaDeCita[i+2]>='0'&&auxcitas->FechaDeCita[i+2]<='9')
				{
					if (auxcitas->FechaDeCita[i + 1] >= '1'&&auxcitas->FechaDeCita[i + 1] <= '9')
					{
						if (origenfechas==NULL)
						{
							origenfechas = new Fechas;
							origenfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							origenfechas->fechas[1] = auxcitas->FechaDeCita[i + 2];
							origenfechas->fecha = atoi(origenfechas->fechas);
							origenfechas->sig = NULL;
						}
						else
						{
							while (auxfechas->sig != NULL)
								auxfechas = auxfechas->sig;
							auxfechas->sig = new Fechas;
							auxfechas = auxfechas->sig;
							auxfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							auxfechas->fechas[1] = auxcitas->FechaDeCita[i + 2];
							auxfechas->fecha = atoi(auxfechas->fechas);
							auxfechas->sig = NULL;
						}
						auxfechas = origenfechas;
					}
				}
				else if (auxcitas->FechaDeCita[i + 1] >= '1'&&auxcitas->FechaDeCita[i + 1] <= '9') {
					if (origenfechas == NULL)
					{
						origenfechas = new Fechas;
						origenfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
						origenfechas->fecha = atoi(origenfechas->fechas);
						origenfechas->sig = NULL;
					}
					else
					{
						while (auxfechas->sig != NULL)
							auxfechas = auxfechas->sig;
						auxfechas->sig = new Fechas;
						auxfechas = auxfechas->sig;
						auxfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
						auxfechas->fecha = atoi(auxfechas->fechas);
						auxfechas->sig = NULL;
					}
					auxfechas = origenfechas;
				}
			}
		}
	}
}
void mandarReporte() {
	auxcitasemana = origencitasemana;
	fstream archivo;
	archivo.open("Reporte por semana.txt", ios::out);
	if (archivo.is_open())
	{
		CitasSemana *temp = origencitasemana;
		while (temp!=NULL)
		{
			int longitud = strlen(temp->Lista);
			int limpia = 100 - longitud;
			for (int i = 0; temp->Lista[longitud + i]<100; i++)
			{
				if (longitud+i<100)
				{
					temp->Lista[longitud + i] = ' ';
				}
				else
				{
					break;
				}
			}
			archivo.write(reinterpret_cast<char*>(temp), sizeof(CitasSemana));
			temp = temp->sig;
		}
		archivo.close();
		return;
	}
}
void rellenarespacionBlanco(CitasSemana *&a ) {
	int longitud = strlen(a->Lista);
	int limpia = 100 - longitud;
	for (int i = 0; a->Lista[longitud+i]<100; i++)
	{
		a->Lista[longitud + i] = ' ';
	}
}
bool buscarEspcialidadCita() {
	cargarCitasArchivo();
	cargarEspecialidadesArchivo();
	auxcitas = origencitas;
	auxespecialidad = origenespecialidad;
	auxcitasemana=origencitasemana = NULL;
	auxfechas =NULL;
	origenfechas = NULL;
	auxfechas = origenfechas;
	auxcitasemana = origencitasemana;
	conseguirDiaDeCita();
	int semana = atoi(TextoSemana);
	bool checkEspecialidad = false;
	while (auxespecialidad!=NULL)//Este busca si la especialidad que ingreso en reealidad existe
	{
		if (strcmp(auxespecialidad->especialidad, TextoEspecialidad) == 0) {
			checkEspecialidad = true;
			break;
		}
		auxespecialidad = auxespecialidad->sig;
	}
	if (checkEspecialidad==true)
	{
		while (auxcitas != NULL)
		{
			if (auxcitas->numeroespecialidadCita == auxespecialidad->numero) {
				//verificarSemanaEspecialidad();
				if (semana==1)
				{
					if (auxfechas->fecha<=7)
					{
						if (origencitasemana == NULL)
						{
							origencitasemana = new CitasSemana;
							strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->horacompleta);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							origencitasemana->sig = NULL;
						}
						else
						{
							while (auxcitasemana->sig != NULL)
								auxcitasemana = auxcitasemana->sig;
							auxcitasemana->sig = new CitasSemana;
							auxcitasemana = auxcitasemana->sig;
							strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->horacompleta);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							auxcitasemana->sig = NULL;
						}
						auxcitasemana = origencitasemana;
					}
				}
				else if (semana == 2) {
					if (auxfechas->fecha>7&&auxfechas->fecha<=14)
					{
						if (origencitasemana == NULL)
						{
							origencitasemana = new CitasSemana;
							strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->horacompleta);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							origencitasemana->sig = NULL;
						}
						else
						{
							while (auxcitasemana->sig != NULL)
								auxcitasemana = auxcitasemana->sig;
							auxcitasemana->sig = new CitasSemana;
							auxcitasemana = auxcitasemana->sig;
							strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->horacompleta);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							auxcitasemana->sig = NULL;
						}
						auxcitasemana = origencitasemana;
					}
				}
				else if (semana == 3) {
					if (auxfechas->fecha>14&&auxfechas->fecha<=21)
					{
						if (origencitasemana == NULL)
						{
							origencitasemana = new CitasSemana;
							strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->horacompleta);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							origencitasemana->sig = NULL;
						}
						else
						{
							while (auxcitasemana->sig != NULL)
								auxcitasemana = auxcitasemana->sig;
							auxcitasemana->sig = new CitasSemana;
							auxcitasemana = auxcitasemana->sig;
							strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->horacompleta);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							auxcitasemana->sig = NULL;
						}
						auxcitasemana = origencitasemana;
					}
				}
				else if (semana == 4) {
					if (auxfechas->fecha>21)
					{
						if (origencitasemana == NULL)
						{
							origencitasemana = new CitasSemana;
							strcpy_s(origencitasemana->Lista, auxcitas->nombrePaciente);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->nombreDoctor);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->FechaDeCita);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->horacompleta);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(origencitasemana->Lista, " ");
							strcat(origencitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							origencitasemana->sig = NULL;
						}
						else
						{
							while (auxcitasemana->sig != NULL)
								auxcitasemana = auxcitasemana->sig;
							auxcitasemana->sig = new CitasSemana;
							auxcitasemana = auxcitasemana->sig;
							strcpy_s(auxcitasemana->Lista, auxcitas->nombrePaciente);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->nombreDoctor);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->FechaDeCita);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->horacompleta);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroDeCitaChar);
							strcat(auxcitasemana->Lista, " ");
							strcat(auxcitasemana->Lista, auxcitas->numeroTelefonicoPacienteChar);
							auxcitasemana->sig = NULL;
						}
						auxcitasemana = origencitasemana;
					}
				}
			}
			auxcitas = auxcitas->sig;
			auxcitasemana = auxcitasemana->sig;
		}
	}
	return checkEspecialidad;
}
void agregarListaEspecialidad() {
	auxcitasemana = origencitasemana = NULL;

	if (origencitasemana==NULL)
	{

	}
}
void verificarSemanaEspecialidad() {
	for (int i=0;auxcitas->FechaDeCita[i]!=NULL;i++)
	{
		if (auxcitas->FechaDeCita[i] == ' ') {
			if (auxcitas->FechaDeCita[i-1]==',')
			{
				if (auxcitas->FechaDeCita[i + 1] >= '0'&&auxcitas->FechaDeCita[i+1] <= '9') {
					if (auxcitas->FechaDeCita[i + 2] >= '0'&& auxcitas->FechaDeCita[i + 2] <= '9') {
						if (origenfechas == NULL)
						{
							origenfechas = new Fechas;
							origenfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							origenfechas->fechas[1] = auxcitas->FechaDeCita[i + 2];
							origenfechas->fecha = atoi(origenfechas->fechas);
							origenfechas->sig = NULL;
						}
						else
						{
							while (auxfechas->sig != NULL)
								auxfechas = auxfechas->sig;
							auxfechas->sig = new Fechas;
							auxfechas = auxfechas->sig;
							auxfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							auxfechas->fechas[1] = auxcitas->FechaDeCita[i + 2];
							auxfechas->fecha = atoi(auxfechas->fechas);
							auxfechas->sig = NULL;
						}
					}
					else
					{
						if (origenfechas == NULL)
						{
							origenfechas = new Fechas;
							origenfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							origenfechas->fecha = atoi(origenfechas->fechas);
							origenfechas->sig = NULL;
						}
						else
						{
							while (auxfechas->sig != NULL)
								auxfechas = auxfechas->sig;
							auxfechas->sig = new Fechas;
							auxfechas = auxfechas->sig;
							auxfechas->fechas[0] = auxcitas->FechaDeCita[i + 1];
							auxfechas->fecha = atoi(auxfechas->fechas);
							auxfechas->sig = NULL;
						}
					}
				}
			}
		}
	}
}
void mandarReporteespecialidad() {
	auxcitasemana = origencitasemana;
	fstream archivo;
	archivo.open("Reporte por especialidad.txt", ios::out);
	if (archivo.is_open())
	{
		CitasSemana *temp = origencitasemana;
		int longitud = strlen(temp->Lista);
		int limpia = 100 - longitud;
		int cien = 100;
		for (int i = 0;temp->Lista[longitud+i]<100 ; i++)
		{
			int check = longitud + i;
			if (check<cien)
			{
				temp->Lista[longitud + i] == ' ';
			}
			else {
				break;
			}
		}
		archivo.write(reinterpret_cast<char*>(temp), sizeof(CitasSemana));
		temp = temp->sig;
	}
	archivo.close();
}
void AgregarNumeroEnQuickSort() {
	raiz = medico;
	auxint = NULL;
	origenint = NULL;
	pasarMedicoAInt(medico);
	OrdenamientoMedicoQuickSort(medico);
	raiz = medico;
	Medicos *temp = raiz;
	pasarMedicoArchivoQuickSort();
	posicionQS = 0;
	raiz = medico;
}
void pasarMedicoAInt(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else
	{
		agregarInt(medico);
		pasarMedicoAInt(medico->izq);
		pasarMedicoAInt(medico->der);
	}
}
void OrdenamientoMedicoQuickSort(Medicos *medico) {
	OrdenamientoQuickSortAux(numeros, 0, numeros.size() - 1);

}
void OrdenamientoQuickSortAux(vector<int>&numeros, int limite_izq, int limite_der) {
	int izq = limite_izq;
	int der = limite_der;
	int pivote = numeros[(izq + der) / 2];
	int temporal;
	do
	{
		while (numeros[izq] < pivote && izq < limite_der) {
			++izq;
		}
		while (pivote<numeros[der]&&der>limite_izq)
		{
			--der;
		}
		if (izq<=der)
		{
			temporal = numeros[izq];
			numeros[izq] = numeros[der];
			numeros[der] = temporal;
			++izq;
			--der;
		}
	} while (izq<=der);
	if (limite_izq<der)
	{
		OrdenamientoQuickSortAux(numeros, limite_izq, der);
	}
	if (limite_der>izq)
	{
		OrdenamientoQuickSortAux(numeros, izq, limite_der);
	}
}
void agregarInt(Medicos *medico) {
	numeros.push_back(medico->Cedula);
	auxint = origenint;
	if (origenint == NULL)
	{
		origenint = new NumeroDeCedulasComp;
		strcpy_s(origenint->ListaQS, medico->NombreDoctor);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->ApellidoPaterno);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->ApellidoMaterno);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->CedulaChar);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->numeroTelefonicoChar);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->HoraInicioChar);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->HoraSalidaChar);
		strcat(origenint->ListaQS, " ");
		strcat(origenint->ListaQS, medico->numerodeconsultorioChar);
		origenint->cedulaInt = medico->Cedula;
		origenint->sig = NULL;
	}
	else
	{
		while (auxint->sig != NULL)
			auxint = auxint->sig;
		auxint->sig = new NumeroDeCedulasComp;
		auxint = auxint->sig;
		strcpy_s(auxint->ListaQS, medico->NombreDoctor);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->ApellidoPaterno);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->ApellidoMaterno);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->CedulaChar);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->numeroTelefonicoChar);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->HoraInicioChar);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->HoraSalidaChar);
		strcat(auxint->ListaQS, " ");
		strcat(auxint->ListaQS, medico->numerodeconsultorioChar);
		auxint->cedulaInt = medico->Cedula;
		auxint->sig = NULL;
	}
	auxint = origenint;
}
void pasarMedicoArchivoQuickSort() {
	fstream archivo;
	archivo.open("QuickSort.txt",ios::out);
	auxint = origenint;
	int controlador = numeros.size();
	NumeroDeCedulasComp *temp = origenint;
	if (archivo.is_open())
	{
		while (controlador>posicionQS)
		{
			while (temp != NULL) {
				if (posicionQS<controlador)
				{
					if (numeros[posicionQS] == temp->cedulaInt) {
						int longitud = strlen(temp->ListaQS);
						int limpia = 150 - longitud;
						int cien = 150;
						for (int i = 0; temp->ListaQS[longitud + i] <= 150; i++) {
							int check = longitud + i;
							if (check <cien)
							{
								temp->ListaQS[longitud + i] = ' ';
							}
							else
							{
								break;
							}
						}
						archivo.write(reinterpret_cast<char*>(temp), sizeof(NumeroDeCedulasComp));
						posicionQS++;
					}
				}
				temp = temp->sig;
			}
			temp = origenint;
		}
		archivo.close();
	}

}
void ordenarPacientesHP() {
	auxpacientes = origenpacientes;
	auxHP = origenHP = NULL;
	pacientes *temp = origenpacientes->sig;
	pacientes cambio;
	while (auxpacientes!=NULL)
	{ 
		while (temp !=NULL)
		{
			if (strcoll(auxpacientes->ApellidoMaterno, temp->ApellidoPaterno) > 0) {
				cambio.ano = auxpacientes->ano;
				strcpy_s(cambio.anoChar, auxpacientes->anoChar);
				strcpy_s(cambio.ApellidoMaterno, auxpacientes->ApellidoMaterno);
				strcpy_s(cambio.ApellidoPaterno, auxpacientes->ApellidoPaterno);
				cambio.Dia = auxpacientes->Dia;
				strcpy_s(cambio.DiaChar, auxpacientes->DiaChar);
				cambio.Edad = auxpacientes->Edad;
				strcpy_s(cambio.EdadChar, auxpacientes->EdadChar);
				strcpy_s(cambio.fechacompleta, auxpacientes->fechacompleta);
				strcpy_s(cambio.genero, auxpacientes->genero);
				cambio.Mes = auxpacientes->Mes;
				strcpy_s(cambio.MesChar, auxpacientes->MesChar);
				strcpy_s(cambio.Nombre, auxpacientes->Nombre);
				strcpy_s(cambio.primermedico, auxpacientes->primermedico);
				strcpy_s(cambio.referencia, auxpacientes->referencia);
				cambio.Telefono = auxpacientes->Telefono;
				strcpy_s(cambio.TelefonoChar, auxpacientes->TelefonoChar);
				

				auxpacientes->ano = temp->ano;
				strcpy_s(auxpacientes->anoChar, temp->anoChar);
				strcpy_s(auxpacientes->ApellidoMaterno, temp->ApellidoMaterno);
				strcpy_s(auxpacientes->ApellidoPaterno, temp->ApellidoPaterno);
				auxpacientes->Dia = temp->Dia;
				strcpy_s(auxpacientes->DiaChar, temp->DiaChar);
				auxpacientes->Edad = temp->Edad;
				strcpy_s(auxpacientes->EdadChar, temp->EdadChar);
				strcpy_s(auxpacientes->fechacompleta, temp->fechacompleta);
				strcpy_s(auxpacientes->genero, temp->genero);
				auxpacientes->Mes = temp->Mes;
				strcpy_s(auxpacientes->MesChar, temp->MesChar);
				strcpy_s(auxpacientes->Nombre, temp->Nombre);
				strcpy_s(auxpacientes->primermedico, temp->primermedico);
				strcpy_s(auxpacientes->referencia, temp->referencia);
				auxpacientes->Telefono = temp->Telefono;
				strcpy_s(auxpacientes->TelefonoChar, temp->TelefonoChar);

				temp->ano = cambio.ano;
				strcpy_s(temp->anoChar, cambio.anoChar);
				strcpy_s(temp->ApellidoMaterno, cambio.ApellidoMaterno);
				strcpy_s(temp->ApellidoPaterno, cambio.ApellidoPaterno);
				temp->Dia = cambio.Dia;
				strcpy_s(temp->DiaChar, cambio.DiaChar);
				temp->Edad = cambio.Edad;
				strcpy_s(temp->EdadChar, cambio.EdadChar);
				strcpy_s(temp->fechacompleta, cambio.fechacompleta);
				strcpy_s(temp->genero, cambio.genero);
				temp->Mes = cambio.Mes;
				strcpy_s(temp->MesChar, cambio.MesChar);
				strcpy_s(temp->Nombre, cambio.Nombre);
				strcpy_s(temp->primermedico, cambio.primermedico);
				temp->Telefono = cambio.Telefono;
				strcpy_s(temp->TelefonoChar, cambio.TelefonoChar);
			}
			temp = temp->sig;
		}
		auxpacientes = auxpacientes->sig;
	}
}
void hacerListaHP() {
	auxHP= NULL;
	origenHP = NULL;
	auxHP = origenHP;
	auxpacientes = origenpacientes;
	while (auxpacientes!=NULL)
	{
		if (origenHP == NULL)
		{
			origenHP = new ListaDePacientesHeapShor;
			strcpy_s(origenHP->ListaHP, auxpacientes->ApellidoPaterno);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->ApellidoMaterno);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->Nombre);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->fechacompleta);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->EdadChar);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->TelefonoChar);
			strcat(origenHP->ListaHP, " ");
			strcat(origenHP->ListaHP, auxpacientes->primermedico);
			origenHP->sig = NULL;
			auxHP = origenHP;
		}
		else
		{
			while (auxHP->sig != NULL)
				auxHP = auxHP->sig;
			auxHP->sig = new ListaDePacientesHeapShor;
			auxHP = auxHP->sig;
			strcpy_s(auxHP->ListaHP, auxpacientes->ApellidoPaterno);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->ApellidoMaterno);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->Nombre);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->fechacompleta);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->EdadChar);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->TelefonoChar);
			strcat(auxHP->ListaHP, " ");
			strcat(auxHP->ListaHP, auxpacientes->primermedico);
			auxHP->sig = NULL;

		}
		auxpacientes = auxpacientes->sig;
	}
}
void reporteHP() {
	auxHP = origenHP;
	fstream archivo;
	archivo.open("HeapShort.txt", ios::out);
	if (archivo.is_open())
	{
		ListaDePacientesHeapShor *temp = origenHP;
		while (temp!=NULL)
		{
			int longitud = strlen(temp->ListaHP);
			for (int i = 0; temp->ListaHP[longitud + i] < 100; i++) {
				if (longitud + i<100)
				{
					temp->ListaHP[longitud + i] = ' ';
				}
				else
				{
					break;
				}
			}
			archivo.write(reinterpret_cast<char*>(temp), sizeof(ListaDePacientesHeapShor));
			temp = temp->sig;
		}
	}
	archivo.close();
}
void hacerEdicion(Medicos *medico) {
	if (medico==NULL)
	{

	}
	else 
	{
		if (temporalmedico.Cedula==medico->Cedula)
		{
			strcpy_s(medico->ApellidoMaterno, temporalmedico.ApellidoMaterno);
			strcpy_s(medico->ApellidoPaterno, temporalmedico.ApellidoPaterno);
			strcpy_s(medico->CedulaChar, temporalmedico.CedulaChar);
			strcpy_s(medico->diasactivos, temporalmedico.diasactivos);
			strcpy_s(medico->DireccionFoto, temporalmedico.DireccionFoto);
			strcpy_s(medico->especialidadM, temporalmedico.especialidadM);
			strcpy_s(medico->HoraInicioChar, temporalmedico.HoraInicioChar);
			strcpy_s(medico->HoraSalidaChar, temporalmedico.HoraSalidaChar);
			strcpy_s(medico->NombreDoctor, temporalmedico.NombreDoctor);
			strcpy_s(medico->numerodeconsultorioChar, temporalmedico.numerodeconsultorioChar);
			strcpy_s(medico->numeroTelefonicoChar, temporalmedico.numeroTelefonicoChar);
			medico->Cedula = temporalmedico.Cedula;
			medico->Domingo = temporalmedico.Domingo;
			medico->HoraInicio = temporalmedico.HoraInicio;
			medico->HoraSalida = temporalmedico.HoraSalida;
			medico->Jueves = temporalmedico.Jueves;
			medico->Lunes = temporalmedico.Lunes;
			medico->Martes = temporalmedico.Martes;
			medico->Miercoles = temporalmedico.Miercoles;
			medico->Jueves = temporalmedico.Jueves;
			medico->Viernes = temporalmedico.Viernes;
			medico->Sabado = temporalmedico.Sabado;
			medico->Viernes = temporalmedico.Viernes;
			return;
		}
		else
		{
			hacerEdicion(medico->izq);
			hacerEdicion(medico->der);
		}
	}
}
void escogerMedicoEdicion() {
	auxcitas = origencitas;
	int contador = 0;
	while (auxcitas!=NULL)
	{
		if (contador==CitasListBox)
		{
			strcpy_s(temporalcitas.atendidaChar, auxcitas->atendidaChar);
			strcpy_s(temporalcitas.DireccionFotoDoctor, auxcitas->DireccionFotoDoctor);
			strcpy_s(temporalcitas.FechaDeCita, auxcitas->FechaDeCita);
			strcpy_s(temporalcitas.horacompleta, auxcitas->horacompleta);
			strcpy_s(temporalcitas.HoraFinalChar, auxcitas->HoraFinalChar);
			strcpy_s(temporalcitas.HoraInicioChar, auxcitas->HoraInicioChar);
			strcpy_s(temporalcitas.mesCitaChar, auxcitas->mesCitaChar);
			strcpy_s(temporalcitas.MinutosFinalChar, auxcitas->MinutosFinalChar);
			strcpy_s(temporalcitas.MinutosInicioChar, auxcitas->MinutosInicioChar);
			strcpy_s(temporalcitas.motivodeCancelacion, auxcitas->motivodeCancelacion);
			strcpy_s(temporalcitas.nombreDoctor, auxcitas->nombreDoctor);
			strcpy_s(temporalcitas.nombrePaciente, auxcitas->nombrePaciente);
			strcpy_s(temporalcitas.numeroDeCitaChar, auxcitas->numeroDeCitaChar);
			strcpy_s(temporalcitas.numeroTelefonicoPacienteChar, auxcitas->numeroTelefonicoPacienteChar);
			temporalcitas.atendida = auxcitas->atendida;
			temporalcitas.cancelada = auxcitas->cancelada;
			temporalcitas.CedulaDoctor = auxcitas->CedulaDoctor;
			temporalcitas.HoraFinal = auxcitas->HoraFinal;
			temporalcitas.HoraInicio = auxcitas->HoraInicio;
			temporalcitas.mesCita = auxcitas->mesCita;
			temporalcitas.MinutosFinal = auxcitas->MinutosFinal;
			temporalcitas.MinutosInicio = auxcitas->MinutosInicio;
			temporalcitas.numeroDeCita = auxcitas->numeroDeCita;
			temporalcitas.numeroespecialidadCita = auxcitas->numeroespecialidadCita;
			temporalcitas.numeroTelefonicoPaciente = auxcitas->numeroTelefonicoPaciente;
		}
		contador++;
		auxcitas = auxcitas->sig;
	} 
	auxcitas = origencitas;
}
void guardarEdicionCitas() {//
	auxcitas = origencitas;
	int contador = 0;
	while (auxcitas!=NULL)
	{
		if (contador==CitasListBox)
		{
			strcpy_s(auxcitas->atendidaChar, temporalcitas.atendidaChar);
			strcpy_s(auxcitas->DireccionFotoDoctor, temporalcitas.DireccionFotoDoctor);
			strcpy_s(auxcitas->FechaDeCita, temporalcitas.FechaDeCita);
			strcpy_s(auxcitas->horacompleta, temporalcitas.horacompleta);
			strcpy_s(auxcitas->HoraFinalChar, temporalcitas.HoraFinalChar);
			strcpy_s(auxcitas->HoraInicioChar, temporalcitas.HoraInicioChar);
			strcpy_s(auxcitas->mesCitaChar, temporalcitas.mesCitaChar);
			strcpy_s(auxcitas->MinutosFinalChar, temporalcitas.MinutosFinalChar);
			strcpy_s(auxcitas->MinutosInicioChar, temporalcitas.MinutosInicioChar);
			strcpy_s(auxcitas->motivodeCancelacion, temporalcitas.motivodeCancelacion);
			strcpy_s(auxcitas->nombreDoctor, temporalcitas.nombreDoctor);
			strcpy_s(auxcitas->nombrePaciente, temporalcitas.nombrePaciente);
			strcpy_s(auxcitas->numeroDeCitaChar, temporalcitas.numeroDeCitaChar);
			strcpy_s(auxcitas->numeroTelefonicoPacienteChar, temporalcitas.numeroTelefonicoPacienteChar);
			auxcitas->atendida = temporalcitas.atendida;
			auxcitas->cancelada = temporalcitas.cancelada;
			auxcitas->CedulaDoctor = temporalcitas.CedulaDoctor;
			auxcitas->HoraFinal = temporalcitas.HoraFinal;
			auxcitas->HoraInicio = temporalcitas.HoraInicio;
			auxcitas->mesCita = temporalcitas.mesCita;
			auxcitas->MinutosFinal = temporalcitas.MinutosFinal;
			auxcitas->MinutosInicio = temporalcitas.MinutosInicio;
			auxcitas->numeroDeCita = temporalcitas.numeroDeCita;
			auxcitas->numeroespecialidadCita = temporalcitas.numeroespecialidadCita;
			auxcitas->numeroTelefonicoPaciente = temporalcitas.numeroTelefonicoPaciente;
		}
		contador++;
		auxcitas = auxcitas->sig;
	}
	auxcitas = origencitas;
}
bool verificacionCedulaBuscadorMedico() {
	int comparar = 0;
	int size = strlen(TextoDoctor);
	for (int i = 0; TextoDoctor[i]!=NULL; i++)
	{
		if (TextoDoctor[i] >= '0'&&TextoDoctor[i] <= '9') {
			comparar++;
		}
	}
	if (size==0)
	{
		return false;
	}
	else if (size==comparar)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool verificacionMesBuscadorMedico() {
	int comparar = 0;
	int size = strlen(TextoMesDeCita);
	for (int i = 0; TextoMesDeCita[i] != NULL; i++)
	{
		if (TextoMesDeCita[i] >= '1'&&TextoMesDeCita[i] <= '4') {
			comparar++;
		}
	}
	if (size == 0)
	{
		return false;
	}
	else if (size == comparar)
	{
		return true;
	}
	else
	{
		return false;
	}
}