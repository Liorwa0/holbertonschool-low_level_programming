#include <stdio.h>
#include <stdlib.h>
#include "store.h"

/**
 * create_store - Allocates and initializes a new store
 *
 * Return: Pointer to new store, or NULL on failure
 */
store_t *create_store(void)
{
	store_t *store;

	store = malloc(sizeof(store_t));
	if (store == NULL)
		return (NULL);

	store->head = NULL;
	return (store);
}

/**
 * store_insert - Inserts a session into the store
 * @store: Pointer to store
 * @session: Pointer to session to insert
 *
 * Return: 1 on success, 0 on failure
 */
int store_insert(store_t *store, session_t *session)
{
	node_t *new_node, *curr;

	if (store == NULL || session == NULL)
		return (0);

	curr = store->head;
	while (curr != NULL)
	{
		if (curr->session != NULL && curr->session->id == session->id)
			return (0);
		curr = curr->next;
	}

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (0);

	new_node->session = session;
	new_node->next = store->head;
	store->head = new_node;

	return (1);
}

/**
 * store_get - Finds a session by ID
 * @store: Pointer to store
 * @id: Session ID to search for
 *
 * Return: Pointer to found session, or NULL if not found
 */
session_t *store_get(store_t *store, int id)
{
	node_t *curr;

	if (store == NULL)
		return (NULL);

	curr = store->head;
	while (curr != NULL)
	{
		if (curr->session != NULL && curr->session->id == id)
			return (curr->session);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * store_delete - Deletes a session from the store by ID and frees memory
 * @store: Pointer to store
 * @id: Session ID to delete
 *
 * Return: 1 on success, 0 if not found
 */
int store_delete(store_t *store, int id)
{
	node_t *curr, *prev = NULL;

	if (store == NULL)
		return (0);

	curr = store->head;
	while (curr != NULL)
	{
		if (curr->session != NULL && curr->session->id == id)
		{
			if (prev == NULL)
				store->head = curr->next;
			else
				prev->next = curr->next;

			free_session(curr->session);
			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}

	return (0);
}

/**
 * store_clear - Clears all sessions from the store
 * @store: Pointer to store
 */
void store_clear(store_t *store)
{
	node_t *curr, *next_node;

	if (store == NULL)
		return;

	curr = store->head;
	while (curr != NULL)
	{
		next_node = curr->next;
		free_session(curr->session);
		free(curr);
		curr = next_node;
	}

	store->head = NULL;
}

/**
 * free_store - Frees the entire store and its contents
 * @store: Pointer to store to free
 */
void free_store(store_t *store)
{
	if (store == NULL)
		return;

	store_clear(store);
	free(store);
}
