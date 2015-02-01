/*! \mainpage Assignment 3
 *
 * \section intro_sec Introduction
 *
 * This documentation consists of code documentation
 * for the problem statement to find 4 tuple from
 * a given set satisfyig a linear equation.It also 
 * documents various cpu utilisation time and memory space
 * depending upon changing optimisation levels in gcc.
 *
 * \section compare_sec Comparisons
 * This comparison is base on a test case of set
 * containing number 1 to 100 and value of k as 50.
 * <table border="1" style="width:100%">
 * <tr>
 *   <th>Optimization level</th>
 *   <th>CPU time (in sec)</th>		
 *   <th>Memory (in Kb)</th>
 * </tr>
 * <tr>
 *   <td>O0</td>
 *   <td>5.08</td>		
 *   <td>13</td>
 * </tr>
 * <tr>
 *   <td>O1</td>
 *   <td>1.85</td>		
 *   <td>8.9</td>
 * </tr>
 * <tr>
 *   <td>O2</td>
 *   <td>1.99</td>		
 *   <td>8.9</td>
 * </tr>
 * <tr>
 *   <td>O3</td>
 *   <td>2.01</td>		
 *   <td>8.9</td>
 * </tr>
 * <tr>
 *   <td>Ofast</td>
 *   <td>2.01</td>		
 *   <td>13</td>
 * </tr>
 * <tr>
 *   <td>Os</td>
 *   <td>2.28</td>		
 *   <td>8.9</td>
 * </tr>
 * </table>
 */
/** @file final.c
 *  @brief Assignment 3.
 *
 *  This file contains the code for implementating following problem.
 *  Given a set Sand a number k find all 4 tuples a,b,c,d 
 *  such that a+b+c*d<=k.The implementation is done using a function
 *  tuple.It consist of a  2 d array aux which is
 *  used to store and print the results
 *  
 *  @author Rahul Goyal
 *  
 *  @bug Segmentation fault if number of solutions greater than range of unsigned long int(4294967295).
 */
#include <stdio.h>
/** @brief Main program.
 *
 *  Number of elements in the set, set and value of k are taken as input from user.
 *  Funstion tupple is called.
 *
 *  @return Void
 */
int main()
{
    int soa,i,k;
    printf("Enter the size of array:\t");
    scanf("%d",&soa);
    int arr[soa];
    printf("Enter the elements of array seperated by a comma:\n");
    for(i=0; i<soa; i++)
    {
        scanf("%d,",&arr[i]);
    }
    printf("Enter the value of k:\t");
    scanf("%d",&k);
    tuple(arr,soa,k);
    return 0;

}
/** @brief Prints all the solutions to the problem.
 *
 *  It first checks the number of solutions created.
 *  Then allots a array aux to store the solutions created.
 *  This is done with a time complexity of 'n P 4'. Then
 *  it checks for the repeated solutions in aux array and
 *  eliminates them.
 *
 *  @param arr[] The set that is given.
 *  @param soa Size of the set.
 *  @param k Value of k in inequality
 *  @return Void
 */
void tuple(int arr[],int soa, int k)
{
    int a,b,c,d,nos=0;
    unsigned long int i =0,j,g,l,m;
    for(a=0; a<soa; a++)
        for(b=0; b<soa; b++)
        {
            if(b==a)
                continue;
            else
                for(c=0; c<soa; c++)
                {
                    if(c==a || c==b)
                        continue;
                    else
                        for(d=0; d<soa; d++)
                        {
                            if(d==a || d==b || d==c)
                                continue;
                            else if((arr[a]+arr[b]+arr[c]*arr[d]) <= k)
                                i++;
                        }

                }

        }
    int aux[i][4];
    j =0;
    for(a=0; a<soa; a++)
        for(b=0; b<soa; b++)
        {
            if(b==a)
                continue;
            else
                for(c=0; c<soa; c++)
                {
                    if(c==a || c==b)
                        continue;
                    else
                        for(d=0; d<soa; d++)
                        {
                            if(d==a || d==b || d==c)
                                continue;
                            else if((arr[a]+arr[b]+arr[c]*arr[d]) <= k)
                            {   aux[j][0] = arr[a];
                                aux[j][1] = arr[b];
                                aux[j][2] = arr[c];
                                aux[j][3] = arr[d];
                                j++;
                            }
                        }

                }

        }
    for(g=0; g<i-1; g++)
        for(l=g+1; l<i; l++)
            if(aux[l][0]==aux[g][0] && aux[l][1]==aux[g][1] && aux[l][2]==aux[g][2] && aux[l][3]==aux[g][3])
            {
                aux[g][0]= 0;
                aux[g][1]= 0;
                aux[g][2]= 0;
                aux[g][3]= 0;
                break;
            }
    for(m=0; m<i; m++)
    {
        if(aux[m][0]==0 && aux[m][1]==0 && aux[m][2]==0 && aux[m][3]==0)
            continue;
        else {
            printf("{%d,%d,%d,%d}\n",aux[m][0],aux[m][1],aux[m][2],aux[m][3]);
            nos++;
        }

    }
    printf("number of soluns :\t%d",nos);
}



