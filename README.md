# MonthlyBudgetProgram
A program that processes a user’s monthly budget. This program can easily be enhanced to process any number of budget items. 

The program have a menu that is called from inside Main. Each item below are functions that will be call from Main.
1.	Load Budget & Spent Items data
2.	Add Budget Item
3.	Print Budget Report
4.	Save Budget & Spent Information
5.	Exit Budget

•	Load Budget & Spent Data - read and load the budget and spent information from budget.txt and spentitems.txt.  Validate that all the main categories (H, U, & F) have a budget amount, if not exit the program and update the budget.txt file. 
ID	Name	Amount
H	Housing	750
U	Utilities 	400
F	Food	350


The program contain several Classes. A parent class named SpentItemType. The parent class should contain several member variables and member functions.
Here are a few member variables and member functions that the program contain, feel free to add any additional one that your program may need:
Members Variables &	Members Functions
	SpentItemTypeID of type string
	SpentItemTypeName of type string
	SpentItemTypeAmount of type double	
	Constructor that has three parameters that has three default values: “NoID”, “NoName”, and 0. Initialized according to the parameters.
	SetSpentItemInformation function set the Spent Item id, name, amount and if amount is less than 0 and then ask for a new amount.
	GetSpentItemTypeID that return the Spent Item id that was set.
	GetSpentItemTypeName that return the Spent Item name that was set.
	GetSpentItemTypeAmount that return the Spent Item Amount that was set.

Members Variables &	Members Functions
	BudgetItemID of type string
	BudgetItemName of type string
	BudgetItemAmount of type double	
	Constructor that has three parameters that has three default values: “NoID”, “NoName”, and 0.0. Initialized according to the parameters.
	SetBudgetItemInformation function set the Budget Item id, name, amount and if amount is less or equal to 0 then ask for a new amount.
	GetBudgettItemID that return the Budget Item id that was set.
	GetBudgetItemName that return the Budget Item name that was set.
	GetBudgetItemAmount that return the Budget Item Amount that was set.
	PrintInformation that is a pure virtual class.

Members Variables	& Members Functions
	itemID of type string
	NumberofItem of type int
	itemName[10] of type SpentItemType	
	Constructor only custom constructor that set the Parent Parameters to the name of the budget item. For example, if the HousingType call the Parent constructor, “H”, “Housing”, 0.0 would be pass to the parent class BudgetItemType.
	SetInformation function to set the budget’s information. The member variables are set according to the parameters. Should have around 6 parameters.
	PrintInformation that print the budget item name, budget amount, all the items bought, and a total of all the items bought. Print to the screen and out to a txt file with the budget name and _Lastnamefirstname.txt at the end.
	AddNewSpentItem function should add a new item to the Spent Item type for this class
	GetNumberofItem function to return the number of item bought
	GetTotalSpentAmount function to return the total of all the items bought (double). Only 2 decimal places
	GetAmountLeftInBudget function to return the amount left in the budget (double). Only 2 decimal places

