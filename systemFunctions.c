/**
 * ***************************************************************************************
 * Este arquivo contém todas as funções de sistema usadas neste programa evms.(This file contains all the system functions used in this program evms)
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
 * Função para definir localidade
 * (Function to set location)
 ******************************************************************************************
 */
int setLocation()
{
	if (setlocale(LC_ALL, "") == NULL)
	{
		printf("Local não suportado\n");
		sleep(MAX_SLEEP);
	}
	return 1;
}

/**
 * ****************************************************************************************
 * Função para inicializar o sistema (Initialize System)
 * (Function to initialize the system)
 ******************************************************************************************
 */
void initSystem(SystemData *sysData)
{
	sysData->status = NULL;
	sysData->statusCount = 0;
	sysData->statusCapacity = 0;

	sysData->languages = NULL;
	sysData->languageCount = 0;
	sysData->languageCapacity = 0;

	sysData->apps = NULL;
	sysData->appCount = 0;
	sysData->appCapacity = 0;

	sysData->users = NULL;
	sysData->userCount = 0;
	sysData->userCapacity = 0;

	sysData->admins = NULL;
	sysData->adminCount = 0;
	sysData->adminCapacity = 0;

	sysData->histories = NULL;
	sysData->historyCount = 0;
	sysData->historyCapacity = 0;

	firstTimeSetup(sysData);
}

/**
 * ****************************************************************************************
 * Este função configura o sistema para o primeiro vez. Ele cria o arquivo de configuração (Configure the system for the first time. It creates the configuration file)
 */
void firstTimeSetup(SystemData *sysData)
{
	// Inicialização de arquivos (Initialization of files)
	FILE *statusFile = NULL;
	FILE *languageFile = NULL;
	FILE *appFile = NULL;
	FILE *userFile = NULL;
	FILE *adminFile = NULL;
	FILE *historyFile = NULL;

	// Leitura de arquivos (Opening files)
	statusFile = fopen("status.txt", "r");
	languageFile = fopen("language.txt", "r");
	appFile = fopen("app.txt", "r");
	userFile = fopen("user.txt", "r");
	adminFile = fopen("admin.txt", "r");
	historyFile = fopen("history.txt", "r");

	if (statusFile == NULL || languageFile == NULL || appFile == NULL || userFile == NULL || adminFile == NULL || historyFile == NULL)
	{
	
		// Criação de arquivos (Creation of files)
		statusFile = fopen("status.txt", "w");
		languageFile = fopen("language.txt", "w");
		appFile = fopen("app.txt", "w");
		userFile = fopen("user.txt", "w");
		adminFile = fopen("admin.txt", "w");
		historyFile = fopen("history.txt", "w");
	}
}

/**
 * ****************************************************************************************
 * Este função gera um número aleatório
 * (This function generates a random number)
 * *****************************************************************************************
 */

int getRandomNumber(int min, int max)
{
	srand(time(NULL));
	int rand_num = rand() % (max - min + 1) + min;
	return rand_num;
}

/**
 * ****************************************************************************************
 * Esta função limpará a tela
 * (This function will Clear screen)
 */

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif // _WIN32
}

/**
 * ****************************************************************************************
 * Este função exibirá o banner do programma
 * (This function will display the banner of the program)
 * ****************************************************************************************
 */

// Este função imprime a data atual (Print current date)
char *displayDate()
{
	time_t now = time(NULL); // Obtenção da data atual

	struct tm *local = localtime(&now); // Conversão da data para o formato local (Conversion of date to local format)

	// Alocação de memória para armazenar data e a hora (Allocate memory for date and time strings)
	char *dateTimeStr = (char *)malloc(sizeof(char) * MAX_NAME_LENGTH);

	// Formatação da data e hora (Formatting of date and time)
	strftime(dateTimeStr, sizeof(dateTimeStr), "%d/%m/%Y %H:%M:%S", local);

	return dateTimeStr;
}
void displayBanner(SystemData *sysData)
{
	clearScreen();
	printf("\n\n");
	displayDate();
	currentDateTime = displayDate();
	printf("\t\t*********************************************************************************************************************\t\t\n");
	printf("\t\t\t\t\t\t\t\t\t\t%s\n", currentDateTime);
	for (int i = 0; i < sysData->appCount; i++)
	{
		for (int j = 0; j < sysData->languageCount; j++)
		{
			if (sysData->apps[i].preferredLanguage_ID == sysData->languages[j].id)
			{
				int foundLanguage = sysData->languages[j].id;
				if (foundLanguage == ENGLISH_LANGUAGE_ID)
				{
					printf("\t\t\t\t\t\t\t\t\t\tVersion: %.2f\n", sysData->apps[i].version);
					for (int k = 0; k < sysData->statusCount; k++)
					{
						if (sysData->apps[i].statusCode == sysData->status[k].code)
						{
							printf("\t\t\t\t\t\t\t\t\t\tStatus: %s\n", sysData->status[k].status);
							break;
						}
					}
					printf("\t\t\t\t\t\t\t\t\t\tPreferred Language: %s\n", sysData->languages[j].name);
					printf("\t\t*********************************************************************************************************************\t\t\n");

					if (is_authenticated)
					{
						printf("\n\n");
						printf("\t\t\t\t\t\t\t\t\t\t\t\t\tHello %s,\t\t\t\t\t\t\t\t\n\n", currentUser_Name);
					}
				}
				if (foundLanguage == PORTUGUESE_LANGUAGE_ID)
				{

					printf("\t\t\t\t\t\t\t\t\t\tVersão: %.2f\n", sysData->apps[i].version);
					for (int k = 0; k < sysData->statusCount; k++)
					{
						if (sysData->apps[i].statusCode == sysData->status[k].code)
						{
							printf("\t\t\t\t\t\t\t\t\t\tEstado: %s\n", sysData->status[k].status);
							break;
						}
					}
					printf("\t\t\t\t\t\t\t\t\t\tLíngua preferida: %s\n", sysData->languages[j].name);
					printf("\t\t*********************************************************************************************************************\t\t\n");

					if (is_authenticated)
					{
						printf("\t\t\t\t\t\t\t\t\t\t\t\t\tOla %s,\t\t\t\t\t\t\t\t\n\n", currentUser_Name);
					}
				}
				break;
			}
			break;
		}
		break;
	}
}