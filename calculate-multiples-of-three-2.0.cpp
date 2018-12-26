#include <iostream>
using namespace std;
int input_digit(string math);
int front_digit(string math, int k, int kk);
int number(int start, int end, string math);
int calculate(int ans_a, int ans_b, int h);
int sum_digit(int total);
int final_sum(int total, int j);
int main() 
{  
  int i=0, A=0, B=0, b=0, b_1=0, math_sym_position[20]={0}, ans[20]={0};
  string sym;
  string math;
  cout << "請輸入算式:";
  cin >> math;
  int input_digit_num = input_digit(math);
  
  //將所有運算符號的位置存入math_sym_position[]中
  //將所有運算符號存入sym[]中
  //計算共有多少個數字(count_math_num)
  while ( A < input_digit_num )
    {
      math_sym_position[i] = front_digit(math , A , input_digit_num);
      sym[i] = math[math_sym_position[i]];
      A = math_sym_position[i] + 1;
      i++;
    }
    
  //將運算的數字變成數值存入ans[]
  int count_math_num = i;
  for(int j = 0; j < count_math_num; j++)
    {
      ans[j] = number(math_sym_position[j], B, math);
      B = math_sym_position[j] + 1;
    }
    
  //先計算乘法和除法
  //將已運算及未運算的數字重新排序存入ans[]
  //將未運算過的符號重新排序存入sym[]
  //最後ans[]和sym[]皆僅剩加法或減法
  for(int n = 0; n < count_math_num - 1; n++)
    {
      if ((int)sym[b] != '+' && (int)sym[b] != '-')
        {
          ans[b] = calculate(ans[b], ans[b+1], (int)sym[b]);
          for(int c = 1 + b; c < count_math_num - b_1; c++)
            {
              ans[c] = ans[c+1];
              sym[c-1] = sym[c];
            }
          b_1++;//共有多少"*"和"/"運算符號
        }
     else
        {
          b++;//共有多少"+"和"-"運算符號
        }
    }
    
  //計算剩下數字的總和  
  int total = ans[0]; 
  for(int m = 0; m < b; m++)
    {
      total = calculate(total, ans[m+1], (int)sym[m]);
    }
    
  //判斷是否為3的倍數    
  int k = sum_digit(total);
  int sum = final_sum(total, k);
  if(sum % 3 == 0)
    {
      cout << "答案是三的倍數";
    }
  else
    {
      cout << "答案不是三的倍數";
    } 
}

//計算總體位數
int input_digit(string math)
  {
    int i = 0;
    while((int)math[i] != 0)
      {
        i++;
      }
    return i;
  }

//計算第一個運算符號前有幾位數
int front_digit(string math, int k,int kk)
  {
    
    while((int)math[k] != '+' && (int)math[k] != '-' && (int)math[k] != '*' && (int)math[k] != '/' && k < kk)
      {
        k++;
      }
    return k;
  }

//計算數字
int number(int start, int end, string math)
  {
    int sum = 0;
    int position = 1;
    for(int z = start - 1; z >= end; z--)
      {
        sum += ((int)math[z] - '0') * position;
        position *= 10;
      }
    return sum;    
  }

//運算
int calculate(int ans_a, int ans_b, int h)
  {
  int total = 0;
  if(h == '+')
    {
      total = ans_a + ans_b;
    }
  if(h == '-')
    {
      total = ans_a - ans_b;
    }    
  if(h == '*')
    {
      total = ans_a * ans_b;
    }    
  if(h == '/')
    {
      total = ans_a / ans_b;
    }
  return total; 
  }

//計算答案位數
int sum_digit(int total)
  {
    int j = 0;
    while(total != 0)
      {
        total /= 10;
        j++;
      }
    return j;
  }

//計算每一位數的加總
int final_sum(int total, int j)
  {
    int sum = 0;
    for(int a = 0; a < j; a++)
      {
        sum += total % 10;
        total /= 10;
      }
    return sum;
  }
