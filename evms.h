/**
 * ***************************************************************************************
 * Este arquivo é o arquivo de cabeçalho para evms.(This file is the header file of evms)
 * @author: ODILI CHINEDUM CHRISTIAN
 * @version: 1.0
 * @copyright: Copyright (c) ODILI CHINEDUM CHRISTIAN
 * @license: Apache 2.0
 * ***************************************************************************************
 */

/**
 *****************************************************************************************
 * Definição de cabeçalho com diretivas condicionais que evitam que o conteúdo do arquivo
 * seja incluído mais de uma vez em uma única compilação
 * (Header definition with conditional directives which prevent the contents of the file
 * from being included more than once in a single compilation)
 * *****************************************************************************************
 */
#ifndef EVMS_H
#define EVMS_H

/**
 ******************************************************************************************
 * Inclusão de bibliotecas
 * ( Include libraries)
 ******************************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>

/**
 ******************************************************************************************
 * Definição de macros
 * (Definition of macros)
 ******************************************************************************************
 */
#define MIN_SLEEP 1
#define MIN_SLEEP 3
#define MAX_SLEEP 5
#define MIN_RANDOM_NUMBER 10000
#define MAX_RANDOM_NUMBER 99999
#define MAX_TRIAL_TIMES 5
#define MAX_NAME_LENGTH 250
#define TRUE 1
#define FALSE 0
#define STATUS_SUCCESS 0
#define INITIAL_CANDIDATE_VOTE_VALUE 0
#define FIRST_LEVEL_MAX 4
#define SECOND_LEVEL_MAX 8
#define THIRD_LEVEL_MAX 12
#define SUPERUSER_LEVEL_MAX 15
#define ENGLISH_LANGUAGE_ID 1
#define PORTUGUESE_LANGUAGE_ID 2

/**
 ******************************************************************************************
 * Definição de variáveis globais
 * (Definition of global variables)
 ******************************************************************************************
 */
// Para sistema (For system)
extern int exitFlag, session, is_authenticated, is_loggedOut, loginCounter;
extern char *currentUser_Name, *currentUser_UserID, currentDateTime;

// Para administrador (For Administrator)
extern int is_loginAdmin, currentAdmin_Level;

// Pare Eleitor (For Voter)
extern int is_loginVoter;

// Pare Candidato (For Candidate)
extern int is_loginCandidate;

/**
 ******************************************************************************************
 * Definição de estruturas
 * (Definition of structures)
 ******************************************************************************************
 */
// Estrutura de status (Status Structure)
typedef struct
{
	int code;
	char *status;
} Status;

// Estrutura de Linguagem (Language Structure)
typedef struct
{
	int id;
	char *name;
} Language;

// Application Data Structure
typedef struct
{
	int id;
	char *name;
	char *originalName;
	char *dateInstalled;
	char *owner;
	char *copyRight;
	float version;
	int preferredLanguage_ID;
	int statusCode;
} App;

// Toda a estrutura do usuário (All User structure)
typedef struct
{
	int id;
	char *name;
	char *user_id;
	char *password;
	char *dateCreated;
	char *lastUpdated;
	char *complaint;
	int hasVoted;
	int age;
	int preferredLanguage_ID;
	int statusCode;
} User;

// Admin Structure
typedef struct
{
	User *users;
	int level;
} Admin;

// Activity History Structure
typedef struct
{
	int id;
	char *user_id;
	char *date;
	char *time;
	char *action;
} History;

// System Structure
typedef struct
{
	Status *status;
	int statusCount;
	int statusCapacity;

	Language *languages;
	int languageCount;
	int languageCapacity;

	App *apps;
	int appCount;
	int appCapacity;

	User *users;
	int userCount;
	int userCapacity;

	Admin *admins;
	int adminCount;
	int adminCapacity;

	History *histories;
	int historyCount;
	int historyCapacity;
} SystemData;

/**
 ******************************************************************************************
 * Protótipos das funções
 * (Prototypes of functions)
 ******************************************************************************************
 */

/*
******************************************************************************************
Inicialização e configuração do sistema (Initialization and configuration of the system)
******************************************************************************************
*/
int setLocation();					  // Defina locação ( Set Location)
void initSystem(SystemData *sysData); // Inicialize o sistema (Initialize System)





/*
*****************************************************************************************
Operações e utilitários
(Operations and utilities)
****************************************************************************************
*/
// Para sistema (For system)
int getRandomNumber(int min, int max);



/*
*****************************************************************************************
Exibição e interação com o usuário
(Display and interaction with the user)
****************************************************************************************
*/

// Para sistema (For system)

// Banner de exibição (Banner of display)
void displayBanner(SystemData *sysData);
//limpa tela (clear screen)
void clearScreen();


// Para administrador (For Administrator)


// Para Eleitor (For Voter)


// Para Candidato (For Candidate)


#endif // EVMS_H