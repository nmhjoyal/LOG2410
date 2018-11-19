///////////////////////////////////////////////////////////
//  Cube.cpp
//  Implementation of the Class Cube
//  Created on:      25-oct.-2018 20:47:57
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Torus.h"


Torus::Torus(const Point3D& pt, float r1, float r2) 
	:PrimitiveAbs(pt)
{
	if (r1 < 0.0 || r1 < 0.0)
		throw std::range_error("Invalid dimension value for torus. Must be larger than 0");

	this->m_center = pt;
	this->m_dimensions[0] = r1;
	this->m_dimensions[1] = r2;
}

Torus::~Torus() {
}

Torus* Torus::clone() const {
	return new Torus(this->m_center, this->m_dimensions[0], this->m_dimensions[1]);
}

size_t Torus::getNbParameters() const {
	return 2;
}

PrimitiveParams Torus::getParameters() const {
	std::vector<float> vecParam;
	vecParam.push_back(this->m_dimensions[0]);
	vecParam.push_back(this->m_dimensions[1]);
	return vecParam;
}

void Torus::setParameter(size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for torus. Must be between 0 and 1");

	if (pValue<0.0)
		throw std::range_error("Invalid dimension value for torus. Must be larger than 0");

	std::vector<float> vecParam = this->getParameters();
	vecParam[pIndex] = pValue;
}

std::ostream& Torus::toStream(std::ostream& o) const {
	return o << "Torus:      center = " << m_center
		<< "; r1 = " << m_dimensions[0]
		<< "; r2 = " << m_dimensions[1]
		<< ";";
}
