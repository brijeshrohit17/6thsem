class base
{
public:
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
private:
	string basename ;
};
class derived : public base
{
public:
	void print(ostream &os)
	{
		print(os);
		os << " " << i;
	}
private:
	int i;
};

//So the new code would look like:

class base
{
public:
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
private:
	string basename ;
};
class derived : public base
{
public:
	void print(ostream &os)
	{
		base::print(os);
		os << " " << i;
	}
private:
	int i;
};