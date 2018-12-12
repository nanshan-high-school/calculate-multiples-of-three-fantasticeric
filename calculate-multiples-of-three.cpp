#include <iostream>
using namespace std;
int input_digit(string math);
int front_digit(string math);
int number(int start, int end, string math);
int calculate(int k, int ans_1, int ans_2, string math);
int sum_digit(int total);
int final_sum(int total, int j);
int main() {  
  int ans_1,ans_2;
  string math;
  cout << "請輸入算式:";
  cin >> math;
  int i = input_digit(math);
  int k = front_digit(math);
  ans_1 = number(k, 0, math);
  ans_2 = number(i, k+1, math);
  int total = calculate(k, ans_1, ans_2, math);
  int j = sum_digit(total);
  int sum = final_sum(total, j);
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
    int i=0;
    while((int)math[i] != 0)
      {
        i++;
      }
    return i;
  }

//計算運算符號前有幾位數
int front_digit(string math)
  {
    int k=0;
    while((int)math[k] != 43 && (int)math[k] != 45 && (int)math[k] != 42 &&(int)math[k] != 47)
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
        for(int z = start-1; z >= end; z--)
      {
      
       sum += ((int)math[z]-'0') * position;
       position *= 10;
      }
    return sum;    
  }

//運算
int calculate(int k, int ans_1, int ans_2, string math)
  {
  int total = 0;
  if((int)math[k] == 43)
    {
      total = ans_1 + ans_2;
    }
  if((int)math[k] == 45)
    {
      total = ans_1 - ans_2;
    }    
  if((int)math[k] == 42)
    {
      total = ans_1 * ans_2;
    }    
  if((int)math[k] == 47)
    {
      total = ans_1 / ans_2;
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
