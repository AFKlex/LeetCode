#include<iostream>
#include<vector>

// I have had the same problem i should avoid doing a loop in loop. 
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxValue = 0; 
        std::vector<int>::iterator p_left = height.begin();
        std::vector<int>::iterator p_right = height.end()-1;

        while (p_left < p_right){
            int distance =  std::distance(height.begin(), p_right) - std::distance(height.begin(), p_left);
            int smaller_hight = 0;

             if(*p_left < *p_right){
                    smaller_hight = *p_left;
                }else{
                    smaller_hight = *p_right;
                }

                int area = smaller_hight * distance;
                
                if(maxValue < area){
                    maxValue = area;
                }

            if(*p_left > *p_right){
                p_right--;
            }else{
                p_left++;
            }

        }
        

        // for(int i=0; i<height.size(); i++){
        //     int h_left = height[i]; 




        //     for(int j=height.size()-1; j>i; j--){
        //         int h_right = height[j];
        //         int distance = j-i; 
        //         int smaller_hight = 0; 
                
        //         if(h_left > h_right){
        //             smaller_hight = h_right;
        //         }else{
        //             smaller_hight = h_left;
        //         }

        //         int area = smaller_hight * distance; 

        //         if(maxValue < area){
        //             maxValue = area;
        //         }

        //     }

            

        // }

    return maxValue;
    }
};

int main(){
    Solution a; 
    std::vector<int> input= {1,8,6,2,5,4,8,3,7};
    int maxArea = a.maxArea(input);
    std::cout << "The max Area is "<< maxArea << std::endl; 
    return 0; 
}