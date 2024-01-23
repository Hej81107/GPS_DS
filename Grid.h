
class Tower {//represents each individual data point
private:
public:
	Tower();

	double cost;
	double ProxCost=0;
	bool select=false;
	int x;
	int y;




};

class Grid {
private:
public:
	 Tower pos[100][100]; //array of potential data points.
	
	double budget=15;
	
	Grid();
	void FindProxCost();
	void Select(int x, int y);
	double Distance(Tower arr[100][100]);
	void InitGrid();
	void PopulateGrid();
	void Greed();
	void PrintGrid();
};


