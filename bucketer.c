#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  // Rated capacity of new all battery
  int ratedCapacity=120;//Ah
  for(int i=0;i<nBatteries;i++)
  {
    // Calculating state of health of battery
    float sohPercentage=((float)presentCapacities[i]/ratedCapacity)*100;
    // Classifying batteries based on SoH
    if(sohPercentage >80 && sohPercentage<=100)
    {
      counts.healthy++;
       
      }
    else if(sohPercentage >=62 && sohPercentage<=80)
    {
      counts.exchange++;
      
    }
    else
    {
      counts.failed++;
       
    }
  }
   printf(" Healthy count :%d\n",counts.healthy);
   printf(" Exchange count :%d\n",counts.exchange); 
   printf(" Failed count :%d\n",counts.failed); 
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
