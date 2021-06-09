#include <string>

#include <fstream>
#include <sstream>
#include <iostream>
#include "FE.cpp"
using namespace std;
void FE(int arr_img_in[breadth][length],float arr_star_coordinates[][2],int &num_stars);


int main()
{   




    ifstream file("Image_1.txt");

string   line;
int row_count=0;
int col_count=0;
    // Read one line at a time into the variable line:
    while(getline(file, line))
    {
       
        stringstream  lineStream(line);

        string value;
       
        while(getline(lineStream,value,','))

        {   
              arr_img_in[row_count][col_count]=stoi(value);
             
             col_count++;
           
        }
            
        
        
        
        col_count=0;
        row_count++;
    } 
    

 


FE(arr_img_in,arr_star_coordinates,num_stars);

//tagging(arr_img_in,arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,arr_final_tags);
//merging(arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,tag_num,final_tag_num,arr_star_coordinates,num_stars);
cout<<tag_num<<endl;
cout<<num_stars<<endl;
cout<<final_tag_num-1<<endl;
for (int i=0; i<final_tag_num+num_single_tag_stars;i++){


    cout<<(arr_star_coordinates[i][1]*pixel_size)<<endl;  //  multiplied by pixel_size
}
return 0;
}

