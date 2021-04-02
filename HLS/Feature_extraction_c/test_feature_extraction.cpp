#include <string>

#include <fstream>
#include <sstream>
#include <iostream>
#include "variables_declare.h"
#include "Tagging.h"
#include "merging.h"
using namespace std;


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
    
ofstream myfile ("arr_image.txt");
  if (myfile.is_open())
  {
    
    for (int i = 0; i <length; i++)
    {
        for (int j = 0; j < breadth; j++)
        {     

            myfile<<arr_img_in[i][j]<<" ";
    

       }
myfile<<endl;
    } 
    myfile.close();
  }
  else cout << "Unable to open file"; 
 


//cout<<arr_img_in[0][0];
tagging(arr_img_in,arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,arr_final_tags);
cout<<tag_num-1<<endl;
cout<<final_tag_num-1<<endl;

   ofstream myfile2 ("sum_out.txt");
  if (myfile2.is_open())
  {
    
    for (int i = 0; i <200; i++)
    {
       
             myfile2<<arr_sums_y[i]<<","<<arr_sums_x[i]<<","<<arr_sums_weight[i]<<","<<arr_num_pixels[i]<<","<<arr_flags[i];
       
myfile2<<endl;
    } 
    myfile2.close();
  }
  else cout << "Unable to open file";
merging(arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,tag_num,final_tag_num,arr_star_coordinates,num_stars);

cout<<num_stars<<endl;

for (int i=0; i<final_tag_num+num_single_tag_stars;i++){


    cout<<(arr_star_coordinates[i][1]*4.8/1000)<<endl;
}
return 0;
}

