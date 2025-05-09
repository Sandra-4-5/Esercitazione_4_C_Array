#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>


using namespace std;


int main()

{ 
  unsigned int i=0;
    
    double* w= new double[8];
    double* r= new double[8];
    char c;
    double S;
    double V=0;
    double rateOfReturn=0;
   
   
   
    ifstream ifs("data.txt");
    if(ifs.fail()){cerr<<"ifs open failed"<<endl;
                   return 1;}


    ifs>>c>>c>>S;

    unsigned int n;

    ifs>>c>>c>>n;
    
    ifs>>c>>c>>c;  
    
    
    while(i<n){ 
      ifs>>w[i];
      ifs>> c;
      ifs>>r[i];

     rateOfReturn+=w[i]*r[i];
     V=(1+rateOfReturn)*S;
     
     i++;
    }

  
    cout << "S = "<<fixed << setprecision(2)<<S<< ", n = " << n << endl;
    cout << "w = [ ";
    for ( i = 0; i < n; i++) cout << w[i] << " ";
    cout << "]"<<endl;

    cout << "r = [ ";
    for ( i = 0; i < n; i++) cout << r[i] << " ";
    cout << "]"<<endl;

    cout << "Rate of return of the portfolio: " << rateOfReturn <<endl;
    cout<<"V: "<<V<<fixed << setprecision(2)<<endl;




    ofstream ofs ("result.txt");

     ofs<<"S="<<S<<fixed<<setprecision(2)<<",";
     ofs<<"n="<<n<<endl;
     ofs<<"w=[";
     for(unsigned int j = 0; j < n; j++){
      ofs << w[j] << " ";
  }
  ofs<<"]"<<endl;

  
     ofs<<"r=[";
     for(unsigned int j = 0; j < n; j++){
      ofs << r[j] << " ";
  }
  ofs<<"]"<<endl;


  ofs << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn<< endl;
  ofs << "V: " << setprecision(2) << V << endl;

 
  ofs.close(); 

     delete [] w;
     delete [] r;
  
    
    
    
    return 0;


}

