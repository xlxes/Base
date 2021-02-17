#include "pch.h"
#include "sto.h"

sto::sto(double lbs)
{
	stone = int(lbs) / lbs_per_stn;
	pds_left = int(lbs) % lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

sto::sto(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * lbs_per_stn + pds_left;
}

sto::sto()
{
	pounds = pds_left = stone = 0;
}

sto::~sto()
{
}

bool sto::operator<(const sto& st)const
{
	if (pounds < st.pounds)
		return true;
	else
		return false;
}

bool sto::operator<=(const sto& st)const
{
	if (pounds <= st.pounds)
		return true;
	else
		return false;
}

bool sto::operator>(const sto& st)const
{
	if (pounds > st.pounds)
		return true;
	else
		return false;
}

bool sto::operator>=(const sto& st)const
{
	if (pounds >= st.pounds)
		return true;
	else
		return false;
}

bool sto::operator==(const sto& st)const
{
	if (pounds == st.pounds)
		return true;
	else
		return false;
}

bool sto::operator!=(const sto& st)const
{
	if (pounds != st.pounds)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const sto& st)
{
	os << st.pounds << "pounds.\n";
	return os;
}