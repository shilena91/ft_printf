/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:58:24 by hopham            #+#    #+#             */
/*   Updated: 2019/11/28 11:01:07 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int	number = 20;
	//char *pointer = "little";

	//printf("Here is a number %2d and a %s word.", number, pointer);
	printf("%+d \n", number);
	printf("%-10d \n", number);
    printf("%-#10x \n", number);  
    printf("%#X \n", number);
	printf("% 5d\n", number);
	return(0);
}
