/**
 * @file metrics.h
 * @brief Funciones para obtener el uso de CPU y memoria desde el sistema de archivos /proc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief tamaño de buffer para guardar las lineas al leerlas
 */
#define BUFFER_SIZE 256

/**
 * @brief Obtiene el porcentaje de uso de memoria desde /proc/meminfo.
 *
 * Lee los valores de memoria total y disponible desde /proc/meminfo y calcula
 * el porcentaje de uso de memoria.
 *
 * @return Uso de memoria como porcentaje (0.0 a 100.0), o -1.0 en caso de error.
 */
double get_memory_usage();

/**
 * @brief Obtiene el porcentaje de uso de CPU desde /proc/stat.
 *
 * Lee los tiempos de CPU desde /proc/stat y calcula el porcentaje de uso de CPU
 * en un intervalo de tiempo.
 *
 * @return Uso de CPU como porcentaje (0.0 a 100.0), o -1.0 en caso de error.
 */
double get_cpu_usage();

/**
 * @brief Obtiene el los procesos en uso en ese momento
 *
 * Lee los procesos running desde proc/stat y lo devuelve
 *
 * @return cantidad de procesos ejecutandose en ese momento
 */
unsigned long long get_process();

/**
 * @brief Obtiene el tiempo promedio de operacion de lectura del disco
 *
 * lee de /proc/diskstats valores de lectura del disco en tiempo y cantidad de operaciones para
 * calcular despues el tiempo promedio de respuesta
 *
 * @return el tiempo promedio de operacion de lectura del disco.
 */
double get_avg_read_disk_time();

/**
 * @brief Obbtiene el tiempo promedio de operacion de escritura del disco
 *
 * lee de /proc/diskstats valores de escritura del disco en tiempo y cantidad de operaciones para
 * calcular despues el tiempo promedio de respuesta
 *
 * @return el tiempo promedio de operacion de escritura del disco.
 */
double get_avg_write_disk_time();

/**
 * @brief Obtiene el porcentaje de uso del disco

 * lee de /proc/diskstats valores de tiempo trabajado, los almacena en una variable y luego opera
 * con la siguiente lectura para saber el porcentaje de utilizacion del mismo en operaciones de IO
 *
 * @return porcentaje de utilizacion del disco.
 */
double get_disk_IO_percentage_time();

/**
 * @brief Obtiene la velocidad de recepcion de packetes de internet en kbps
 *
 * Lee los de /proc/net/dev datos de la cantidad de bytes recibidos, los guarda en una variable para luego
 * operar con la siguiente lectura para calcular en kbps la velocidad de recepcion de bytes
 *
 * @return la velocidad de recepcion de bytes en kbps.
 */
double get_net_receive_kbps();

/**
 * @brief Obtiene la velocidad de envio de packetes de internet en kbps
 *
 * Lee los de /proc/net/dev datos de la cantidad de bytes enviados, los guarda en una variable para luego
 * operar con la siguiente lectura para calcular en kbps la velocidad de envio de bytes
 *
 * @return la velocidad de envio de bytes en kbps.
 */
double get_net_sent_kbps();

/**
 * @brief Obtiene el total de packetes de internet recibidos
 *
 * Lee los de /proc/net/dev datos de la cantidad packetes recibidos para luego retornarlos.
 *
 * @return la cantidad total de paquetes recibidos de internet.
 */
unsigned long long get_net_received_packets();

/**
 * @brief Obtiene el total de packetes de internet enviados
 *
 * Lee los de /proc/net/dev datos de la cantidad packetes enviados para luego retornarlos.
 *
 * @return la cantidad total de paquetes enviados de internet.
 */
unsigned long long get_net_sent_packets();
