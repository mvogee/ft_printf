/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:26:19 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/05 20:26:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int main(void)
{
	write(1, "what happens when i try to write an escape character \% \n", 55);
	printf("%*s\n", 20, "hi im a string");
	printf("%20s\n ","hi im a string that is hopefully longer than 20 chars");
	printf("hi%%\n");
	printf("hi %50.5s\n", "this is the string");
	return (0);
}