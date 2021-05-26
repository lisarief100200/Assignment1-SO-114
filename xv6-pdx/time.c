#ifdef CS333_P2
#include "types.h"
#include "user.h"

int main(int argc, char * argv[])
{
  if(argc == 1){
    printf(1, "(null) run in 0.000 seconds.\n");
    exit();
  }

  int start_time = uptime();
  int pid = fork();

  if(pid < 0){
    exit();
  }

  else if(pid == 0){
    exec(argv[1], argv+1);
    exit();
  }

  else if(pid > 0){
    wait();

    int end_time = uptime();
    int total = end_time - start_time;

    int second  = total/1000;
    int millisecond = total%1000;

    if(millisecond >= 100){
      printf(1, "%s ran in %d.%d seconds.\n", argv[1], second, millisecond);
    }
    else if(millisecond < 10){
      printf(1, "%s ran in %d.00%d seconds.\n", argv[1], second, millisecond);
    }
    else{
      printf(1, "%s ran in %d.0%d seconds.\n", argv[1], second, millisecond);
    }
  }
  else
    exit();

  exit();
}
#endif // CS333_P2
