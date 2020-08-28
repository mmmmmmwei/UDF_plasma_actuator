//written by Lee Ming Wei, School of Aerospace Engineering in Universiti Sains Malaysia
//UDF are written in C and compiled by FLUENT using visual studio
//reference 1: UDF 6.3 User Manual
//reference 2: West, Thomas, and Serhat Hosder. "Numerical investigation of plasma actuator configurations for flow separation control at multiple angles of attack." 6th AIAA Flow Control Conference. 2012.

//INFORMATION
//define plasma as a rectangle source in momentum to simplify the code
//PLEASE do have knowledge in C programming before start coding

//DECLARATION
//NO validation is done!!

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "udf.h" //udf library in C language
DEFINE_SOURCE(plasma_source, c, t, dS, eqn) //define macro
{
	real xc[ND_ND]; //declaration of cell coordinate
	real source, x, y; //declaration of plasma, x-coordinate and y-coordinate

	C_CENTROID(xc, c, t);  //centroid of cell
	x = xc[0]; //x as the 1st array of xc
	y = xc[1]; //y as the 2nd array of xc

	if ((x > 0.048285011) && (y > 0.058866676) && (x < 0.14667337) && (y < 0.11919238)) //define the plasma region
	{
		source = 5.0; //the value of plasma source
		dS[eqn] = 0; //explicit solution
	}
	else
	{
		source = 0;
		dS[eqn] = 0;
	}
	C_UDMI(c, t, 0) = source; //adding effect
	return source;
}
