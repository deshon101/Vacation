//---------------------------------------------------------------------------
// File name:  vacation.cpp
// Assign ID:  PROG5
// Due Date:    02/10/17 
//
// Purpose:    Write a trip report for a family vacation. The report contains
//              a travel log describing the trip, and a summary of statistics 
//              for the trip.
//
// Author:      dgrant De'Shon Grant ;
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{ 
//----------------------------------------------------------------------
// Declare variables, ONE PER LINE.
//----------------------------------------------------------------------
  
    string homeCity,
    destCity;
    
    int startHour,
    startMin,
    endHour,
    endMin,
    destMiles,
    homeMiles,
    totalMilesTraveled,
    
    homeStartHour,
    homeStartMin,
    homeEndHour,
    homeEndMin;
    
    float destTravelTime,
    totalDrivingTime,
    
    mpg,
    gasPrice,
    avg_Speed,
    galsUsed,
    fuelCost,
    homeTravelTime;
    
//-|--------------------------------------------------------------------
//-|    1. Open files.
//-|--------------------------------------------------------------------  
    
    ifstream inF;
    ofstream outF;
    inF.open("travel.dat");
    outF.open("trip.rpt");
    
    char colon;
    
//-|----------------------------------------------------------------------
//-| Display the copyright notice declaring authorship.
//-|----------------------------------------------------------------------

    cout << endl << "(c) 2017, dgrant De'Shon Grant " << endl << endl;
    
//-|--------------------------------------------------------------------
//-|    2. Read the inputs.
//-|        1.1 Read trip data.
//-|        1.2 Read fuel data.
//-|--------------------------------------------------------------------  

    getline (inF, homeCity); 
    inF >> startHour >> colon >> startMin;
    inF.ignore(1000, '\n');
    getline (inF, destCity);
    inF >> endHour >> colon >> endMin;
    inF >> destMiles >> homeMiles >> homeStartHour >> colon >> homeStartMin >> homeEndHour >> colon >> homeEndMin;
    inF >> mpg >> gasPrice;
          
//-|--------------------------------------------------------------------
//-|  3. Perform calculations.
//-|      3.1 Compute miles traveled.
//-|      3.2 Compute driving times (a) to destination; (b) back home; (c) total.
//-|      3.3 Compute average driving speed. 
//-|      3.4 Compute gallons of gas used.
//-|      3.5 Compute total fuel cost.
//-|--------------------------------------------------------------------
    
    totalMilesTraveled = destMiles + homeMiles;
    destTravelTime = (endHour + endMin/60.0) - (startHour + startMin/60.0);
    if (startHour > endHour)
    {
        destTravelTime = (endHour + 24) - startHour;
    }
    homeTravelTime = (homeEndHour + homeEndMin/60.0) - (homeStartHour + homeStartMin/60.0);
    if (homeStartHour > homeEndHour)
    {
        homeTravelTime = (homeEndHour + 24) - homeStartHour;
    }
    totalDrivingTime = destTravelTime + homeTravelTime;
    avg_Speed = totalMilesTraveled / totalDrivingTime;
    if (totalDrivingTime == 0)
    {
        avg_Speed = 0.0;
    }
    galsUsed = totalMilesTraveled / mpg;
    fuelCost = galsUsed * gasPrice; 
    
    
    

//-|--------------------------------------------------------------------
//-|    4. Display the TRIP REPORT to monitor in the required format.
//-|        4.1 Display Trip Report heading.
//-|        4.2 Display Travel Log section.
//-|        4.3 Display Trip Statistics.
//-|--------------------------------------------------------------------

    cout << "TRIP REPORT" << endl << endl;
    cout << "Travel Log:" << endl; 
    cout << "=================" << endl << endl;
    
    cout << "Departed from " << homeCity << " at " << setw(2) << setfill('0') << startHour << ':' << setw(2) << setfill('0') << startMin << '.' << endl;
    cout << "Traveled " << destMiles << " miles to " << destCity << ", arrived at " << endl << setw(2) << setfill('0') << endHour << ':' << setw(2) << setfill('0') << endMin << '.';
    cout << " Travel time, " << fixed << showpoint << setprecision(2) << destTravelTime << " hours." << endl << endl;
    cout << "Departed from " << destCity << " at " << setfill('0') << setw(2) <<homeStartHour << ':' << setw(2) << setfill('0') << homeStartMin << '.' << endl;
    cout << "Traveled " << homeMiles << " miles, arrived at " << setw(2) << setfill('0') << homeEndHour << ':' << setw(2) << setfill('0') << homeEndMin << setfill(' ') << '.' << endl << endl;    
    
    cout << "Trip Statistics:" << endl;
    cout << "=================" << endl << endl;
    cout << right << setw(8) << totalMilesTraveled <<  " = " << "Total miles traveled" << endl;
    cout << right << setw(8) << fixed << showpoint << setprecision(1) << galsUsed << " = Gallons of gas used @ " << mpg << " mpg" << endl;
    cout << "$ "  << right << setw(6) << fixed << showpoint << setprecision(2) << fuelCost << " = " << "Total fuel costs @ $" << fixed << showpoint << setprecision(2) << gasPrice << "/gal" << endl; 
    cout <<  right << setw(8) << fixed << showpoint << setprecision(2) << totalDrivingTime << " = " << "Total travel time (hours)" << endl;
    cout << right << setw(8) << fixed << showpoint << setprecision(2) << avg_Speed << " = " << "Average driving speed (mph)" << endl << endl;
//-|-----------------------------------------------
//-|  5. Write the TRIP REPORT to trip.rpt file in the required format.
//-|      5.1 Write Trip Report heading.
//-|      5.2 Write Travel Log section.
//-|      5.3 Write Trip Statistics.
//-|-----------------------------------------------  

    outF << "TRIP REPORT" << endl << endl;
    outF << "Travel Log:" << endl; 
    outF << "=================" << endl << endl;
    
    outF << "Departed from " << homeCity << " at " << setw(2) << setfill('0') << startHour << ':' << setw(2) << setfill('0') << startMin << '.' << endl;
    outF << "Traveled " << destMiles << " miles to " << destCity << ", arrived at " << endl << setw(2) << setfill('0') << endHour << ':' << setw(2) << setfill('0') << endMin << '.';
    outF << " Travel time, " << fixed << showpoint << setprecision(2) << destTravelTime << " hours." << endl << endl;
    outF << "Departed from " << destCity << " at " << setfill('0') << setw(2) <<homeStartHour << ':' << setw(2) << setfill('0') << homeStartMin << '.' << endl;
    outF << "Traveled " << homeMiles << " miles, arrived at " << setw(2) << setfill('0') << homeEndHour << ':' << setw(2) << setfill('0') << homeEndMin << setfill(' ') << '.' << endl << endl;    
    
    outF << "Trip Statistics:" << endl;
    outF << "=================" << endl << endl;
    outF << right << setw(8) << totalMilesTraveled <<  " = " << "Total miles traveled" << endl;
    outF << right << setw(8) << fixed << showpoint << setprecision(1) << galsUsed << " = Gallons of gas used @ " << mpg << " mpg" << endl;
    outF << "$ "  << right << setw(6) << fixed << showpoint << setprecision(2) << fuelCost << " = " << "Total fuel costs @ $" << fixed << showpoint << setprecision(2) << gasPrice << "/gal" << endl; 
    outF <<  right << setw(8) << fixed << showpoint << setprecision(2) << totalDrivingTime << " = " << "Total travel time (hours)" << endl;
    outF << right << setw(8) << fixed << showpoint << setprecision(2) << avg_Speed << " = " << "Average driving speed (mph)" << endl << endl;
    

      
//-|---------------------------------------------------------------------
//-|  6. Close files.                
//-|---------------------------------------------------------------------    
    
  
inF.close();  
outF.close();
    
  
//-|---------------------------------------------------------------------
//-| Display the copyright notice declaring authorship again.
//-|---------------------------------------------------------------------

  cout << endl << "(c) 2017, dgrant  De'Shon Grant " << endl << endl;
    
return 0;  
}
