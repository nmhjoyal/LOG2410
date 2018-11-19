
#define EA_8099F38C_C8A3_47d0_948F_F38A0B83FFB2__INCLUDED_

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float r1, float r2);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_dimensions[2];
};


