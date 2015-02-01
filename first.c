/*
 * first.c
 *
 *  Created on: Jan 30, 2015
 *      Author: rahul
 */
#include <stdio.h>
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

}
void tuple(int arr[],int soa, int k)
{
    int a,b,c,d;
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
                                printf("{%d,%d,%d,%d}\n",arr[a],arr[b],arr[c],arr[d]);
                        }

                }

        }

}

