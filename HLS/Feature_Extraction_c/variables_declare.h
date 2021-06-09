// All the varibles are declared here

const int breadth=1024, length=1280; // Dimension of the image
const int Threshold=14; // Threshold intensity
double arr_sums_x[200]={0}; // arr to store sum of x-coordinates of pixels having same tag
double arr_sums_y[200]={0};  // arr to store sum of y-coordinates of pixels having same tag
double arr_sums_weight[200]={0}; // Sum of intensity values of pixels having same tag
int arr_num_pixels[200]={0};     // Number of pixels having same tag
int arr_flags[200]={0};          // to store final tag value associated with each tag
int arr_final_tags[100][50]={0};  //Table containing statistics of num of tags, and its number associated eith each final_tag
double pixel_size=4.8/1000; 
int arr_img_in_add[breadth+1][length+2] = {0};
int arr_tags[breadth+1][length+2]= {0};
int tag_num= 1; //tag_1,,tag_2 num of tags=tag_num
int final_tag_num = 1; //flag1,flag2... num of final_tags=final_tag_num

const int star_max_pixel=150;
const int star_min_pixel=3;
//arrays to sum the values of different tagged regions of the same star
double  arr_tot_sum_x[40]={0}; // update as final_tag_num
double arr_tot_sum_y[40]={0};
double arr_tot_weights[40]={0};
int arr_tot_pixels[40]={0};




int arr_img_in[breadth][length]={0};
float arr_star_coordinates[100][2]={0};
int final_tag_for_merge=0;
int num_single_tag_stars=0;
int num_stars=0;