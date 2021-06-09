


#include<iostream>
using namespace std;
// Function to merge sum rows of different tags with same final_tag
void update_sum(int final_tag_for_merge){

  int tags_to_be_merged;
tags_to_be_merged= arr_final_tags[final_tag_for_merge-1][0] ;//adjustment of indices


for(int i_merge_rows=1;i_merge_rows<=tags_to_be_merged;i_merge_rows++){
// arr_tot_sum has merged data at index corresponding final_tag_for_merge-1
  arr_tot_sum_y[final_tag_for_merge-1]=arr_tot_sum_y[final_tag_for_merge-1]+arr_sums_y[arr_final_tags[final_tag_for_merge-1][i_merge_rows]-1];
  arr_tot_sum_x[final_tag_for_merge-1]=arr_tot_sum_x[final_tag_for_merge-1]+arr_sums_x[arr_final_tags[final_tag_for_merge-1][i_merge_rows]-1];
  arr_tot_weights[final_tag_for_merge-1]=arr_tot_weights[final_tag_for_merge-1]+arr_sums_weight[arr_final_tags[final_tag_for_merge-1][i_merge_rows]-1];
  arr_tot_pixels[final_tag_for_merge-1]=arr_tot_pixels[final_tag_for_merge-1]+arr_num_pixels[arr_final_tags[final_tag_for_merge-1][i_merge_rows]-1];
}

}


//variables for in function purpose


void merging(double arr_sums_x[200],double arr_sums_y[200],double arr_sums_weight[200],int arr_num_pixels[200],int arr_flags[200],int &tag_num, int &final_tag_num,float arr_star_coordinates[][2], int &num_stars)
{
//initializing variables 
  tag_num=tag_num-1;
  final_tag_num=final_tag_num-1;
  num_single_tag_stars=0;

//loop to find single tagged regions and their position
  for(int i_single_tag=0;i_single_tag<tag_num;i_single_tag++){
	//if region is singly tagged
    if(arr_flags[i_single_tag]==0){
   //Check if no. of pixels are within range
     if((arr_num_pixels[i_single_tag]<=star_min_pixel) || (arr_num_pixels[i_single_tag]>=star_max_pixel)){continue;}
// update number of stars
     num_single_tag_stars=num_single_tag_stars+1;
     num_stars=num_stars+1;
//update star coordinates
     arr_star_coordinates[final_tag_num+num_single_tag_stars-1][1]= -1*(((arr_sums_y[i_single_tag]/arr_sums_weight[i_single_tag])-1)-((breadth/2)-0.5));
     arr_star_coordinates[final_tag_num+num_single_tag_stars-1][0]= (((arr_sums_x[i_single_tag]/arr_sums_weight[i_single_tag])-1)-((length/2)-0.5));

   }
  //If the region is multitagged
   else{
    final_tag_for_merge=arr_flags[i_single_tag];
    update_sum(final_tag_for_merge);
  }

}

// loop for finding centroids of multi tagged region
for(int i_multi_tag=0;i_multi_tag<final_tag_num;i_multi_tag++){
  if((arr_tot_pixels[i_multi_tag]<=star_min_pixel) || (arr_tot_pixels[i_multi_tag]>=star_max_pixel) ) { continue;}

//update no. of stars

  num_stars=num_stars+1;
  
  //update star coordinates
  arr_star_coordinates[i_multi_tag][1]=-1*(((arr_tot_sum_y[i_multi_tag]/arr_tot_weights[i_multi_tag])-1)-((breadth/2)-0.5));
  arr_star_coordinates[i_multi_tag][0]=(((arr_tot_sum_x[i_multi_tag]/arr_tot_weights[i_multi_tag])-1)-((length/2)-0.5));

}

}

