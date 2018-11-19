///////////////////////////////////////////////////////////
//  TransformedObjet3D.cpp
//  Implementation of the Class TransformedObjet3D
//  Created on:      26-oct.-2018 17:42:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TransformedObjet3D.h"

TransformedObjet3D::TransformedObjet3D(const PrimitiveAbs & obj3d, const Point3D & translat, float scal)
	: m_objet3d(obj3d.clone()), m_translation(translat), m_scale(scal)
{
}

TransformedObjet3D::TransformedObjet3D(const TransformedObjet3D & mdd)
	: m_objet3d(mdd.m_objet3d->clone()), m_scale(mdd.m_scale), m_translation(mdd.m_translation)
{
}

TransformedObjet3D::~TransformedObjet3D(){

}

void TransformedObjet3D::addChild(const Objet3DAbs& obj3d){
	// Deleguer a l'objet decore la tache d'ajouter un enfant
}


Objet3DIterator TransformedObjet3D::begin()
{
	// A Completer...
	Objet3DContainer cont;
	return Objet3DIterator(cont.begin());
}


Objet3DIterator_const TransformedObjet3D::cbegin() const {

	// A Completer...
	Objet3DContainer cont;
	return Objet3DIterator_const(cont.cbegin());
}


Objet3DIterator_const TransformedObjet3D::cend() const {

	// A Completer...
	Objet3DContainer cont;
	return Objet3DIterator_const(cont.cend());
}


Objet3DAbs* TransformedObjet3D::clone() const 
{
	// A Completer...
	Objet3DAbs *newObj = new TransformedObjet3D(*this);
	return newObj;
}


Objet3DIterator TransformedObjet3D::end()
{
	// A Completer...
	Objet3DContainer cont;
	return Objet3DIterator(cont.end());
}


Point3D TransformedObjet3D::getCenter() const 
{
	// A Completer...
	return this->m_objet3d->getCenter() + this->m_translation;
}


size_t TransformedObjet3D::getNbParameters() const 
{
	// A Completer...
	return this->m_objet3d->getNbParameters();
}


PrimitiveParams TransformedObjet3D::getParameters() const 
{
	// A Completer...
	Point3D pt = this->m_objet3d->getCenter();
	pt *= this->m_scale;
	std::vector<float> vecParam = this->m_objet3d->getParameters();
	for (int i = 0; i < vecParam.size(); i++) {
		vecParam[i] *= this->m_scale;
	}
	return vecParam;
}


void TransformedObjet3D::moveCenter(const Point3D& delta){
	// A Completer...
	this->m_objet3d->moveCenter(delta);
}


void TransformedObjet3D::removeChild(Objet3DIterator_const obj3dIt)
{
	// Deleguer a l'objet decore la tache d'eliminer un enfant
	// A Completer...
}


void TransformedObjet3D::setCenter(const Point3D& center){
	// A Completer...
	this->m_objet3d->setCenter(center);
}


void TransformedObjet3D::setParameter(size_t pIndex, float pValue)
{
	// A Completer...
	return this->m_objet3d->setParameter(pIndex, pValue);
}

float TransformedObjet3D::getScale() const
{
	// A Completer...
	return this->m_scale;
}

void TransformedObjet3D::setScale(float scal)
{
	// A Completer...
	this->m_scale = scal;
}

Point3D TransformedObjet3D::getTranslation() const
{
	// A Completer...
	return this->m_translation;
}

void TransformedObjet3D::setTranslation(const Point3D & translat)
{
	// A Completer...
	this->m_translation = translat;
}


std::ostream& TransformedObjet3D::toStream(std::ostream& o) const 
{
	o << "Objet Transforme: OBJET={ " << *m_objet3d 
	  << " }, Translation = " << m_translation << ", Scale = " << m_scale << std::endl;

	return  o;
}