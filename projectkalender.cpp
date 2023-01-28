#include <iostream>
#include <conio.h>
#include <iomanip> 
#include <time.h> 


using namespace std;
 
void printkalender(int tahun)
{
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	int tanggal[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
	string listbulan[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }; 
                       
    
    cout<<" ==================================="<<endl;
    cout<<"           kalender - "<<tahun<<endl;
    cout<<" ==================================="<<endl<<endl;
	
    int hari; 
    int saat_ini; 
   
   	int y = tahun - 1;
    saat_ini = ( y + y/4 - y/100 + y/400 + t[0] + 1) % 7;
   
    for (int i = 0; i < 12; i++) 
    { 
    	if( i==1 )
			if (tahun % 400 == 0 || (tahun % 4 == 0 && tahun % 100 != 0)) 
				hari = 29;
			else	
				hari = tanggal[i];
		else
			hari = tanggal[i];
     
  		cout<<endl<<"  ------------"<<listbulan[i]<<"------------- " <<endl;   
  
        cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat"<<endl; 
  
        int k; 
        for (k = 0; k < saat_ini; k++) 
            cout<<"     "; 
  
        for (int j = 1; j <= hari; j++) 
        {
        	k++;
            cout<<setw(5)<<j;
            if (k > 6) 
            { 
                k = 0; 
                cout<<endl; 
            } 
        } 
        
		if (k)
			cout<<endl; 

        saat_ini = k; 
    }
  
    return; 
}

int main() {
	system("cls");

 	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	
	int tahun = 1900 + local_time->tm_year; 
	char option;
	
	do{
		system("cls");
		printkalender(tahun);
		
		cout<<endl<<endl;
		cout<<"Press "<<endl;
		cout<<"- n untuk tahun selanjutnya"<<endl;
		cout<<"- p untuk tahun sebelumnya"<<endl;
		cout<<"- e untuk keluar"<<endl;
		option = getche();
		switch(option){
			case 'n':
				tahun++;
				break;
			case 'p':
				tahun--;
				break;
		}
			
	}while(option!='e' && option!='E');	 	
 	
    return 0;
}
