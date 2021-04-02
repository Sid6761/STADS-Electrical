const int length=1024, breadth=1280;
const int Threshold=15;
double arr_sums_x[200]={0};
double arr_sums_y[200]={0};
double arr_sums_weight[200]={0};
int arr_num_pixels[200]={0};
int arr_flags[200]={0};
int arr_final_tags[100][50]={0};

int arr_img_in_add[length+1][breadth+2] = {0};
int arr_tags[length+1][breadth+2]= {0};
int tag_num= 1; //tag_1,tag_2.. num of tags=tag_num-1
int final_tag_num = 1; //flag1,flag2... num of final_tags=final_tag_num-1

const int star_max_pixel=150;
const int star_min_pixel=3;
//arrays to sum the values of different tagged regions of the same star
double  arr_tot_sum_x[40]={0}; // update as final_tag_num
double arr_tot_sum_y[40]={0};
double arr_tot_weights[40]={0};
int arr_tot_pixels[40]={0};




int arr_img_in[length][breadth]={0};
float arr_star_coordinates[100][2]={0};
int final_tag_for_merge=0;
int num_single_tag_stars=0;
int num_stars=0;