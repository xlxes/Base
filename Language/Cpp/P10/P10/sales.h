#ifndef SALE_H_
#define SALE_H_

namespace SALES
{
	const int QUA = 4;
	class Sales
	{
	private:
		double sales[QUA];
		double average;
		double min;
		double max;
	public:
		Sales();
		Sales(const double ar[], int n);
		~Sales();
		void setSales();
		void showSales() const;
	};
}

#endif // !SALE_H_

