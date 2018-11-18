///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"


Objet3DComposite::Objet3DComposite(){

}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	// A Completer...
	this->m_objetContainer = mdd.m_objetContainer;

}

Objet3DComposite::~Objet3DComposite(){
}

Objet3DComposite * Objet3DComposite::clone() const
{
	const Objet3DContainer newCont(this->m_objetContainer);
	Objet3DComposite *newObj = new Objet3DComposite();
	newObj->m_objetContainer = newCont;
	return newObj;
}

void Objet3DComposite::addChild(const Objet3DAbs& obj3d)
{
	// A Completer...
	Objet3DPtr newPtr(obj3d.clone());
	this->m_objetContainer.push_back(std::move(newPtr));
}

Objet3DIterator Objet3DComposite::begin(){

	// A Completer...
	return Objet3DIterator(this->m_objetContainer.begin());
}

Objet3DIterator_const Objet3DComposite::cbegin() const {

	// A Completer...
	return Objet3DIterator_const(this->m_objetContainer.cbegin());
}

Objet3DIterator_const Objet3DComposite::cend() const {

	// A Completer...
	return Objet3DIterator_const(this->m_objetContainer.cend());
}

Objet3DIterator Objet3DComposite::end(){

	// A Completer...
	return Objet3DIterator(this->m_objetContainer.end());
}

Point3D Objet3DComposite::getCenter() const {
	
	// A Completer...
	return this->computeCenter();
}

size_t Objet3DComposite::getNbParameters() const 
{
	return 0;
}

PrimitiveParams Objet3DComposite::getParameters() const {

	return  PrimitiveParams();
}

void Objet3DComposite::removeChild(Objet3DIterator_const obj3dIt)
{
	// A Completer...
	int pos = 0;
	while (this->m_objetContainer.at(pos) != nullptr) {
		if (&this->m_objetContainer.at(pos) == obj3dIt._Ptr) {
			this->m_objetContainer.erase(this->m_objetContainer.begin() + pos);
			break;
		}
		pos++;
	}
	
}

void Objet3DComposite::moveCenter(const Point3D & delta)
{
	// A Completer...
	this->getCenter() += delta;
}

void Objet3DComposite::setCenter(const Point3D& center){
	// A Completer...
	this->getCenter() = center;
}

void Objet3DComposite::setParameter(size_t pIndex, float pValue){
	PrimitiveParams params = this->getParameters();

	params[pIndex] = pValue;
}

Point3D Objet3DComposite::computeCenter() const
{
	// Calcul la moyenne des centres de tous les enfants
	// S'il n'y a pas d'enfant, initialise a (0,0,0)

	// A Completer...
	if (sizeof(this->m_objetContainer) == 0)
		return Point3D(0, 0, 0);

	Objet3DIterator_const it = this->cbegin();
	Point3D pt = it->getCenter();
	Point3D ptSomme = Point3D(0, 0, 0);
	ptSomme += pt;
	float nbObjets = 1;

	while(&it++ != nullptr) {
		pt = it->getCenter();
		ptSomme += pt;
		nbObjets++;
	}

	ptSomme /= nbObjets;
	return ptSomme;
}

// Variable statique permettant de stocker le niveau d'indentation
size_t Objet3DComposite::outputIndent = 0;

std::ostream& indentation(std::ostream& o, size_t indentLevel)
{
	for (auto iindent = 0; iindent < indentLevel; ++iindent)
		o << "\t";
	return o;
}

std::ostream & Objet3DComposite::toStream(std::ostream & o) const
{
	o << "Composite: center = " << computeCenter() << ": {" << std::endl;
	++outputIndent;
	for (auto it = cbegin(); it != cend(); ++it)
		indentation(o, outputIndent) << *it << std::endl;
	--outputIndent;
	indentation(o, outputIndent) << "}";

	return o;
}
