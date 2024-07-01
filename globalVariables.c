/**
 * ***************************************************************************************
 * Este arquivo contém as variáveis globais usadas neste programa evms.(This file contains all the global functions used in this program evms)
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
 * Variáveis globais
 * (Global Variables)
 ******************************************************************************************
 */
// Para Sistema (For System)
int exitFlag = FALSE;
int session = FALSE;
int is_authenticated = FALSE;
int is_loggedOut = FALSE;
int loginCounter = 0;
char *currentUser_Name = NULL;
char *currentUser_UserID = NULL;
char *currentDateTime;

// Para Administrador (For Administrator)
int is_loginAdmin = FALSE;
int currentAdmin_Level;

// Para Eleitor (For Voter)
int is_loginVoter = FALSE;

// Para Candidato (For Candidate)
int is_loginCandidate = FALSE;
