/*Course: COSC 1437 Programming Fundamental Ⅱ*/
/*Subject: Project 2*/
/*Structor: Gregory Rogers*/
/*Student: Zhaoying Meng*/
/*Due: 12/11/2018*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class SpentItemType
{
public:
	string SpentItemTypeID;
	string SpentItemTypeName;
	double SpentItemTypeAmount;

	SpentItemType()
	{
		SpentItemTypeID = "NoID";
		SpentItemTypeName = "NoName";
		SpentItemTypeAmount = 0.0;
	}

	void SetSpentItemInformation(string id, string name, double amount)
	{
		SpentItemTypeID = id;
		SpentItemTypeName = name;
		SpentItemTypeAmount = amount;
	}


	string GetSpentItemTypeID()
	{
		return SpentItemTypeID;
	}

	string GetSpentItemTypeName()
	{
		return SpentItemTypeName;
	}

	double GetSpentItemTypeAmount()
	{
		return SpentItemTypeAmount;
	}

};


class BudgetItemType
{
private:
	double BudgetItemAmount;

public:
	string BudgetItemID;
	string BudgetItemName;

	void SetBudgetItemInformation(string id, string name, double amount)
	{
		BudgetItemID = id;
		BudgetItemName = name;
		BudgetItemAmount = amount;
	}

	string GetBudgettItemID()
	{
		return BudgetItemID;
	}

	string GetBudgetItemName()
	{
		return BudgetItemName;
	}

	double GetBudgetItemAmount()
	{
		return BudgetItemAmount;
	}

	virtual void PrintInformation() = 0;

	BudgetItemType(string id = "NoID", string name = "NoName", double amount = 0.0)
	{
		BudgetItemID = id;
		BudgetItemName = name;
		BudgetItemAmount = amount;
	}

};

class HousingType : public BudgetItemType
{
private:
	string itemID;
	int NumberofItem;
	SpentItemType itemName[10];
	double totalspentamount = 0;
	double leftamount;

public:
	HousingType(string id = "H", string name = "Housing", int amount = 0.0) :BudgetItemType(id, name, amount)
	{
		itemID = "H";
		NumberofItem = 0;
	}

	void SetInformation(string id, string name, double amount)
	{
		if (itemID == id)
		{
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
			/*cout << NumberofItem << endl;*/
		}
	}

	void PrintInformation()
	{
		cout << "Housing item ID is " << BudgetItemID << endl;
		cout << "Housing Budget Amount is " << GetBudgetItemAmount() << endl;
		for (int i = 0; i < NumberofItem; i++)
		{
			cout << " " << left << setw(10) << itemName[i].GetSpentItemTypeID() << setw(15) << itemName[i].GetSpentItemTypeName()
				<< setw(15) << itemName[i].GetSpentItemTypeAmount() << endl;
		}

		cout << "The total of all the items purchase is " << GetTotalSpentAmount() << endl;
		cout << "The amount left in the Housing is " << GetAmountLeftInBudget() << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << endl;
	}

	void AddNewSpentItem(string id, string name, double amount)
	{
		if (itemID == id)
		{
			cout << NumberofItem << endl;
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
		}
	}


	int GetNumberofItem()
	{
		return NumberofItem;
	}

	double GetTotalSpentAmount()
	{
		for (int i = 0; i < NumberofItem; i++)
		{
			totalspentamount = totalspentamount + itemName[i].GetSpentItemTypeAmount();
		}

		return totalspentamount;
	}


	double GetAmountLeftInBudget()
	{
		leftamount = GetBudgetItemAmount() - totalspentamount;
		return leftamount;
	}

};

class UtilitiesType : public BudgetItemType
{
private:
	string itemID;
	int NumberofItem;
	SpentItemType itemName[10];
	double totalspentamount = 0;
	double leftamount;

public:
	UtilitiesType(string id = "U", string name = "Utilities", int amount = 0.0) :BudgetItemType(id, name, amount)
	{
		itemID = "U";
		NumberofItem = 0;
	}

	void SetInformation(string id, string name, double amount)
	{
		if (itemID == id)
		{
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
		}
	}

	void PrintInformation()
	{
		cout << "Utilities item ID is " << BudgetItemID << endl;
		cout << "Utilities Budget Amount is " << GetBudgetItemAmount() << endl;
		for (int i = 0; i < NumberofItem; i++)
		{
			cout << " " << left << setw(10) << itemName[i].GetSpentItemTypeID() << left << setw(15) << itemName[i].GetSpentItemTypeName()
				<< left << setw(15) << itemName[i].GetSpentItemTypeAmount() << endl;
		}

		cout << "The total of all the items purchase is " << GetTotalSpentAmount() << endl;
		cout << "The amount left in the Housing is " << GetAmountLeftInBudget() << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << endl;
	}

	void AddNewSpentItem(string id, string name, double amount)
	{
		if (itemID == id)
		{
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
		}
	}

	int GetNumberofItem()
	{
		return NumberofItem;
	}

	double GetTotalSpentAmount()
	{
		for (int i = 0; i < NumberofItem; i++)
		{
			totalspentamount = totalspentamount + itemName[i].GetSpentItemTypeAmount();
		}

		return totalspentamount;
	}


	double GetAmountLeftInBudget()
	{
		leftamount = GetBudgetItemAmount() - totalspentamount;
		return leftamount;
	}

};


class FoodType : public BudgetItemType
{
private:
	string itemID;
	int NumberofItem;
	SpentItemType itemName[10];
	double totalspentamount = 0;
	double leftamount;

public:
	FoodType(string id = "F", string name = "Food", int amount = 0.0) :BudgetItemType(id, name, amount)
	{
		itemID = "F";
		NumberofItem = 0;
	}

	void SetInformation(string id, string name, double amount)
	{
		if (itemID == id)
		{
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
		}
	}

	void PrintInformation()
	{
		cout << "Food item ID is " << BudgetItemID << endl;
		cout << "Food Budget Amount is " << GetBudgetItemAmount() << endl;
		for (int i = 0; i < NumberofItem; i++)
		{
			cout << " " << left << setw(10) << itemName[i].GetSpentItemTypeID() << setw(15) << itemName[i].GetSpentItemTypeName()
				<< setw(15) << itemName[i].GetSpentItemTypeAmount() << endl;
		}

		cout << "The total of all the items purchase is " << GetTotalSpentAmount() << endl;
		cout << "The amount left in the Housing is " << GetAmountLeftInBudget() << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << endl;
	}

	void AddNewSpentItem(string id, string name, double amount)
	{
		if (itemID == id)
		{
			itemName[NumberofItem].SpentItemTypeID = id;
			itemName[NumberofItem].SpentItemTypeName = name;
			itemName[NumberofItem].SpentItemTypeAmount = amount;
			NumberofItem++;
		}
	}

	int GetNumberofItem()
	{
		return NumberofItem;
	}

	double GetTotalSpentAmount()
	{
		for (int i = 0; i < NumberofItem; i++)
		{
			totalspentamount = totalspentamount + itemName[i].GetSpentItemTypeAmount();
		}

		return totalspentamount;
	}


	double GetAmountLeftInBudget()
	{
		leftamount = GetBudgetItemAmount() - totalspentamount;
		return leftamount;
	}

};

int main()
{
	int num;
	string id, name;
	double amount;
	ifstream infile1;
	ifstream infile2;
	HousingType housingtype;
	UtilitiesType utilitiestype;
	FoodType foodtype;
	string newid, newname;
	double newamount;

	cout << fixed << showpoint << setprecision(3);

	do
	{
		cout << "1. Load Budget & Spent Items data" << endl;
		cout << "2. Add Budget Item" << endl;
		cout << "3. Print Budget Report" << endl;
		cout << "4. Save Budget & Spent Information" << endl;
		cout << "5. Exit Budget" << endl;

		cout << "Please enter a number: ";
		cin >> num;
		cout << endl;

		if (num == 1)
		{
			infile1.open("budget.txt");
			for (int i = 0; i < 3; i++)
			{
				infile1 >> id;
				infile1 >> name;
				infile1 >> amount;
				/*cout << id << " ";
				cout << name << " ";
				cout << amount << endl;*/
				if (id == "H")
				{
					housingtype.SetBudgetItemInformation(id, name, amount);
					//housingtype.PrintInformation();
				}
				else if (id == "F")
				{
					foodtype.SetBudgetItemInformation(id, name, amount);
					//foodtype.PrintInformation();
				}
				else if (id == "U")
				{
					utilitiestype.SetBudgetItemInformation(id, name, amount);
					//utilitiestype.PrintInformation();
				}

			}


			infile2.open("spentitems.txt");
			for (int i = 0; i < 9; i++)
			{
				infile2 >> id;
				infile2 >> name;
				infile2 >> amount;
				/*cout << id << " ";
				cout << name << " ";
				cout << amount << endl;*/

				if (id == "H")
				{
					housingtype.SetInformation(id, name, amount);
				}
				else if (id == "F")
				{
					foodtype.SetInformation(id, name, amount);
				}
				else if (id == "U")
				{
					utilitiestype.SetInformation(id, name, amount);
				}

			}


			infile1.close();
			infile2.close();
		}
		else if (num == 2)
		{
			cout << "Please enter a new item " << endl;
			cout << "Please enter the budget item ID: ";
			cin >> newid;
			cout << "please enter the budget item name: ";
			cin >> newname;
			cout << "Plaeae enter the budget item amount: ";
			cin >> newamount;
			cout << endl;

			if (newid == "H")
			{
				housingtype.AddNewSpentItem(newid, newname, newamount);
			}
			else if (newid == "F")
			{
				foodtype.AddNewSpentItem(newid, newname, newamount);
			}
			else if (newid == "U")
			{
				utilitiestype.AddNewSpentItem(newid, newname, newamount);
			}
		}
		else if (num == 3)
		{
			housingtype.PrintInformation();
			foodtype.PrintInformation();
			utilitiestype.PrintInformation();
		}
		else if (num == 4)
		{
			
		}
		else if (num == 5)
		{
			cout << "Thanks! Good bye! ! !" << endl;
			break;
		}
		else
			cout << "Please enter a correct number(1-5)!" << endl;

		cout << endl;

	} while (num != 5);

	system("pause");
	return 0;
}