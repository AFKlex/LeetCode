#include<iostream>
#include<string>
#include<map>
#include <cmath>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {

        std::string result=""; 

        std::map<int,char> colums; 
        colums[0]= 'Z';
        colums[1] = 'A'; 
        colums[2] = 'B'; 
        colums[3] = 'C';
        colums[4] = 'D'; 
        colums[5] = 'E'; 
        colums[6] = 'F'; 
        colums[7] = 'G'; 
        colums[8] = 'H'; 
        colums[9] = 'I'; 
        colums[10] = 'J'; 
        colums[11] = 'K'; 
        colums[12] = 'L'; 
        colums[13] = 'M'; 
        colums[14] = 'N'; 
        colums[15] = 'O'; 
        colums[16] = 'P'; 
        colums[17] = 'Q'; 
        colums[18] = 'R'; 
        colums[19] = 'S'; 
        colums[20] = 'T'; 
        colums[21] = 'U'; 
        colums[22] = 'V'; 
        colums[23] = 'W'; 
        colums[24] = 'X'; 
        colums[25] = 'Y'; 
        colums[26] = 'Z';
          
    
        int biggest_index=0;
        while (pow(26,biggest_index+1) < columnNumber){

            
            std::cout << biggest_index << std::endl; 
            biggest_index++; 
        
        }

        std::cout << "Biggets Index: " << biggest_index << std::endl; 

        int new_colum;
        int index_value; 
        for(int i =biggest_index; i >= 0; i--){
            //std::cout << "I: " << i << std::endl; 

            //if( columnNumber % 26 != 0){
                index_value = columnNumber/ pow(26,i);

             
                result += colums[index_value];

                columnNumber -= (index_value * pow(26,i)); 
            
            
            
            //}


            
            

            

            std::cout << "Index Value: " << index_value << std::endl; 
            
            //


        }


        


         return result;

    }

   
};

int main(){

    Solution a; 
    //int input; 
    //std::cout << "Pleas input a Number: "; 
    //std::cin >> input; 

    for (int i=700; i<705; i++){
        std::string result = a.convertToTitle(i); 

        std::cout <<"I: "<< i << " The result is: " << result << "\n"<< std::endl;

    }    

        

     

    return 0; 
}

