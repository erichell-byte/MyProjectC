using System;
	
	double sum ;
	double rate ;
	int term ; // количество месяцев кредита
	int selectedMonth; // месяц в котором досрочное погашение
	double payment;
	double rateMonth;
	double any; // аннуитетный платеж
	double CurPercent;
	double OdDept = 0;
	double CurDebt;
	int CurMonth = 5;
	double OverpaySum = 0; // сумма переплаты при погашении с уменьшением суммы
	double OverpayTime = 0; // сумма переплаты при погашении с уменьшением срока
	DateTime date1 = new DateTime(2021, 6, 1);

	bool[] right = new bool[5];
	right[0] = double.TryParse(args[0], out sum);
	right[1] = double.TryParse(args[1], out rate);
	right[2] = int.TryParse(args[2], out term);
	right[3] = int.TryParse(args[3], out selectedMonth);
	right[4] = double.TryParse(args[4], out payment);

	if (right[0] == false || payment >= sum || selectedMonth >= term || right[1] == false || right[2] == false || right[3] == false || right[4] == false)
		Console.WriteLine("Ошибка ввода. Проверьте входные данные и повторите запрос.");
	else
	{
		rateMonth = rate / 100 / 12;
		double annyitet(double rateMonth, double sum, int term)
		{
			double any = (sum * rateMonth * Math.Pow((1 + rateMonth), term)) / (Math.Pow((1 + rateMonth), term) - 1);
			any = Math.Round(any, 2);
			return (any);
		}
		static double Percent(double CurDebt,double rateMonth, int CurMonth, double rate)
		{
			double CurPercent = ((CurDebt * rate * DateTime.DaysInMonth(2021, CurMonth)) / (365 * 100));
			CurPercent = Math.Round(CurPercent, 2);
			return (CurPercent);
		}
		static int ManyMonth(double rateMonth, double any, double CurDebt)
		{
			double many = 1 + rateMonth;
			int term = Convert.ToInt32((Math.Log((any / (any - (rateMonth * CurDebt))), many)));
			return (term);
		}
		any = annyitet(rateMonth, sum, term);
		CurDebt = sum;
		int checker = 1;
		Console.WriteLine("{0, -15} {1, -15} {2, -15} {3, -15} {4, -15} {5, 20}","Дата платежа", "Платеж", "Тело кредита,ОД",  "Проценты", "Остаток долга", "Уменьшение суммы"); //! разобраться 

		while (checker <= term) // уменьшение суммы
		{
			CurPercent = Percent(CurDebt, rateMonth, CurMonth, rate);
			OverpaySum +=  CurPercent;
			OverpaySum = Math.Round(OverpaySum, 2);
			OdDept = any - CurPercent;
			OdDept = Math.Round(OdDept, 2);
			CurDebt = CurDebt - OdDept;
			CurDebt = Math.Round(CurDebt, 2);
			if (checker == selectedMonth)
			{
				CurDebt = CurDebt - payment;
				any = annyitet(rateMonth, CurDebt, term - checker);
			}
			Console.WriteLine("{0, -15} {1, -15} {2, -15} {3, -15} {4, -15}",date1.ToString("dd.MM.yyyy"), any, OdDept, CurPercent, CurDebt);
			date1 = date1.AddMonths(1);
			CurMonth = CurMonth + 1;
			if (CurMonth > 12)
				CurMonth = 1;
			checker++;
		}
		Console.WriteLine();
		Console.WriteLine("{0, -15} {1, -15} {2, -15} {3, -15} {4, -15} {5, 20}","Дата платежа", "Платеж", "Тело кредита,ОД",  "Проценты", "Остаток долга", "Уменьшение срока");
		any = annyitet(rateMonth, sum, term); // обнуляем переменные
		CurDebt = sum;
		checker = 1;
		CurMonth = 5;
		date1 = new DateTime(2021, 6, 1);
		while (checker <= term) // уменьшение срока
		{
			
			CurPercent = Percent(CurDebt, rateMonth, CurMonth, rate);
			OverpayTime +=  CurPercent;
			OverpayTime = Math.Round(OverpayTime, 2);
			OdDept = any - CurPercent;
			OdDept = Math.Round(OdDept, 2);
			CurDebt = CurDebt - OdDept;
			if(CurDebt < 0)
				CurDebt = 0.00;
			CurDebt = Math.Round(CurDebt, 2);
			if (checker == selectedMonth)
			{	
				term = ManyMonth(rateMonth, any, CurDebt);
				CurDebt = CurDebt - payment;
				selectedMonth = 0;
				checker = 0;
			}
			Console.WriteLine("{0, -15} {1, -15} {2, -15} {3, -15} {4, -15}",date1.ToString("dd.MM.yyyy"), any, OdDept, CurPercent, CurDebt);
			date1 = date1.AddMonths(1);
			CurMonth = CurMonth + 1;
			if (CurMonth > 12)
				CurMonth = 1;
			checker++;
		}
	Console.WriteLine();
	Console.WriteLine("{0, -15} {1, 15} р.", "Переплата при уменьшнии платежа:", OverpaySum);
	Console.WriteLine("{0, -15} {1, 18} р.", "Переплата при уменьшнии срока:", OverpayTime);
	if (OverpaySum > OverpayTime)
	{
		OverpaySum = OverpaySum - OverpayTime;
		OverpaySum = Math.Round(OverpaySum, 2);
		Console.WriteLine("Уменьшение срока выгоднее уменьшения платежа на " + OverpaySum + " р." );
	}
	else if(OverpayTime > OverpaySum)
	{
		OverpayTime -=OverpaySum;
		OverpayTime = Math.Round(OverpayTime, 2);
		Console.WriteLine("Уменьшение платежа выгоднее уменьшения срока на " + OverpayTime + " р." );
	}
	else
		Console.WriteLine("Переплата одинакова в обоих вариантах.");
	}
	