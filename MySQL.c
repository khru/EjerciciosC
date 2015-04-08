/* gcc -o MySQL.exe $(mysql_config --cflags) MySQL.c $(mysql_config --libs) */
#include <mysql.h>
#include <stdio.h>
main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   char *server = "localhost";
   char *user = "root";
   char *password = "passwd"; /* Contraseña de acceso a MySQL */
   char *database = "instituto";
   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   /* Tras la conexión si no hay ningun error muestra un mensaje*/
   printf("[+]Conectado a la base de datos\n");
   /* Envia una petición a MySQL */
   if (mysql_query(conn, "show tables")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   /* Tras el envio de la consulta o petición muestra un mensaje*/
   printf("\n[+] Haciendo query\n");
   res = mysql_use_result(conn);
   /* Titulo de la tabla*/ 
   printf("\n[+] Mostrando resultados [+]\nLas tablas dentro de la base de datos MySQL son:\n");
   /* Recorre todas las filas de las columnas especificadas*/
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);

   if (mysql_query(conn, "use instituto;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   if (mysql_query(conn, "select * from matricula;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
   printf("\nSELECT * FROM matricula; \n");
   printf("cod_mat\tcod_asig\tnre\tanyo\tcod_curso\tnota\n");
   while ((row = mysql_fetch_row(res)) != NULL) /* recorrer la variable res con todos los registros obtenidos para su uso */
      printf("%s\t%s\t%s\t%s\t%s\t\t%s\n", row[0],row[1],row[2],row[3],row[4],row[5]); 
   /* Libera el espacio en memoria que ocupa la petición o consulta */
   mysql_free_result(res);
   /* Cierra la conexión con MySQL */
   mysql_close(conn);
}
