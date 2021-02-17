namespace SALES
{
	const int QUARTERS = 4;		//最多4个数值
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales &s, const double ar[], int n);
	void setSales(Sales &s);
	void showSales(const Sales &s);
}
