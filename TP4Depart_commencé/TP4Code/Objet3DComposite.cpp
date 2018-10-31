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
	return nullptr;
}

void Objet3DComposite::addChild(const Objet3DAbs& obj3d)
{
	// A Completer...
	std::unique_ptr<Objet3DAbs> newPtr  = std::unique_ptr<Objet3DAbs>(obj3d.clone());

	this->m_objetContainer.push_back(newPtr);
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
	this->m_objetContainer.erase(obj3dIt);
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

	auto it = this->m_objetContainer.begin;
	Point3D pt = it.getCenter();
	float sommeX = 0.0;
	float sommeY = 0.0;
	float sommeZ = 0.0;
	int nbObjets = 1;
	sommeX += pt.x;
	sommeY += pt.y;
	sommeZ += pt.z;

	while(it.next() != nullptr) {
		pt = it.getCenter();
		sommeX += pt.x;
		sommeY += pt.y;
		sommeZ += pt.z;
		nbObjets++;
	}

	return Point3D(sommeX / nbObjets, sommeY / nbObjets, sommeZ / nbObjets);
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
