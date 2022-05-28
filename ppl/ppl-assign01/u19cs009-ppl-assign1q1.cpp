#include<bits/stdc++.h>
using namespace std;
class DB;
class DM {
	float meter;
	float centimeter;
	friend DM addinDM(DM, DB);
	friend DB addinDB(DB, DM);
public:
	DM(float m = 0, float cm = 0)
	{
		if (cm >= 100)
		{
			m += floor(cm / 100);
			cm /= 100;
			cm -= floor(cm);
			cm *= 100;
		}
		this->meter = m;
		this->centimeter = cm;
	}
	float inMeter()
	{
		return this->meter;
	}
	float inCM()
	{
		return this->centimeter;
	}
	void setMeter(float val)
	{
		this->meter = val;
	}
	void setCentimeter(float val)
	{
		this->centimeter = val;
	}
};

class DB {
	float feet;
	float inch;
	friend DM addinDM(DM, DB);
	friend DB addinDB(DB, DM);
public:
	DB(float ft = 0, float in = 0)
	{
		if (in >= 12)
		{
			ft += floor(in / 12);
			in /= 12;
			in -= floor(in);
			in *= 12;
		}
		this->feet = ft;
		this->inch = in;
	}
	float inFeet()
	{
		return this->feet;
	}
	float inInch()
	{
		return this->inch;
	}
	void setFeet(float val)
	{
		this->feet = val;
	}
	void setInch(float val)
	{
		this->inch = val;
	}
};

DM addinDM(DM obj1, DB obj2)
{
	float x , y;
	//conversion to metric unit
	y = obj2.inch * 2.54;
	y += obj2.feet * 30.48 + obj1.centimeter + (obj1.meter * 100);
	x = floor(y / 100);
	y = (y / 100) - floor(y / 100);
	y *= 100;
	//creating an object in mettric unit after addition
	DM temp(x, y);
	return temp;
}

DB addinDB(DB obj1, DM obj2)
{
	float x , y;
	//conversion to imperial unit
	y = obj2.centimeter * 0.393701;
	y += obj2.meter * 39.3701 + obj1.inch + (obj1.feet * 12);
	x = floor(y / 12);
	y = (y / 12) - floor(y / 12);
	y *= 12;
	//creating an object in imperial unit after addition
	DB temp(x, y);
	return temp;
}

int main()
{
	float m = 0, cm = 0, f = 0, i = 0;
	cout << "Please enter Metric length : ";
	cin >> m >> cm;

	//Metric length X
	cout << "Length X in Metric[Input] and Imperial[Conversion with sum].\n";
	     cout << "Inputs for X are    : " << m << " and " << cm << endl;
	DM metriclen(m , cm);
	DB temp1;
	cout << "Metric Length [X]   : " << metriclen.inMeter() << " m and " << metriclen.inCM() << " cm" << endl;
	DB metricinimperial = addinDB(temp1, metriclen);
	cout << "Imperial Length [X] : " << metricinimperial.inFeet() << " ft and " << metricinimperial.inInch() << " inch" << endl;

	cout << "\nPlease enter Imperial length : ";
	cin >> f >> i;
	//Imperial length
	cout << "\nLength Y in Imperial[Input] and Metric[Conversion with sum].\n";
	     cout << "Inputs for Y are    : " << f << " and " << i << endl;
	DB imperiallen(f, i);
	DM temp2;
	cout << "Imperial Length [Y] : " << imperiallen.inFeet() << " ft and " << imperiallen.inInch() << " inch" << endl;
	DM imperialinmetric = addinDM(temp2, imperiallen);
	cout << "Metric Length [Y]   : " << imperialinmetric.inMeter() << " m and " << imperialinmetric.inCM() << " cm" << endl;

	DM metricsum = addinDM(metriclen, imperiallen);
	DB imperialsum = addinDB(imperiallen, metriclen);
	cout << "\nSum [X + Y] in Metric unit   : " << metricsum.inMeter() << " m and " << metricsum.inCM() << " cm" << endl;
	cout << "Sum [X + Y] in Imperial unit : " << imperialsum.inFeet() << " ft and " << imperialsum.inInch() << " inch" << endl;
	return 0;
}
