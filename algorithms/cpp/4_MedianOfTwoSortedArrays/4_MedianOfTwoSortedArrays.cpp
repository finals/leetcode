#include <iostream>
#include <vector>

using namespace std;

class Solution {  
public:  
    /** 
     * @param A: An integer array. 
     * @param B: An integer array. 
     * @return: a double whose format is *.5 or *.0 
     */  
    double findMedianSortedArrays(vector<int> A, vector<int> B) {  
      int m=A.size(),n=B.size();  
      int s=m+n;  
      if(s&0x01)//真为奇数  
          return findKth(A,B,0,0,m,n,s/2+1);  
      else  
      {  
          double a=findKth(A,B,0,0,m,n,s/2);  
          double b=findKth(A,B,0,0,m,n,s/2+1);  
          return (a+b)/2;  
      }  
         // return (findKth(A,B,0,0,m,n,s/2)+findKth(A,B,0,0,m,n,s/2+1))/2;  
  
    }  
private:  
    double findKth(vector<int> A, vector<int> B,int start1,int start2,int m,int n,int k)//start1，start2代表每个vector起始的下标;m,n代表各vector剩余的元素个数  
    {  
        //保证A是较短的数组,因为会出现数组长度小于k/2的情况，所以根据较小数组来定另一个数组  
        if(m>n)//m代表A的长度，n代表B的长度  
            return findKth(B,A,start2,start1,n,m,k);  
        if(m==0)//m=0即代表数组arr1中已经没有元素了，所以中位数从B中找  
            return B[start2+k-1];//下标加start2的原因是不一定是从下标0开始，可能下标0到start2的元素已经被抛弃  
        if(k==1)  
            return min(A[start1],B[start2]);  
        int x=min(k/2,m),y=k-x;//记录两组中位数下标  
        if(A[start1+x-1]<B[start2+y-1])  
            return findKth(A,B,start1+x,start2,m-x,n,k-x);//start1+x表示舍弃x个不可能的元素，m-x表示将x个元素  
                                                          //剔除掉数组，k-x表示这x个元素已经被剔除，接下来中位数表示第k-x个元素  
        else  
            if(A[start1+x-1]>B[start2+y-1])  
                return findKth(A,B,start1,start2+y,m,n-y,k-y);//<span style="font-family:Arial, Helvetica, sans-serif;">start2+y表示舍弃y前的元素</span>  
  
            else  
                return A[start1+x-1];  
  
    }//本题舍弃的均为各自数组所选下标之前的元素  
};  


int main(void)
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(3);

    nums2.push_back(2);
    //nums2.push_back(4);
   
    int mid = s.findMedianSortedArrays(nums1, nums2);

    cout << mid << endl;
    return 0;
}

