///////////////////////////////////////////////////////////
//  Sphere.cpp
//  Implementation of the Class Sphere
//  Created on:      25-oct.-2018 20:47:54
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Sphere.h"


Sphere::Sphere(const Point3D& pt, float r)
: PrimitiveAbs(pt)	// A Completer...
{
	if (r < 0.0)
		throw std::range_error("Invalid radius value for sphere. Must be larger than 0");

	this->m_center = pt;
	this->m_radius = r;
}

Sphere::~Sphere(){
}

Sphere * Sphere::clone() const
{
	// A Completer...
	return new Sphere(this->m_center, this->m_radius);
}

size_t Sphere::getNbParameters() const {

	// A Completer...
	return 1;
}

PrimitiveParams Sphere::getParameters() const {

	// A Completer...
	std::vector<float> vecParam;
	vecParam.push_back(this->m_radius);
	return vecParam;
}

void Sphere::setParameter(size_t pIndex, float pValue){
	if (pIndex != 0)
		throw std::range_error("Invalid parameter index for sphere. Must be 0");

	if (pValue < 0.0)
		throw std::range_error("Invalid radius value for sphere. Must be larger than 0");

	// A Completer...
	std::vector<float> vecParam = this->getParameters();
	vecParam[pIndex] = pValue;
}

std::ostream & Sphere::toStream(std::ostream & o) const
{
	return o << "Sphere:    center = " << m_center << "; r = " << m_radius << ";";
}
