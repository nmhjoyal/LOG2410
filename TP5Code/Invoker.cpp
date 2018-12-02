///////////////////////////////////////////////////////////
//  Invoker.cpp
//  Implementation of the Class Invoker
//  Created on:      08-nov.-2018 21:05:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <iostream>

#include "Invoker.h"


Invoker::Invoker()
{
}

Invoker::~Invoker()
{
}

void Invoker::execute(CmdPtr & cmd)
{
	// A COMPLETER:
	//		- Executer la commande
	//		- Stocker le pointeur dans la liste des commandes faites

	cmd.get()->execute();
	this->m_cmdDone.push_back(cmd);
}

void Invoker::undo()
{
	// A COMPLETER:
	//		- Verifier que la liste des commandes faites n'est pas vide
	//		- Si elle n'est pas vide:
	//			- Recuperer la derniere commande faite
	//			- Annuler la commande
	//			- Retirer la derniere commande de la liste des commandes faites
	//			- Ajouter la commande a la liste des commandes defaites
	if (!this->m_cmdDone.empty()) {
		CmdPtr oldCmd = this->m_cmdDone.back();
		oldCmd.get()->cancel();
		this->m_cmdDone.pop_back();
		this->m_cmdUndone.push_back(oldCmd);
	}

}

void Invoker::redo()
{
	// A COMPLETER:
	//		- Verifier que la liste des commandes defaites n'est pas vide
	//		- Si elle n'est pas vide:
	//			- Recuperer la derniere commande defaite
	//			- Executer la commande
	//			- Retirer la derniere commande de la liste des commandes defaites
	//			- Ajouter la commande a la liste des commandes faites
	if (!this->m_cmdUndone.empty()) {
		CmdPtr oldCmd = this->m_cmdUndone.back();
		oldCmd.get()->execute();
		this->m_cmdUndone.pop_back();
		this->m_cmdDone.push_back(oldCmd);
	}
}