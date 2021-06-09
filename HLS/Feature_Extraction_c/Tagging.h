



    // Indices corresponding to tag and final_tag are tag-1 and final_tag-1 eg, to get statistics of tag_m, arr_sums_x m-1]
 int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}



void tagging(int arr_img_in[breadth][length],double arr_sums_x[200],double arr_sums_y[200],double arr_sums_weight[200],int arr_num_pixels[200],int arr_flags[200],int arr_final_tags[100][50])
{
     // modified img array for processing consisting of original img padded with zeroes to top,left and right

    for(int i=1; i<breadth+1; i++)
    {
        for(int j=1; j<length+1; j++)
        {
            arr_img_in_add[i][j]=arr_img_in[i-1][j-1];

        }
    }
    
    
    int tag,final_tag,intensity_val,tag_left,tag_above,intensity_left,intensity_above,flag_above,flag_left;
    for(int i=1; i<breadth+1; i++)
    {
        for(int j=1; j<length+1; j++)
        {
            intensity_val= arr_img_in_add[i][j];
            if(intensity_val> Threshold)
            {
                intensity_left=arr_img_in_add[i][j-1];
                intensity_above=arr_img_in_add[i-1][j];
                //checking the pixel to the left
                if(intensity_left> Threshold)
                {
                    tag_left=arr_tags[i][j-1];
                    //checking above pixel
                    if(intensity_above>Threshold)
                    {
                        tag_above=arr_tags[i-1][j];
                        //checking if the above and left pixels have same tag
                        if(tag_left==tag_above)
                        {
                            tag=tag_above; //tagging the pixel with the tag of above pixel
                            arr_tags[i][j]=tag;
                            arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                            arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                            arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                            arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                            arr_flags[tag-1]=arr_flags[tag-1]+0;
                        }
                        else
                        {
                            // if above and left pixels dont have same tag --both bright

                            //checking flags

                            if(arr_flags[tag_above-1]>0)
                            {
                                //flag of above tag has some value
                                flag_above=arr_flags[tag_above-1];
                                if(arr_flags[tag_left-1]>0)
                                {
                                    //flags of both of the left and above tag have some value
                                    flag_left=arr_flags[tag_left-1];

                                    if(flag_above==flag_left)
                                    {
                                        //both have same flag
                                        tag=tag_above;
                                        arr_tags[i][j]=tag;

                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;
                                    }

                                    else
                                    {
                                        // have different flags
                                        tag=tag_above;
                                        arr_tags[i][j]=tag;

                                       
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                                        //merging data : Adding large_flag data to small_flag_data
                                       int large_flag=max(flag_left,flag_above);
                                       int  small_flag=min(flag_left,flag_above);
                                       int  existing_tags_num=arr_final_tags[small_flag-1][0]; //number of tags for corresponding flag
                                        int tags_to_add= arr_final_tags[large_flag-1][0]; //number of tags to be added in small_tag row
                                        for(int iter=1; iter<= tags_to_add; iter++)
                                        {
                                            arr_final_tags[small_flag-1][existing_tags_num+iter]=arr_final_tags[large_flag-1][iter];
                                            arr_flags[arr_final_tags[large_flag-1][iter]]=small_flag;
                                            arr_final_tags[large_flag-1][iter]= 0;

                                        }
                                        arr_final_tags[large_flag-1][0]=0;
                                        arr_final_tags[small_flag-1][0]=existing_tags_num+tags_to_add;

                                    }
                                }
                                else
                                {
                                    //if only above tag has a flag
                                    tag=tag_above;
                                    arr_tags[i][j]=tag;

                                    
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                                    final_tag=arr_flags[tag_above-1];
                                    arr_flags[tag_left-1]=final_tag;
                                    arr_final_tags[final_tag-1][arr_final_tags[final_tag-1][0]+1]=tag_left;
                                    arr_final_tags[final_tag-1][0]=arr_final_tags[final_tag-1][0]+1;
                                }

                            }

                            else
                            {
                                //both tags are bright  with different tags and above tag has no flag
                                if(arr_flags[tag_left]>0)
                                {
                                    //left tag has a flag
                                    tag=tag_above;
                                    arr_tags[i][j]=tag;

                                    
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                                    final_tag=arr_flags[tag_left-1];
                                    arr_flags[tag_above-1]=final_tag;
                                    arr_final_tags[final_tag-1] [arr_final_tags[final_tag-1][0]+1]=tag_above;

                                }
                                else
                                {
                                    // both tags don't have flags
                                    tag=tag_above;
                                    arr_tags[i][j]=tag;

                                    
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                                    final_tag=final_tag_num; //generating new flag
                                    arr_flags[tag_above-1]=final_tag;
                                    arr_flags[tag_left-1]=final_tag;
                                    arr_final_tags[final_tag-1][1]=tag_above;
                                    arr_final_tags[final_tag-1][2]=tag_left;
                                    arr_final_tags[final_tag-1][0]=2;
                                    final_tag_num++;
                                }

                            }

                        }


                    }

                    else
                    {
                        // left pixel is bright and Above pixel is dark
                        tag=tag_left;
                        arr_tags[i][j]=tag;

                       
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                    }
                }

                else
                {
                    //left pixel is dark
                    if(intensity_above>Threshold)
                    {
                        //left pixel is dark but above pixel is bright
                        tag_above=arr_tags[i-1][j];;

                        tag=tag_above;
                        arr_tags[i][j]=tag;

                        
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;


                    }
                    else
                    {
                        //Left and above pixels are both dark
                        if((arr_img_in_add[i][j+1]> Threshold) &&(arr_img_in_add[i-1][j+1]>Threshold))
                        {
                            //Both of the pixel to the right and right-above are bright
                            tag=arr_tags[i-1][j+1];
                            arr_tags[i][j]=tag;

                            
                                        arr_sums_y[tag-1]=arr_sums_y[tag-1]+intensity_val*(i);
                                        arr_sums_x[tag-1]=arr_sums_x[tag-1]+intensity_val*(j);
                                        arr_sums_weight[tag-1]=arr_sums_weight[tag-1]+intensity_val;
                                        arr_num_pixels[tag-1]=arr_num_pixels[tag-1]+1;
                                        arr_flags[tag-1]=arr_flags[tag-1]+0;

                        }
                        else
                        {
                            //None of them are bright
                            tag=tag_num; //generate a new tag
                            arr_tags[i][j]=tag;

                            arr_sums_y[tag-1]=intensity_val*(i);
                            arr_sums_x[tag-1]=intensity_val*(j);
                            arr_sums_weight[tag-1]=intensity_val;
                            arr_num_pixels[tag-1]=1;
                            arr_flags[tag-1]=0;

                            tag_num++;

                        }

                    }
                }



            }

        }
    }
}
