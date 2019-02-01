/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:02:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 18:40:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	long a = 0;
	ft_printf("J'ai %i %s et %c yeux et 0.1%% de capacite cerebrale % \n", 4, "dents", '2');
	printf("J'ai %p\n", &a);
	return (0);
}
