#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>

int main() {

    double S=1000.00, rateOfReturn , finalValue;
    int n=8;
    std::vector<double> w, r;
   

   
    std::ifstream ifs("data.txt");
    if (!ifs) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    ifs >> S >> n; 
        
    
    w.resize(n);
    r.resize(n);

    for (int i = 0; i < n; i++) {
        ifs >> w[i] >> r[i]; 
        rateOfReturn += w[i] * r[i];
    }
    ifs.close();


    // Calcolo del finalValue
    finalValue = (1 + rateOfReturn) * S;

    
    std::cout << "S = " << std::fixed << std::setprecision(2) << S << ", n = " << n << std::endl;
    std::cout << "w = [ ";
for (int i = 0; i < n; ++i) {
        std::cout << w[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "r = [ ";
    for (int i = 0; i < n; ++i) {
        std::cout << r[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "The rate of return is : " << std::fixed << std::setprecision(4) << rateOfReturn << std::endl;
    std::cout << "V : " << finalValue << std::endl;

    
     std::ofstream ofs("result.txt");
     ofs<< "S = " << std::fixed << std::setprecision(2) << S << ", n = " << n << std::endl;
     ofs << "w = [ ";
     for (double value : w) ofs << value << " ";
     ofs << "]" << std::endl;
     ofs << "r = [ ";
     for (double value : r) ofs << value << " ";
     ofs<< "]" << std::endl;
     ofs << "The rate of return of the portfolio  : " << std::fixed << std::setprecision(4) << rateOfReturn << std::endl;
     ofs<< "V : " << finalValue << std::endl;
     ofs.close();
 
     return 0;
 }
