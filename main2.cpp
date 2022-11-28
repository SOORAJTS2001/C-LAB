#include<iostream>
#include<map>
#include <fstream>
using namespace std;
// this is the vehicle class
class Vehicle
{
    public:
    string make,model,plateNumber;
    int year,mileage,numSeats;
    Vehicle(string mke,string mdel,string plteNumber,int yer,int mleage,int nmSeats)//first constructor with all the parameters
    {
        make = mke;
        model = mdel;
        plateNumber = plteNumber;
        year = yer;
        mileage= mleage;
        numSeats = nmSeats;
        
    }
    Vehicle(string mke,string mdel,int yer,int nmSeats,int mleage=0)//second constructor with default value for mileage
    {
        make = mke;
        model = mdel;
        year = yer;
        numSeats=nmSeats;
        mileage=mleage;
    }
    void getMake(Vehicle* v)//Vehhicle pointer to access the attributes of the class
   
    {
        cout<<v->make<<endl;
    }
    
    void getModel(Vehicle* v)
    {
        cout<<v->model<<endl;
    }
    void getYear(Vehicle* v)
    {
        cout<<v->year<<endl;
    }
    void getMileage(Vehicle* v)
    {
        cout<<v->mileage<<endl;
    }
    void getPlateNumber(Vehicle* v)
    {
        cout<<v->plateNumber<<endl;
    }
    void getNumSeats(Vehicle* v)
    {
        cout<<v->numSeats<<endl;
    }
    void setPlateNumber(Vehicle* v,string newPlateNumber)//it is to set the plate number
    {
       v->plateNumber = newPlateNumber;
       cout<<"The new plate number is: "<<v->plateNumber<<endl;
    }    
};
class Taxi:public Vehicle{
    public:
    int taxiId,numOfFares; 
    float fareTotal;
    Taxi(string mke, string mdel, int yer, int mleage,int numSeats, int txiId,string plteNumber="unknown",float freTotal=0.0,int nmOfFares=0)
    :Vehicle(mke,mdel,plteNumber,yer,mleage,numSeats)//this is the constructor of the taxi class which inherits from the vehicle class
    //so when this constructor is called the the vehicle consturctor is called first
    {
        taxiId = txiId;
        fareTotal = freTotal;
        numOfFares = nmOfFares;
        make = mke;
        model = mdel;
        year = yer;
        mileage = mleage;
        plateNumber = plteNumber;
        numSeats = numSeats;
        taxiId = txiId;
    }
    void getID(Taxi*taxi)//this is to get the id of the taxi
    {

        cout<<"the id of the taxi is"<<taxi->taxiId<<endl;
    }
    void getNumOfFares(Taxi*taxi)
    {
        cout<<"the num of fairs"<<taxi->numOfFares<<endl;
    } 
    void getFareTotal(Taxi*taxi)
    {
        cout<<"the total fairs"<<taxi->fareTotal<<endl;
    }
    void addFare(Taxi*taxi,float fare)
    {
        taxi->fareTotal+=fare;
        taxi->numOfFares++;
        cout<<"the total fairs"<<taxi->fareTotal<<endl;
    }
    void setID(Taxi*taxi,int newID)
    {
        taxi->taxiId = newID;
        cout<<"the new id of the taxi is"<<taxi->taxiId<<endl;
    }
    void resetFareInfo(Taxi*taxi)
    {
         taxi->fareTotal = 0.0;
         taxi->numOfFares = 0;
         cout<<"the fare has been resetted"<<endl;
    }

};
int main()

{
    map<int,Taxi*>mp;//this is the map which stores the taxi id and the taxi object
    //accessing from the map, .first is the key and .second is the value,where the value is the object of the taxi class
    Taxi t1("Toyota","Corolla",2015,100000,4,1,"ABC1234");
    Taxi t2("Mercedes","E-class",2019,120000,4,2,"ABD1234");
    t1.addFare(&t1,100);//this is to add the fare to the taxi
    // t1.getID(&t1);//this is to get the id of the taxi
    // t1.getNumOfFares(&t1);//this is to get the number of fares of the taxi
    // t1.getFareTotal(&t1);//this is to get the total fare of the taxi
    // t1.setID(&t1,3);//this is to set the id of the taxi
    t1.resetFareInfo(&t1);//this is to reset the fare info of the taxi
    mp[1]=&t1;
    mp[2]=&t2;//storing the address to the map so that we can access it later
    int choice;
    while(true)
    {
        cout<<"______________________________________________"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|                  Menu                       |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"| 1. Show list of All taxi                    |"<<endl;
        cout<<"| 2. Add new taxi                             |"<<endl;
        cout<<"| 3. Reset Taxi's fare information            |"<<endl;
        cout<<"| 4. Add To Total fare of a Taxi              |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cout<<" Please enter your choice: ";
        cin>>choice;//taking the choice from the user
        string myText;
        if(choice==1)
        {
            cout<<"Sr.No       "<<"Make       "<<"Model       "<<"Plate Number       "<<"Year       "<<"Mileage       "<<"Texi ID        "<<"Number of Seats       "<<"Number of Fares       "<<"Total Fare       "<<endl;
            ofstream MyFile("taxi.txt");
            for(auto it:mp)//this saves the data to the text file
            {
                MyFile<<"Taxi ID: "<<it.first<<endl;
                MyFile<<"Make: "<<it.second->make<<endl;
                MyFile<<"Model: "<<it.second->model<<endl;
                MyFile<<"Year: "<<it.second->year<<endl;
                MyFile<<"Mileage: "<<it.second->mileage<<endl;
                MyFile<<"Plate Number: "<<it.second->plateNumber<<endl;
                MyFile<<"Number of Seats: "<<it.second->numSeats<<endl;
                MyFile<<"Number of Fares: "<<it.second->numOfFares<<endl;
                MyFile<<"Total Fares: "<<it.second->fareTotal<<endl;
                MyFile<<"______________________________________________"<<endl;
                cout<<it.first<<"       "<<it.second->make<<"       "<<it.second->model<<"       "<<it.second->plateNumber<<"       "<<it.second->year<<"       "<<it.second->mileage<<"       "<<it.second->taxiId<<"       "<<it.second->numSeats<<"       "<<it.second->numOfFares<<"       "<<it.second->fareTotal<<endl;
                //shows the data to the user
            }
            MyFile.close();
        }
        else if(choice ==2)
        {
            string make,model,plateNumber;
            int year,mileage,numSeats,taxiId;
            //taking the data from the user
            cout<<"Enter Make: ";
            cin>>make;
            cout<<"Enter Model: ";
            cin>>model;
            cout<<"Enter Year: ";
            cin>>year;
            cout<<"Enter Mileage: ";
            cin>>mileage;
            cout<<"Enter Plate Number: ";
            cin>>plateNumber;
            cout<<"Enter Number of Seats: ";
            cin>>numSeats;
            cout<<"Enter Taxi ID: ";
            cin>>taxiId;
            Taxi t(make,model,year,mileage,numSeats,taxiId,plateNumber);
            mp[taxiId]=&t;
            ofstream MyFile("taxi.txt");
            for(auto it:mp)//updating the data to the text file
            {
                MyFile<<"Taxi ID: "<<it.first<<endl;//accessing from the map, .first is the key and .second is the value,where the value is the object of the taxi class
                MyFile<<"Make: "<<it.second->make<<endl;
                MyFile<<"Model: "<<it.second->model<<endl;
                MyFile<<"Year: "<<it.second->year<<endl;
                MyFile<<"Mileage: "<<it.second->mileage<<endl;
                MyFile<<"Plate Number: "<<it.second->plateNumber<<endl;
                MyFile<<"Number of Seats: "<<it.second->numSeats<<endl;
                MyFile<<"Number of Fares: "<<it.second->numOfFares<<endl;
                MyFile<<"Total Fares: "<<it.second->fareTotal<<endl;
                MyFile<<"______________________________________________"<<endl;
                cout<<it.first<<"       "<<it.second->make<<"       "<<it.second->model<<"       "<<it.second->plateNumber<<"       "<<it.second->year<<"       "<<it.second->mileage<<"       "<<it.second->taxiId<<"       "<<it.second->numSeats<<"       "<<it.second->numOfFares<<"       "<<it.second->fareTotal<<endl;
            }
            MyFile.close();
        }
        else if(choice ==3)
        {
            int taxiId;
            cout<<"Enter Taxi ID: ";
            cin>>taxiId;
            mp[taxiId]->resetFareInfo(mp[taxiId]);//resetting the fare info of the taxi
            ofstream MyFile("taxi.txt");
            for(auto it:mp)
            {
                MyFile<<"Taxi ID: "<<it.first<<endl;
                MyFile<<"Make: "<<it.second->make<<endl;
                MyFile<<"Model: "<<it.second->model<<endl;
                MyFile<<"Year: "<<it.second->year<<endl;
                MyFile<<"Mileage: "<<it.second->mileage<<endl;
                MyFile<<"Plate Number: "<<it.second->plateNumber<<endl;
                MyFile<<"Number of Seats: "<<it.second->numSeats<<endl;
                MyFile<<"Number of Fares: "<<it.second->numOfFares<<endl;
                MyFile<<"Total Fares: "<<it.second->fareTotal<<endl;
                MyFile<<"______________________________________________"<<endl;
                cout<<it.first<<"       "<<it.second->make<<"       "<<it.second->model<<"       "<<it.second->plateNumber<<"       "<<it.second->year<<"       "<<it.second->mileage<<"       "<<it.second->taxiId<<"       "<<it.second->numSeats<<"       "<<it.second->numOfFares<<"       "<<it.second->fareTotal<<endl;
            }
            MyFile.close();
        }
        else if(choice ==4)
        {
            int taxiId;
            float fare;
            cout<<"Enter Taxi ID: ";
            cin>>taxiId;
            cout<<"Enter Fare: ";
            cin>>fare;
            mp[taxiId]->addFare(mp[taxiId],fare);//adding the fare to the taxi
            ofstream MyFile("taxi.txt");
            for(auto it:mp)
            {
                MyFile<<"Taxi ID: "<<it.first<<endl;
                MyFile<<"Make: "<<it.second->make<<endl;
                MyFile<<"Model: "<<it.second->model<<endl;
                MyFile<<"Year: "<<it.second->year<<endl;
                MyFile<<"Mileage: "<<it.second->mileage<<endl;
                MyFile<<"Plate Number: "<<it.second->plateNumber<<endl;
                MyFile<<"Number of Seats: "<<it.second->numSeats<<endl;
                MyFile<<"Number of Fares: "<<it.second->numOfFares<<endl;
                MyFile<<"Total Fares: "<<it.second->fareTotal<<endl;
                MyFile<<"______________________________________________"<<endl;
                cout<<it.first<<"       "<<it.second->make<<"       "<<it.second->model<<"       "<<it.second->plateNumber<<"       "<<it.second->year<<"       "<<it.second->mileage<<"       "<<it.second->taxiId<<"       "<<it.second->numSeats<<"       "<<it.second->numOfFares<<"       "<<it.second->fareTotal<<endl;
            }
            MyFile.close();
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
    
    