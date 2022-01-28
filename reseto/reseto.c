#include <stdio.h>
#include <stdlib.h>

struct pNum{
  int val;
  int active;
};

int reseto(int n, int k){
  struct pNum numList[n-2];

  // initialize structs
  int t = 0;
  for (int i = 2; i <= n; i++){
    numList[i-2].val = i;
    numList[i-2].active = 1;
    //printf("Val %d\n", i);
    t = i;
  }

  //printf("%d\n", numList[0].val);

  //loop through em!
  int kCount = 0;
  for (int i = 0; i <= n-2; i++){
    if (!numList[i].active){
      continue;
    }


    int curIndex = 0;
    for (int j = 1; j < n; j++){
      curIndex = ((i + 2) * j) - 2; // Handle 2 item offset get multiple, then go back to index form.

      //printf("curIndex: %d\n", curIndex);

      if (curIndex > n - 2){
        break;
      }

      if (numList[curIndex].active){
        //printf("crossing out %d\n", numList[curIndex].val);
        numList[curIndex].active = 0;
        kCount += 1;
      }

      if (kCount == k){
        return(numList[curIndex].val);
      }
    }
    
  }
}

int main(){
  int n; int k;

  int numInputs = scanf("%d %d", &n, &k);

  if (numInputs != 2){
    printf("bad input!!\n");
    exit(1);
  }

  int ans = reseto(n,k);

  /* int ans = reseto(7,3); */

  printf("%d\n", ans);
}


