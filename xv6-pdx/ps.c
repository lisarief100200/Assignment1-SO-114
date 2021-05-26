#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

int main(int argc, char * argv[])
{
  int max = 72; // 1, 16, 64, 72
  struct uproc * table = malloc(sizeof(*table)*max);
  int num_procs = getprocs(max, table);
  uint second;
  uint millisecond;

  uint second_cpu;
  uint millisecond_cpu;

  if(table == 0){
    printf(1, "Invalid, unable to make table \n");
    exit();
  }

  printf(1, "MAX = %d", max);
  printf(1, "\nPID\tName         UID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");

  for(int i = 0; i < num_procs; i++){
    printf(1, "%d\t%s\t     %d\t\t%d\t%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid);

    // Elapsed time
    second  = table[i].elapsed_ticks/1000;
    millisecond = table[i].elapsed_ticks%1000;

    if(millisecond >= 100){
      printf(1, "%d.%d\t", second, millisecond);
    }
    else if(millisecond < 10){
      printf(1, "%d.00%d\t", second, millisecond);
    }
    else{
      printf(1, "%d.0%d\t", second, millisecond);
    }

    // CPU time
    second_cpu  = table[i].CPU_total_ticks/1000;
    millisecond_cpu = table[i].CPU_total_ticks%1000;

    if(millisecond_cpu >= 100){
      printf(1, "%d.%d\t", second_cpu, millisecond_cpu);
    }
    else if(millisecond_cpu < 10){
      printf(1, "%d.00%d\t", second_cpu, millisecond_cpu);
    }
    else{
      printf(1, "%d.0%d\t", second_cpu, millisecond_cpu);
    }

    // State & Size
    printf(1, "%s\t%d\n", table[i].state, table[i].size);
  }

  free(table);
  exit();
}
#endif // CS333_P2
