package appHomework2;

public final class Patient {



        private String id;
        private String nombre;
        private String apellidos;
        private int edad;
        private String genero;

        public Patient(String id, String nombre, String apellidos, int edad, String genero) {
            this.id = id;
            this.nombre = nombre;
            this.apellidos = apellidos;
            this.edad = edad;
            this.genero = genero;
        }

        public String getId() {
            return id;
        }

        public void setId(String id) {
            this.id = id;
        }

        public String getNombre() {
            return nombre;
        }

        public void setNombre(String nombre) {
            this.nombre = nombre;
        }

        public String getApellidos() {
            return apellidos;
        }

        public void setApellidos(String apellidos) {
            this.apellidos = apellidos;
        }

        public int getEdad() {
            return edad;
        }

        public void setEdad(int edad) {
            this.edad = edad;
        }

        public String getGenero() {
            return genero;
        }

        public void setGenero(String genero) {
            this.genero = genero;
        }

        /**
         * Show all dates of a Patient
         */
        public void mostrar() {
            System.out.println("\n\t---------------");
            System.out.println("ID Patient: " + id);
            System.out.println("Name: " + nombre);
            System.out.println("Last Name: " + apellidos);
            System.out.println("Age: " + edad);
            System.out.println("Gender: " + genero);
            System.out.println("\t---------------");
        }

}
