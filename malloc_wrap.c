/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:09:12 by okraus            #+#    #+#             */
/*   Updated: 2024/10/17 09:41:09 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Link-time interposition of malloc and free using the static
 * linker's (ld) "--wrap symbol" flag.
 * 
 * Compile the executable using "-Wl,--wrap,malloc -Wl,--wrap,free".
 * This tells the linker to resolve references to malloc as
 * __wrap_malloc, free as __wrap_free, __real_malloc as malloc, and
 * __real_free as free.
 */

void	*__real_malloc(size_t size);
void	__real_free(void *ptr);

/* 
 * __wrap_malloc - malloc wrapper function 
 */
void	*__wrap_malloc(size_t size)
{
	void *ptr;

	if (rand() % 42)
		ptr = __real_malloc(size);
	else
		ptr = NULL;
	dprintf(2, "malloc(%zu) = %p\n", size, ptr);
	return ptr;
}

/* 
 * __wrap_free - free wrapper function 
 */
void	__wrap_free(void *ptr)
{
	__real_free(ptr);
	dprintf(2, "free(%p)\n", ptr);
}
