 // Kidane Mussie
 // 5-4-16
 // CS15-01 Assignment8
 #include<iostream>
 #include<ios>
 #include<limits>
 #include<stdlib.h>
 #include<string.h>
 using namespace std;

 struct Node
 {
    Node *Previous,
         *Next;
    string empId;
    float hours,
          payrate;
 };

 int main()
 {

     int elements = 0,
         choice1,
         choice2;
     float hours, payrate;
     string id;
     bool again = true;
     Node *First = nullptr,
          *Last = nullptr,
          *tempPrevious,
          *tempNext,
          *N,
          *NTemp;

     while(again)
     {
         cout << "1 - Enter an Employee at the beginning of the list" << endl;
         cout << "2 - Enter an Employee at the end of the list" << endl;
         cout << "3 - Enter an Employee anywhere in the list" << endl;
         cout << "4 - Change an existing records fields" << endl;
         cout << "5 - Delete an Employee" << endl;
         cout << "6 - Display Employee records from beginning to end" << endl;
         cout << "7 - Display Employee records in reverse order" << endl;
         cout << "8 - Quit" << endl << endl;
         cout << "Enter an option(1-5): ";
         cin  >> choice1;

         switch(choice1)
         {
             case 1 : // insert node at beginning of list
             {

                        system("cls");

                        N = new Node;
                        elements++;
                        N ->Next = First;
                        N ->Previous = nullptr;
                        First = N;

                        cout << "Enter an Employee ID: ";
                        cin  >> id;
                        cout << "\nEnter the number hours worked: ";
                        cin  >> hours;
                        cout << "\nEnter the payrate: ";
                        cin  >> payrate;

                        N ->empId = id;
                        N ->hours = hours;
                        N ->payrate = payrate;

                        if(elements == 1)
                        {
                            Last = N;
                        }
                        if(elements > 1)
                        {
                            N = N ->Next;
                            N ->Previous = First;
                        }
                        break;
             }

             case 2 : // insert node at end of list
             {

                        system("cls");

                        N = new Node;
                        elements++;
                        N ->Next = nullptr;
                        N ->Previous = Last;
                        Last = N;

                        cout << "Enter an Employee ID: ";
                        cin  >> id;
                        cout << "\nEnter the number hours worked: ";
                        cin  >> hours;
                        cout << "\nEnter the payrate: ";
                        cin  >> payrate;

                        N ->empId = id;
                        N ->hours = hours;
                        N ->payrate = payrate;


                        if(elements == 1)
                        {
                            First = nullptr;
                            First = N;
                            N ->Previous = nullptr;
                        }
                        if(elements > 1)
                        {
                            N = N ->Previous;
                            N ->Next = Last;
                        }
                        break;
             }

             case 3 : // insert node anywhere in list
            {
                        system("cls");
                        bool found = true;

                        NTemp = new Node;

                        if(elements > 0)
                        {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Enter an existing Employee ID to insert the new Employee after";
                            cout << "\n\nEnter existing Employee ID: ";
                            getline(cin,id);
                            NTemp ->empId = id;
                            NTemp = First;

                            while(found)
                            {
                                if(NTemp ->empId == id)
                                {

                                    N = new Node;
                                    elements++;
                                    tempNext = NTemp ->Next;
                                    tempPrevious = NTemp;

                                    cout << "\n\nNew Employee Record:";
                                    cout << "\nEnter a new Employee ID: ";
                                    cin  >> id;
                                    cout << "\nEnter the number hours worked: ";
                                    cin  >> hours;
                                    cout << "\nEnter the payrate: ";
                                    cin  >> payrate;

                                    N ->empId = id;
                                    N ->hours = hours;
                                    N ->payrate = payrate;

                                    if(tempNext != nullptr && tempPrevious != nullptr)
                                    {
                                        NTemp ->Next = N;
                                        N ->Next = tempNext;
                                        N ->Previous = tempPrevious;
                                        N = N ->Next;
                                        N ->Previous = NTemp ->Next;

                                    }
                                    if(NTemp == Last)
                                    {
                                        N ->Next = nullptr;
                                        N ->Previous = Last;
                                        Last = N;
                                        N = N ->Previous;
                                        N ->Next = Last;
                                        break;
                                    }

                                    found = false;

                                }
                                else
                                {
                                    NTemp = NTemp ->Next;
                                    if((NTemp ->Next == nullptr) && (NTemp ->empId != id) )
                                    {
                                        cout << "Employee " << id << " does not exist" << endl << endl;
                                        system("pause");
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "No records exist" << endl;
                            system("pause");
                        }
                        break;
             }


             case 4 : // change an existing records fields
             {

                        system("cls");
                        bool found = true;

                        if(elements > 0)
                        {
                            cout << "Enter an Employee ID: ";
                            cin  >> id;
                            N = First;

                            while(found)
                            {
                                if(N ->empId == id)
                                {
                                    cout << "Change a Field Value" << endl << endl;
                                    cout << "1 - Employee ID" << endl;
                                    cout << "2 - Total hours worked" << endl;
                                    cout << "3 - Payrate" << endl;
                                    cout << "\nEnter an Option(1 to 3): ";
                                    cin  >> choice2;

                                    switch(choice2)
                                    {
                                        case 1 :
                                        {
                                                    system("cls");

                                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                    cout << "Enter Employee ID: ";
                                                    getline(cin,id);
                                                    N ->empId = id;
                                                    break;
                                        }

                                        case 2 :
                                        {
                                                    system("cls");

                                                    cout << "Enter total hours worked: ";
                                                    cin  >> hours;
                                                    N ->hours = hours;
                                                    break;
                                        }

                                        case 3 :
                                        {
                                                    system("cls");

                                                    cout << "Enter the payrate: ";
                                                    cin  >> payrate;
                                                    N ->payrate = payrate;
                                                    break;
                                        }

                                        default :
                                                    system("cls");
                                                    cout << "Please enter a valid menu option(1 - 3)" << endl;
                                                    system("pause");
                                    }
                                    cout << endl;
                                    system("pause");
                                    break;

                                    found = false;

                                }
                                else
                                {
                                    N = N ->Next;
                                    if((N ->Next == nullptr) && (N ->empId != id) )
                                    {
                                        cout << "Employee " << id << " does not exist" << endl << endl;
                                        system("pause");
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "No Employee records exist" << endl;
                            system("pause");
                        }
                        break;
             }

             case 5 :
             {
                 if(elements > 0)
				 {
					system("cls");
					bool again1 = true;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "\nEnter an Employee ID to Find and Delete: ";
					getline(cin,id);
					NTemp = First;

					while (again1)
					{
						if(NTemp ->empId == id)
						{
							cout << "\nEmployee " << NTemp ->empId << " has been deleted" << endl;
							elements--;
							if (elements == 0)
							{
						   		delete NTemp;
								First = nullptr;
								Last = nullptr;
								system("pause");
						   		break;
							}
							tempPrevious = NTemp ->Previous;
							tempNext = NTemp ->Next;
							delete NTemp;

							if(tempPrevious == nullptr)
							{

								NTemp = tempNext;
								NTemp -> Previous = nullptr;
								First = NTemp;
								system("pause");
								break;
							}

							if(tempNext == nullptr)
							{

								NTemp = tempPrevious;
								NTemp -> Next = nullptr;
								Last = NTemp;
								system("pause");
								break;
							}

							if((tempPrevious != nullptr) && (tempNext != nullptr))
							{
								NTemp = tempPrevious;
								NTemp -> Next = tempNext;
								NTemp = tempNext;
								NTemp -> Previous = tempPrevious;
								system("pause");
								break;
							}
						}
						else
						{

							NTemp = NTemp -> Next;
							if ((NTemp -> Next == nullptr) && (NTemp ->empId != id))
							{
								cout << "\nEmplyee" << id << " does not exist" << endl;
								system("pause");
								break;
							}

						}
					}
				}
				else
				{
				    system("cls");
					cout << "\nNo records exist" << endl;
					system("pause");
				}
				break;
             }

             case 6 : // display list from beginning to end
             {

                        system("cls");

                        if(elements > 0)
                        {
                            N = First;
                            while(N ->Next != nullptr)
                            {
                                cout << "Employee ID: " << N ->empId << endl;
                                cout << "Hours worked: " << N ->hours << endl;
                                cout << "Payrate: $" << N ->payrate << "/hour" << endl << endl;
                                N = N ->Next;
                            }
                            cout << "Employee ID: " << N ->empId << endl;
                            cout << "Hours worked: " << N ->hours << endl;
                            cout << "Payrate: $" << N ->payrate << "/hour" << endl;
                        }
                        else
                        {
                            cout << "No records exist" << endl;

                        }
                        system("pause");
                        break;
             }

             case 7 : // display list in reverse order
             {

                        system("cls");

                        if(elements > 0)
                        {
                            N = Last;
                            while(N ->Previous != nullptr)
                            {
                                cout << "Employee ID: " << N ->empId << endl;
                                cout << "Hours worked: " << N ->hours << endl;
                                cout << "Payrate: $" << N ->payrate << "/hour" << endl << endl;
                                N = N ->Previous;
                            }
                            cout << "Employee ID: " << N ->empId << endl;
                            cout << "Hours worked: " << N ->hours << endl;
                            cout << "Payrate: $" << N ->payrate << "/hour" << endl;
                        }
                        else
                        {
                            cout << "No records exist" << endl;
                        }
                        system("pause");
                        break;
             }

             case 8 :
                        system("cls");
                        cout << "Exiting..." << endl << endl;
                        exit(0);
                        break;

             default :
                        system("cls");
                        cout << "Please enter a valid menu option(1 - 8)" << endl;
                        system("pause");
         }
         system("cls");
     }
     return 0;
 }
