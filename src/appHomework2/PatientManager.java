package appHomework2;

import java.util.ArrayList;
import java.lang.reflect.Array;
import java.util.Scanner;

public class PatientManager {

        private ArrayList<Patient> pacientes;
        private Scanner teclado;

        public PatientManager() {
            pacientes = new ArrayList<Patient>();
            teclado = new Scanner(System.in);
        }

        /**
         * Crea y registra un nuevo paciente.
         * @return True si se pudo registrar con éxito el nuevo paciente.
         * False si no fue posible registrarlo.
         */
        public boolean nuevoPaciente() {
            System.out.println("\n\tALTA NUEVO PACIENTE");
            System.out.print("Enter the patient's ID : ");
            String id = teclado.nextLine();
            boolean idOk = esDni(id);
            while(idOk == false){
                System.out.println("Error! Enter the patient's ID: ");
                id = teclado.nextLine();
                idOk = esDni(id);
            }

            //Name input
            System.out.print("Nombre: ");
            String nombre = teclado.nextLine();
            System.out.print("Apellidos: ");
            String apellidos = teclado.nextLine();
            System.out.print("Genero: ");
            String genero = teclado.nextLine();
            System.out.print("Edad: ");
            int edad = teclado.nextInt();
            teclado.nextLine();//Tras leer un int, conviene "limpiar" el stream de entrada, para evitar problemas al querer leer luego datos String
            Patient nuevoPaciente = new Patient(id, nombre, apellidos, edad, genero);
            return pacientes.add(nuevoPaciente);//Devuelve TRUE si se insertó correctamente, FALSE si no se pudo insertar
        }

        /**
         * Lista por pantalla los datos de todos los pacientes registrados.
         */
        public void mostrarPacientes() {
            for (Patient p: pacientes)
                p.mostrar();
        }

        public boolean esDni(String strDni){
            boolean verifiedDni = false;
            char[] ch = strDni.toCharArray();
            StringBuilder strBuild = new StringBuilder();
            for(char c : ch){
                if(Character.isDigit(c)){
                    strBuild.append(c);
                    verifiedDni = true;
                }
            }
            return verifiedDni;
        }


}
