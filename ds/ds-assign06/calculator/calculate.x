struct inputs{
	float num1;
	float num2;
	char operator;
};
 
program CALCULATE_PROG{
	version CALCULATE_VER{
		float CALCULATE(inputs)=1;
	}=1;
}=0x2fffffff;
