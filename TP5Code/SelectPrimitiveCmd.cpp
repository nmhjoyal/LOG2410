///////////////////////////////////////////////////////////
//  SelectPrimitiveCmd.cpp
//  Implementation of the Class SelectPrimitiveCmd
//  Created on:      08-nov.-2018 21:05:02
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "SelectPrimitiveCmd.h"
#include "VisitorPrimitiveSelector.h"

SelectPrimitiveCmd::SelectPrimitiveCmd(PRIMITIVE_TYPE typ, Object3DAbs & obj3d)
	: m_type(typ), m_obj3d(obj3d)
{
}

SelectPrimitiveCmd::~SelectPrimitiveCmd()
{
}

void SelectPrimitiveCmd::cancel()
{
	// A COMPLETER: Vider le conteneur local a la commande d'objets selectionnes
	this->m_selectObjContainer.clear();
}


void SelectPrimitiveCmd::execute()
{
	// A COMPLETER:
	//		- Construire un visiteur de selection
	//		- Appliquer le visiteur a l'objet 3d
	//		- Recuperer les objets selectionnes dans le conteneur local de la commande
	VisitorPrimitiveSelector selector = VisitorPrimitiveSelector(this->m_type);
	this->m_obj3d.accept(selector);
	selector.getSelectObjects(this->m_selectObjContainer);
}

void SelectPrimitiveCmd::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	// A COMPLETER:
	// Transferer les objets selectionnes du conteneur local a la commande
	// vers le conteneur fourni en argument
	while(!this->m_selectObjContainer.empty()){
		auto obj = this->m_selectObjContainer.back();
		this->m_selectObjContainer.pop_back();
		objContainer.push_back(obj);
	}
}
