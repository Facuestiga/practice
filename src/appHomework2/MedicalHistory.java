package appHomework2;

public final class MedicalHistory {



        private String codigo;
        private String fecha;
        private String idPaciente;
        private String idMedico;
        private String observaciones;

        public MedicalHistory(String codigo, String fecha, String idPaciente,
                                String idMedico, String observaciones) {
            this.codigo = codigo;
            this.fecha = fecha;
            this.idPaciente = idPaciente;
            this.idMedico = idMedico;
            this.observaciones = observaciones;
        }

        public String getCodigo() {
            return codigo;
        }

        public void setCodigo(String codigo) {
            this.codigo = codigo;
        }

        public String getFecha() {
            return fecha;
        }

        public void setFecha(String fecha) {
            this.fecha = fecha;
        }

        public String getIdPaciente() {
            return idPaciente;
        }

        public void setIdPaciente(String idPaciente) {
            this.idPaciente = idPaciente;
        }

        public String getIdMedico() {
            return idMedico;
        }

        public void setIdMedico(String idMedico) {
            this.idMedico = idMedico;
        }

        public String getObservaciones() {
            return observaciones;
        }

        public void setObservaciones(String observaciones) {
            this.observaciones = observaciones;
        }

        /**
         * Muestra por consola todos los datos del Historial Clinico
         */
        public void mostrar() {
            System.out.println("\n\t---------------");
            System.out.println("History code: " + codigo);
            System.out.println("Date: " + fecha);
            System.out.println("ID Patient: " + idPaciente);
            System.out.println("ID Doctor: " + idMedico);
            System.out.println("Observations:\n" + observaciones);
            System.out.println("\t---------------");
        }

}
