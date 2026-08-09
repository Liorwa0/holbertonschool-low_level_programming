#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * create_session - Creates and initializes a new session
 * @id: Session identifier
 * @data: Pointer to data string
 *
 * Return: Pointer to new session, or NULL on failure
 */
session_t *create_session(int id, const char *data)
{
	session_t *session;

	session = malloc(sizeof(session_t));
	if (session == NULL)
		return (NULL);

	session->id = id;
	if (data != NULL)
	{
		session->data = strdup(data);
		if (session->data == NULL)
		{
			free(session);
			return (NULL);
		}
	}
	else
	{
		session->data = NULL;
	}

	return (session);
}

/**
 * update_session_data - Safely updates data for an existing session
 * @session: Pointer to session
 * @new_data: Pointer to new data string
 *
 * Return: 1 on success, 0 on failure
 */
int update_session_data(session_t *session, const char *new_data)
{
	char *temp;

	if (session == NULL)
		return (0);

	if (new_data == NULL)
	{
		free(session->data);
		session->data = NULL;
		return (1);
	}

	temp = strdup(new_data);
	if (temp == NULL)
		return (0);

	free(session->data);
	session->data = temp;

	return (1);
}

/**
 * free_session - Safely frees a session and its internal data
 * @session: Pointer to session to free
 */
void free_session(session_t *session)
{
	if (session == NULL)
		return;

	if (session->data != NULL)
	{
		free(session->data);
		session->data = NULL;
	}

	free(session);
}
