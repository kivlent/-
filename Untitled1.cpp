#include <iostream>
#include <algorithm>
using namespace std;
 
int main ()
{
	int weather[31]={0,1,1,0,2,0,1,2,0,1,1,2,1,0,1,1,1,2,2,1,1,0,0,1,0,2,1,0,0,1,1};
	int cw[3]={5,8,10};
	int cf[3]={7,6,8};
	int pw=5;
	int pf=10;
	int map[11]={1,25,26,27,24,23,21,9,15,14,12};
	int neibgo[11][2]={{1},{2,4},{3},{},{5},{6},{3,7},{6,8},{7,9},{8,10},{9}};
	int neifrom[11][2]={{},{0},{1},{2,6},{1},{4},{5,7},{6,8},{7,9},{8,10},{9}};
	int vlg[11]={0,0,0,0,0,0,0,0,1,0,0};
	int mine[11]={0,0,0,0,0,0,0,0,0,0,1};
	int start=0;
	int end=3;
	
	int dp[31][11][401][601]={0};
	
	for(int w=0;w<=400;++w)
	{
		for(int f=0;f<=((1200 - 3 * w) /2);++f)
		{
			dp[0][0][w][f] = 10000 - pw * w - pf * f;
		}
	}
	
	
	for(int k=0;k<=29;++k)
	{
		if(weather[k+1] == 2)
		{
			for(int j=0;j<=10;++j)
			{
				if(vlg[j] == 1)
				{
				 for(int w=0;w<=400;++w)
				    {
				  	for( int f=0;f<=(1200 - 3 * w) /2+1;++f)
					{
						if(dp[k][j][w][f] > 0)
						{
							int money = dp[k][j][w][f];
							int maxf = 601;
							for(int ww=w;ww<=400;++ww)
							{
								for(int ff=f;ff<=min(maxf, int((1200 - 3 * ww)) / 2) + 1;++ff)
								{
									if((ww - cw[2]) >= 0 and (ff - cf[2]) >= 0)
									{
										if(dp[k+1][j][ww - cw[2]][ff - cf[2]] >= dp[k][j][w][f] - 2 * pw * (ww - w) - 2 * pf * (ff - f) or 2 * pw * (ww - w) + 2 * pf * (ff - f) > money or 3 * ww + 2 * ff > 1200)
										{
											maxf=ff;
										}
										else
										{
											dp[k + 1][j][ww - cw[2]][ff - cf[2]] = dp[k][j][w][f] - 2 * pw * (ww - w) - 2 * pf * (ff - f);
										}
									}
								}
							}
						}
					}
		        	}  
			    }
				else
				{
					if(mine[j] == 1)
					{
						 for(int w=0;w<=400;++w)
						 {
						 	for( int f=0;f<=((1200 - 3 * w) /2);++f)
						 	{
						 		if(dp[k][j][w][f] > 0)
						 		{
						 			if(w - 3 * cw[2] >= 0 and f - 3 * cf[2] >= 0)
						 			{
						 				dp[k+1][j][w - 3 * cw[2]][f - 3 * cf[2]] = max(dp[k][j][w][f] + 1000, dp[k+1][j][w - 3 * cw[2]][f - 3 * cf[2]]);
									 }
									if(w - cw[2] >= 0 and f - cf[2] >= 0)
									{
										dp[k+1][j][w - cw[2]][f - cf[2]] = dp[k][j][w][f];
									}
								 }
							 }
						 }
					}
					
					else
					{
					for(int w=0;w<=400;++w)
					{
							for( int f=0;f<=((1200 - 3 * w) /2);++f)
							{
								if(dp[k][j][w][f] > 0)
								{
									if(w - cw[2] >= 0 and f - cf[2] >= 0 and dp[k][j][w][f] >= 0)
									{
										 dp[k+1][j][w - cw[2]][f - cf[2]] = dp[k][j][w][f];
									}
								}
							}
						}	
					}
						 }	 	
				}
			}
			else
			{
				for(int j=0;j<=10;++j)
				{
					if( vlg[j] == 1)
					{
					 for(int w=0;w<=400;++w)
					 {
					 		for( int f=0;f<=((1200 - 3 * w) /2);++f)
					 		{
					 			if(dp[k][j][w][f] > 0)
					 			{
					 				int money = dp[k][j][w][f];
					 				int maxf=601;
					 				for(int ww=w;ww<=400;++ww)
					 				{
					 					for(int ff=f;ff<=min(maxf, int((1200 - 3 * ww)) / 2) + 1;++ff)
					 					{
					 						if((ww - cw[weather[k+1]]) >= 0 and (ff - cf[weather[k+1]]) >= 0)
					 						{
					 							{int i;
										int h[i];
											for( i=0;i<=22;++i)
											{
												for(int m=0;m<=10;++m)
												
												{for(int n=0;n<=1;++n)
												{
												h[i]=neibgo[m][n];
											    if(dp[k + 1][i][ww - cw[weather[k+1]]][ff - cf[weather[k+1]]] >= dp[k][j][w][f] - 2 * pw * (ww - w) - 2 * pf * (ff - f) or 2 * pw * (ww - w) + 2 * pf * (ff - f) > money or 3 * ww + 2 * ff > 1200)
											    {
											    	maxf=ff;
												}
												else
												{
												dp[k + 1][i][ww - cw[weather[k+1]]][ff - cf[weather[k+1]]] = dp[k][j][w][f] - 2 * pw * (ww - w) - 2 * pf * (ff - f);	
												}
											}
											}
											}
										}
											 }
										 }
									 }
								 }
								 //
							 }
					 }
					}
					else
					{
						if(mine[j] == 1)
						{
							for(int w=0;w<=400;++w)
							{
								for( int f=0;f<=((1200 - 3 * w) /2);++f)
								{
									if(dp[k][j][w][f] > 0)
									{
										if(w - 2 * cw[weather[k+1]] >= 0 and f - 2 * cf[weather[k+1]] >= 0)
										{int i;
										int h[i];
											for( i=0;i<=22;++i)
											{
												for(int m=0;m<=10;++m)
												
												{for(int n=0;n<=1;++n)
												{
												h[i]=neibgo[m][n];
												dp[k + 1][h[i]][w - 2 * cw[weather[k + 1]]][f - 2 * cf[weather[k + 1]]] = max(dp[k + 1][h[i]][w - 2 * cw[weather[k + 1]]][f - 2 * cf[weather[k + 1]]], dp[k][j][w][f]);
											}
											}
											}
										}
										if(w - 3 * cw[weather[k+1]] >= 0 and f - 3 * cf[weather[k+1]] >= 0)
										{
											dp[k+1][j][w - 3 * cw[weather[k+1]]][f - 3 * cf[weather[k+1]]] = max(dp[k+1][j][w - 3 * cw[weather[k+1]]][f - 3 * cf[weather[k+1]]],dp[k][j][w][f] + 1000);
										}
									}
								}
							}
						}
						else
						{
							for(int w=0;w<=400;++w)
							{
								for( int f=0;f<=((1200 - 3 * w) /2);++f)
								{
									if(dp[k][j][w][f] > 0)
									{
										if(w - 2 * cw[weather[k+1]] >= 0 and f - 2 * cf[weather[k+1]] >= 0)
										{int i;
											int h[i];
										for(int i =0;i<=22;++i)
										{
											for(int m=0;m<=10;++m)
											
											{for(int n=0;n<=1;++n)
											
											
											{
											h[i]= neibgo[m][n];
											dp[k + 1][h[i]][w - 2 * cw[weather[k + 1]]][f - 2 * cf[weather[k + 1]]] = max(dp[k + 1][h[i]][w - 2 * cw[weather[k + 1]]][f - 2 * cf[weather[k + 1]]], dp[k][j][w][f]);
										}
												
											}	
										}
									}
								}
							}
						}
					}
				}
			}
		}
	int obj=0;
	for(int k=1;k<=30;++k)
	{
		if(dp[k][3][0][0] >= obj)
		{
			obj = dp[k][3][0][0];
		}
	}
	cout<<obj<<endl;
	return 0;
	}






















	
} 
