#include <iostream>
#include <thread>

int
main ()
{
  int sum = 0;

  auto f =[&sum] (){
    for (int i = 0; i < 1000000; i++)
      {
	sum += 1;
      }
  };

  std::thread t1 (f);
  std::thread t2 (f);

  t1.join ();
  t2.join ();

  std::cout << sum << std::endl;

  return 0;
}
