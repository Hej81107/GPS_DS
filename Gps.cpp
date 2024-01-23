#include "Grid.h"

#include <iostream>

int main()
{
	Grid x;
	x.InitGrid();
	x.PopulateGrid();
	x.FindProxCost();
	x.Greed();
	

	x.PrintGrid();

	

}