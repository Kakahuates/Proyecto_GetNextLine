/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakahuate <kakahuate@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:31:06 by kakahuate         #+#    #+#             */
/*   Updated: 2025/06/04 16:50:29 by kakahuate        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	bytes_read; //el numero de bytes leidos
	char	*buffer; //puntero a un buffer donde se guardan los datos leidos
	int		count; //cuantos bytes como maximo quiero leer
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		printf("Error al leer el archivo");
		close(fd);
		return ((char *) NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}
int main()
{
	int		fd;
	char	*path;
	char	*line_to_print;
	int		i;

	path = "text.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 4)
	{
		line_to_print = get_next_line(fd);
		printf("fd es: %i,  %s\n", fd, line_to_print);
		i++;
	}
	close(fd);
	return(0);
}




/* static void	error_message(const char *msg)
{
	size_t	length;
	int		max_msg_length;

	length = 0;
	max_msg_length = 256;
	while (msg[length] != '\0' && length < max_msg_length - 1)
		length++;
	write(STDOUT_FILENO, msg, length);
	write(STDOUT_FILENO, "\n", 1);
}

char	*get_next_line(int fd)
{
	ssize_t	read_fd;
	// puntero char a donde guardaré lo que ya leí, usar malloc
	char	*read_buffer;
	// tamaño final del buffer donde guardo lo que lei, ya que puede variar
	int		buffer_size;

	buffer_size = BUFFER_SIZE;
	
	// asignamos memoria para lo que leimos
	read_buffer = (char *)malloc(buffer_size);
	if (read_buffer == NULL)
	{
		error_message("Error, no se pudo asignar memoria para el buffer");
		close(read_fd);
	}
	
	// 1. leer el archivo, read me retorna tipo ssize_t, buffer_size es la
	// cantidad de bytes maxima que quiero leer de una sola vez
	read_fd = read(fd, read_buffer, buffer_size);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	// 1. declarar variables
	int		fd;
	char	*file_name;
	char	*str_to_print;
	int		i;

	fd = 0;
	i = 0;
	// 2. Si se pasa de 2 argumentos, mandar msg de error
	if (argc > 2)
	{
		fprintf(stderr, "Error: %s archivo\n", argv[0]);
		return (1);
	}
	// 3. Hay 2 argumentos
	file_name = argv[1];

	// 4. abrir el archivo
	fd = open(file_name, O_RDONLY);

	// 5. Verficar que la apertura es exitosa
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	
	// 6. llamado a la funcion
	if (i < 4)
	{
		str_to_print = get_next_line(fd);
		printf("File descriptor: %i\n %s\n", fd, str_to_print);
		i++;
	}
	close(fd);
	return (0);
} */