/**
 * ***************************************************************************************
 * Este arquivo contém as funções principais para evms.(This file contains the main functions of evms)
 * @author: ODILI CHINEDUM CHRISTIAN
 * @version: 1.0
 * @copyright: Copyright (c) ODILI CHINEDUM CHRISTIAN
 * @license: Apache 2.0
 * ***************************************************************************************
 */

/**
 * ****************************************************************************************
 * Inclusão de bibliotecas interno
 * ( Include internal header file libraries)
 ******************************************************************************************
 */
#include "evms.h"

/**
 * ****************************************************************************************
 * Este é o ponto de entrada do programa.
 * ( This is the entry point of the program.)
 * *****************************************************************************************
 */
int main()
{
	// Chame configuração especificas do local (Call specific configuration of the local)
	setLocation();

	// Declaração de variável sysData (Declaration of variable sysData)
	SystemData sysData;

	initSystem(&sysData);
	return 0;
}