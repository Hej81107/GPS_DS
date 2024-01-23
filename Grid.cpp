#include "Grid.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include<string>
#include <sstream>
#include <math.h>
#include<algorithm>

using namespace std;
// By: Hayden Juday and Prateek Mukherjee



Tower::Tower() {
	bool select = false;
}


void Grid::Select(int x, int y) {			//select point and everything within a radius of 2
	for (int i = 0; i <= 2; i++) {
			pos[x+i][y].select = true;
			pos[x-i][ y].select = true;
			pos[x][y+i].select = true;
			pos[x][y-i].select = true;
			pos[x-1][y+1].select = true;
			pos[x + 1][y + 1].select = true;
			pos[x - 1][y - 1].select = true;
			pos[x + 1][y - 1].select = true;
			pos[x + i][y+1].select = true;
			pos[x - i][y+1].select = true;
			pos[x+1][y + i].select = true;
			pos[x+1][y - i].select = true;
			pos[x + i][y - 1].select = true;
			pos[x - i][y - 1].select = true;
			pos[x - 1][y + i].select = true;
			pos[x - 1][y - i].select = true;
		
		
	}
}

	Grid:: Grid() {
		
		
	}
	 
	 void Grid::InitGrid() {
		 for (int i = 0; i < 100; i++) {
			 for (int j = 0; j < 100; j++)
			 {
				 pos[i][j].cost = 0;

			 }
		 }
	 }

	 void Grid::PopulateGrid() {
srand(time(0));
for (int x = 3; x < 23; x++) {
	for (int y = 3; y < 23; y++) {
		int R = rand() % (32 - 1 + 1) + 1;							//Generates Upper class. 1/28 chance to place a value on any spot in grid for pos[3-23][3-23]   Comes out to about 10-15 placements.
		if (R == 1) {
			pos[y][x].cost = rand() % (7 - 5 + 1) + 5;		//Random value 5-7
			pos[y][x].ProxCost = pos[y][x].cost;
			pos[y][x].x = x;
			pos[y][x].y = y;
		}
	}
}
for (int x = 5; x < 25; x++) {
	for (int y = 40; y < 70; y++) {
		int R = rand() % (25 - 1 + 1) + 1;							//Generates Upper Middle class.    Comes out to about 15-20 placements.
		if (R == 1) {
			pos[y][x].cost = rand() % (5 - 2 + 1) + 2;		//Random value 2-5
			pos[y][x].ProxCost = pos[y][x].cost;
			pos[y][x].x = x;
			pos[y][x].y = y;
		}
	}
}
for (int x = 50; x < 80; x++) {
	for (int y = 3; y < 23; y++) {
		int R = rand() % (20 - 1 + 1) + 1;							//Generates middle class.    Comes out to about 20-25 placements.
		if (R == 1) {
			pos[y][x].cost = rand() % (2 - 1 + 1) + 1;		//Random value 1-2
			pos[y][x].ProxCost = pos[y][x].cost;
			pos[y][x].x = x;
			pos[y][x].y = y;

		}
	}
}
for (int x = 50; x < 75; x++) {
	for (int y = 50; y < 75; y++) {
		int R = rand() % (15 - 1 + 1) + 1;							//Generates lower class.    Comes out to about 25-30 placements.
		if (R == 1) {
			pos[y][x].cost = 0.1 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (0.5 - 0.1)));		//Random value 0.5-0.1
			pos[y][x].x = x;
			pos[y][x].y = y;
		}
	}
}

	 }
	 void Grid::FindProxCost() {
		 for (int x = 2; x < 100; x++) {
			 for (int y = 2; y < 100; y++) {
				// for (int i = 1; i <= 2; i++) {
					 if (pos[x][y].cost != 0) {
						 for (int i = 1; i <= 2; i++) {
							 //pos[x][y].ProxCost += pos[x][y].cost;
							 pos[x][y].ProxCost += pos[x + i][y].cost;
							 pos[x][y].ProxCost += pos[x - i][y].cost;
							 pos[x][y].ProxCost += pos[x][y + i].cost;
							 pos[x][y].ProxCost += pos[x][y - i].cost;
							 pos[x][y].ProxCost += pos[x + i][y + 1].cost;
							 //pos[x][y].ProxCost += pos[x - 2][y + 1].cost;
							 //pos[x][y].ProxCost += pos[x + 1][y + 2].cost;
							 //pos[x][y].ProxCost += pos[x + 1][y - 2].cost;
							 pos[x][y].ProxCost += pos[x + i][y - 1].cost;
							 //pos[x][y].ProxCost += pos[x - 2][y - 1].cost;
							 pos[x][y].ProxCost += pos[x - 1][y + i].cost;
							 pos[x][y].ProxCost += pos[x - 1][y - i].cost;
						 }
						 //pos[x][y].ProxCost += pos[x][y].cost;
						 pos[x][y].ProxCost += pos[x - 2][y + 1].cost;
						 pos[x][y].ProxCost += pos[x + 1][y + 2].cost;
						 pos[x][y].ProxCost += pos[x + 1][y - 2].cost;
						 pos[x][y].ProxCost += pos[x - 2][y - 1].cost;
					 }
					 // pos[x + i][y].select = true;//(1,0),(2,0)
					  //pos[x - i][y].select = true;//(-1,0),(-2,0)
					  //pos[x][y + i].select = true;//(0,1),(0,2)
					 // pos[x][y - i].select = true;//(0,-1),(0,-2)
					 // pos[x + i][y + 1].select = true;//(1,1),    (2,1)
					 // pos[x - 2][y + 1].select = true;//,  (-2,1)
					 // pos[x + 1][y + 2].select = true;//     (1,2)
					 // pos[x + 1][y - 2].select = true;//,  (1,-2)
					 // pos[x + i][y - 1].select = true;//(1,-1)   ,(2,-1)
					 // pos[x - 2][y - 1].select = true;//,(-2,-1)
					 //pos[x - 1][y + i].select = true;//(-1,1),   (-1,2)
					 // pos[x - 1][y - i].select = true;//(-1,-1),(-1,-2)

				 //}
			 }
		 }

	 }
	 double Grid::Distance(Tower arr[100][100]) {
		 return 0;
	 }


	 void Grid::Greed() {
		 int Mybudget = 15;
		 while (Mybudget != 0) {
			
			 Tower max = pos[0][0];					//temp variable
			 for (int i = 0; i < 100; i++) {
				 for (int j = 0; j < 100; j++){		//Searches through every point in grid.
					 Tower point = pos[i][j];		//Temp variable
					 if (!point.select && point.ProxCost > max.ProxCost) {
						 max = point;
						 	//"Circles" point if conditions are met.
						 

					 }
                  }
			 }
			 Select(max.y, max.x);
			 max.select=true;
			 Mybudget--;
		 }
	 }



	 void Grid::PrintGrid()
	 {
		 for (int i = 0; i <200; i++)									//prints upper border
			 cout << "-";
		 for (int x = 0; x < 100; x++)
		 {
			 cout <<"|"<< endl;
			 for (int y = 0; y < 100; y++) {

				 if (pos[x][y].cost == 0 && pos[x][y].select) {//Draws circle

					 cout << "*";


				 }
				
				 
				 if (pos[x][y].cost >= 1 && pos[x][y].cost <= 7) {
					 cout << pos[x][y].cost << "";
				 }								//prints cost
				 else if (pos[x][y].cost < 1 && pos[x][y].cost != 0) {
					 std::stringstream ss;
					 ss << setw(0) << setprecision(1);					//converts values <1 to a string and removes the 0 before decimal.(to save space)
					 ss << fixed << pos[x][y].cost;
					 string str = ss.str();
					 cout << str.substr(1, str.size() - 1);
					 
				 }

				 else if (pos[x][y].cost == 0&&pos[x][y].select==false) {
					 cout << " ";
				 }
				
				 }
				 
			 } 
			
		 
		 cout << endl;
		 for (int i = 0; i < 200; i++)									//prints lower border
			 cout << "-";
		
	 };



