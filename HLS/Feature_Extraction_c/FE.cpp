// This program integrates Tagging and merging both blocks together in a single function
#include<stdio.h>
#include "variables_declare.h"
#include"Tagging.h"
#include "merging.h"
void tagging(int arr_img_in[breadth][length],double arr_sums_x[200],double arr_sums_y[200],double arr_sums_weight[200],int arr_num_pixels[200],int arr_flags[200],int arr_final_tags[100][50]);
void merging(double arr_sums_x[200],double arr_sums_y[200],double arr_sums_weight[200],int arr_num_pixels[200],int arr_flags[200],int &tag_num, int &final_tag_num,float arr_star_coordinates[][2], int &num_stars);

void FE(int arr_img_in[breadth][length],float arr_star_coordinates[][2],int &num_stars)
{
	tagging(arr_img_in,arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,arr_final_tags);
	merging(arr_sums_x,arr_sums_y,arr_sums_weight,arr_num_pixels,arr_flags,tag_num,final_tag_num,arr_star_coordinates,num_stars);


}
 